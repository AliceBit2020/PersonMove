#pragma once

#include <iostream>
using namespace std;

class Person {
private:
	char* name;
	char* fname;
	char* phone;
	int age;
	char* mf;

public:
	Person();
	Person(int ag, const char* m_f, const char* nm, const char* fn, const char* phn);
	Person(const Person& prs) ;//// copy constructor
	Person( Person&& prs);//// move constructor   &&- r value посилання для тимчасових обєктів що повертаються

	Person& operator=(const Person& obj) ;////оператор присвоєння, за аналогією  copy constructor, не побітове COPY
	Person& operator=( Person&& obj); ///MOVE




	bool  operator == (const Person& obj);///// логічний оператор дорівнює
	//bool  operator != (const Person& obj);  DZ!!!!!!!!!!!!!!!!!!!!

	/// <summary>
	/// bool operator>(const Person& obj);////порівнюємо за ім'я та фаміліє
	/// bool operator<(const Person& obj);
	/// </summary>
	/// 
	/// Додаємо клас Date( якому є operator=)
	/// 
	/// 

	~Person();


	void Output()const;
	void SetName(const char* nm);



};
