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
        
        cin>>n;
        vector<vector<int>>a(2,vector<int>(n));
        for(i=0;i<2;i++)
            for(j=0;j<n;j++)
                cin>>a[i][j];
        ans = INT_MAX;
        int sum1=0,sum2=0;
        for(i=0;i<n;i++)sum1 += a[0][i];
        for(i=0;i<n;i++){
            sum1 -= a[0][i];
            ans = min(ans,max(sum1,sum2));
            sum2 += a[1][i];
        }
        cout<<ans;

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