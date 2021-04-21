#include <iostream>
#include <thread>
#include <set>
#include "NiRegister.h"

#include "libuv/uv.h"

#include "filesystem/fs_std.hpp"

#include "spdlog/spdlog.h"

#include "spdlog/stopwatch.h"

using namespace std;


class DataChecker : public  navinfo::IDataChecker
{
public:
	virtual void display() const
	{
		std::cout << "this is datachecker." << std::endl;
	}
};

class OtherChecker : public navinfo::IDataChecker
{
public:
	virtual void display()const
	{
		std::cout << "this is other." << std::endl;
	}
};

REGIST_CHECKER(DataChecker)
REGIST_CHECKER(OtherChecker)

std::vector<std::string>  msgs;
static void idle_cb(uv_idle_t* handle) {
	if (!msgs.empty())
	{
		std::cout << *msgs.rbegin() << std::endl;
		msgs.pop_back();
	}
}
uv_idle_t idle_handle;
void loop()
{

	int ret = uv_idle_init(uv_default_loop(), &idle_handle);

	if (0 == ret)
	{
		uv_idle_start(&idle_handle, idle_cb);
	}
	uv_run(uv_default_loop(), UV_RUN_DEFAULT);
	std::cout << "¡¶¡¶----END----¡·¡·" << std::endl;
}

void testPlugin()
{
	GET_CHECKER(DataChecker)->display();
	GET_CHECKER(OtherChecker)->display();
}

void testIdle()
{
	std::thread  thr(loop);
	msgs.push_back("hellop");
	msgs.push_back("world");
	getchar();
	uv_stop(uv_default_loop());
	thr.join();
	getchar();
}

void testLog()
{
	spdlog::set_pattern("%^%H:%M:%S:%z-[thread %t][%l] %v");
	spdlog::info("world hello");
	spdlog::error("something error.");
	getchar();
}
void testFile()
{
	fs::path filepath("C:/Test/cpptest/DataCheckerTest/test");
	if (!fs::exists(filepath))
	{
		std::error_code ret;

		if (!fs::create_directory(filepath, ret))
		{
			std::cout << "path create error : " << ret.message() << std::endl;
			return;
		}
	}
	else
	{
		auto de = fs::recursive_directory_iterator(filepath);
		
		for (auto item : de)
		{
			if (item.is_regular_file())
			{
				std::cout << "is regular file : " << item.file_size() << std::endl;
				fs::ifstream ifile(item.path());
				if (ifile.is_open())
				{
					
				}
			}
			else if (item.is_directory())
			{
				std::cout << "directory." << std::endl;
			}
			else
			{
				std::cout << "others" << std::endl;
			}
			
		}
	}
	getchar();
}


int main(int argc, char **argv)
{
	//testPlugin();

	//testIdle();

	testLog();

	//testFile();

	return 0;
}