/*
 Problem : https://www.spoj.com/problems/KNAPSACK/

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

const int mx=2005;
ll dp[mx][mx];
ll w[mx],p[mx];
ll capacity,n;

ll solve(ll item,ll curW)
{
    if(item>n)return 0;
    if(dp[item][curW]!=-1)return dp[item][curW];

    ll ans1=0,ans2=0;
    if(w[item]+curW<=capacity) ans1=p[item]+solve(item+1,curW+w[item]);  //for 1 ..or taking the item..
    ans2=solve(item+1,curW);         //for 0

    return dp[item][curW]=max(ans1,ans2);
}



int main()
{
    optimize();
    cin>>capacity>>n;
    for(ll i=1;i<=n;i++)cin>>w[i]>>p[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0)<<endl;

}

//Alhamdulillah..


/*
4 5
1 8
2 4
3 0
2 5
2 3

Output:

13


*/



