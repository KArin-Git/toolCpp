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
    int getInt(); // get integer
    int getInt(int min, int max, const char* prompt = nullptr);  // get integer between min and max with option prompt question
    // MARK: String
    size_t strLen(const char* str)const; // returns the lenght of the C-string in characters
    char* strCpy(char* des, const char* src)const; // Copies the srouce character string into the destination
    char* strCat(char* des, const char* src)const; // Concantinates "src" C-string to the end of "des"
    const char* strStr(const char* str1, const char* str2);     // returns the address of first occurance of "str2" in "str1"
                                                                // returns nullptr if no match is found
    // MARK: Utils
    void flushkeys(); // flush keyboard buffer until '\n
    bool ValidYesResponse(char ch); // return true if ch == Y/y or N/n
    bool yes(); // validate until user's input is Y/y or N/n
    // MARK: DMA
    char* allocateCpy(size_t& length, const char* src)const; // DMA from src
};

// MARK: this prototype, extern makes a file scope variable >> global
extern Utils U;
}

#endif /* Utils_hpp */
