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

    //cout<<"CALLED";
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    
    int ar[4];
    int max1=INT_MIN,max2=INT_MIN;

    for(int i=0;i<4;i++)
    {
        cin>>ar[i];
        if(i<2){
            max1=max(max1,ar[i]);
        }
        else{
            max2=max(max2,ar[i]);
        }
    }
    sort(ar,ar+4);

    if(max1==ar[3] && max2==ar[2])cout<<"YES"<<endl;
    else if(max1==ar[2] && max2==ar[3])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
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