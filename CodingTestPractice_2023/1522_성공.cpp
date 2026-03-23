#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 
문제
a와 b로만 이루어진 문자열이 주어질 때,  a를 모두 연속으로 만들기 위해서 필요한 교환의 회수를 최소로 하는 프로그램을 작성하시오.
이 문자열은 원형이기 때문에, 처음과 끝은 서로 인접해 있는 것이다.

예를 들어,  aabbaaabaaba이 주어졌을 때, 2번의 교환이면 a를 모두 연속으로 만들 수 있다.

입력
첫째 줄에 문자열이 주어진다. 문자열의 길이는 최대 1,000이다.

출력
첫째 줄에 필요한 교환의 회수의 최솟값을 출력한다.
 */


int main()
{
    string charactors;
    cin >> charactors;
    // cout << charactors.length();

    int a_num = 0, b_num = 0, swap_times = 1001;
    int str_length = charactors.length();

    for (int i = 0; i < str_length; i++)
    {
        if (charactors[i] == 'a')
        {
            a_num++;
        }
    }
    for (int i = 0; i < str_length; i++)
    {
        int tmp = 0;
        for (int j = 0; j < a_num; j++)
        {
            if (charactors[(i + j) % str_length] != 'a')
            {
                tmp++;
            }
        }
        swap_times = min(swap_times, tmp);
    }
    cout << swap_times;

    return 0;
}
