#include <bits/stdc++.h>

using namespace std;

int RandNum(int N){
    int r1 = rand() % 295;
    int r2 = rand() % 295;
    int r3 = rand() % 295;
    return (r1+r2+r3)%N;
}
