#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * @brief 참고자료 : https://hyeo-noo.tistory.com/138
 * 문제
N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.

어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 
이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.

각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 
하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.

이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. 
N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 10,000), X가 공백으로 구분되어 입력된다. 
두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다. 
시작점과 끝점이 같은 도로는 없으며, 시작점과 한 도시 A에서 다른 도시 B로 가는 도로의 개수는 최대 1개이다.

모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.

출력
첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.
 */

#define inf (2<<29)
int N, M, X;
int root[1001][1001];
int ans[1001];
bool visited[1001];

void init_NMX()
{
    cin >> N >> M >> X;
}
void init_root()
{
    for (int cnt_i = 0; cnt_i <= N; cnt_i++)
    {
        for (int cnt_j = 0; cnt_j <= N; cnt_j++)
        {
            root[cnt_i][cnt_j] = inf;
        }
    }
    int tmp_stp, tmp_endp;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp_stp >> tmp_endp;
        cin >> root[tmp_stp][tmp_endp];
    }
    
}
void reset_ans()
{
    for (int cnt_i = 0; cnt_i <= N; cnt_i++)
    {
        ans[cnt_i] = inf;
    }
    
}
void show_root()
{
    for (int cnt_i = 1; cnt_i <= N; cnt_i++)
    {
        for (int cnt_j = 1; cnt_j <= N; cnt_j++)
        {
            if (root[cnt_i][cnt_j] == inf)
            {
                cout <<"\t";
            }
            else
                cout << root[cnt_i][cnt_j] <<"\t";
        }
        cout <<"\n";
    }

}


queue<int> Q;
vector<int> Dist;
void find_ans(int stp)
{
    Dist.clear();
    Dist.resize(N+1, inf);
    Dist[stp] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> > ,greater<pair<int, int> > > PQ;
    PQ.push(make_pair(0,stp));

    while (!PQ.empty())
    {
        int min_cost = PQ.top().first;
        int now = PQ.top().second;
        PQ.pop();

        if (min_cost > Dist[now])      continue;
        
        for (int cnt_i = 1; cnt_i <= N; cnt_i++)
        {
            if (root[now][cnt_i] == inf)    continue;
            int next =  cnt_i;
            int next_cost = min_cost + root[now][cnt_i];

            // Dist[next] = min(next_cost, root[stp][next]);
            
            if (next_cost < Dist[next])
            {
                Dist[next] = next_cost;
                PQ.push(make_pair(next_cost, next));
            }
        }        
    }
}


int main()
{
    init_NMX();
    init_root();
    // show_root();

    for (int cnt_i = 1; cnt_i <= N; cnt_i++)
    {
        find_ans(cnt_i);
        ans[cnt_i] = Dist[X];
        for (int cnt_j = 1; cnt_j <= N; cnt_j++)
        {
            // cout << Dist[cnt_j] <<"\t";
        }
        
        // cout <<"\n";
    }
    // cout <<"\n";
    find_ans(X);
    int ret = 0;
    for (int cnt_i = 1; cnt_i <= N; cnt_i++)
    {
        ans[cnt_i] += Dist[cnt_i];
        // cout << ans[cnt_i] <<"\t";
        ret = max(ret, ans[cnt_i]);
    }
    cout << ret;


    

    return 0;
}