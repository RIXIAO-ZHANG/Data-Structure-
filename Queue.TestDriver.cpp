// programmer: RIXIAO ZHANG 
// ID: 1582174

#include <iostream>

using namespace std;

#include "Queue.h"
#include <cassert>
#include <string>

int main()
{
	cout << "programmer: RIXIAO ZHANG " << endl; 

	cout << "Queue test: double" << endl; 
	Queue<double> double_test;
	cout << "------------------" << endl;
	cout << "Testing Queue::size & Queue::Queue" << endl;
	cout << "EXPECTED: 0" << endl; 
	cout << "ACTUAL: "<< double_test.size() << endl;
	assert(double_test.size() == 0);
	cout << "Pass!" << endl << endl; 

	cout << "Testing Queue::push & Queue::back" << endl;
	double_test.push(100.89);
	double_test.push(214.432);
	double_test.push(69823.1);
	double_test.push(680.22);
	cout << "Expected back: 680.22" << endl; 
	cout << "ACTUAL: " << double_test.back() << endl;
	assert(double_test.back()==680.22);
	cout << "Pass!" << endl << endl;

	cout << "Testing Queue::pop & Queue::front" << endl;
	double_test.pop();
	double_test.pop();
	cout << "Expected front: 69823.1" << endl;
	cout << "ACTUAL: " << double_test.front() << endl;
	assert(double_test.front() == 69823.1);
	cout << "Pass!" << endl << endl;

	cout << "Testing Queue::empty"<< endl;
	double_test.pop();
	double_test.pop();
	cout << "Expected: empyt" << endl;
	cout << "ACTUAL: " << double_test.empty() << endl;
	assert(double_test.empty() == true);
	cout << "Pass!" << endl << endl;

	cout << "Testing Queue Copy Constructor" << endl;
	double_test.push(65.32);
	double_test.push(6879.21);
	double_test.push(68.23);
	double_test.push(879.65);
	Queue<double> dCopy_test(double_test);
	for (int i = 0; i < 4; i++)
	{
		assert( dCopy_test.front() == double_test.front());
		dCopy_test.pop();
		double_test.pop();
	}
	cout << "Pass!" << endl << endl;

	cout << "Testing Queue operator = " << endl;
	double_test.push(3456.98);
	double_test.push(55.121);
	double_test.push(56789.345);
	double_test.push(63249.472);
	Queue<double> dOper_test = double_test;
	for (int i = 0; i < 4; i++)
	{
		assert(dOper_test.front() == double_test.front());
		dOper_test.pop();
		double_test.pop();
	}
	cout << "Pass!" << endl << endl;

	cout << "Testing Constant Queue" << endl;
	double_test.push(47.12);
	double_test.push(5.12);
	double_test.push(34.1);
	double_test.push(678.2);
	const Queue<double> Cdouble_test(double_test);
	cout << "EXPECTED size: 4" << endl; 
	cout << "ACTUAL: " << Cdouble_test.size() << endl;
	assert(Cdouble_test.size() == 4); 
	assert(Cdouble_test.empty() == false);
	cout << "Pass!" << endl << endl << endl << endl; 



	cout << "Queue test: string" << endl;
	Queue<string> string_test;
	cout << "Testing Queue::size & Queue::Queue" << endl; 
	cout << "EXPECTED size = 0" << endl;
	cout << "ACTUAL: " << string_test.size() << endl; 
	assert(string_test.size() == 0);
	cout << "Pass!" << endl << endl; 

	cout << "Testing Queue::push & Queue::back" << endl;
	string_test.push("100");
	string_test.push("200");
	string_test.push("300");
	string_test.push("400");
	cout << "EXPECTED back:'400' " << endl;
	cout << "ACUTAL" << string_test.back() << endl;
	assert(string_test.back() == "400");
	cout << "Pass!" << endl << endl;

	cout << "Testing Queue::pop & Queue::front" << endl;
	string_test.pop();
	string_test.pop();
	cout << "EXPECTED front:'300' " << endl;
	cout << "ACUTAL" << string_test.front() << endl;
	assert(string_test.front() == "300");
	cout << "Pass!" << endl << endl;

	cout << "Testing Queue::empty" << endl;
	string_test.pop();
	string_test.pop();
	cout << "EXPECTED empty " << endl;
	cout << "ACUTAL" << string_test.empty() << endl;
	assert(string_test.empty() == true);
	cout << "Pass!" << endl << endl;

	cout << "Testing Copy Constructor" << endl;
	string_test.push("1000");
	string_test.push("2000");
	string_test.push("3000");
	string_test.push("4000");
	Queue<string> CopyString(string_test);
	for (int i = 0; i < 4; i++)
	{
		assert(CopyString.front() == string_test.front());
		CopyString.pop();
		string_test.pop();
	}
	cout << "Pass!" << endl << endl;

	cout << "Testing operator =" << endl;
	string_test.push("4678");
	string_test.push("2359");
	string_test.push("0987654");
	string_test.push("2314546");
	Queue<string> operString;
	operString = string_test;
	for (int i = 0; i < 4; i++)
	{
		assert(operString.front() == string_test.front());
		operString.pop();
		string_test.pop();
	}

	cout << "Testing Constant object" << endl;
	string_test.push("14df78");
	string_test.push("23wert59");
	const Queue<string> ConstString(string_test);
	cout << "EXPECTED size: 2" << endl; 
	cout << "ACTUAL: " << ConstString.size() << endl; 
	assert(ConstString.size() == 2);
	assert(ConstString.empty() == false);
	cout << "Pass!" << endl << endl;


	system("pause");

}