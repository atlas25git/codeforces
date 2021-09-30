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
        cin>>n>>m>>k;
        // if(k)k--;
        if(n-1>m){
            cout<<"NO\n";
            return;
        }
        if(k>2)
        {
            int remEdges = m - k-1;
            int remN = n - k;

            if((!remEdges && !remN))
            {
                cout<<"YES\n";
                return;
            }
            else if(remEdges || remN)
            {
                if(remEdges>=(remN + remN -1)){
                    cout<<"NO\n";
                    return;
                }
                else cout<<"YES\n";
                return;
                       
            }
        }
        else{
            if(k==2)
                {
                    if((n==2 && m==1))
                        {
                            cout<<"YES\n";
                            return;
                        }
                    else if(n==1 && !m)
                        {
                            cout<<"YES\n";
                            return;
                        }
                    else{
                        int rE = m - k -1;
                        int rN = n - k;
                        if(!rE && !rN)
                        {
                            cout<<"YES\n";
                            return;
                        }
                        else{
                            if(rE == (2*rN - 1))
                            {
                                cout<<"YES\n";
                                return;
                            }
                        }
                    }
                }

            if(k==1)
                if(n==1 && !m){
                    cout<<"YES\n";
                    return;
                }
            
            if(!k){
                if(!m){
                    cout<<"YES\n";
                    return;
                }
            }

        }


        // int remE = m-(n-1);
        // if(n==2)
        // {
        //     if(k>1 && remE == 0){
        //         cout<<"YES\n";
        //         return;
        //     }
        // }
        // if(2<k && remE<=n-2)
        // {
        //     cout<<"YES"<<endl;
        //     return;
        // }
        // else{
        //     int req = n-2;
        //     if(req == remE)
        //     {
        //         cout<<"YES\n";
        //         return;
        //     }
        // }

        cout<<"NO\n";
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