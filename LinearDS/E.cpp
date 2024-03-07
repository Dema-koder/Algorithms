#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector <int> b(n + 2);
    b[n] = -1;
    b[n + 1] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int sch = 0;
    for (int i = 0; i < b.size() - 2; i++)
    {
        if (b[i] == b[i + 1] && b[i] == b[i + 2])
        {
            int a = b[i];
            for (; b[i] == a; sch++)
            {
                b.erase(b.begin() + i);
            }
            i = -1;
        }
    }
    cout << sch;
}
