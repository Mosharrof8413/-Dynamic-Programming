/*
 Problem : https://atcoder.jp/contests/dp/tasks/dp_a

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
ll h[mx],dp[mx],n;

ll solve(ll i)
{
    if( i==n ) return 0;
    if(dp[i]!=-1)return dp[i];

    ll ans1=2e9,ans2=2e9;
    if(i+1<=n) ans1=abs(h[i]-h[i+1])+solve(i+1);
    if(i+2<=n) ans2=abs(h[i]-h[i+2])+solve(i+2);
    dp[i]= min(ans1,ans2);
    return dp[i];
}


int main()
{
    optimize();

    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(ll i=1; i<=n; i++)cin>>h[i];
    cout<<solve(1)<<endl;

}

//Alhamdulillah..


/*
6
30 10 60 10 60 50

Output:
40

*/


