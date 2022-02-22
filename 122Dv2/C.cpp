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
        int hc,dc,hm,dm,w,a;
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;
        //cout<<hc<<" "<<dc<<" "<<hm<<" "<<dm<<" "<<k<<" "<<w<<" "<<a<<"\n";

        int cm = hm/dc;// + (!(hm%dc))?1:0;
        int mm = hc/dm;// + (!(hc%dm))?1:0;
        
        if(hm%dc)cm++;
        if(hc%dm)mm++;

        int remM = cm -  mm;
        //cout<<remM<<"\n";
        if(remM < 0)
        {
            cout<<"YES\n";
            return;
        }
        // else if(remM == 0)
        // {
        //     int arm = k*a;
        //     int wep = k*w;

        //     if(arm >= (dm - (hc%dm)))
        //     {
        //         cout<<"YES\n";
        //         return;
        //     }
        //     else if((hm/(dc+wep)) < (hc/dm))
        //     {
        //         cout<<"YES\n";
        //         return;
        //     }
        //     else cout<<"NO\n";
        //     return;
        // }
        // else{
        //     int movesReq = abs(remM);
        //     int arm = k*a;
        //     int wep = k*w;

        //     if(((hc+arm)/dm) > (hm/dc))
        //     {
        //         cout<<"YES\n";
        //         return;
        //     }

        //     else if((hm/(dc+wep)) < (hc/dm))
        //     {
        //         cout<<"YES\n";
        //         return;
        //     }
        //     else cout<<"NO\n";
        //     return;

        // }

        else{
            i = 0;
            while(i<=k)
            {   
               int nhc = hc + a*(i);
               int ndc = dc + w*(k-i);
                cm = hm/ndc;// + (!(hm%dc))?1:0;
                mm = nhc/dm;// + (!(hc%dm))?1:0;
                if(hm%ndc)cm++;
                if(nhc%dm)mm++;

                //cout<<cm<<" "<<mm<<"\n";
                int remM = cm -  mm;
                //cout<<remM<<"\n";
                if(remM < 0)
                {
                    cout<<"YES\n";
                    return;
                }
                else if(remM == 0)
                {
                    int hrc = nhc%dm;
                    //cout<<hrc<<" ::\n";
                    if(1 || hrc <= i*a)
                    {
                        cout<<"YES\n";
                        return;
                    }
                }
                i++;
            }
        }

        cout<<"NO\n";
        return;
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