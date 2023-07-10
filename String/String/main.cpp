//
//  main.cpp
//  String
//
//  Created by Bussarin Apichitchon on 7/7/2566 BE.
//

#include <iostream>

#include "String.hpp"
#include "Utils.hpp"

using namespace std;
using namespace sdds;

int main(int argc, const char * argv[]) {
    String name = "Arin";
    String lastname = "Api";
    String fullname;
//    fullname = name;
//    fullname += " ";
//    fullname += lastname;
//    cout << "Name: >" << name << "<" << endl;
//    cout << "Last name: " << lastname << "<" << endl;
//    cout <<"Full name: " << fullname << "<" << endl;
    fullname = name + " " + lastname;
    cout <<"Full name: >" << fullname << "<" << endl;
    return 0;
}
