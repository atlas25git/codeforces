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
        cin>>n>>k;
        vector<pair<int,int>>arr(n+1);
        arr[0].first=INT_MAX;
        for(int i=1;i<=n;i++)
            {  
                cin>>arr[i].first;
                arr[i].second = i;
            }

            sort(arr.begin(),arr.end());
            // cout<<arr[0].first<<" arr "<<arr[0].second<<endl;
            // cout<<arr[1].first<<" arr "<<arr[1].second<<endl;

            int maxA = INT_MIN;
            for(int i=1;i<n;i++)
            {
                maxA = max(maxA, arr[i-1].second*arr[i].second - k*(arr[i-1].first|arr[i].first));
            }
            cout<<maxA<<endl;
            
            //cout<<arr[0].second*arr[1].second-k*(arr[0].first | arr[1].first)<<endl;
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