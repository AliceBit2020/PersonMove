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


	///0  Звичайні типи

	//	
	//int a, b,c;
	//a = b= c = 5;////    operator =

	///////1. Послідовне використання оператора присвоєння  типу obj1=obj2=2  вимагає від оператора присвоєння повертати посилання на обєкт  Person& operator=(const Person& obj)  

	//Person test(100, "f", "Oleksandra", "Ternova", "222322");

	//Person obj1;

	//Person obj2(25,"m","name","l_name","534636541");

	//obj2 = test;	/// copy

	//obj1.Output();
	//obj2.Output();

	///// move 

	//obj1 = move(test);
	//obj1.Output();
	//test.Output();

	/////2. Повернення обєкту за копією і подальше присвоєння призводить до того що тричі виділяеться память та потім відаляється при глибокому копіюванні, цього можна уникнути якщо передати/перенести/move управління обєктом памяті test  що виділився всередині фнкціі назовні одразу obj . Для цього перепишемо конструктор копіювання і присвоєння з глибоким копіюванням 

	Person obj1;
	obj1 = Generate();///  move =

	Person obj2 = Generate();///move по умолчанию в системе
	obj2.Output();

	//Person obj3 = Generate();
	Person obj4 = move(obj2);////   явно move конструктор

	

	//Person obj1;
	//obj1 = obj4;  ////copy  глибоке копыювання
	//obj1 = move (obj4);/// move  obj4 передає вказівники obj1 а сам залишається з nullptr


	//////////////////  Copy
	//Func1(test);

	/////////////////  Copy

	//Person obj_c(test);
	
	}  /// destructor test

Person Generate()////   возврат обьекта из функции уже заложена move семантика
{
	
	return Person (100, "f", "Oleksandra", "Ternova", "222322");
}


