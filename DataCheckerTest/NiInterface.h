#pragma once
#include <string>
namespace navinfo
{

	//! ���û�����
	class IConfig
	{
	public:

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