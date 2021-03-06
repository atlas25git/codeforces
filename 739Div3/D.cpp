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
void solve(){
    int i,j,k,n,m,ans=INT_MAX,cnt=0,sum=1;
        cin>>n;
        if(__builtin_popcount(n)==1 && n!=1)
        {
            cout<<0<<endl;
            return;
        }
        
        string s = to_string(n);
        if(s.size()==1)
        {   
            if((s[i]-'0')&1)
                cout<<2<<endl;
            else cout<<1<<endl;
            return;
        }
        for(i=0;s[i];i++)
        {
            if(__builtin_popcount(s[i]-'0') == 1 && s[i] != '1')
                {   
                    int x = s.size()-1;
                    ans=min(ans,x);
                }
        }

        while(n>sum<<1)
        {
            sum <<= 1;
        }

        string s1 = to_string(sum);
        unordered_set<int>s2;
        for(i=0;s1[i];i++)
            {
                s2.insert(s[i]-'0');
                s2.insert(s1[i]-'0');

            }
        for(auto x: s)s2.erase(x-'0');

        cnt = s2.size();
        ans=min(ans,cnt*2);
        cout<<ans<<" "<<sum<<" "<<cnt<<" "<<endl;

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
            int t;
            cin>>t;
            while(t--)
            solve();
        }
    }