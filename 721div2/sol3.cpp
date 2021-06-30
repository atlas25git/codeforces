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
    cin>>n;
    string s;
    cin>>s;
    bool pal=1;
    int cnt_0=0;
    int cnt_1=0;

    
    for(int i=0;s[i];i++)if(s[i]=='0')cnt_0++;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i])pal=0;
        if((s[i]=='1' || s[n-1-i]=='1') && s[i]!=s[n-1-i])cnt_1++;
    }
    if(pal){
        if(cnt_0==1){cout<<"BOB\n"; return;}
        if(cnt_0%2){
			cout << "ALICE\n";
			return;
		}
		cout << "BOB\n";
		return;
    }
    if(cnt_0==2 && cnt_1==1){
		cout << "DRAW\n";
		return;
	}
	cout << "ALICE\n";
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
    {   int t;
        cin>>t;
        while(t--)
        solve();
    }
}