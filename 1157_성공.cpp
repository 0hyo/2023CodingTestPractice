#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/**
 * @brief 
문제
알파벳 대소문자로 된 단어가 주어지'면', 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 
단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 
주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 
단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
 * 
 */
char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
char ALPHABET[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
int main()
{
    string word;
    cin >> word;
    int nums[26] = {0, };
    
    for (int cnt_i = 0; cnt_i < word.length(); cnt_i++)
    {
        for (int cnt_j = 0; cnt_j < 26; cnt_j++)
        {
            if (word[cnt_i] == alphabet[cnt_j] || word[cnt_i] == ALPHABET[cnt_j])
            {
                nums[cnt_j]++;
            }            
        }
    }
    int max_index, max_nums = 0;
    for (int cnt_i = 0; cnt_i < 26; cnt_i++)
    {
        if (max_nums < nums[cnt_i])
        {
            max_nums = nums[cnt_i];
            max_index = cnt_i;
        }
    }
    for (int cnt_i = 0; (cnt_i < 26); cnt_i++)
    {
        if (cnt_i == max_index)
            continue;
        if (max_nums == nums[cnt_i])
        {
             max_index = -1;
        }
    }
    if (max_index == -1)
        cout << "?";
    else
        cout << ALPHABET[max_index];

    return 0;
}