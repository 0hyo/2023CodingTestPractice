#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

bool comp(int x, int y) {return x > y;}


int solution() {
    vector<int> people;
    int limit;
    cin.tie(NULL);
    cout.tie(NULL);
    string line;
    getline(cin, line);
    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());
    string num = "";
    for(char ch : line){
        if(isdigit(ch)){
            num += ch;
        }
        else if(!isdigit(ch) & !num.empty())
        {
            people.push_back(stoi(num));
            num = "";
        }
    }

    limit = people.back();
    people.pop_back();
    sort(people.begin(), people.end());
    

    
    cout << "limit : " << limit << endl;
    // cout << line << endl;
    int answer = 0;

    return answer;
}

int main() {
    solution();
                                                       


    return 0;
}