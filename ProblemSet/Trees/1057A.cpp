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

void dfs(int u,int v,vector<vector<int>>& adj,vector<int>& path,vector<bool>& vis)
{   
    vis[u]=true;
    // cout<<u<<" "<<v<<"::"<<endl;
    path.push_back(u);

    if(u == v)
        {   
            // cout<<"Final"<<path.size()<<endl;
            // for(auto x: path)cout<<x+1<<" ";
            return;
        }
        
    for(auto x: adj[u])
        {
            bool found=0;
            if(!vis[x] )
                {
                    dfs(x,v,adj,path,vis);
                    if(x==v){found=1;return;}
                }
            if(found)return;
        }

    // cout<<"del "<<path.back()<<endl;
    if(path.back() == v)return;
    path.pop_back();
    vis[u] = false;
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n;
    vector<int> nodes(istream_iterator<int>(cin),{});
    vector<vector<int>> adj(n-1);

    for(int i=0;i<n-1;i++)
    {
        adj[nodes[i]-1].push_back(i+1);
    }

    vector<int>path;
    vector<bool>vis(n,0);
    dfs(0,n-1,adj,path,vis);

    for(auto x: path)cout<<x+1<<" ";
        
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

// 0 1 2 
// 1 3 4 6 
// 2 5 
// 3 
// 4 7 
// 5 
// 6 