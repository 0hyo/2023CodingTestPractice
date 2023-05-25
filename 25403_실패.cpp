#include <iostream>
#include <cmath>
using namespace std;


/**
 * @brief 부분성공
 * 
좌표평면에 
빨간색 점 N개와 
파란색 점 M개가 있다. 
또한, 자연수 W, H가 주어진다.
 
i번째 (1 ≤ i ≤ N)
 빨간색 점의 좌표는 (rx_i, ry_i)이고, 
j번째 (1 ≤ j ≤ M) 
파란색 점의 좌표는 (bx_j , by_j)이다. 모든 점들의 좌표는 서로 다르다.

가로 W, 세로 H인 직사각형을 변이 좌표축에 평행하고 꼭짓점이 정수 좌표에 놓이도록 할 것이다. 
이 때 직사각형이 포함하는 빨간색 점과 파란색 점의 개수의 차가 가장 크게 만들고 싶다.

직사각형이 점을 포함한다는 것은, 직사각형의 왼쪽 아래 꼭짓점 좌표가 
(a, b)이고 점의 좌표가 (x, y)일 때 
a ≤ x ≤ a + W, b ≤ y ≤ b + H를 만족한다는 것이다.

개수의 차의 최댓값을 구하고, 그 답에 해당하는 직사각형의 위치를 찾아라.

입력 
첫 번째 줄에 빨간색 점의 개수 N과 파란색 점의 개수 M, 직사각형의 가로 및 세로 길이 W와 H가 각각 주어진다.

그 다음 줄부터 
N개의 줄에 걸쳐 각 빨간색 점의 
x, y좌표 
rx_i, ry_i가 주어진다.

그 다음 줄부터 
M개의 줄에 걸쳐 각 파란색 점의 
x, y좌표 
bx_j, by_j가 주어진다.

출력
첫 번째 줄에 빨간색 점과 파란색 점의 개수의 차의 최댓값을 출력한다.
두 번째 줄에 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표를 출력한다. 답이 여러 개라면 아무 것이나 출력한다.

제한
1 ≤ N, M ≤ 100,000 
1 ≤ W, H ≤ 10^9 = 1,000,000,000
 
1 ≤ rx_i, ry_i ≤ 10^9 (1 ≤ i ≤ N)
1 ≤ bx_j, by_j ≤ 10^9 (1 ≤ j ≤ M)
 */

void show_2dim(int array[][2], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "(" << array[i][0] << ", " << array[i][1] << " )" << endl;
    }   
    cout << endl;   
}


int main()
{
    int N, M, W, H, max_x, min_x, max_y, min_y ;
    cin >> N >> M >> W >> H;
    int red_Dot[100001][2];
    int blue_Dot[100001][2];
    max_x = 0, max_y = 0, min_x = 1000000001, min_y = 1000000001;
    for (int i = 0; i < N; i++)
    {
        cin >> red_Dot[i][0] >> red_Dot[i][1];
        max_x = max(max_x, red_Dot[i][0]);
        max_y = max(max_y, red_Dot[i][1]);
        min_x = min(min_x, red_Dot[i][0]);
        min_y = min(min_y, red_Dot[i][1]);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> blue_Dot[i][0] >> blue_Dot[i][1];
        max_x = max(max_x, blue_Dot[i][0]);
        max_y = max(max_y, blue_Dot[i][1]);
        min_x = min(min_x, blue_Dot[i][0]);
        min_y = min(min_y, blue_Dot[i][1]);
    }


    int red_Dot_Num, blue_Dot_Num;
    int ret_val[3] = {0,}; // 차의 절댓값, x좌표, y좌표

    for (int i = min_x - W - 1; i <= max_x + 1; i++)
    {
        for (int j = min_y - H - 1; j <= max_y + 1; j++)
        {
            red_Dot_Num = 0; blue_Dot_Num = 0;
            for (int k = 0; k < N; k++)
            {
                if ( i <= red_Dot[k][0] && red_Dot[k][0] <= i + W && j <= red_Dot[k][1] && red_Dot[k][1] <= j + H )
                {
                    red_Dot_Num++;
                }                
            }
            for (int k = 0; k < M; k++)
            {
                if (i <= blue_Dot[k][0] && blue_Dot[k][0] <= i + W && j <= blue_Dot[k][1] && blue_Dot[k][1] <= j + H )
                {
                    blue_Dot_Num++;
                }
            }
            if(ret_val[0] < abs(red_Dot_Num - blue_Dot_Num))
            {
                ret_val[0] = abs(red_Dot_Num - blue_Dot_Num);
                ret_val[1] = i;
                ret_val[2] = j;
            }
        }        
    }
    


    cout << ret_val[0] << endl;
    cout << ret_val[1] << " "<< ret_val[2];
    return 0;
}