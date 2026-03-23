#include <iostream>
using namespace std;

/**
 * 입력
 * 입력은 총 28줄로 각 제출자(학생)의 출석번호 n(1 ≤ n ≤ 30)가 한 줄에 하나씩 주어진다. 출석번호에 중복은 없다.

 * 출력
 * 출력은 2줄이다. 1번째 줄엔 제출하지 않은 학생의 출석번호 중 가장 작은 것을 출력하고, 2번째 줄에선 그 다음 출석번호를 출력한다.
 */

int main()
{
    int a[31] = {};
    int tmp;
    for (int i = 0; i < 30; i++)
    {
        cin >> tmp;
        a[tmp] = 1;
    }
    for(int i = 1 ; i < 31; i++)
    {
        if(a[i] == 0)
            cout << i << endl;
    }
    return 0;
}