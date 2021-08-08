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
const int N = 100005, M=22;
void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        string s,t;
        cin>>s>>t;
        n = s.size();
        m = t.size();
        string built;

        for(i=0;s[i];i++){
            for(j=0;j<i;j++)
                built+=s[j];
            built += s[i];
            for(j=i-1;j>=0;j--)
                built += s[j];
            built += '#';
        }
        cout<<(built.find(t)!=string::npos?"YES":"NO")<<endl;
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