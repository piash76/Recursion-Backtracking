
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
const int M=500005;

ll n,m;
string dict[105],rule[105];

string pat;
ll lim;
vector<string> ans;


void solve(ll idx)
{
    if(idx==lim)
    {
        for(auto it:ans) cout<<it;

        cout<<endl;

        return ;
    }


    if(pat[idx]=='#')
    {
        for(ll i=0;i<n;i++)
        {
            ans.push_back(dict[i]);
            solve(idx+1);
            ans.pop_back();
        }

    }
    else
    {
        for(ll i=0;i<=9;i++)
        {
            char ch=i+'0';
            string st="";
            st+=ch;

            ans.push_back(st);
            solve(idx+1);
            ans.pop_back();
        }

    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;

    while(cin>>n)
    {
        for(i=0;i<n;i++) cin>>dict[i];

        cin>>m;

        for(i=0;i<m;i++) cin>>rule[i];

        /*for(i=0;i<n;i++) cout<<dict[i]<<" ";
        cout<<endl;
        for(i=0;i<m;i++) cout<<rule[i]<<" ";
        cout<<endl;*/


        cout<<"--"<<endl;

        for(i=0;i<m;i++)
        {
            ans.clear();
            pat=rule[i];
            lim=pat.size();

            solve(0);

        }





    }

    return 0;

}

/*

2
root
2super
1
#0
1
admin
1
#0#

*/




