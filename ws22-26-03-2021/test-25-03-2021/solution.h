#include <string>   
#include <cstdint> // uint8_t, uint16_t
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

struct Student {
    std::string name;
    uint16_t group; 
    std::vector<uint16_t> grades;
};

//=========================[TASK 1: up to 0.35]===============================//

std::vector<Student> readStudents(std::istream& istr)
{
    std::vector<Student> res;

    std::string line, token;

    while(std::getline(istr, line))
    {
        std::istringstream ss(line);
        std::vector<std::string> lineAsVector;

        while(std::getline(ss, token, '\t'))
        {
            lineAsVector.push_back(token);   
        }

        Student s;
        s.name = lineAsVector[0];
        s.group = std::stoul(lineAsVector[1]);

        for(int i = 2; i < lineAsVector.size(); i++)
        {
            s.grades.push_back(std::stoul(lineAsVector[i]));
        }

        res.push_back(s);

    }

    return res;
}

//=========================[TASK 2: up to 0.15]===============================//

double gpa(const Student& student)
{
    if(student.grades.size() == 0)
        return 0.0;

    double accum = 0.0; // sum all grades of a student

    for(int i = 0; i < student.grades.size(); i++)
    {
        accum += student.grades[i];
    }

    return accum / student.grades.size();
}

std::ostream& operator<<(std::ostream& s, const Student& student)
{
    // Name: Venere Maia, Group: 173, GPA: 6.5
    s << "Name: " << student.name << ", Group: " << student.group << ", GPA: " << gpa(student);

    return s;
}

std::ostream& operator<<(std::ostream& s, const std::vector<Student>& v)
{
    for(int i = 0; i < v.size(); i++)
    {
        s << v[i] << std :: endl;
    }  
    return s;
}


//=========================[TASK 3: up to 0.35]===============================//


std::map<uint16_t, double> calcGroupAverage(const std::vector<Student>& students)
{
    std::map<uint16_t, double> res; // key are the group names, and the values are the average gpa per group

    std::map<uint16_t, int> c; // keys are group numbers, and values are number of students per group

    for(Student student : students)
    {
        c[student.group] = c.find(student.group) != c.end() ? c[student.group] + 1 : 1;
        res[student.group] = res.find(student.group) != res.end() ? res[student.group] + gpa(student) : gpa(student);
    }

    std::map<uint16_t, double>::iterator it;
    for(it = res.begin(); it != res.end(); ++it)
    {
        it->second /= c[it->first];
    }

    return res;
}

//=========================[TASK 4: up to 0.15]===============================//

bool weakStudent(const Student& student)
{
    bool unsatisfactoryGrade = false; // innocent if we do not find unsatsGrade

    for(int i = 0; i < student.grades.size(); i++)
    {
        if(student.grades[i] < 4)
        {
            unsatisfactoryGrade = true;
            break;
        }
    }

    return unsatisfactoryGrade;
}

std::vector<Student>& removeWeakStudents(std::vector<Student>& students)
{
    std::vector<Student>::iterator it;

    for(it = students.begin(); it != students.end(); )
    {
        if(weakStudent(*it))
        {
            it = students.erase(it);  // if "it" is passed by reference 
        }else{
            ++it;
        }
    }


    return students;
}