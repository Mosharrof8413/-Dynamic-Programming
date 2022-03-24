/*
 Problem : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1557

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

const int mx=212;
ll dp[mx][22][12];
ll n,q,D,m,a[mx];

ll solve(ll indx,ll sum,ll cnt)
{
    if(indx>n || cnt==m)
    {
        return (cnt==m && sum==0);
    }

    if(dp[indx][sum][cnt]!=-1) return dp[indx][sum][cnt];

    ll ans=0;
    ll d=(sum+a[indx])%D;
    if(d<0)d+=D;
    ans+=solve(indx+1,d,cnt+1);
    ans+=solve(indx+1,sum,cnt);

    return dp[indx][sum][cnt]=ans;
}

int main()
{
    optimize();
    ll tc=0;
    while(cin>>n>>q && n && q)
    {
        tc++;
        cout<<"SET "<<tc<<":"<<endl;
        for(ll i=1;i<=n;i++)cin>>a[i];
        for(ll i=1;i<=q;i++)
        {
            memset(dp,-1,sizeof(dp));
            cin>>D>>m;
            cout<<"QUERY "<<i<<": "<<solve(1,0,0)<<endl;

        }
    }



}

//Alhamdulillah..


/*
10 2
1
2
3
4
5
6
7
8
9
10
5 1
5 2
5 1
2
3
4
5
6
6 2
0 0
Output:

SET 1:
QUERY 1: 2
QUERY 2: 9
SET 2:
QUERY 1: 1

*/



