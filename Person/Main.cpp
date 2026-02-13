#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

Person Generate();
void Func1(Person prs)
{
	prs.Output();
}///  передача по копії   prs destructor
void main()
{


	///////1. Послідовне використання оператора присвоєння  типу obj1=obj2=2  вимагає від оператора присвоєння повертати посилання на обєкт  Person& operator=(const Person& obj)  

	//Person test(100, "f", "Oleksandra", "Ternova", "222322");


	//Person obj2(25,"m","name","l_name","534636541");

	//obj2 = test;	/// copy operator =

	//Person obj1;
	//obj1 = move(test);//// move operator =


	//
	//obj1.Output();
	//obj2.Output();
	//test.Output();

	///2.  Constructor  copy vs move

	Person test(100, "f", "Oleksandra", "Ternova", "222322");

	Person deepCopy(test);//copy

	Person mooveCopy(move(test));

	deepCopy.Output();
	cout << "___________________________" << endl;
	test.Output();
	cout << "___________________________" << endl;
	mooveCopy.Output();
	
	
	}  /// destructor test

Person Generate()////   возврат обьекта из функции уже заложена move семантика
{
	
	return Person (100, "f", "Oleksandra", "Ternova", "222322");
}


