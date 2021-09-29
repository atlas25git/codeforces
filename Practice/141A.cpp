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
const std::string WHITESPACE = " \n\r\t\f\v";
std::string ltrim(const std::string &s)
{
size_t start = s.find_first_not_of(WHITESPACE);
return (start == std::string::npos) ? "" : s.substr(start);
}
std::string rtrim(const std::string &s)
{
size_t end = s.find_last_not_of(WHITESPACE);
return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
std::string trim(const std::string &s) {
return rtrim(ltrim(s));
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
vector<string> tokenize(string s, const char* del)
{
    vector<string> res;
    auto x = s.c_str();
    char y[s.size()+1];
    strcpy(y,x);
    auto tok = strtok(y,del);
    while(tok)
    {
    res.push_back(string(tok));
    tok = strtok(0,del);
    }
    return res;
}
void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        string s,p,q;
        cin>>s>>p>>q;

        vector<int> dp(26,0);
        for(auto x: q)
            dp[x-'A']++;
        
        // for(auto x: dp)cout<<x<<" ";
        // cout<<endl;

        for(auto x: s)dp[x-'A']--;
        //  for(auto x: dp)cout<<x<<" ";
        // cout<<endl;
        for(auto x: p)dp[x-'A']--;
        //  for(auto x: dp)cout<<x<<" ";
        // cout<<endl;

        for(auto x: dp)if(x!=0){
            cout<<"NO";
            return;
        }
        cout<<"YES";

        // multiset<char> st(q.begin(),q.end());

        // for(auto& x: s)
        //     if(st.find(x)!=st.end())
        //         st.erase(st.lower_bound(x)),
        //         x = '0';


        // for(auto& x: p)
        //     if(st.find(x)!=st.end())
        //         st.erase(st.lower_bound(x)),
        //         x = '0';
        // cout<<s<<p<<endl;
        // for(auto x: s)if(x!='0'){
        //     cout<<"NO";
        //     return;
        // }

        // for(auto x: p)if(x!='0'){
        //     cout<<"NO";
        //     return;
        // }

        // cout<<"YES";

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