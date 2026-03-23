/* 문제
N×M크기의 배열로 표현되는 미로가 있다.
1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

예제 입력 1 
4 6
101111
101010
101011
111011
예제 출력 1 
15
예제 입력 2 
4 6
110110
110110
111111
111101
예제 출력 2 
9
예제 입력 3 
2 25
1011101110111011101110111
1110111011101110111011101
예제 출력 3 
38
예제 입력 4 
7 7
1011111
1110001
1000001
1000001
1000001
1000001
1111111
예제 출력 4 
13
*/
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int ans = 0;
    int N, M;
    int dist[100][100];
    string arr[100];
    
    queue<pair<int, int> > Q;    
// input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin  >> arr[i];
    }
// reset
    // fill_n(dist, dist + 10000,10000);
    fill(*dist, *dist+10000, 10000);
    dist[0][0] = 1;
    Q.push(pair<int, int>(0, 0));
    int i = 0, j = 0;
    int dx[4] = {-1, 1, 0, 0};    
    int dy[4] = {0, 0, -1, 1};    
    int x, y, nx, ny;
    while (!Q.empty())
    {
        // pair<int, int>(x, y) = Q.front();
        x = Q.front().first;
        y = Q.front().second;
        // cout<< "x = " << x << " y = " << y << endl;  
        // cout << "size : " << Q.size() << endl;
        Q.pop();
        // cout << "size : " << Q.size() << endl;

        for (int cnt_i = 0; cnt_i < 4; cnt_i++)
        {
            nx = x + dx[cnt_i];
            ny = y + dy[cnt_i]; 
            // cout<< "arr[" << nx << "][" << ny << "]=" << arr[nx][ny] << endl;  
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) {continue;}
            else if(arr[nx][ny] == '0') {continue;}
            else if(dist[nx][ny] <= dist[x][y] + 1) {continue;}
            else{
                dist[nx][ny] = dist[x][y] + 1;
                Q.push(pair<int, int>(nx, ny));
                // cout<< "nx = " << nx << " ny = " << ny << endl;  
                // pair<int, int>(x, y) = Q.back();
                // cout<< "x = " << x << " y = " << y << endl;  
                pair<int, int>(x, y) = Q.front();
                // cout<< "x = " << x << " y = " << y << endl;  
                
            }
        }
    }
    // cout << "dist : " << dist[N-1][M-1] ;
    cout << dist[N-1][M-1] ;


    return 0;
}