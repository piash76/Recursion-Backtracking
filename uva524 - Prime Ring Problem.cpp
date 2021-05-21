
///Bismillahir Rahmanir Rahim
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

vector<int> v;
int n;
int vis[18];

bool is_prime(int n)
{
    if(n==1) return false;
    bool flag = true;
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool is_safe(int num,int prev)
{
    if(vis[num]==0 and is_prime(num+prev)) return true;
    else return false;
}

void solve(int idx,int prev)
{
    //cout<<"IDX "<<idx<<" PREV "<<prev<<endl;
    if(idx==n)
    {

        if(is_prime(prev+1))
        {
            printf("1");
            for(auto x:v) printf(" %d",x);
            printf("\n");
        }
        return ;
    }

    for(int i=2;i<=n;i++)
    {
        if(is_safe(i,prev))
        {
            vis[i]=1;
            v.push_back(i);
            solve(idx+1,i);

            vis[i]=0;
            v.pop_back();

        }
    }

    return ;
}


int main()
{


    int t=0,i,j,cas=0;

    while(scanf("%d",&n)!=EOF)
    {
        t++;

        if(t>1) printf("\n");

        v.clear();
        memset(vis,0,sizeof(vis));

        printf("Case %d:\n",++cas);



        solve(1,1); ///idx=1 ,prev=1;

        ///printf("\n");



    }

    return 0;

}




