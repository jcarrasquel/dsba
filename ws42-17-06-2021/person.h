#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

typedef unsigned int UInt;

// "ABSTRACT" class
class Person {
    public:
        Person()
        {
            std::cout << "Person's Default Constructor\n";
        }

        explicit Person(const std::string& name)
            : _name(name)
        {
            std::cout << "Person's Init Constructor\n";
        }

        virtual ~Person()
        {
            std::cout << "Person's Destructor\n";
        }

        virtual double calcSalary() const;

        const std::string& getName() const { return _name; }
        void setName(const std::string& name) { _name = name; }

    protected:
        std::string _name;
};


class Student : public Person
{
    public:
        Student()
            //: Person () // implicitly calls the default constructor of the base class
        {
            std::cout << "Student's Default Constructor\n";
        }

        Student(const std::string& name, UInt grId)
            : _groupId(grId)
            , Person(name)
        {
            std::cout << "Student's Init Constructor. ";
            std::cout << "The base part name is: " << _name << '\n';
        }

        ~Student()
        {
            std::cout << "Student's Destructor\n";
        }

    public:
        std::string makeNameGroup() const
        {
            std::stringstream ss;
            ss << "Name: " << _name << ", Group ID: " << _groupId;

            return ss.str();
        }

        void addGrade(int grade)
        {
            _grades.push_back(grade);
        }

        UInt getGroupId() const { return _groupId; }
        void setGroupId(UInt grId) { _groupId = grId;}

        virtual double calcSalary() const override;

    protected:

        std::vector<int> _grades;   // collection

    private:
        UInt _groupId;
};


class Professor : public Person
{
    public:
        Professor()
            //: Person () // implicitly calls the default constructor of the base class  //("Marco")
        {
            std::cout << "Professor's Default Constructor\n";
        }

        Professor(const std::string& name, UInt qPeriod)
            : _qualPeriod(qPeriod)
            , Person(name)
        {
            std::cout << "Professor's Init Constructor. ";
            std::cout << "The base part name is: " << _name << "\n";
        }
        ~Professor()
        {
            std::cout << "Professor's Destructor\n";
        }

    public:
        virtual double calcSalary() const override;
        UInt getQualPeriod() const { return _qualPeriod; }

    private:
        UInt _qualPeriod;
};


#endif // PERSON_H_