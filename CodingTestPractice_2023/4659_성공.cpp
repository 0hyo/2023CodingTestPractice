#include <iostream>
#include <string>
using namespace std;
/**
 * @brief 
문제
좋은 패스워드를 만드는것은 어려운 일이다. 
대부분의 사용자들은 buddy처럼 발음하기 좋고 기억하기 쉬운 패스워드를 원하나, 이런 패스워드들은 보안의 문제가 발생한다. 
어떤 사이트들은 xvtpzyo 같은 비밀번호를 무작위로 부여해 주기도 하지만, 사용자들은 이를 외우는데 어려움을 느끼고 심지어는 포스트잇에 적어 컴퓨터에 붙여놓는다. 
가장 이상적인 해결법은 '발음이 가능한' 패스워드를 만드는 것으로 적당히 외우기 쉬우면서도 안전하게 계정을 지킬 수 있다. 

회사 FnordCom은 그런 패스워드 생성기를 만들려고 계획중이다. 
당신은 그 회사 품질 관리 부서의 직원으로 생성기를 테스트해보고 생성되는 패스워드의 품질을 평가하여야 한다. 
높은 품질을 가진 비밀번호의 조건은 다음과 같다.

1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
이 규칙은 완벽하지 않다;우리에게 친숙하거나 발음이 쉬운 단어 중에서도 품질이 낮게 평가되는 경우가 많이 있다.

입력
입력은 여러개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 테스트할 패스워드가 주어진다.
마지막 테스트 케이스는 end이며, 패스워드는 한글자 이상 20글자 이하의 문자열이다. 
또한 패스워드는 대문자를 포함하지 않는다.

출력
각 테스트 케이스를 '예제 출력'의 형태에 기반하여 품질을 평가하여라.
 * 
 */
char alphabet[26] = {'a','b','c','d',
                    'e','f','g','h',
                    'i','j','k','l',
                    'm','n','o','p',
                    'q','r','s','t',
                    'u','v','w','x',
                    'y','z'};
char Vowel[5] = {'a', 'e', 'i', 'o', 'u'};
char Consonant[21] = {'b','c','d','f',
                    'g','h','j','k',
                    'l','m','n','p',
                    'q','r','s','t',
                    'v','w','x','y',
                    'z'};

void print_invalid(string str)
{
    cout << "<" << str <<"> is not acceptable.\n"; 
}
void print_valid(string str)
{
    cout << "<" << str <<"> is acceptable.\n"; 
}
bool is_there_Vowel(string str)
{
    for (int cnt_i = 0; cnt_i < str.length(); cnt_i++)
    {
        for (int cnt_j = 0; cnt_j < 5; cnt_j++)
        {
            if (str[cnt_i] == Vowel[cnt_j])
                return true;
        }
    }
    return false;
}
bool is_Vowel(char ch)
{
    for (int cnt_i = 0; cnt_i < 5; cnt_i++)
    {
        if(ch == Vowel[cnt_i])
        {
            return true;
        }
    }
    return false;
}
bool is_Consonant(char ch)
{
    for (int cnt_i = 0; cnt_i < 21; cnt_i++)
    {
        if(ch == Consonant[cnt_i])
        {
            return true;
        }
    }
    return false;
}
bool is_duplicatuon(string str)
{
    for (int cnt_i = 0; cnt_i < str.length(); cnt_i++)
    {
        if (is_Vowel(str[cnt_i]) && is_Vowel(str[cnt_i + 1]) && is_Vowel(str[cnt_i + 2]))
        {
            return true;
        }
        if (is_Consonant(str[cnt_i]) && is_Consonant(str[cnt_i + 1]) && is_Consonant(str[cnt_i + 2]))
        {
            return true;
        }
    }
    return false;
}
bool is_double_Alphabet(string str)
{
    for (int cnt_i = 0; cnt_i < str.length() - 1; cnt_i++)
    {
        if (str[cnt_i] == 'e' || str[cnt_i] == 'o')
            continue;
        if (str[cnt_i] ==  str[cnt_i + 1])
            return true;
    }
    return false;
}
int main()
{
    string ID, end = "end";
    while (true)
    {
        getline(cin, ID);
        if ((ID == end)) break;
        else if (!is_there_Vowel(ID))      // 모음 없으면 inv
            print_invalid(ID);        
        else if (is_duplicatuon(ID))
            print_invalid(ID);        
        else if (is_double_Alphabet(ID))
            print_invalid(ID);        
        else
            print_valid(ID);
    }
    
    return 0;
}