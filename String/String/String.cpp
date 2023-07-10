//
//  String.cpp
//  String
//
//  Created by Bussarin Apichitchon on 7/7/2566 BE.
//

#include "Utils.hpp"
#include "String.hpp"

using namespace std;

namespace sdds {

// MARK: file scope instance called U of utils in Utils.cpp
String S;

// MARK: String class
// return true is m_data == nullptr
bool String::isEmpty()const {
    return  m_data == nullptr;
}
// set String to empty state
sdds::String &String::setEmpty() {
    m_data = nullptr;
    m_length = 0u;
    return *this;
}
// constructor
String::String(const char* cstr) {
    if (cstr) {
        m_length = U.strLen(cstr);
        m_data = new char[m_length + 1];
        U.strCpy(m_data, cstr);
    }
}
// destructor
String::~String() {
    delete[] m_data;
}
// copy constructor
String::String(const String& Src) {
    // set everything to safe empty state, done in class init
    operator=(Src);
}
// copy assignment
String& String::operator=(const String& Src) {
    // operator const char* () return the address of m_data
    if (this != &Src) { // prevents self-copying
        delete[] m_data;
        setEmpty(); // set empty incase Src is empty
        // operator bool() same as Src.m_data
        if (Src) {
            m_length = Src.m_length;
            m_data = new char[m_length + 1];
            U.strCpy(m_data, Src.m_data);
        }
    }
    return *this;
}
// getter return m_length
size_t String::getLength() const {
    return m_length;
}
// casting String class to const char*
String::operator const char* ()const {
    return m_data;
}
// casting to bool, be able to check for validity
String::operator bool() const {
    return !isEmpty();
}
// concat using +=
String& String::operator+=(const String& S) {
    char* newData = new char[m_length + S.getLength() + 1];
    newData[0] = 0; // empty string
    if (*this) {
        U.strCpy(newData, m_data);
    }
    if (S) {
        U.strCat(newData, S);
    }
    delete[] m_data;
    m_data = newData;
    return *this;
}
// display
ostream& String::display(ostream& ostr)const {
    if (*this) {
        ostr << m_data;
    }
    return ostr;
}

// MARK: free function
std::ostream& operator<<(std::ostream& ostr, const String& Roper) {
    return Roper.display(ostr);
}

}

