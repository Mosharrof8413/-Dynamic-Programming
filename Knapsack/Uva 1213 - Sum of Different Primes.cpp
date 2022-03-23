
/*
 Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=submit_problem&problemid=3654&category=0
 */

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second


ll gcd ( ll a, ll b )
{
    return __gcd ( a, b );
}
ll lcm ( ll a, ll b )
{
    return a * ( b / gcd ( a, b ) );
}

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int MX=1e7+123;
bitset<MX>is_prime;
vector<ll>primes;
void primeGen(ll n)
{
    ll sq=sqrt(n);
    for(ll i=3; i<=n; i+=2)is_prime[i]=1;

    for(ll i=3; i<=sq; i+=2)
    {
        if(is_prime[i]==1)
        {
            for(ll j=i*i; j<=n; j+=(i+i))
                is_prime[j]=0;
        }
    }
    primes.PB(2);
    is_prime[2]=1;
    for(ll i=3; i<=n; i+=2)
    {
        if(is_prime[i]==1)primes.PB(i);
    }
}

ll dp[260][1200][15];
ll n,k;
ll solve(ll indx_prime,ll sum,ll cnt)
{
    if(indx_prime>=primes.size() || sum>=n || cnt>=k)
    {
        return (cnt==k && sum==n);
    }
    if(dp[indx_prime][sum][cnt]!=-1)return dp[indx_prime][sum][cnt];

    ll ans=0;
    ans+=solve(indx_prime+1,sum+primes[indx_prime],cnt+1);
    ans+=solve(indx_prime+1,sum,cnt);

    return dp[indx_prime][sum][cnt]=ans;

}

int main()
{
    optimize();
    ll limt=1e6+123;
    //string st="abcdefghijklmnopqrstuvwxyz";
     primeGen(1200);

    while(cin>>n>>k && n && k)
    {
           memset(dp,-1,sizeof(dp));
           cout<<solve(0,0,0)<<endl;
    }



}

//Alhamdulillah..

/*
input :
24 3
24 2
2 1
1 1
4 2
18 3
17 1
17 3
17 4
100 5
1000 10
1120 14
0 0

output :
2
3
1
0
0
2
1
0
1
55
200102899
2079324314
*/



