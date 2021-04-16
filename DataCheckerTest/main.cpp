#include <iostream>
#include <set>
#include "NiRegister.h"
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
//navinfo::DataCheckerPlugin<DataChecker> s_Data("DataChecker");

int main(int argc, char **argv)
{
	GET_CHECKER(DataChecker)->display();
	GET_CHECKER(OtherChecker)->display();
	getchar();
	return 0;
}