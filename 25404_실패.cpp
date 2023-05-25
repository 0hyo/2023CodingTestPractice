#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief 뭐가 문젠지 못찾음 + 구글링 실패
 * 
 * 문제
원형의 주차 타워가 있다. 주차 타워에는 
N개의 칸이 원형으로 있다. 각 칸은 시계 방향으로 차례대로 
1번째, 2번째, ... , N번째 칸으로 부른다. 각 칸에는 차가 한 대씩 들어있다. 
i번째 칸에 있는 차는 번호 a_i를 가지고 있다.

주차 타워에는 두 개의 버튼이 있다. 버튼 A를 누르면 주차 타워를 시계방향으로, 버튼 B를 누르면 주차 타워를 반시계방향으로 한 칸 회전할 수 있다. 


이 때, 주차 타워에서 모든 차를 빼려 한다.

맨 아래에 있는 한 개의 칸에서만 차를 뺄 수 있다. 초기 상태에는 1번째 칸이 맨 아래에 있다.
 맨 아래에 있지 않은 칸에 있는 차를 빼기 위해서는, 먼저 버튼을 적절히 눌러서 주차 타워를 회전해, 차가 있는 칸을 맨 아래로 옮겨야 한다.

추가적으로, 번호 x를 가진 차를 빼기 위해서는 먼저 번호가 x보다 작은 모든 차를 먼저 빼어야 한다.
 즉, 주차 타워에 번호가 x 미만인 차가 남아 있다면, 번호가 x인 차를 뺄 수 없다.

주차 타워에서 모든 차를 빼기 위해, 버튼을 눌러야 하는 총 횟수의 최솟값을 구하는 프로그램을 작성하여라.

입력
첫 번째 줄에 정수 N이 주어진다.
두 번째 줄에 차들의 번호 
a_1, ... , a_N이 순서대로 공백을 사이에 두고 주어진다.

출력
첫 번째 줄에 버튼을 눌러야 하는 총 횟수의 최솟값을 출력하라.

제한
1 ≤ N ≤ 100,000 
1 ≤ a_i ≤ 1,000,000,000 
 */


void sort(int array[], int len)
{
    int tmp;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if(array[j] < array[i])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
        
    }
    
}
int main()
{
    int N;
    int car[100001];
    int sorted_num[100001];
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> car[i];
        sorted_num[i] = car[i];
    }
    sort(sorted_num, N);    //빼야 할 차의 번호 순서 배열

    int cnt = 0;
    int current_floor = 0;  // 현재 지상에 있는 차의 배열 index
    int next_floor; // 다음 지상으로 내려올 차의 배열 index
    int out_car_num;// 빼야 할 차의 번호
    for (int i = 0; i < N; i++)
    {
        out_car_num = sorted_num[i];    //빼야하는 차의 숫자
        next_floor = (current_floor + (int)floor(N / 2)) % N;

        for(int j = 0; j < N; j++)  //뺄 차의 위치 찾기
        {
            if(out_car_num == car[j])
            {
                if (min((current_floor - next_floor + N) % N ,(next_floor - current_floor + N) % N ) >= min((current_floor - j + N) % N ,(j - current_floor + N) % N ))
                {
                    next_floor = j;                    
                }
            }
        }

        
        cnt += min((next_floor - current_floor + N) % N, (current_floor - next_floor + N) % N );
        car[next_floor] = 0;
        // for (int X = 0; X < N; X++)
        // {
        //     cout << car[X] << " ";
        // }cout << endl;  
        current_floor = next_floor;
    }
    cout << cnt;

    return 0;
}