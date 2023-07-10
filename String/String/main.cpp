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
    String S = "ABC";
    S[5] = 'D';
    cout << ">" << S << "<" << endl;
    return 0;
}
