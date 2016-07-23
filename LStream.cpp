#include <iostream>

void ReadLine(std::string& s){
    std::cin; getline(std::cin,s);
}

void ReadInt(int& N){
    std::string s;
    std::cin; getline(std::cin,s);

    N = 0;
    for(std::string::iterator it = s.begin(); it != s.end(); it++){
        N = N * 10 + (*it - '0');
    }
}
