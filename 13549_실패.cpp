/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

예제 입력 1
5 17
예제 출력 1
2
*/
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100000
using namespace std;
void wrong_way()
{
    int N, K;
    cin >> N >> K;
    int ans = 0;
    int tmp_N = N, tmp_K = K;
    if(K <= N){
        ans += N - K;
    }
    else{ // K >= N
        int big_K, bit_len_N, bit_len_K, temp_diff;
        for (bit_len_N = 0; tmp_N > 0; bit_len_N++)
            {tmp_N = tmp_N >> 1;}
        for (bit_len_K = 0; tmp_K > 0; bit_len_K++)
            {tmp_K = tmp_K >> 1;}
        big_K = (K >>(bit_len_K - bit_len_N));
        if(big_K > N){
            temp_diff = big_K - N;
            if(temp_diff > (1 << bit_len_N))
                ans += ((1 << bit_len_N) - temp_diff);
            else
                ans += temp_diff;
            for (int cnt_i = 0; cnt_i < (bit_len_K-bit_len_N); cnt_i++){
                if(K & 0x1)
                    ans++;
                K = K >> 1;
            }
        }
        else{
            ans += N - big_K;
            // cout << "k_bit_len : " << bit_len_K << " N_bit_len : " << bit_len_N << endl;
            for (int cnt_i = 0; cnt_i < (bit_len_K - bit_len_N); cnt_i++){
                if(K & 0x1)
                    ans++;
                K = K >> 1;
            }
        }
    }

    cout << ans;

}
int main(){
    int N, K, num;
    cin >> N >> K;
    int ans = 0;
    int dist[100001];
    fill_n(dist, 100001, 100000);
    deque<int> Q;
    Q.push_front(N);
    dist[N] = 0;
    while (!Q.empty()){
        num = Q.front();
        // cout << "num : " << num <<endl;
        // cout << "dist[num] : " << dist[num] <<endl;
        // cout << "size : " << Q.size() <<endl;
        Q.pop_front();
        if(num - 1 >= 0 && dist[num - 1] > dist[num] + 1){
            Q.push_back(num - 1);
            dist[num - 1] = dist[num] + 1;
        }
        if(num + 1 <= MAX && dist[num + 1] > dist[num] + 1){
            Q.push_back(num + 1);
            dist[num + 1] = dist[num] + 1;
        }
        if ((num << 1) <= MAX && dist[num << 1] > dist[num]){
            Q.push_front(num << 1);
            dist[num << 1] = dist[num];
        }
    }
    cout << dist[K];
    

    return 0;
}
