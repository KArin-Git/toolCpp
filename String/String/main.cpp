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
void print(String S) {
    cout << S << endl;
}
String get() {
    String tmp;
    cin >> tmp;
    return tmp;
}
int main(int argc, const char * argv[]) {
    String name = "Arin Apic";
    print(name); // print(String S = name);
    cout << "Name: ";
    // cin >> name;
    name = get();
    cout << "Hello " << name << endl;
    return 0;
}
