#pragma once
#include <string>
namespace navinfo
{

	//! 配置基础类
	class IConfig
	{
	public:

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