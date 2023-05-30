#include <iostream>
#include<unistd.h>  

using namespace std;
/**
 * @brief 실패, 참고자료 : https://oriburger.tistory.com/entry/PS%EC%99%84%EC%A0%84%ED%83%90%EC%83%89-BOJ-17484-%EC%A7%84%EC%9A%B0%EC%9D%98-%EB%8B%AC-%EC%97%AC%ED%96%89Small?category=967352
 *                     https://yunseu-l.tistory.com/227
우주비행이 꿈이였던 진우는 음식점 '매일매일싱싱'에서 열심히 일한 결과 달 여행에 필요한 자금을 모두 마련하였다! 
지구와 우주사이는 N X M 행렬로 나타낼 수 있으며 각 원소의 값은 우주선이 그 공간을 지날 때 소모되는 연료의 양이다.

[예시]

진우는 여행경비를 아끼기 위해 조금 특이한 우주선을 선택하였다. 진우가 선택한 우주선의 특징은 아래와 같다.

1. 지구 -> 달로 가는 경우 우주선이 움직일 수 있는 방향은 아래와 같다.

2. 우주선은 전에 움직인 방향으로 움직일 수 없다. 즉, 같은 방향으로 두번 연속으로 움직일 수 없다.

진우의 목표는 연료를 최대한 아끼며 지구의 어느위치에서든 출발하여 달의 어느위치든 착륙하는 것이다.
최대한 돈을 아끼고 살아서 달에 도착하고 싶은 진우를 위해 달에 도달하기 위해 필요한 연료의 최소값을 계산해 주자.

입력
첫줄에 지구와 달 사이 공간을 나타내는 행렬의 크기를 나타내는 N, M (2≤ N, M ≤ 6)이 주어진다.
다음 N줄 동안 각 행렬의 원소 값이 주어진다. 각 행렬의 원소값은 100 이하의 자연수이다.

출력
달 여행에 필요한 최소 연료의 값을 출력한다.
 * 
 */

int dx[3] = {-1, 0, 1};

/**
 * @brief 
 * 
 * @param XY    : 위치에 따른 연료 소모랭
 * @param x     : 앞으로 전진한 수
 * @param y     : 좌우 위치
 * @param N     : 총 전진해야 할 거리
 * @param M     : 좌우 폭
 * @param direction : 마지막으로 움직인 방향.
 * @return int  :소모 연료.
 */
int solution(int XY[6][6], int x, int y, int N, int M, int direction)
{

    if (x == N)
        return 0;
    int ret = 2 << 20;
    for (int i = -1; i < 2; i++)
    {
        if (((y + i) < 0) || ((y + i) >= M))
            continue;
        if (direction == i)
            continue;
        ret = min(ret, solution(XY, x + 1, y + i, N, M, i) + XY[x][y]);
    }
    return ret;
}

int main()
{
    int N, M; 
    int XY[6][6];
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> XY[i][j];
        }
    }

    int sol = 2<<20;
    // cout << sol << " \n";
    for (int i = 0; i < M; i++)
    {
        sol = min(sol, solution(XY, 0, i, N, M, -2) );
    }
    cout << sol;

    return 0;
}

/**
 * @brief 내가 푼 방법, 실패
 * 
int main()
{
    int N, M;
    cin >> N >> M;

    int mat[6][6];
    for (int  i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mat[i][j];
        }
    }
    int min_score = 10000;
    int direction[6][2];   
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            direction[i][j] = -2;
        }
    }
    
    // fill_n(direction, direction + 12, -2);

    int mat_score[6][6];
    for (int j = 0; j < M; j++)
    {
        mat_score[0][j] = mat[0][j];
    }


    for (int i = 1; i < N; i++)
    {
        // 첫번째 지역으로 올 수 있는 경우
        if ((direction[0][0] == 0) && (direction[0][1] != -1))
        {
            direction[0][1] = -1;   //이번에 온 방향 (갱신할 값)
            mat_score[i][0] = mat_score[i - 1][1] + mat[i][0]; 
        }
        if ((direction[0][0] == -1) && (direction[0][1] != -1))
        {
            if (mat_score[i - 1][0] < mat_score[i - 1][1])
            {
                direction[0][1] = 0;
                mat_score[i][0] = mat_score[i - 1][0] + mat[i][0]; 
            }
            else
            {
                direction[0][1] = -1;
                mat_score[i][0] = mat_score[i - 1][1] + mat[i][0]; 
            }
        }
        else// 올 수 있는 경우가 없는 경우
        {
            direction[0][1] = -2;
            mat_score[i][0] = 10000;
        }

        //마지막 지역으로 올 수 있는 경우
        if ((direction[M - 2][0] == 1) && (direction[M - 1][0] == 0))
        {   // 마지막 지역으로 올 수 없는 경우.
            mat_score[i][M - 1] = 10000;
        }
        else if ((direction[M - 2][0] != 1) && (mat_score[i - 1][M - 2] < mat_score[i - 1][M - 1]))
        {
            direction[M - 1][1] = 1;   //이번에 온 방향 (갱신할 값)
            mat_score[i][M - 1] = mat_score[i - 1][M - 2] + mat[i][M - 1];
        }
        else if((direction[M - 2][0] != 0) && (mat_score[i - 1][M - 2] > mat_score[i - 1][M - 1]))
        {
            direction[M - 1][1] = 0;   //이번에 온 방향 (갱신할 값)
            mat_score[i][M - 1] = mat_score[i - 1][M - 1] + mat[i][M - 1];
        }
        else{
            direction[M - 1][1] = -2;
            mat_score[i][M - 1] = 10000;
        }
        
        for (int j = 1; j < M - 1; j++)
        {
            if((direction[j - 1][0] == 1) && (direction[j][0] == 0) && (direction[j + 1][0] == -1) )
            {   // 아무 것도 못 오는 상황.
                direction[j][1] = -2;
                mat_score[i][j] = 10000;
            }
            else if ((direction[j - 1][0] != 1) && (mat_score[i - 1][j - 1] < mat_score[i - 1][j]) && (mat_score[i - 1][j - 1] < mat_score[i - 1][j + 1]) )
            {
                direction[j][1] = 1;
                mat_score[i][j] = mat_score[i - 1][j - 1] + mat[i][j];
            }
            else if ((direction[j][0] != 0) && (mat_score[i - 1][j] < mat_score[i - 1][j - 1]) && (mat_score[i - 1][j] < mat_score[i - 1][j + 1]) )
            {
                direction[j][1] = 0;
                mat_score[i][j] = mat_score[i - 1][j - 1] + mat[i][j];
            }
            else if ((direction[j + 1][0] != -1) && (mat_score[i - 1][j + 1] < mat_score[i - 1][j - 1]) && (mat_score[i - 1][j + 1] < mat_score[i - 1][j]) )
            {
                direction[j][1] = -1;
                mat_score[i][j] = mat_score[i - 1][j + 1] + mat[i][j];
            }
        }
        for (int j = 0; j < M; j++)
        {
            direction[j][0] = direction[j][1];
        }
            
    }


    // for (int j = 0; j < M; j++)
    // {
        //  cout << mat_score[N - 1][j] << " ";
        // min_score = min(min_score, mat_score[N - 1][j]);
    // }
    cout << min_score;


    return 0;
}
 */