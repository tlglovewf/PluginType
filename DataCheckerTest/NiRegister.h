/****************************************************************************
*Copyright (c) 2021  All Rights Reserved.
*公司名称：
*命名空间：	navinfo
*文件名  ：	NiRegister.h
*作用    ： 注册类
*创建人  ： 涂理根
*创建时间：	2021/4/16 13:20:49
*****************************************************************************/
#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "NiInterface.h"
namespace navinfo
{
	template<typename T>
	class Register final
	{
	public:
		Register<T>() = default;
		~Register<T>() = default;

		Register<T>& operator=(const Register&) = delete;
		/*
		 * 单例
		 */
		static Register<T>& getSingleton()
		{
			static Register<T> s_instance;
			return s_instance;
		}

		/*
		 * 注册
		 */
		void regist(std::shared_ptr< IPluginBase<T> > ptr)
		{
			mItems.emplace(std::make_pair(ptr->name(), ptr->content()));
		}

		/*
		 * 注销
		 */
		void unregist(std::shared_ptr< IPluginBase<T> > ptr)
		{
			mItems.erase(ptr->name());
		}

		/*
		 * 获取实例对象
		 */
		std::shared_ptr<T> getObject(const std::string &name)
		{
			auto iter = mItems.find(name);
			return (iter == mItems.end()) ? nullptr : iter->second;
		}

	protected:
		using ItemContainer = std::unordered_map<std::string, std::shared_ptr< T > >;

		ItemContainer							mItems;

	};


	/*
	* 插件类
	*/
	template<typename T, typename C>
	class PluginInstance 
	{
	public:
		PluginInstance(const std::string &name)
		{
			static shared_ptr< IPluginBase<C> > t = std::make_shared<IPluginBase<C> >(name, std::make_shared<T>());
			Register<C>::getSingleton().regist(t);
		}

		virtual ~PluginInstance() = default;
	protected:
		std::shared_ptr<T> _ptr;
	};

	template<typename T>
	class DataCheckerPlugin : public PluginInstance<T, IDataChecker> {
	public:
		DataCheckerPlugin<T>(const std::string &name) :PluginInstance<T, IDataChecker>(name)
		{

		};
	};


	template<typename T>
	class DataPreProcPlugin : public PluginInstance<T, IDataPreProcesser> {
	public:
		DataPreProcPlugin<T>(const std::string &name) : PluginInstance<T, IDataPreProcesser>(name)
		{

		}
	};

}

/*
 * 数据检查注册宏定义
 */
using R_IDataChecker		= navinfo::Register<navinfo::IDataChecker>;
#define REGIST_CHECKER(CLS) \
		navinfo::DataCheckerPlugin<CLS> s_##CLS(#CLS);
#define UNREGIST_CHECKER(CLS) \
		R_IDataChecker::getSingleton().unregist(#CLS);
#define GET_CHECKER(CLS) \
		R_IDataChecker::getSingleton().getObject(#CLS)

/*
 * 数据预处理宏定义
 */
using R_IDataPreProcesser = navinfo::Register<navinfo::IDataPreProcesser>;
#define REGIST_PREPROC(CLS) \
		navinfo::DataPreProcPlugin<CLS> s_##CLS(#CLS);
#define UNREGIST_PREPROC(CLS) \
		R_IDataPreProcesser::getSingleton().unregist(#CLS);
#define GET_PREPROC(CLS) \
		R_IDataPreProcesser::getSingleton().getObject(#CLS)