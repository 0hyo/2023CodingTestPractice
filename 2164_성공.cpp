#include <iostream>
#include <queue>
using namespace std;
/**
 * @brief 
 * 문제
N장의 카드가 있다. 
각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.

이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 
우선, 제일 위에 있는 카드를 바닥에 버린다. 
그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.

예를 들어 N = 4인 경우를 생각해 보자. 
카드는 제일 위에서부터 1, 2, 3, 4 의 순서로 놓여있다. 1을 버리면 2, 3, 4가 남는다. 
여기서 2를 제일 아래로 옮기면 3, 4, 2가 된다. 3을 버리면 4, 2가 되고, 4를 밑으로 옮기면 2, 4가 된다. 
마지막으로 2를 버리고 나면, 남는 카드는 4가 된다.

N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(1 ≤ N ≤ 500,000)이 주어진다.

출력
첫째 줄에 남게 되는 카드의 번호를 출력한다.
 * 
 */
queue<int> init(int N)
{
    queue<int> Q;
    for (int  cnt_i = 1; cnt_i <= N; cnt_i++)
    {
        Q.push(cnt_i);
    }
    return Q;
}


int main()
{
    int N;
    cin >> N;
    queue<int> Q;
    Q = init(N);
    int tmp;
    while (Q.size() != 1)
    {
        Q.pop();
        tmp = Q.front();
        Q.pop();
        Q.push(tmp);
        // cout << tmp <<" ";
    }
    tmp = Q.front();
    cout << tmp;

    

    return 0;
}