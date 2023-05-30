#include <iostream>
using namespace std;
/**
 * @brief 문제
 *  
1부터 N까지 
N개의 정점으로 이루어진 트리가 있다. 
i번째 간선은 서로 다른 두 정점 
A_i, B_i를 잇는다. (1 ≤ i ≤ N - 1)

 
N개의 정점 중 몇 개를 골라, 그 고른 정점들을 
S = {s_1, s_2, ... , s_K}라고 하자. 또한, 
s_i = v를 만족하는 i (1 ≤ i ≤ K)가 존재할 때, 
정점 v가 S에 속한다고 부르자.

S에 속하는 서로 다른 두 정점 
u, v에 대하여, 
S에 속하는 정점만을 이용하여 트리 위에서 
u, v 사이를 오갈 수 있다면, 
“u와 v는 S 위에서 연결되어 있다”고 하자.

예를 들어, 아래와 같은 트리를 생각하자. (N = 7)


만일, 
K = 6, 
S = {1, 2, 3, 4, 5, 6}라면, 
“1과 2”, “3과 5”, “4와 6”은 
각각 서로 S 위에서 연결되어 있다. 
그러나, “1과 6”, “2와 7”은 
각각 서로 S 위에서 연결되어 있지 않다.

다음 조건을 모두 만족하는 정점쌍 
(u, v)의 개수를 
S의 연결 강도라고 하자.

 
u와 v는 서로 다른 두 정점.
 
1 ≤ u < v ≤ N.
 
u와 v는 
S 위에서 연결되어 있다.
고른 정점들 
S가 주어질 때, 
S의 연결 강도를 계산하는 프로그램을 작성하라. 
여러분은 이러한 질의 Q개에 대하여 모두 답해야 한다.

입력
첫 번째 줄에 정수 
N이 주어진다.

다음 (N - 1)개의 줄에 각 간선에 대한 정보가 주어진다. 이 중 
i (1 ≤ i ≤ N - 1)번째 줄에는 두 정수 
A_i, B_i가 주어진다.

다음 줄에 정수 
Q가 주어진다.

다음 
Q개의 줄에 각 질의에 대한 정보가 주어진다. 이 중 
i (1 ≤ i ≤ Q)번째 줄은 
i번째 질의를 나타내며, 정수 
K와 K개의 정수 
s_1, ... , s_K가 차례대로 주어진다.

출력
첫 번째 줄부터 
Q개의 줄에 걸쳐, 각 질의에 대한 답을 출력한다. 이 중 
i (1 ≤ i ≤ Q)번째 줄에는 
i번째 질의에서 주어진 
S에 대하여, S의 연결 강도를 출력한다.

제한
2 ≤ N ≤ 250,000 
1 ≤ Q ≤ 100,000 
모든 i (1 ≤ i ≤ N - 1)에 대해, 
1 ≤ A_i ≤ N.
모든 i (1 ≤ i ≤ N - 1)에 대해, 
1 ≤ B_i ≤ N.
모든 i (1 ≤ i ≤ N - 1)에 대해, 
A_i ≠ B_i.
주어지는 그래프는 트리이다.
모든 질의에 대해, 
1 ≤ K ≤ N.
각 질의에서, 모든 
i (1 ≤ i ≤ K)에 대해, 
1 ≤ s_i ≤ N.
각 질의에서, 고른 
K개의 정점 
s_1, ... , s_K는 서로 다르다.
 
Q개의 질의에서 주어지는 
K들의 합은 
1,000,000 이하이다.
 */


int main()
{
    int N; 
    cin >> N;




    return 0;
}