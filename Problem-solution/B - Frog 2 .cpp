/*
 Problem : https://atcoder.jp/contests/dp/tasks/dp_b

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
ll h[mx],dp[mx],n,k;

ll solve(ll i)
{
    if( i==n ) return 0;
    if(dp[i]!=-1)return dp[i];

    ll ans=2e9 ;
    for(ll j=1;j<=k;j++)
    {
        if(i+j<=n) ans=min(ans,abs(h[i]-h[i+j])+solve(i+j));
    }
    dp[i]=ans;
    return dp[i];   //return dp[i]=ans;

}


int main()
{
    optimize();

    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(ll i=1; i<=n; i++)cin>>h[i];
    cout<<solve(1)<<endl;

}

//Alhamdulillah..


/*
10 4
40 10 20 70 80 10 20 70 80 60

Output:
40

complexity : O(n*k)

*/



