#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/**
 * @brief 실패
 *       시간초과로 인한 실패.
 *       참고 : https://kevinthegrey.tistory.com/158
 * 
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다. 

입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.
 */
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M, S = 0;
    string operation;
    int number;
    cin >> M;


    for (int i = 0; i < M; i++)
    {
        operation.clear();
        cin >> operation;

        if(operation == "add")
        {
            cin >> number;
            S |= (1 << number);
        }
        else if(operation == "remove")
        {
            cin >> number;
            S &= ~(1 << number);
        }    
        else if(operation == "check")
        {
            cin >> number;
            cout << ((S >> number) & 0x01) << '\n';

            // if (S & (1 << number))    cout << 1 << '\n';
            // else    cout << 0 << '\n';
        }
        else if(operation == "toggle")
        {
            cin >> number;
            S ^= (1 << number);
            // S |= (((S >> number) & 0x01) ^ 0x01) << number;
        }
        else if(operation == "all")
        {
            S = 0x1fffff;
            // S = (1<<21) - 1;
        }
        else if(operation == "empty")
        {
            S = 0x00;
        }
    }
    

    return 0;
}