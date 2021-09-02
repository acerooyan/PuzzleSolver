// If you really want to make a program for the app, be my guest.
// You may prefer to do so in /exp instead.
// Or better yet, use gtest to automate your own test cases!
#include <iostream>
#include <map>
#include "proj1.hpp"

int main()
{
    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("POT", "PAN", "BIB",  puzzle);
    std:: cout << p1;
    return 0;
}



