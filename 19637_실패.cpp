#include <iostream>
#include <unistd.h>
using namespace std;
/**
 * @brief 참고 : https://ipwag.tistory.com/164
문제
게임 개발자인 밀리는 전투력 시스템을 만들어, 캐릭터가 가진 전투력을 기준으로 칭호를 붙여주려고 한다.

예를 들어, 
전투력 10,000 이하의 캐릭터는 WEAK,
10,000 초과 그리고 100,000 이하의 캐릭터는 NORMAL, 
100,000 초과 그리고 1,000,000 이하의 캐릭터는 STRONG 칭호를 붙여준다고 하자. 
이를 IF문으로 작성한다면 아래와 같이 구현할 수 있다.

if power <= 10000
 print WEAK
else if power <= 100000
 print NORMAL
else if power <= 1000000
 print STRONG
혼자서 게임을 개발하느라 매우 바쁜 밀리를 대신해서, 캐릭터의 전투력에 맞는 칭호를 출력하는 프로그램을 작성하자.

입력
첫 번째 줄에는 
칭호의 개수 N (1 ≤ N ≤ 105)과 칭호를 출력해야 하는 
캐릭터들의 개수 M (1 ≤ M ≤ 105)이 빈칸을 사이에 두고 주어진다. (1 ≤ N, M ≤ 105)

두 번째 줄부터 N개의 줄에 각 
칭호의 이름을 나타내는 길이 1 이상, 11 이하의 영어 대문자로만 구성된 문자열과 해당 칭호의 
전투력 상한값을 나타내는 109 이하의 음이 아닌 정수가 주어진다. 
칭호는 전투력 상한값의 비내림차순으로 주어진다. 

N + 2번째 줄부터 M개의 각 줄에는 캐릭터의 전투력을 나타내는 음이 아닌 정수가 주어진다. 
해당하는 칭호가 없는 전투력은 입력으로 주어지지 않는다.

출력
M개의 줄에 걸쳐 캐릭터의 전투력에 맞는 칭호를 입력 순서대로 출력한다. 
어떤 캐릭터의 전투력으로 출력할 수 있는 칭호가 여러 개인 경우 가장 먼저 입력된 칭호 하나만 출력한다.
 * 
 */

int binary_Search(int* int_array, int element, int N)
{
    int stp, midp, endp;
    stp = 1, endp = N;
    while (stp <= endp)
    {
        midp = (stp + endp) / 2;
        if (element > int_array[midp])
            stp = midp + 1;
        else 
            endp = midp - 1;
    }
    if (element <= int_array[midp])
        return midp;
    else
        return midp + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int N, M, standard[100001] = {0, };
    string style[100001];
    cin >> N >> M;
    for (int cnt_i = 1; cnt_i <= N; cnt_i++)
    {
        cin >> style[cnt_i] >> standard[cnt_i];
    }

    int charactor;
    for (int cnt_i = 0; cnt_i < M; cnt_i++)
    {
        cin >> charactor;
        cout << style[binary_Search(standard, charactor, N)] << "\n";
        // cout << "\n" << charactor << "\t" << standard[binary_Search(standard, charactor, N)] << "\t" << style[binary_Search(standard, charactor, N)] << "\t";
    }
    
    

    return 0;
}