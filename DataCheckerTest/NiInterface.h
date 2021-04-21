/****************************************************************************
*Copyright (c) 2021  All Rights Reserved.
*��˾���ƣ�
*�����ռ䣺	navinfo
*�ļ���  ��	NiInterface.h
*����    �� �����ӿڲ�
*������  �� Ϳ���
*����ʱ�䣺	2021/4/16 13:20:49
*****************************************************************************/
#pragma once
#include <string>
#include <vector>
namespace navinfo
{

	//! ���û�����
	class IConfig
	{
	public:

	};
	

	//! ͨ��ȼ�
	enum class eNotifyType
	{
		eInfo,
		eWarn,
		eError
	};

	//! ��������
	struct MsgContent
	{
		eNotifyType _type;
		std::string _content;
	};

	class IListener;
	class ISubject;

	typedef std::shared_ptr<navinfo::IListener> ListenPtr;
	typedef std::shared_ptr<navinfo::ISubject>  SubjectPtr;


	//! ������
	class IListener
	{
	public:
		IListener() { }
		virtual ~IListener() = default;

		//! ����
		virtual void listen(const MsgContent &content) = 0;
	protected:
		//���ÿ������캯��
		IListener(const IListener &listener) = delete;
		IListener& operator=(const IListener &) = delete;

	};

	//! ������
	class ISubject
	{
	public:
		using ListenContainer = std::set< ListenPtr >;
		using ListenContIter  = ListenContainer::iterator;

		ISubject() = default;
		virtual ~ISubject() = default;

		//! ��Ӽ�����
		void addListen(ListenPtr lsten)
		{
			_lstens.insert(lsten);
		}

		//! �Ƴ�������
		void rmListen(ListenPtr lsten)
		{
			_lstens.erase(lsten);
		}

		//! ͨ��
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


	//! ����ӿ���
	template<typename T>
	class IPluginBase
	{
	public:
		IPluginBase(const std::string &name, std::shared_ptr<T> ptr):_name(name), _ptr(ptr){}
		/*
		 * ��ȡ����
		 */
		std::string name()const { return _name; }

		std::shared_ptr<T> content()const { return _ptr; }
	protected:
		std::string				_name;
		std::shared_ptr<T>      _ptr;
	};

	//! ���ݼ��
	class IDataChecker 
	{
	public:
		IDataChecker() = default;
		virtual ~IDataChecker() = default;

		virtual void display() const = 0;
	};

	//! ����Ԥ����
	class IDataPreProcesser 
	{
	public:
	};
}