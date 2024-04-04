#include <iostream> 
using namespace std;

const int SZ = 510;
const int INF = 1e9 + 10;

int d[SZ][SZ], e[SZ][SZ];
 
int main() {



    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> d[i][j];

    int mx = 0;
    for (int i = 0; i < m; i++) {
        mx = max(mx, d[0][i]);
        e[0][i] = mx;
    }

    for (int i = 1; i < n; i++) {
        int mx = INF;
        for (int j = 0; j < m; j++) {
            mx = max(min(mx, e[i - 1][j]), d[i][j]);
            e[i][j] = mx;
        }
        mx = INF;
        for (int j = m - 1; j >= 0; j--) {
            mx = max(min(mx, e[i - 1][j]), d[i][j]);
            e[i][j] = min(e[i][j], mx);
        }
    }

    cout << e[n - 1][m - 1];
    
    return 0;
}
