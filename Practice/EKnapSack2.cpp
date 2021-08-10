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

struct item{
    int val,wt;
};

int sol(vector<item>& a,int n,int wt)
{
    //since here the constraints on wt are very large thus we'll 
    //make a dp fill up table for number of items and maxPossible value
    //that could be formed using them, and the cell will contain wt req
    //now traverse the last row for the wt satisfying the given criteria

    //max value calculation:
    int maxVal = n*1000; //as val can at max be 1000 individually
    vector<vector<int>>dp(n+1,vector<int>(maxVal+1,INT_MAX));
    for(int i=0;i<=maxVal;i++)dp[1][i]=INT_MAX;
    dp[1][0] = 0;
    dp[1][a[1].val] = a[1].wt;

    for(int i=2;i<=n;i++)
        for(int j=0;j<=maxVal;j++)
        {   
            dp[i][j] = dp[i-1][j];
            if(maxVal>=a[i].val)
            {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i-1][j-a[i].val] + a[i].wt
                );
            }

        }

    int ans=0;
    //lookup for the appr wt under constraint with n items
    for(int i=0;i<=maxVal;i++)
        if(dp[n][i]<=wt)ans = i;
    return ans;
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        int wt;
        cin>>n>>wt;
        vector<item>a(n+1);
        for(i=1;i<=n;i++)cin>>a[i].wt>>a[i].val;
        cout<<sol(a,n,wt)<<endl;
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