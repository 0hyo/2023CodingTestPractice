#include <iostream>
using namespace std;
/**
 * @brief 문제
두 자연수 A, B가 주어졌을 때, A ≤ x ≤ B를 만족하는 모든 x에 대해 x를 이진수로 표현했을 때 1의 개수의 합을 구하는 프로그램을 작성하시오.

즉, f(x) = x를 이진수로 표현 했을 때 1의 개수라고 정의하고, 아래 식의 결과를 구하자.

 
\[\sum_{x=A}^{B}{f(x)}\] 

입력
첫 줄에 두 자연수 A, B가 주어진다. (1 ≤ A ≤ B ≤ 10^16)

출력
1의 개수를 세어 출력한다.
 * 
 */

long long accumulated_bit[55] = {0, };
int get_l(int N)
{
    int ret = 0;
    while (N >= 1)
    {
        ret++;  
        N = N >> 1;
    }
    return ret;
}
long long hamm_W_Sum(long long N)
{
    long long ret = 0;
    for (int cnt_i = 54; cnt_i >= 0; cnt_i--)
    {
            cout << "1 << N : " << N <<"\n";
            cout << "1 << cnt_i : " << (long long)(1 << cnt_i) <<"\n\n";
        if (N & (1 << cnt_i))
        {
            // cout << "ret : " << ret <<"\n";
            ret += accumulated_bit[cnt_i - 1] + 1;
            N = N ^ (1 << (cnt_i - 1));
            ret += N;            
        }        
    }
    cout <<"\n";
    // while (N != 0)
    // {
    //     int tmp = get_l(N);
    //     ret += accumulated_bit[tmp - 1] + 1;
    //     N = N ^ (1 << (tmp - 1));
    //     ret += N;
    // }
    return  ret;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    long long ret = 0;
    cin >> A >> B;
    // int B_length = get_l(B);
    for (int cnt_i = 1; cnt_i <= 54; cnt_i++)
    {
        accumulated_bit[cnt_i] = (accumulated_bit[cnt_i - 1]) << 1; 
        accumulated_bit[cnt_i] += 1 << (cnt_i - 1);
    }

    cout << hamm_W_Sum(B) - hamm_W_Sum(A - 1) <<"\n";
   

    return 0;
}
