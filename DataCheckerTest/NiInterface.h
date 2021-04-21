/****************************************************************************
*Copyright (c) 2021  All Rights Reserved.
*公司名称：
*命名空间：	navinfo
*文件名  ：	NiInterface.h
*作用    ： 基础接口层
*创建人  ： 涂理根
*创建时间：	2021/4/16 13:20:49
*****************************************************************************/
#pragma once
#include <string>
#include <vector>
namespace navinfo
{

	//! 配置基础类
	class IConfig
	{
	public:

	};
	

	//! 通告等级
	enum class eNotifyType
	{
		eInfo,
		eWarn,
		eError
	};

	//! 监听内容
	struct MsgContent
	{
		eNotifyType _type;
		std::string _content;
	};

	class IListener;
	class ISubject;

	typedef std::shared_ptr<navinfo::IListener> ListenPtr;
	typedef std::shared_ptr<navinfo::ISubject>  SubjectPtr;


	//! 监听者
	class IListener
	{
	public:
		IListener() { }
		virtual ~IListener() = default;

		//! 监听
		virtual void listen(const MsgContent &content) = 0;
	protected:
		//禁用拷贝构造函数
		IListener(const IListener &listener) = delete;
		IListener& operator=(const IListener &) = delete;

	};

	//! 主题类
	class ISubject
	{
	public:
		using ListenContainer = std::set< ListenPtr >;
		using ListenContIter  = ListenContainer::iterator;

		ISubject() = default;
		virtual ~ISubject() = default;

		//! 添加监听者
		void addListen(ListenPtr lsten)
		{
			_lstens.insert(lsten);
		}

		//! 移除监听者
		void rmListen(ListenPtr lsten)
		{
			_lstens.erase(lsten);
		}

		//! 通告
		void notiy(const MsgContent &content)
		{
			for(auto item : _lstens)
			{
				item->listen(content);
			}
		}

		virtual navinfo::MsgContent buildContent() = 0;
	protected:
		
		ListenContainer _lstens;
	};


	//! 插件接口类
	template<typename T>
	class IPluginBase
	{
	public:
		IPluginBase(const std::string &name, std::shared_ptr<T> ptr):_name(name), _ptr(ptr){}
		/*
		 * 获取名称
		 */
		std::string name()const { return _name; }

		std::shared_ptr<T> content()const { return _ptr; }
	protected:
		std::string				_name;
		std::shared_ptr<T>      _ptr;
	};

	//! 数据检查
	class IDataChecker 
	{
	public:
		IDataChecker() = default;
		virtual ~IDataChecker() = default;

		virtual void display() const = 0;
	};

	//! 数据预处理
	class IDataPreProcesser 
	{
	public:
	};
}