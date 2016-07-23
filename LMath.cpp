#include <bits/stdc++.h>

int RandNum(int N){
    int r1 = std::rand() % 295;
    int r2 = std::rand() % 295;
    int r3 = std::rand() % 295;
    int r4 = std::rand() % 295;
    return (r1*r2+r3*r4)%N;
}
