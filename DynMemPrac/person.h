#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person();
    Person(string n, int a);
    string getName();
    void setName(string s);
    int getAge() {return age;}
    Person operator+(int val);
};




#endif // PERSON_H
