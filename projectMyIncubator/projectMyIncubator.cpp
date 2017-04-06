// projectMyIncubator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::runtime_error;
using std::initializer_list;

int main(int argc, char *argv[])
{
	cout << "Hello, VS2017\n" << endl;
	cout << "Command line arguments:" << endl;
	cout << "------------------------" << endl;
	cout << "argc: [" << argc << "]" << endl;
	cout << "argv: " << endl;

	for (int i = 0; i != argc; i++)
	{
		cout << i << ": " << argv[i] << endl;
	}
	cout << endl;

#if TBD
	// TODO: How to output hex value?
	unsigned char uCharVal = 0;
	uCharVal = 256;
	std::cout << std::hex << uCharVal << std::endl;
	uCharVal = 128;
	std::cout << std::hex << uCharVal << std::endl;
#endif
	
	void test(void);
	test();

	//system("pause");

    return 0;
}
 
void test(void)
{
	extern void reloadOriginal(int a=3);
	reloadOriginal();
	reloadOriginal(2);
}

void reloadOriginal(int a = 1)
{
	cout << a << " " << endl;
}

void testInitList(void)
{
	void testInitializerList(initializer_list<string> args, string extVal);

	testInitializerList({ "1. ", "3 ", "args" }, "Hi!");
	testInitializerList({ "2. ", "5 ", "args ", "OK ", "?" }, "Hi again!");
}

void testInitializerList(initializer_list<string> args, string extVal)
{
	for (string cur : args)
		cout << cur;
	cout << endl;
	cout << extVal << endl;
}

void exceptionThrow(void)
{
	throw runtime_error("Fox's exception!");
}

void testException(void)
{
	try {
		exceptionThrow();
	}
	catch (runtime_error e) {
		cout << "Exception caught! It is a " << e.what() << endl;
	}
}

void testArray(void)
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

#if 0
	for (auto row : ia)
		for (auto col : row) // ERROR row被编译器转成int*，不能对int*进行range for
			cout << col << endl;
#endif

	for (auto &row : ia)
		for (auto col : row) // row是4个元素数组的引用
			cout << col << endl;

	for (auto &row : ia)
		for (auto col : row)
			col = 123; // col不是引用，所以没有修改到ia的元素

	for (auto &row : ia)
		for (auto &col : row)
			col = 123; // col是引用，直接修改到ia的元素


}

void testVector(void)
{
	vector<int> vInt{ 1, 2, 3, 4, 5 };

	for (auto itr = vInt.begin(); itr != vInt.end(); itr++)
	{
		cout << *itr << endl;
	}
}

void testRangeFor(void)
{
	string strFox("Hello, viper.\n");

	cout << "Original: " << strFox << endl;
	for (char c : strFox)
	{
		c = toupper(c);
	}
	cout << "range for with char c: " << strFox << endl;

	for (char &c : strFox)
	{
		c = toupper(c);
	}
	cout << "range for with char &c: " << strFox << endl;
}
