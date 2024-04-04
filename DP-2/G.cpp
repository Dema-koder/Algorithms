#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
 
using namespace std;
 
vector< vector<int> > dp(503 + 2, vector<int> (503 + 2, -1));
 
int p(int x,int y,int w,int h){
 
    if (x < 1 || y < 1 || x > w || y > h){
        return 0;
    }
    if (x == 1 && y == 1){
        return 1;
    }
    if (dp[x][y] != -1){
        return dp[x][y];
    }
 
    dp[x][y] = (p(x - 2, y - 1, w, h) +
               p(x - 2, y + 1, w, h) +
               p(x - 1, y - 2, w, h) +
               p(x + 1, y - 2, w, h)) % ((int)1e6 + 7);
 
    return dp[x][y];
 
}
 
int main() {
    int a, b;
    cin >> a >> b;
    cout << p(a, b, a, b);
 
 
    return 0;
}
