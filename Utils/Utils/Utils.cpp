//
//  Utils.cpp
//  Utils
//
//  Created by Bussarin Apichitchon on 6/6/2566 BE.
//

#include <iostream>
#include "Utils.hpp"

using namespace std;

namespace sdds {

// MARK: file scope instance called U of utils in Utils.cpp
Utils U;
// get integer
int Utils::getInt() {
    int value{};
    bool done{};
    do {
        done = false;
        cin >> value;
        if (cin) { // same as !cin.fail
            // if the last char is not '\n' >> garbage
            if (cin.get() != '\n') {
                cout << "Only an integer please, try again: ";
            }
            else {
                done = true;
            }
        }
        else {
            // clear the fail state
            cin.clear();
            cout << "Invalid Integer, try again: ";
        }
        // short-circuit evaluation.
        (!done) && cin.ignore(10000, '\n');
    } while (!done);
    return value;
}
// get integer between min and max
int Utils::getInt(int min, int max, const char* prompt) {
    int value{};
    // if provide message then using it
    if (prompt) cout << prompt;
    do {
        value = getInt();
        // con1 if value is NOT in range, then skip con2
        // con1 is true, then do con2
    } while ((value < min || value > max) &&
             cout
             << "Please insert the number that between "
             << min << " and " << max
             << ", try again: ");
    return value;
}

// MARK: String
// strlen
size_t Utils::strLen(const char* str)const {
    size_t len{};
    for (len = 0; str[len]; len++);
    return len;
}
// strcpy
char* Utils::strCpy(char* des, const char* src)const {
    size_t i;
    for (i = 0; src[i]; i++) des[i] = src[i];
    des[i] = char(0);
    return des;
}
// strcat
char* Utils::strCat(char* des, const char* src)const {
    size_t len = strLen(des);
    size_t i = 0;
    while (src[i]) {
        des[i + len] = src[i];
        i++;
    }
    des[i + len] = char(0);
    return des;
}

// MARK: Utils
// flush keyboard buffer until '\n
void Utils::flushkeys() {
   while (cin.get() != '\n');
}
// return true if ch == Y/y or N/n
bool Utils::ValidYesResponse(char ch) {
   return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
}
// validate until user's input is Y/y or N/n
bool Utils::yes() {
   char ch = 0;
   do {
      cin >> ch;
      flushkeys();
   } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
   return ch == 'y' || ch == 'Y';
}

}
