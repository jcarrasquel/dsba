#include <iostream>
#include <memory>

#include "person.h"
#include "smartpointer.h"
#include "shape.h"

void demo1()
{
	// up-casting (calcSalary() is a virtual function)

	Student* s = new Student("Joan",9); // s is a pointer to a new Student

	Professor* prof = new Professor("Smith",10);

	Person* ptr = s; // BaseClass* ptr = derivedClass;

	std::cout << ptr->calcSalary() << std::endl; //1800

	// down-casting

	// DerivedClass* ptr = &baseClass; //"SAFE DOWNCASTING"

	if(Student* ptrStu = dynamic_cast<Student*>(ptr)){
		std::cout << ptrStu->getAverageMark() << std::endl;
	}

	delete s;
	delete prof;
}

// smart pointers


void demo2()
{	
	// (0) a custom smart pointer

	SmartPtr<Student> ptr = new Student("Joan", 9);

	std :: cout << ptr->calcSalary() << std::endl;

}

void demo3()
{
	// (1) unique_pointer. Only one pointer at-a-time can point to Anna

	Student* anna = new Student("anna", 10); // p1 holds the "ownership" of Anna

	std::unique_ptr<Student> p1(anna);

	p1.release(); 

	std::unique_ptr<Student> p2(anna);
}

void demo4()
{
	// (2) shared_pointer. Many pointers can point to Anna

	Student* anna = new Student("Anna", 10);

	std::shared_ptr<Student> p1(anna);

	std::shared_ptr<Student> p2, p3;

	p2 = p1;
	p3 = p1;

	std::cout << p1.use_count() << std::endl;

	Student* john = new Student("John", 12);

	p1.reset(john); // RELEASE "Anna" and TAKE "John"

	std::cout << p2.use_count() << std::endl;
}

void demo5()
{
	// abstract class

	Circle c1(green, 2.0);

	std :: cout << c1.calcArea() << std :: endl;

	Shape* sPtr = &c1; // UPCASTING

	std :: cout << sPtr->calcArea() << std :: endl;
}

int main()
{
	demo5();

	return 0;
}