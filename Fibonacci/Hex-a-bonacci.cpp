/*
 Problem link : https://lightoj.com/problem/hex-a-bonacci
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
ll dp[10005];
int a, b, c, d, e, f;
int fib(int n)
{
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=(fib(n-1)% 10000007 + fib(n-2)% 10000007 + fib(n-3)% 10000007 + fib(n-4)% 10000007 + fib(n-5)% 10000007 + fib(n-6)% 10000007)% 10000007;
}
int main()
{
    optimize();
    int n, t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", tt, fib(n) % 10000007);
    }
    return 0;
}
//Alhamdulillah..


/*
Input:
6
0 1 2 3 4 5 20
1 2 3 4 5 6 10000
3 2 1 5 0 1 9
4 12 9 4 5 6 15
9 8 7 6 5 4 3
3 4 3 2 54 5 4

Output:
Case 1: 216339
Case 2: 5333347
Case 3: 79
Case 4: 16636
Case 5: 6
Case 6: 54

*/




