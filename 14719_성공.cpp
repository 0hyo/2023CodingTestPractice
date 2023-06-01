#include <iostream>
using namespace std;
/**
 * @brief 
문제
2차원 세계에 블록이 쌓여있다. 비가 오면 블록 사이에 빗물이 고인다.
비는 충분히 많이 온다. 고이는 빗물의 총량은 얼마일까?

입력
첫 번째 줄에는 2차원 세계의 세로 길이 H과 2차원 세계의 가로 길이 W가 주어진다. (1 ≤ H, W ≤ 500)
두 번째 줄에는 블록이 쌓인 높이를 의미하는 0이상 H이하의 정수가 2차원 세계의 맨 왼쪽 위치부터 차례대로 W개 주어진다.
따라서 블록 내부의 빈 공간이 생길 수 없다. 또 2차원 세계의 바닥은 항상 막혀있다고 가정하여도 좋다.

출력
2차원 세계에서는 한 칸의 용량은 1이다. 고이는 빗물의 총량을 출력하여라.
빗물이 전혀 고이지 않을 경우 0을 출력하여라.
 * 
 */
int main()
{
    int H, W, blocks[501];
    cin >> H >> W;
    int max_height = 0;
    for (int i = 0; i < W; i++)
    {
        cin >> blocks[i];
        max_height = max(max_height, blocks[i]);
    }
    int total_standing_water = 0;
    
    for (int i = 1; i <= max_height; i++)
    {
        int tmp_standing_water = 0, start_point = W-1, end_point = 0;
        // cout << "height : " << i << "\n";
        for (int j = 0; j < W; j++)
        {
            if (blocks[j] >= i)
            {
                start_point = min(start_point, j);
                end_point = max(end_point, j);
            }
        }
        // cout << "st_p :" << start_point <<"\t end-p : " << end_point << "\n";
        for (int j = start_point; j < end_point; j++)
        {
            if (blocks[j] < i)
            {
                total_standing_water++;
            }
        }
        
    }
    
    cout << total_standing_water;


    return 0;
}