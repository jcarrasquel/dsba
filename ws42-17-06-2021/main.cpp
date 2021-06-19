#include <iostream>
#include "person.h"
#include <memory>

// *** use of virtual functions ***
void demo1()
{
	Student stu("Marco", 1811);
	stu.addGrade(10);
	stu.addGrade(10);
	stu.addGrade(10);

	// some magic...

	Person* persPtr = &stu; //BaseClass* b = &derivedClass; UP-CASTING
	std :: cout << persPtr->calcSalary() << std :: endl;
}

//-------------------------------------------------------

// *** virtual (runtime) polymorphism ***

std::vector<Person*> createSample()
{
    std::vector<Person*> team;

    Student* anna = new Student("Anna", 134);
    anna->addGrade(10);

    Professor* prof = new Professor("Dr. Smith", 20);
   
    // "Up-casting"
    team.push_back(prof);
    team.push_back(anna);

    return team;
}

void deletePeopleVector(std::vector<Person*>& team)
{
    // DONE: clear memory
    for(Person* pers : team)
        delete pers;
    team.clear();
}

void demo2()
{
    std::vector<Person*> team = createSample(); // team = [Professor:Dr.Smith,Student:Anna]

    for(const Person* pers : team) 
    {
        // Down-cast to access back again to the DerivedClass!

        // is a student?
        if(const Student* stu = dynamic_cast<const Student*>(pers))
        {
            std::cout<<"It's a student! Student group: " << stu->getGroupId() << std::endl;
        }

        // is a professor? 
        if(const Professor* prof = dynamic_cast<const Professor*>(pers))
        {
            std::cout<<"It's a professor! Qualification: " << prof->getQualPeriod() << std::endl;
        }

    	std :: cout << "Person: " << pers->getName() << " Salary: " << pers->calcSalary() << std::endl;

    }

    deletePeopleVector(team);
}

//-------------------------------------------------------

// *** dynamic casting ***
void demo3()
{
	Person* john = new Person("John Doe");

    Student* ptrStu = dynamic_cast<Student*>(john);
}

//--------------------------------------------------------

// *** smart pointer ***
void demo4()
{
	Person* john = new Person("John Doe");

    std::unique_ptr<Person> smartPtr(john);
}

//--------------------------------------------------------

// *** abstract class (is needed to modify person.h and .cpp) ***

void demo5()
{
    //Person john("John Doe"); <--- not possible if we change Person to abstract class

    Student mary("Mary Smith", 1921);
    mary.addGrade(10);
    
    Person* pMary = &mary;
    Student* p2Mary = &mary;
    
    std::cout << "Mary's salary: " << pMary->calcSalary() << ", or " << p2Mary->calcSalary() << "\n";
}

int main()
{
    //demo1();
    //demo2();
    //demo3();
    //demo4();
    //demo5();

    return 0;
}