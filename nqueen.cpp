///https://www.youtube.com/watch?v=xFv_Hl4B83A

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

int board[10][10],n;

void print_sol()
{
    for(int i=1;i<=n;i++)  ///row
    {
        for(int j=1;j<=n;j++)  ///col
        {
            if(board[i][j]==1)
            {
                cout<<"I "<<i<<" J "<<j<<" ";
                //cout<<j<<" ";
            }
        }

    }
    cout<<endl;
}


bool is_safe(int row,int col)
{
    for(int i=1;i<row;i++)  ///checking upper rows
    {
        if(board[i][col]==1) return false;
    }

    ///check upper left diagonal
    int i=row,j=col;

    while(i>=1 and j>=1)
    {
        if(board[i][j]==1) return false;
        i--;
        j--;
    }

    ///check upper right diagonal
    i=row,j=col;

    while(i>=1 and j<=n)
    {
        if(board[i][j]==1) return false;
        i--;
        j++;
    }

    return true;

}

bool solve(int row)
{

    if(row==n+1)  ///solution found
    {
        print_sol();
        return true;

    }

    bool res=false;
    for(int col=1;col<=n;col++)
    {
        if(is_safe(row,col))
        {
            board[row][col]=1;

            res=res|solve(row+1);

            board[row][col]=0;

        }
    }

    return res;

}


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int t,i,j;
    cin>>t;
    while(t--)
    {
        memset(board,0,sizeof(board));

        cin>>n;

        solve(1); ///1 no queen ,queens can be imagined by row


    }

    return 0;

}

/*
for n=4

2 4 1 3
3 1 4 2

*/




