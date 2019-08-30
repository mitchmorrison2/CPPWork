#include "mstring.h"
#include <cstring>

mString::mString()
{
    data = nullptr;
}

mString::~mString()
{
    if (data != nullptr)
        delete[] data; //keep from memory leak
}

mString::mString(char* p) {
    data = new char [strlen(p) + 1]; //allow for null-term char
    strcpy(data, p); //p strcpy into data with null-term char
}

mString::mString(const mString& p) {
    data = new char[strlen(p.data) + 1]; //allow for null-term char
    strcpy(data, p.data); //p strcpy into data with null-term char
}

mString& mString::operator= (const char* p) {
    if (data!= nullptr) {
        delete[] this->data; //invoking data member
    }
    data = new char[strlen(p) + 1];
    strcpy(data, p);
    return (*this); //returns type mString
}

mString& mString::operator= (const mString& p) {
    if (data != nullptr) {
        delete[] this->data;
    }
    data = new char[strlen(p.data) + 1];
    strcpy(data, p.data);
    return (*this); //returns address of new mString copy
}

mString mString::operator+ (const mString& z) {

    char* temp = this->data;
    temp = new char[strlen(data) + strlen(z.data) + 1];
    strcpy(temp, data);
    strcat(temp, z.data);
    return temp; //returns new mString temp
}

mString& mString::operator+= (const mString& z) {
    char* temp = this->data;
    if (data != nullptr) {
        delete[] this->data; //free memory for usage
    }
    this->data = new char[strlen(data) + strlen(z.data) + 1];
    strcpy(this->data, temp);
    strcat(this->data, z.data);
    delete[] temp; //free storage of temp pointer
    return (*this); //returns address of newly concatenated mString by defreferncing this pointer
}

bool mString::operator== (const char* t) {
    if (strcmp(data, t) != 0) { //strcmp evaluates to 0 if equal
        return false;
    }
    else return true;
}

bool mString::operator== (const mString& p) {
    if (strcmp(data, p.data) != 0) { //strcmp evaluates to 0 if equal
        return false;
    }
    else return true;
}

bool mString::operator< (const char* s) {
    if (strcmp(this->data, s) < 0) { //if strcmp evaluates to <0 returns true
        return true;
    }
    else return false;
}

bool mString::operator< (const mString& s) {
        if (strcmp(this->data, s.data) < 0) { //if strcmp evaluates to <0 returns true
        return true;
    }
    else return false;
}

char& mString::operator[] (const int n) {

}

int mString::size() {

}

mString mString::substring(int a, int b) {

}

char c_str() {

}

friend std::ostream& operator<< (std::ostream&, const String&) { //should this be mString

}

