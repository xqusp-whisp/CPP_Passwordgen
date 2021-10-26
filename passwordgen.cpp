#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <direct.h>
#include <ctime>
#include <fstream>

int main()
{
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYXZ0123456789!%&,.;:+-_=#@";
    int length, rNum;
    std::string name;

    std::cout << "What would you like your password to be named?" << std::endl;
    std::cin >> name;
    
    std::cout << "Enter the amount of digits for your password:" << std::endl;
    std::cin >> length;

    srand(time(NULL));
    std::string finalPassword = "";
    for (int i = 0; i <= length; i++)
    {
        rNum = rand() % 63 + 1;

        finalPassword += characters[rNum];
    }
    std::ofstream file;
    file.open("passwords\\" + name + ".txt", std::ofstream::out | std::ofstream::app);
    file << finalPassword;
    std:: cout << "Done\n";
    file.close();

    return 0;
}

//basically this stuff makes some pretty snazzy passwords ranging from 1 char to 100,000 chars.