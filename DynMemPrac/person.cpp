#include "person.h"

person::person()
{
}

person::~person()
{
}

Person::Person()
{
    name = "Bob";
    age = 20;
}

Person::Person(string n, int a)
{
    name = n;
    age = a;
}

string Person::getName()
{
    return name;
}

void Person::setName(string s)
{
    name = s;
}

Person Person::operator+(int val)
{
    Person temp(this->name, this->age + val);
    return temp;
}