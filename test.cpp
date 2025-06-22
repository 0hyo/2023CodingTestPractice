#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(int x, int y) {return x > y;}

int main() {
    size_t big = SIZE_MAX;  // size_t가 가질 수 있는 최댓값
    size_t overflow = big + 1;  // 오버플로우 발생

    cout << "overflow 값: " << bitset<128>(big) << endl;  // MAX 출력

    cout << "overflow 값: " << overflow << endl;  // 0 출력
    return 0;
}