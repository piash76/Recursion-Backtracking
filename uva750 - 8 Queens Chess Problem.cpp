

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


int board[10][10],n=8,a,b,cnt;

set<vector<int> > ans;


void print_sol()
{
    vector<int> vec;



    for(int i=1;i<=n;i++)  ///col
    {
        for(int j=1;j<=n;j++)  ///row
        {
            if(board[j][i]==1)
            {
               /// cout<<"I "<<i<<" J "<<j<<" ";
               /// printf(" %d",j);
               vec.push_back(j);

            }
        }

    }
   /// cout<<endl;
   ans.insert(vec);

}


bool is_safe(int row,int col)
{
   /// /*
    for(int i=1;i<row;i++)  ///checking upper rows
    {
        if(board[i][col]==1) return false;
    }

    ///*/


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

    if(row==n+1 and board[a][b]==1)  ///solution found
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
    for(i=1;i<=t;i++)
    {
        ans.clear();

        cnt=1;

        memset(board,0,sizeof(board));

       // cin>>n;
        cin>>a>>b;

        if(i>1) cout<<endl;

       printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        solve(1); ///1 no queen ,queens can be imagined by row

        for(auto vc:ans)
        {
           printf("%2d     ",cnt++);
            for(auto it:vc)
            {
                cout<<" "<<it;
            }
            cout<<endl;
        }





    }

    return 0;

}




