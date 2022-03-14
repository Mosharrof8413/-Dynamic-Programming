/*
 Problem : https://atcoder.jp/contests/dp/tasks/dp_c

*/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);


const int mx=100123;
ll dp[mx][4];
ll gain[mx][4];
ll n;

ll solve(ll day,ll work)
{
    if(day>n)return 0;
    if(dp[day][work]!=-1)return dp[day][work];
    ll ans=0;
    for(ll i=1;i<=3;i++)
    {
        if(i!=work)
        {
           ans=max(ans,gain[day][i]+solve(day+1,i));
        }
    }
    return dp[day][work]=ans;
}

int main()
{
    optimize();

     cin>>n;
     for(ll i=1;i<=n;i++)
     {
         for(ll j=1;j<=3;j++)cin>>gain[i][j];
     }
     memset(dp,-1,sizeof(dp));
     cout<<solve(1,0)<<endl;
}

//Alhamdulillah..


/*
3
10 40 70
20 50 80
30 60 90


Output:

210


*/



