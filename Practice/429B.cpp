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
const int NN = 1005;
int boyStart[NN][NN];
int girlStart[NN][NN];
int boyEnd[NN][NN];
int girlEnd[NN][NN];
int calories[NN][NN];



int mc(int M,int N)
{
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            boyStart[i][j] = calories[i][j] + max(boyStart[i-1][j],boyStart[i][j-1]);
        }
    }

    for(int i=M;i >= 1;i--)
        for(int j=1;j<=N;j++)
            girlStart[i][j] = calories[i][j]
                + max(girlStart[i+1][j],girlStart[i][j-1]);

    for(int i=M;i>=1;i--){
        for(int j=N;j>=1;j--)
            boyEnd[i][j] = calories[i][j]
                + max(boyEnd[i+1][j],boyEnd[i][j+1]);
    }                

    for(int i=1;i<=M;i++){
        for(int j=N;j>=1;j--){
            girlEnd[i][j] = calories[i][j] 
                + max(girlEnd[i-1][j],girlEnd[i][j+1]);
        }
    }

    int ans = 0;
    for(int i=2;i<M;i++)
        for(int j=2;j<N;j++)
        {
            int ans1 = boyStart[i][j-1] + boyEnd[i][j+1] + girlStart[i+1][j] + girlEnd[i-1][j];
            int ans2 = boyStart[i-1][j] + boyEnd[i+1][j] + girlStart[i][j-1] + girlEnd[i][j+1];

            ans = max(ans1,ans2);
        }
        return ans;
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n>>m;
    memset(boyStart,0,sizeof boyStart);
    memset(girlStart,0,sizeof girlStart);
    memset(boyEnd,0,sizeof boyEnd);
    memset(girlEnd,0,sizeof girlEnd);
    memset(calories,0,sizeof calories);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>calories[i][j];
        
    cout<<mc(n,m)<<endl;
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