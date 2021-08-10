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

struct activity
{
    int A,B,C;
};

int sol(vector<activity> ar,int n)
{
    int dp[n+1][3];
    memset(dp,0,sizeof(dp));
    //base case
    dp[1][0] = ar[1].A;
    dp[1][1] = ar[1].B;
    dp[1][2] = ar[1].C;

    for(int i=2;i<=n;i++)
    {
        dp[i][0] = ar[i].A + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = ar[i].B + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = ar[i].C + max(dp[i-1][0],dp[i-1][1]);

    }

    return max(dp[n][0],max(dp[n][1],dp[n][2]));

}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n;
    vector<activity>ar(n+1);
    for(int i=1;i<=n;i++)
    cin>>ar[i].A,
    cin>>ar[i].B,
    cin>>ar[i].C;
    
    cout<<sol(ar,n)<<endl;
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