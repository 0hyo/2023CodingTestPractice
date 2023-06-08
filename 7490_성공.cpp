#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;
/**
 * @brief 문제
1부터 N까지의 수를 오름차순으로 쓴 수열 1 2 3 ... N을 생각하자.
그리고 '+'나 '-', 또는 ' '(공백)을 숫자 사이에 삽입하자(+는 더하기, -는 빼기, 공백은 숫자를 이어 붙이는 것을 뜻한다). 
이렇게 만든 수식의 값을 계산하고 그 결과가 0이 될 수 있는지를 살피자.

N이 주어졌을 때 수식의 결과가 0이 되는 모든 수식을 찾는 프로그램을 작성하라.

입력
첫 번째 줄에 테스트 케이스의 개수가 주어진다(<10).

각 테스트 케이스엔 자연수 N이 주어진다(3 <= N <= 9).

출력
각 테스트 케이스에 대해 ASCII 순서에 따라 결과가 0이 되는 모든 수식을 출력한다. 각 테스트 케이스의 결과는 한 줄을 띄워 구분한다.
 * 
 */

char sign[3] = {' ', '+', '-'};
int main()
{
    int number_of_test_Case, N;
    char operations[10];
    cin >> number_of_test_Case;
    // cout <<"\n";
    for (int cnt_i = 0; cnt_i < number_of_test_Case; cnt_i++)
    {
        cin >> N;
        for (int cnt_j = 0; cnt_j < pow(3, N - 1); cnt_j++)
        {
            int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
            int value = 0;
            for (int cnt_k = 0; cnt_k < N - 1; cnt_k++)
            {
                operations[N - cnt_k - 2] = sign[ (int)(cnt_j / pow(3, cnt_k)) % 3];
                // cout << operations[cnt_k];
            }
            for (int cnt_k = N - 2; cnt_k >= 0; cnt_k--)
            {
                if (operations[cnt_k] == ' ')
                {
                    while (numbers[cnt_k + 1] > numbers[cnt_k])
                    {
                        // cout   << numbers[cnt_k];
                        numbers[cnt_k] *= 10;
                    }
                    numbers[cnt_k] += numbers[cnt_k + 1];
                }
                else if (operations[cnt_k] == '+')
                    value += numbers[cnt_k + 1];
                else if (operations[cnt_k] == '-')
                    value -= numbers[cnt_k + 1];
            }
            // cout << "cnt_j = " << cnt_j <<"\n";
            value += numbers[0];
            // for (int i = 0; i < N; i++)
            // {
            //     cout << numbers[i] <<" ";
            // }cout <<"\n";
            
            if (value == 0)
            {
                for (int cnt_k = 0; cnt_k < N - 1; cnt_k++)
                {
                    cout << cnt_k + 1 << operations[cnt_k];
                }
                
                // for (int cnt_k = 0; cnt_k < N; cnt_k++)
                // {
                //     cout << numbers[cnt_k] <<" ";
                // }cout <<"\n";
                // for (int cnt_k = 0; cnt_k < N - 1; cnt_k++)
                // {
                //     cout << operations[cnt_k] <<" ";
                // }
                
                cout << N <<"\n";
                // cout << "=" << value << "\n";
                // cout << value << "\n";
            }
        }
        cout <<"\n";
    }
    return 0;
}
