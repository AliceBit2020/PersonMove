#include "Person.h"


Person::Person()
{
	cout << "Constructor defoult" << endl;
	age = 0;
	mf = new char[8]{ "Unknown" };////// динамічно виділили пам_ять
	name = new char[8]{ "Unknown" };
	fname = new char[8]{ "Unknown" };////// динамічно виділили пам_ять
	phone = new char[8]{ "Unknown" };
}



Person::Person(int ag, const char* m_f, const char* nm, const char* fn, const char* phn)///
{
	cout << "Constr param" << endl;
	age = ag;

	
	int size = strlen(m_f) + 1;////робота зі строками  тут вызначаемо розмір строки m_f що зайде  mail -4
	mf = new char[size];////виділяемо в кучі пям_ть під потрібний розмір
	strcpy_s(mf, size, m_f);/////робимо копію з m_f що зайде в наше поле mf

	size = strlen(nm) + 1;
	name = new char[size];
	strcpy_s(name, size, nm);


	size = strlen(fn) + 1;
	fname = new char[size];
	strcpy_s(fname, size, fn);

	size = strlen(phn) + 1;
	phone = new char[size];
	strcpy_s(phone, size, phn);

}

Person::Person(const Person& prs)/////copy constructor
{
	cout << "Copy constructor" << endl;
	/////name = prs.name; ///побітове копі
	int size = strlen(prs.name) + 1;
	name = new char[size];
	strcpy_s(name, size, prs.name);

	size = strlen(prs.fname) + 1;
	fname = new char[size];
	strcpy_s(fname, size, prs.fname);

	size = strlen(prs.mf) + 1;
	mf = new char[size];
	strcpy_s(mf, size, prs.mf);

	size = strlen(prs.phone) + 1;
	phone = new char[size];
	strcpy_s(phone, size, prs.phone);

	age = prs.age;

}



Person::Person( Person&& prs)/////   obj=prs
{
	cout << "Move constructor" << endl;

	name = prs.name;
	fname = prs.fname;
	mf = prs.mf;
	phone = prs.phone;
	age = prs.age;


	prs.name = nullptr;
	prs.fname= nullptr;
	prs.mf = nullptr;
	prs.phone = nullptr;
}

Person& Person::operator=(const Person& prs)
{
	cout << "Operator = copy" << endl;

	int size = strlen(prs.name) + 1;
	//////name = new char[8]{ "Unknown" };
	delete[] name;
	name = new char[size];
	strcpy_s(name, size, prs.name);

	size = strlen(prs.fname) + 1;
	delete[] fname;
	fname = new char[size];
	strcpy_s(fname, size, prs.fname);

	size = strlen(prs.mf) + 1;
	delete[] mf;
	mf = new char[size];
	strcpy_s(mf, size, prs.mf);

	size = strlen(prs.phone) + 1;
	delete[] phone;
	phone = new char[size];
	strcpy_s(phone, size, prs.phone);

	age = prs.age;


	return *this;
}

Person& Person::operator=(Person&& prs)///obj   Move
{
	cout << "Move =" << endl;
	delete[] name;
	delete[] fname;
	delete[] mf;
	delete[] phone;

	////передаємо право користування ресурсами
	name = prs.name;
	fname = prs.fname;
	mf = prs.mf;
	phone = prs.phone;
	age = prs.age;


	


	prs.name = nullptr;
	prs.fname = nullptr;
	prs.mf = nullptr;
	prs.phone = nullptr;
	return *this;
}

bool Person::operator==(const Person& obj)//////   тут порівнюємо this з obj
{


	////if(name==obj.name)////указатели, не підходить  порівняння вказівників
	//// if (*name==*obj.name)//// порівняння перших символів


	/////////    ПОРІВНЯННЯ СТРОК!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////	/*
////////	
////////	int strcmp(
////////   const char *string1,
////////   const char *string2
////////);
////////	
////////	Возвращаемое значение каждой из этих функций отображает порядковое отношение строки string1 к строке string2.
////////
////////		Значение	Отношение типа string1 к string2
////////		< 0	string1 меньше string2
////////		0	string1 идентична string2
////////		> 0	string1 больше string2*/



	if (strcmp(this->name, obj.name) == 0)//////
		if (strcmp(this->fname, obj.fname) == 0)
			if (strcmp(this->phone, obj.phone) == 0)
				if (strcmp(this->mf, obj.mf) == 0)
					if (age == obj.age)
						return true;


	return false;
}

Person::~Person()
{
	cout << "Destructor" << endl;
	if(name )
	delete [] name;///char*
	if(fname)
	delete[] fname;
	if(mf)
	delete[] mf;
	if(phone)
	delete[] phone;
}

void Person::Output() const
{

	if (name != nullptr)
	{
		cout << "Name: " << name << endl;
		cout << "Fisrt name: " << fname << endl;
		cout << "Age: " << age << endl;
		cout << "M/F: " << mf << endl;
		cout << "Phone: " << phone << endl;
	}
	else
		cout << "Nillptr" << endl;
}

void Person::SetName(const char* nm)
{

	int size = strlen(nm) + 1;
	delete[] name;
	name = new char[size];
	strcpy_s(name, size, nm);



}

