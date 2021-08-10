/***************************************
*****Solution authored by Atlas25.******
*****************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int mod = 1e9 + 7;
const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
int fact[N], inv[N], invfact[N];
void factInverse() {
fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
for (long long i = 2; i < N; i++) {
fact[i] = (fact[i - 1] * i) % MOD;
inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
}
}
int add(int a, int b) {
if ((a += b) >= MOD)
    a -= MOD;
else if (a < 0)
    a += MOD;
return a;
}
int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}
int nCr(int n, int r) {
    if (r > n)
        return 0;
    return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}
void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>k;
        vector<int> h(istream_iterator<int>(cin),{});
        //for(auto x:h)cout<<x<<endl;

        vector<int> dp(n+1,0);

        dp[0] = 0;
        dp[1] = abs(h[0] - h[1]);
        //dp[2] = min(abs(h[1] - h[2])+dp[]);

        for(int i=2;i<=n;i++)
        {   
            dp[i] = INT_MAX;
            for(j=i-1;j>-1 && (i-j)<=k;j--)
                dp[i] = min(dp[i],(dp[j] + abs(h[i] - h[j])));
        }
        cout<<dp[n-1]<<endl;
        // for(auto x:dp)cout<<x<<endl;

}
void init() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int32_t main(){
    init();
        {
            // int t;
            // cin>>t;
            // while(t--)
            solve();
        }
    }