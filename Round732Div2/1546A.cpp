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
        int a[n+1];
        vector<pair<int,int>> res;
        //storing the first array first.
        for(i=1;i<=n;i++)cin>>a[i];
        //Now for the arr B we weill store its substraction
        //with arr[i], and thus the sum would denote if they both 
        //are valid question

        for(i=1;i<=n;i++)
        {
            cin>>k;
            a[i]-=k;
            sum+=a[i];
        }

        if(sum){cout<<-1<<endl;return;}

        for(int i=1;i<=n;i++){
        //here it'll be ensured that ai>bi
        //and it'll run for levelling the overflow
            for(int j=1;j<=a[i];j++)
                for(int k=1;k<=n;k++)
                    {   
                        //the case where ak<bk
                        if(a[k]<0)
                        { 
                           res.push_back({i,k});
                           ++a[k];
                           break;
                        }
                    }
        }
    cout<<res.size()<<endl;
    for(auto x:res)cout<<x.first<<" "<<x.second<<"\n";

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