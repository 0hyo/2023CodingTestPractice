#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief   참고자료 : https://fre2-dom.tistory.com/144
 *                  https://astrid-dm.tistory.com/439
문제
매일 아침, 세준이는 학교에 가기 위해서 차를 타고 D킬로미터 길이의 고속도로를 지난다. 
이 고속도로는 심각하게 커브가 많아서 정말 운전하기도 힘들다. 어느 날, 세준이는 이 고속도로에 지름길이 존재한다는 것을 알게 되었다. 
모든 지름길은 일방통행이고, 고속도로를 역주행할 수는 없다.

세준이가 운전해야 하는 거리의 최솟값을 출력하시오.

입력
첫째 줄에 지름길의 개수 N과 고속도로의 길이 D가 주어진다. 
N은 12 이하인 양의 정수이고, D는 10,000보다 작거나 같은 자연수이다. 
다음 N개의 줄에 지름길의 시작 위치, 도착 위치, 지름길의 길이가 주어진다. 
모든 위치와 길이는 10,000보다 작거나 같은 음이 아닌 정수이다. 지름길의 시작 위치는 도착 위치보다 작다.

출력
세준이가 운전해야하는 거리의 최솟값을 출력하시오.
 */

void swap(int* st_p, int* end_p, int* length, int i, int j)
{
    int tmp;

    tmp = st_p[i];
    st_p[i] = st_p[j];
    st_p[j] = tmp;

    tmp = end_p[i];
    end_p[i] = end_p[j];
    end_p[j] = tmp;

    tmp = length[i];
    length[i] = length[j];
    length[j] = tmp;
}

int sort(int* st_p, int* end_p, int* length, int N, int D)
{
    int over_point = 0;
    for (int i = 0; i < N; i++)
    {
        if(end_p[i] <= D)
        {
            over_point++;
        }
        for (int j = 0; j < i; j++)
        {
            if (end_p[j] > end_p[i] )
            {
                swap(st_p, end_p, length, i, j);
            }
        }
    }
    return over_point;
}

int main()
{
    int N, D;
    cin >> N >> D;
    int st_p[12], end_p[12], length[12];
    for (int i = 0; i < N; i++)
    {
        cin >> st_p[i] >> end_p[i] >> length[i];
    }
    int  over_point = sort(st_p, end_p, length, N, D);

    int min_len[10001];
    min_len[0] = 0;
    for (int i = 1; i <= D; i++)
    {
        min_len[i] = min_len[i - 1] + 1;
        for (int j = 0; j < N; j++)
        {
            if (end_p[j] == i)
            {
                min_len[i] = min(min_len[st_p[j]] + length[j], min_len[i]);
            }
            
        }
        
    }
    
    

    cout << min_len[D];
    
    return 0;
}