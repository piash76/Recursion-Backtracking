

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

vector<int> v,ans;
int a[22];
int n,lim,maxx;

void solve(int idx,int sum)
{
    if(idx==n)
    {
        if(sum<=lim and maxx<sum)
        {
            maxx=sum;
            ans=v;
        }
        return ;
    }

    v.push_back(a[idx]);
    solve(idx+1,sum+a[idx]);
    v.pop_back();

    solve(idx+1,sum);

}

int main()
{


    ll t,i,j;

    while(scanf("%d",&lim)!=EOF)
    {


        ans.clear();
        v.clear();
        maxx=-1;

        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);

        solve(0,0);

        for(auto it:ans) printf("%d ",it);
        printf("sum:%d\n",maxx);


    }

    return 0;

}



