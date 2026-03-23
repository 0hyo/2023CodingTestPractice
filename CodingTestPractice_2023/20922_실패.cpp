#include <iostream>
using namespace std;
/*
문제
홍대병에 걸린 도현이는 겹치는 것을 매우 싫어한다. 특히 수열에서 같은 원소가 여러 개 들어 있는 수열을 싫어한다. 도현이를 위해 같은 원소가 
K개 이하로 들어 있는 최장 연속 부분 수열의 길이를 구하려고 한다.

 
100,000 이하의 양의 정수로 이루어진 길이가 
N인 수열이 주어진다.  이 수열에서 같은 정수를 
K개 이하로 포함한 최장 연속 부분 수열의 길이를 구하는 프로그램을 작성해보자.

입력
첫째 줄에 정수 
N 
(1 <= N <= 200,000)과 
K 
(1 <= K <= 100)가 주어진다.

둘째 줄에는 
{a_1, a_2, ... a_n}이 주어진다 (
1 <= a_i <= 100,000)

출력
조건을 만족하는 최장 연속 부분 수열의 길이를 출력한다.
*/

// 참고 : https://khu98.tistory.com/187
int main()
{
    int ret = 0;
    int N, K;
    int a[200001];
    int times[100001];

    // 숫자 입력
    cin >> N >> K;
    for (int i = 0; i < N; i++) {   cin >> a[i];    }

    //부분수열의 시직점과 끝점을 기준으로 한다.
    int start_pointer = 0, end_pointer = 0;
    while (end_pointer < N)
    {
        times[a[end_pointer]]++;       // 부분행렬에서 숫자가 나온 횟수 계산
        if (times[a[end_pointer]] <= K)
            ret = max(end_pointer - start_pointer + 1, ret);    // 현재 부분수열의 길이와 비교
        else
        {
            while (times[a[end_pointer]] > K)
            {
                times[a[start_pointer++]]--;
            }
        }
        end_pointer++;
    }

    cout << ret;
    return 0;
}


/**
 * @brief 시간 초과 실패

    int N , K;
    int number[200001];  //i번째 수열 값 ; i번째 수열이 중복된 횟수; i번재 수열을 보함하는 최대 길이 수열
    char times[200001] = {};// i번재 수열의 숫자가 중복된 횟수
    int score[200001] = {};// i번째 수열로 시작하는 최장 부분수열의 길이

    cin >> N >> K;

    // 수열 길이 계산
    int mark = 0;
    int ret = 0; // 최장길이

    for(int i = 0; i < N - ret + 1; i++)
    {
        // 수열 입력
        cin >> number[i] ;

        for(int j = mark; j <= i; j++)
        {
            if(number[j] == number[i] )
            {
                times[j]++; // count++
                if(times[j] == K + 1)
                {
                    if(ret < score[mark])   // 최장 부분 수열 길이 갱신.
                        ret = score[mark];
                    mark = j + 1;                // mark번째 부터 i번째 까지의 부분 수열은 K개 이상의 중복 수를 포함함.
                }
            }
            else
                score[j]++;                  //   수열길이 갱신
        }
    }
    

    if(ret < score[mark])
        ret = score[mark];
    cout << ret;

    return 0;
 * 
 */