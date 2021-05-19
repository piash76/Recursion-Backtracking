#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

int m, n, k;
vector<int> g[105];

int color[105];
int maxx;
int ans[105];

int check(int x) {
  for (auto i:g[x])
  {


    if (color[i]) {
      return 0;
    }

  }
  return 1;
}

void dfs(int i)
{
  if (i > maxx) {
    maxx = i;
    for (int j = 1; j <= n; j++)
      ans[j] = color[j];
  }



  for (int j = 1; j <= n; j++) {
    if (check(j) && !color[j]) {
      color[j] = 1;
      dfs(i+1);
      color[j] = 0;
    }
  }
  return ;
}



int main(void)
{
  int x, y;

  scanf("%d", &m);

  while (m--)
  {
    scanf("%d %d", &n, &k);
    for(int i=0;i<105;i++) g[i].clear();
    for (int i = 0; i < k; i++) {
      scanf("%d %d", &x, &y);

      g[x].push_back(y);
      g[y].push_back(x);
    }
    memset(color, 0, sizeof(color));
    maxx = 0;
    dfs(0);

    printf("%d\n", maxx);

     int f = 0;
    for (int i = 1; i <= n; i++)
    {
      if (ans[i])
      {
        if (f) cout<<" ";
        cout<<i;
        f = 1;
      }
    }
    puts("");


   /*
    int f = 0;
    for (int i = 1; i <= n; i++)
    {
      if (ans[i])
      {
        if (f) printf(" ");
        printf("%d", i);
        f = 1;
      }
    }
    puts("");
    */
  }


  return 0;
}
