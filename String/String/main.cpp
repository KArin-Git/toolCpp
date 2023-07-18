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

void prnChar(const String& S, size_t idx) {
    cout << S[idx] << endl;
}

int main(int argc, const char * argv[]) {
    String S = "ABC";
    S[5] = 'D';
    // cout << ">" << S << "<" << endl;
    prnChar(S, 7);
    return 0;
}
