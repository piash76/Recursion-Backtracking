///https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e15;
const int mod=1e9+7;
const int N=1005;

int mat[105][105],n;

bool is_safe(int r,int c)
{
    ///checking up in same col
    for(int i=1;i<=n;i++)
    {
        if(mat[i][c])
        {
            return false;
        }

    }

    ///checking upper left diagonal

    int i=r,j=c;

    while(i>=1 and j>=1)
    {
        if(mat[i][j])
        {
            return false;
        }
        i--;j--;
    }

    ///checking upper right diagonal

    i=r,j=c;

    while(i>=1 and j<=n)
    {
        if(mat[i][j])
        {
            return false;
        }
        i--;j++;
    }

    return true;
}

bool solve(int row)
{

    if(row==n+1) return true;

    for(int i=1;i<=n;i++)  ///col
    {
        if(is_safe(row,i))
        {
            mat[row][i]=1;


            if(solve(row+1)) return true;

            mat[row][i]=0;


        }
    }

    return false;
}

int main()
{

    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);


    cin>>n;

    solve(1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }






    return 0;

}




