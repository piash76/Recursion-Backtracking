

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

const ll inf=1e18;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1
const int M=105;

ll n,m,no;  ///no is no of color
vector<ll> g[M];
ll col[M];


bool is_safe(ll u,ll clr)
{
    for(auto v:g[u])
    {
        if(col[v]==clr) return false;
    }

    return true;

}

bool mcoloring(ll node)
{
    if(node==n+1) return true;

    for(ll clr=1;clr<=no;clr++)
    {
        if(is_safe(node,clr))
        {
            col[node]=clr;

            if(mcoloring(node+1)) return true;

            col[node]=0;
        }
    }

    return false;
}


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;
    cin>>t;
    while(t--)
    {

        for(i=1;i<M;i++) { g[i].clear();col[i]=0; }

        cin>>n>>m>>no;

        for(i=1;i<=m;i++)
        {
            ll u,v;cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }

        if(mcoloring(1)) cy;
        else cn;

        for(i=1;i<=n;i++) cout<<col[i]<<" ";
        cout<<endl;



    }

    return 0;

}
/*

1
4 10 3
1 2
1 3
1 4
2 1
2 3
3 1
3 2
3 4
4 1
4 3

*/





