/*
 Problem : https://atcoder.jp/contests/dp/tasks/dp_d

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
ll dp[123][mx];
ll p[123],w[123];
ll n,total_w;

ll solve(ll indx,ll curW)
{
    if(indx>n)return 0;
    if(dp[indx][curW]!=-1)return dp[indx][curW];

    ll ans1=0,ans2=0;
    if(w[indx]+curW<=total_w) ans1=p[indx]+solve(indx+1,w[indx]+curW);   // for 1 state...

        ans2=solve(indx+1,curW);                                  //for 0 state...don't take this ..
    return dp[indx][curW]=max(ans1,ans2);
}


int main()
{
    optimize();
    cin>>n>>total_w;
    for(ll i=1;i<=n;i++)cin>>w[i]>>p[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0)<<endl;

}

//Alhamdulillah..


/*
3 8
3 30
4 50
5 60


Output:

90


*/


