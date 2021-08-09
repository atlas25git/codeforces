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
        vector<pair<int,int>>a(n);
        for(i=0;i<n;i++)
            cin>>a[i].F,
            a[i].S = i;

        if(k==n)
        {
            cout<<"YES"<<endl;
            return;
        }

        if(k==1)
        {
            for(i=1;i<n;i++)
               { 
                   if(a[i].F<a[i-1].F)
                    {
                        cout<<"NO"<<endl;
                        return;
                    };
               }

            cout<<"YES"<<endl;
            return;
                
        }

    sort(a.begin(),a.end());
    // cout<<"###################################"<<endl;
    // for(auto x: a)cout<<x.F<<" "<<x.S<<endl;
    // cout<<endl;
    //``3
    int df = n-k;
    cnt=0;
    for(i=1;i<n;i++)
        {
            if((a[i].S - a[i-1].S) == 1)
            {   
                cnt++;
                //condn found check if the seq len is till n-k
                // int x=i-1;
                // int cnt = 0;
                // for(int z=0;z<df;z++)
                //     {
                //         if((a[x+1+z].S-a[x+z].S) == 1)
                //             cnt++;
                //     }
                //cout<<"c "<<cnt<<endl;
                if(cnt == df)
                {
                    cout<<"YES"<<endl;
                    return;
                }
                //i+=cnt;
            }
        }

    cout<<"NO"<<endl;
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
            int t;
            cin>>t;
            while(t--)
            solve();
        }
    }