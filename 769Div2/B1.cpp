/***************************************
*****Solution authored by Atlas25.******
*****************************************/
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
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
        cin>>n;
        // ans  = INT_MAX;
        // for(i=0;i<=n-2;i++)
        // {   
        //     j = ans;
        //     ans = min(ans,(i^(i+1)));
            
        //     if(j!=ans)
        //        { //cout<<ans<<"\n";
        //         k = i;}
        // }

        // cout<<k<<" "<<k+1<<" ";
        // n--;
        // for(i=0;i<=n/2;i++)
        // {
        //     j = i;
        //     m = n-i;
        //     if(j==m && j!=k)
        //         cout<<j<<" ";
        //     else {
        //         if(j!=k && j!=k+1)
        //             cout<<j<<" ";
        //         if(m!=k && m!=k+1)
        //             cout<<m<<" ";
        //         }
        // }
        // cout<<"\n";

        // ans = INT_MIN;
        // vector<int> a,b;
        // if(n == 2)
        //     {
        //         cout<<0<<" "<<1<<"\n";
        //         return;
        //     }

        // for(i=0;i<=n-1;i++)
        //     {
        //         // ans = max(ans,(i^(i+1)));
        //         if(i&1)a.push_back(i);
        //         else b.push_back(i);
        //     }
        
        // for(i=0;i<a.size()-1;i++)
        //     ans = max(ans,a[i]^(a[i+1]));

        // for(i=0;i<b.size()-1;i++)
        //     ans = max(ans,b[i]^(b[i+1]));

        // cout<<ans<<"\n";
        n--;
        if(n&1)
        {
        n++;    
        cout<<0<<" "<<n-2<<" "<<n-1<<" ";

        for(i=1;i<n;i++)
        {
            if(i == n-1 || i==n-2)continue;
            cout<<i<<" ";
        }}
        else{
        n++;
        cout<<0<<" "<<n-1<<" ";

        for(i=1;i<n;i++)
        {
            if(i == n-1)continue;
            cout<<i<<" ";
        }
        }
        cout<<"\n";

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
            #ifndef ONLINE_JUDGE
                auto begin = high_resolution_clock::now();
            #endif
            int t;
            cin>>t;
            while(t--)
            solve();
            #ifndef ONLINE_JUDGE
                auto end = high_resolution_clock::now();
                cout << fixed << setprecision(4) << "Execution Time: " << duration_cast<duration<double>>(end - begin).count() << "seconds" << '\n';
            #endif
        }
    }