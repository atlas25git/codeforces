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

vector<vector<int>>dp;

string getLCS(string s,string t,int len){
            //cout<<s<<" "<<t<<" ";
   
    //cout<<len<<endl;
    string LCS;
    int i=1,j=1;
    while(len>0){

        if(s[i-1]==t[j-1])
        {
            LCS.push_back(s[i-1]);
            i++,j++,len--;
        }
        else
        {
            if(dp[i][j+1]>dp[i+1][j])j++;
            else i++;

        }
        
    }
    cout<<LCS<<endl;
    return LCS;
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    string s1,s2;
    cin>>s1>>s2;

    n = s1.length();
    m = s2.length();

    dp.resize(n+1,vector<int>(m+1,0));

    for(i = 0;i<=n;i++)
        for(j=0;j<=m;j++)
        {
            if(!i || !j)
                dp[i][j]=0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else  dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    cout<<dp[n][m]<<endl;
    getLCS("axyb","abyxb",dp[n][m]);

        
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