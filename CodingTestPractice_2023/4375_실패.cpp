#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, i, j, tmp;

    while(cin >> N)
    {
        int one = 0;
        int ten = 1;
        i = 0;
        tmp = N;
        
        while(1)
        {
            one += (ten);
            ten = (ten * 10)% tmp;
            one = one % tmp;
            i++;

            if (one == 0)
                {
                    cout << i << endl;
                    break;
                }
            // cout << "one : " << one << endl;
            // cout << "ten : " << ten << endl;
        }
    }
    

    return 0;
}