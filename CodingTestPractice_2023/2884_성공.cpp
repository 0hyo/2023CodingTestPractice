#include <iostream>

using namespace std;

//45분 일찍 알람 설정하기
int main()
{
    int H, M, a, b;
    cin >> H >> M;
    // cout << H << " " << M << endl;  // 원래


    a = (M - 45); // 분
    if(a < 0)
    {
        a += 60;
        if(H - 1 < 0)
            b = H + 23;
        else
            b = H - 1;
    }
    else
        b = H;
    cout << b << " " << a << endl;

}