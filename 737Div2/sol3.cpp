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


int mem[N][2], vis[N][2];
int cntEven, _2pwn, n;

int dp(int i, bool equal)
{
    if(i<0)return 1;
    int& rt = mem[i][equal];
    if(!equal)return rt = mul(_2pwn,dp(i-1,0));
    if(n&1)
        return rt = mul(dp(i-1,1),add(cntEven,1));
    return rt = add(mul(dp(i-1,1),cntEven),dp(i-1,0));
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n>>k;
    cntEven=0;
    for(int i=0;i<n;i++)
            cntEven = add(cntEven,nCr(n,i));
        _2pwn = 1;
        for(int i=0;i<n;i++)
            _2pwn = mul(_2pwn,2);
        cout<<dp(k-1,1)<<endl;
    
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
            factInverse();
            int t;
            cin>>t;
            while(t--)
            solve();
        }
    }