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
// concat using += >> const char + const char
String& String::operator+=(const char* cstr) {
    if (cstr) {
        char* newData = new char[m_length + U.strLen(cstr) + 1];
        newData[0] = 0; // empty string
        if (*this) {
            U.strCpy(newData, m_data);
        }
        // operator const char* () return string m_data
        U.strCat(newData, cstr);
        m_length += U.strLen(cstr);
        delete[] m_data;
        m_data = newData;
    }
    return *this;
}
// concat using += >> String + String
String& String::operator+=(const String& S) {
    if (S) {
        char* newData = new char[m_length + S.getLength() + 1];
        newData[0] = 0; // empty string
        if (*this) {
            U.strCpy(newData, m_data);
        }
        // operator const char* () return string m_data
        U.strCat(newData, S);
        m_length += S.getLength();
        delete[] m_data;
        m_data = newData;
    }
    return *this;
}
// concat using + >> const char + const char
String String::operator+(const char* cstr)const {
    /*
     String copy = *this;
     copy += cstr;
     return copy;
    */
    return String(*this) += cstr;
}
// concat using + >> String + String
String String::operator+(const String& Scr)const {
    /*
     String copy = *this;
     copy += Scr;
     return copy;
    */
    return String(*this) += Scr;
}
// return char[idx], return the element of arr[idx]
const char& String::operator[](size_t idx)const {
    const char* ret = &m_junk;
    if (*this) {
        // check limit the length of arr idx >> return gabage
        ret = &m_data[idx % m_length];
    }
    return *ret;
}
// display
ostream& String::display(ostream& ostr)const {
    if (*this) {
        ostr << m_data;
    }
    return ostr;
}
// read / cin
std::istream& String::read(std::istream& istr) {
    char tmp[4096]{}; // limit arr size
    istr.getline(tmp, 4096);
    // same as if(istr.fail())
    if (istr) {
        if (*this) {
            delete[] m_data;
            setEmpty();
        }
        m_data = U.allocateCpy(m_length, tmp);
    }
    return istr;
}

// MARK: free function
std::ostream& operator<<(std::ostream& ostr, const String& Roper) {
    return Roper.display(ostr);
}
std::istream& operator>>(std::istream& istr, String& Roper) {
    return Roper.read(istr);
}
// concat using + >> const char + const char
String operator+(const char* cstr, const String& Roper) {
    /*
     String result(cstr);
     result += Roper;
     return result;
    */
    return String(cstr) += Roper; // create a nameless String and += Roper
}

}

