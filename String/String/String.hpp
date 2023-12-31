//
//  String.hpp
//  String
//
//  Created by Bussarin Apichitchon on 7/7/2566 BE.
//

#ifndef String_hpp
#define String_hpp

#include <iostream>

namespace sdds {

// MARK: String class
class String {
    // ald init every data to safe empty state
    char* m_data{};
    size_t m_length{};
    char m_junk;
    // return true is m_data == nullptr
    bool isEmpty()const;
    // set String to empty state
    String& setEmpty();
public:
    // constructor
    String(const char* cstr = nullptr);
    // destructor
    ~String();
    // copy constructor
    String(const String& Src);
    // copy assignment
    String& operator=(const String& Src);
    // getter return m_length
    size_t getLength() const;
    // getter + casting type conversion, String class to char*
    operator const char* ()const;
    // casting type conversion, String class to bool, be able to check for validity
    operator bool() const;
    // concat using += >> const char + const char
    String& operator+=(const char* cstr);
    // concat using += >> String + String
    String& operator+=(const String& S);
    // concat using + >> const char + const char
    String operator+(const char* cstr)const;
    // concat using + >> String + String
    String operator+(const String& Scr)const;
    // return char[idx], return the element of arr[idx]
    const char& operator[](size_t idx)const;
    // display m_date
    std::ostream& display(std::ostream& ostr = std::cout)const;
    // read / cin
    std::istream& read(std::istream& istr = std::cin);
};

// MARK: free function
std::ostream& operator<<(std::ostream& ostr, const String& Roper);
std::istream& operator>>(std::istream& istr, String& Roper);
// concat using + >> const char + const char(class member)
String operator+(const char* cstr, const String& Roper);

// MARK: this prototype, extern makes a file scope variable >> global
extern String S;

}

#endif /* String_hpp */
