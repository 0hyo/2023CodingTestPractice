/*
2차원 평면의 KOI 마을에 N개의 집이 있다. 각 i번째 집의 위치는 (X_i , Y_i)이다.
 
i번째 집과 j번째 집 사이의 거리는 |X_i - X_j | + |Y_i - Y_j |이다. 즉, 두 집 사이의 거리는 X의 차이와 Y의 차이의 합이다. 
예를 들어, (1, 6)에 위치한 집과 (2, 4)에 위치한 집은 (2 - 1) + (6 - 4)인 3만큼 떨어져 있다.

KOI 마을은 재난 발생 시 주민들이 안전하게 대피할 수 있도록 
K개의 집에 대피소를 설치할 계획이다. 모든 주민의 안전을 고려하여, 집에서 가장 가까운 대피소로 이동할 때 가장 긴 거리가 최소가 되도록 대피소를 설치할 
K개의 집을 선택하고, 그때 대피소와 가장 멀리 떨어진 집과의 거리를 구하려고 한다.

아래는 
5개의 집이 각각 (1, 5), (3, 0), (3, 3), (6, 12), (8, 9)에 위치한 마을의 예이다.

이 마을에 2개의 대피소를 설치하려고 한다. 
만약 (3, 0)과 (1, 5)에 위치한 집에 대피소를 설치한다면 설치하지 않은 나머지 세 집에서 가까운 대피소까지의 거리가 각각 3, 11, 12이고, 이 중 가장 먼 거리는 12이다.
하지만 (3, 3)와 (6, 12)에 위치한 집에 대피소를 설치하면 가장 가까운 대피소와 가장 멀리 떨어져 있는 집은 (8, 9)에 위치한 집으로, (6, 12)와 5만큼 떨어져 있다. 
대피소를 어떻게 설치해도 최대 거리가 5보다 작아지는 경우가 없으므로 5가 구하고자 하는 거리가 된다.

KOI 마을의 집들의 위치와 설치할 대피소의 개수가 주어질 때, 대피소를 설치하는 모든 방법 중 가장 가까운 대피소와 집 사이의 거리 중 가장 큰 값이 가장 작을 때의 거리를 구해라.

입력
첫 번째 줄에 N과 K가 공백을 사이에 두고 주어진다.
다음 N개의 줄에는 집의 위치가 주어지는데, 이 중 i (1 ≤ i ≤ N)번째 줄에는 X_i와 Y_i가 공백을 사이에 두고 주어진다.

출력
첫 번째 줄에 답을 출력한다.

제한
주어지는 모든 수는 정수이다.
 
1 ≤ K ≤ 3  
K ≤ N ≤ 50 
0 ≤ X_i ≤ 100,000  
0 ≤ Y_i ≤ 100,000 
같은 위치에 집이 여럿 존재하지 않는다. 즉, 
(X_1, Y_1), (X_2, Y_2) ... (X_N , Y_N )는 서로 다르다.
*/
#include <iostream>
using namespace std;
int main()
{
    int N, K;
    int X[50], Y[50];
    cin >> N >> K;
//  입력
    for (int i = 0; i < N; i++)    {
        cin >> X[i] >> Y[i];
    }
//  모든 곳에 대피소
    if (N == K ){printf("0"); return 0;}
//  i to j 거리
    int dist[50][50] = {0,};
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){ 
            dist[i][j] = abs(X[i]-X[j]) + abs(Y[i]- Y[j]);}}
//  출력 확인 
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){ 
            printf("%d ",dist[i][j]);
            }
        printf("\n");
        }    


    int min[50];
    for (int i = 0; i < 50; i++)
        { min[i] = 100001;    }
    
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            if(dist[i][j] < min[i]){
                min[i] = dist[i][j];
                }
            else;
        }
    }

    int tmp_min, tmp_max, tmp_i;
    //tmp_max: i에서 최댓값, tmp_min: 거리 최댓값의 최솟값
    while (K > 0)
    {
        tmp_min = 100001;
        for (int i = 0; i < N; i++){
            tmp_max = 0;
            for (int j = 0; j < N; j++){
                if (dist[i][j] > tmp_max){
                    tmp_max = dist[i][j];       // i에 대피소를 만들었을때의 최댓값
                }
                // printf("tmp_max = %d\n",tmp_max);
            }
            if (tmp_min > tmp_max){
                tmp_min = tmp_max;              // 최댓값을 최소가 되게 하는 i 찾기
                tmp_i = i;
                }
            // printf("tmp_min = %d\n",tmp_min);
        }
        // printf("tmp_i = %d\n",tmp_i);
        // for (int i = 0; i < N; i++){
        //     if(dist[tmp_i][i] <= tmp_min){
        //         dist[tmp_i][i] = 0;
        //     }
        //     if(dist[i][tmp_i] <= tmp_min){
        //         dist[i][tmp_i] = 0;
        //     }
        // }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] > dist[tmp_i][j])
            {
                dist[i][j] = dist[tmp_i][j];
            }
        }
    }
        
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){ 
            printf("%d ",dist[i][j]);
            }
        printf("\n");
        }    

        K--;
    }
    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){ 
    //         printf("%d ",dist[i][j]);
    //         }
    //     printf("\n");
    //     }    

    printf("%d", tmp_min);

    return 0;
}