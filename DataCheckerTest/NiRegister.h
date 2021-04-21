/****************************************************************************
*Copyright (c) 2021  All Rights Reserved.
*��˾���ƣ�
*�����ռ䣺	navinfo
*�ļ���  ��	NiRegister.h
*����    �� ע����
*������  �� Ϳ���
*����ʱ�䣺	2021/4/16 13:20:49
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
		 * ����
		 */
		static Register<T>& getSingleton()
		{
			static Register<T> s_instance;
			return s_instance;
		}

		/*
		 * ע��
		 */
		void regist(std::shared_ptr< IPluginBase<T> > ptr)
		{
			mItems.emplace(std::make_pair(ptr->name(), ptr->content()));
		}

		/*
		 * ע��
		 */
		void unregist(std::shared_ptr< IPluginBase<T> > ptr)
		{
			mItems.erase(ptr->name());
		}

		/*
		 * ��ȡʵ������
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
	* �����
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
 * ���ݼ��ע��궨��
 */
using R_IDataChecker		= navinfo::Register<navinfo::IDataChecker>;
#define REGIST_CHECKER(CLS) \
		navinfo::DataCheckerPlugin<CLS> s_##CLS(#CLS);
#define UNREGIST_CHECKER(CLS) \
		R_IDataChecker::getSingleton().unregist(#CLS);
#define GET_CHECKER(CLS) \
		R_IDataChecker::getSingleton().getObject(#CLS)

/*
 * ����Ԥ����궨��
 */
using R_IDataPreProcesser = navinfo::Register<navinfo::IDataPreProcesser>;
#define REGIST_PREPROC(CLS) \
		navinfo::DataPreProcPlugin<CLS> s_##CLS(#CLS);
#define UNREGIST_PREPROC(CLS) \
		R_IDataPreProcesser::getSingleton().unregist(#CLS);
#define GET_PREPROC(CLS) \
		R_IDataPreProcesser::getSingleton().getObject(#CLS)