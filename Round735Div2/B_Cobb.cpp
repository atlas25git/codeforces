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

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first<b.second;
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>k;
        vector<int>arr(n);
        //arr[0].first=INT_MAX;
        for(int i=0;i<n;i++)
            {  
                cin>>arr[i];
                //arr[i].second = i+1;
            }

            //sort(arr.begin(),arr.end());
            // cout<<arr[0].first<<" arr "<<arr[0].second<<endl;
            // cout<<arr[1].first<<" arr "<<arr[1].second<<endl;

            ans = INT_MIN;

            for(i=n-1;i>=0;i--)
                for(j=n-1;j>i;j--)
                    if((i+1)*(j+1) < ans)break;
                    else
                    {
                        ans = max(ans,(i+1)*(j+1)-k*(arr[i]|arr[j]));
                    }
            

            cout<<ans<<endl;
            
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