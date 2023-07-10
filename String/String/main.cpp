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
    String name = "Arin", last = "Api";
    name += last;
    String fullname(name);
    String empty;
    name = name;
    last = name;
    cout << fullname << endl;
    fullname = empty;
    return 0;
}
