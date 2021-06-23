#include <QtWidgets/QApplication>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickView>
#include <QQuickItem>
#include <QLabel>
#include <QDir>
#include <QMessageBox>

#include "Frameless/FrameLessView.h"
#include "Frameless/Trans.h"
#include "Frameless/QuickTool.h"

#include <QSystemSemaphore>
#include <QSharedMemory>

static void prepareApp()
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#    if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
	QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#    endif
#endif
	QCoreApplication::setOrganizationName("Navinfo");
	QCoreApplication::setOrganizationDomain("https://www.navinfo.com");
	QCoreApplication::setApplicationName("Navinfo");
}

int main(int argc, char *argv[])
{
	
	////确保只运行一次
	QSystemSemaphore sema("Quality_Sema", 1, QSystemSemaphore::Open);
	sema.acquire();//在临界区操作共享内存  SharedMemory

	QSharedMemory mem("Quality_Exe"); //全局对象名

	QApplication app(argc, argv);
	if (!mem.create(1))
	{
		QMessageBox::information(nullptr, "warning", "已有一个运行实例");
		sema.release();
		return -1;
	}
	sema.release();

	prepareApp();


	
#if 0
    QQuickView viewer;
    viewer.engine()->addImportPath("./Ui/TaoQuick/imports/");
    viewer.rootContext()->setContextProperty("taoQuickImagePath", "./Ui/TaoQuick/imports/TaoQuick/Images");
    viewer.setSource(QUrl("main.qml"));

    viewer.show();
	
	QLabel *label = new QLabel();
    label->setText("hello world");

	viewer.engine()->rootContext()->setContextProperty("labelpop", label);

    //label->show();
#else
    const auto appPath = QDir::cleanPath(app.applicationDirPath());
    FrameLessView view;
	view.setMinimumSize({ 1440, 960 });
	view.setMaximumSize({ 1440, 960 });
	view.resize({ 1440, 960 });
    view.moveToScreenCenter();

	Trans trans;
    QuickTool quickTool;
	trans.beforeUiReady(view.rootContext(), "");
	#    ifdef TaoQuickImport
    view.engine()->addImportPath("qrc:/");
    qWarning() << "TaoQuickImportPath " << TaoQuickImport;
#    endif

#    ifdef TaoQuickImage
    view.rootContext()->setContextProperty("taoQuickImagePath", TaoQuickImage);
#    endif

#    ifdef _DEBUG
    view.rootContext()->setContextProperty("isDebug", true);
#    else
    view.rootContext()->setContextProperty("isDebug", QVariant(false));
#    endif

    view.rootContext()->setContextProperty("qmlPath", qmlPath);
    view.rootContext()->setContextProperty("imgPath", imgPath);
    view.rootContext()->setContextProperty("contentsPath", contentsPath);

    view.rootContext()->setContextProperty("appPath", appPath);

    view.rootContext()->setContextProperty("view", &view);
	//界面导航
	view.rootContext()->setContextProperty("quickTool", &quickTool);

    const QUrl url("qrc:/Qml/main.qml");
   
    QObject::connect(&view, &QQuickView::statusChanged, [&](QQuickView::Status status) {
        if (status == QQuickView::Status::Ready) {
            trans.afterUiReady();
            quickTool.setRootObjet(view.rootObject());
        }
    });
	view.setSource(url);
    //qml call 'Qt.quit()' will emit engine::quit, here should call qApp->quit
    QObject::connect(view.engine(), &QQmlEngine::quit, qApp, &QCoreApplication::quit);
    //qml clear content before quit
    QObject::connect(qApp, &QGuiApplication::aboutToQuit, qApp, [&view]() { view.setSource({}); });

    view.show();
#endif
    return app.exec();
}
