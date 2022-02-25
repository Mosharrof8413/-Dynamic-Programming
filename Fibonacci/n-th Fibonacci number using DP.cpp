/*
 Problem link :
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

ll dp[10000];
int fib(int n)
{
  if(n<=1)dp[n]=n;
  if(dp[n]!=-1)return dp[n];
  return dp[n]=fib(n-1)+fib(n-2);
}
 void initi(ll n)
 {
     for(ll i=0;i<=10000;i++)dp[i]=-1;
 }
int main()
{
    optimize();
    initi(10000);
    ll n;
    cin>>n;
    cout<<n<<"-th fibonacci number is : "<<fib(n)<<endl;
    for(ll i=0;i<n;i++)cout<<dp[i]<<" ";
    return 0;
}
//Alhamdulillah..


/*
Input:
4

Output:
4-th fibonacci number is : 3
0 1 1 2

*/





