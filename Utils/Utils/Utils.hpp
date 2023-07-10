//
//  Utils.hpp
//  Utils
//
//  Created by Bussarin Apichitchon on 6/6/2566 BE.
//

#ifndef Utils_hpp
#define Utils_hpp
#include <cstddef>

namespace sdds {

// MARK: Utils class
class Utils {
    // NO data member
public:
    // MARK: Int
    // get integer
    int getInt();
    // get integer between min and max with option prompt question
    int getInt(int min, int max, const char* prompt = nullptr);
    // MARK: String
    // strlen
    size_t strLen(const char* str)const;
    // strcpy
    char* strCpy(char* des, const char* src)const;
    // strcat
    char* strCat(char* des, const char* src)const;
    // MARK: Utils
    // flush keyboard buffer until '\n
    void flushkeys();
    // return true if ch == Y/y or N/n
    bool ValidYesResponse(char ch);
    // validate until user's input is Y/y or N/n
    bool yes();
};

// MARK: this prototype, extern makes a file scope variable >> global
extern Utils U;


}

#endif /* Utils_hpp */
