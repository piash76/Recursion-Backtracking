

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

ll n,h;
vector<int> v;

void solve(ll idx,ll ham)
{
    if(ham>h) return;

    if(idx==n)
    {
        if(ham==h)
        {
        for(auto it:v) cout<<it;
        cout<<endl;
        }

        return ;
    }

    v.push_back(0);
    solve(idx+1,ham);
    v.pop_back();

    v.push_back(1);
    solve(idx+1,ham+1);
    v.pop_back();

}

int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j,cas=0;
    cin>>t;
    while(t--)
    {
        if(cas) cout<<endl;
        cas++;

        v.clear();

        cin>>n>>h;

        solve(0,0);

       // cout<<endl;

    }

    return 0;

}



