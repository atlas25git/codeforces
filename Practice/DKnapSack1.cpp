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

int sol(vector<item>& a,int totalItem,int totalWt)
{
    vector<vector<int>>dp(totalItem+1,vector<int>(totalWt+1,0));

    //base case
    //for item 1
    dp[1][a[1].wt] = a[1].val;

    for(int i=2;i<=totalItem;i++)
    {
        for(int wt=0;wt<=totalWt;wt++)
         {  
             dp[i][wt] = dp[i-1][wt];
            if(wt>=a[i].wt)
            {
                dp[i][wt] = max(
                    dp[i][wt],
                    a[i].val + dp[i-1][wt - a[i].wt]
                );

            }
         }    
    }
    return *max_element(dp[totalItem].begin(),dp[totalItem].end());
}


void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    int totalWt;
    cin>>n>>totalWt;

    vector<item>a(n+1);
    for(i=1;i<=n;i++)cin>>a[i].wt>>a[i].val;

    cout<<sol(a,n,totalWt)<<endl;      
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