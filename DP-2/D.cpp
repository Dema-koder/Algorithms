#include <cstdio>
#include <cstring>
#include <cassert>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int MOD = (int)1e9 + 7;
const int maxN = 1001;
const int maxS = 9001;

int k, sum;
int f[maxN][maxS];

inline void add( int &a, int b )
{
  if ((a += b) >= MOD)
    a -= MOD;
}

inline void sub( int &a, int b )
{
  if ((a -= b) < 0)
    a += MOD;
}

int main()
{


  scanf("%d%d", &k, &sum); 
  f[0][0] = 1;
  forn(i, k)
  {
    int res = 0;
    forn(s, sum + 1)
    {
      add(res, f[i][s]);
      if (s >= 10)
        sub(res, f[i][s - 10]);
      f[i + 1][s] = res;
    }
  }
  printf("%d\n", f[k][sum]);
  return 0;
}
              
