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
    cin>>n;
    int ar[n];
    int even=0,oddfreq=0;
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        if(!(ar[i]&1))even++;
        else if(ar[i]&1 && ar[i]!=1)mp[ar[i]]++;

    }
    
    for(auto it:mp)
    {
        if(it.second > 1)
        {   m = it.second;
            while(m)
            {   
                m--;
                oddfreq+=m;
            }
        }
    }
    int oddMul=0;
    for(auto it : mp)
    {
        for(auto it1 : mp)
        {
            if(it.first!=it1.first && it1.first%it.first==0)
           {     //oddMul+=it1.second;
            // k = it1.second==0?it.second+1:it.second;
            // while(k)
            // {   
            //     k--;
            //     oddMul+=k;
            // }
            oddMul+=it1.second*it.second;
           }
        }
    }
    //oddfreq=0;
    if(even==0){
        //cout<<"if1"<<endl;
        cout<<oddfreq+oddMul<<endl;
        return;
    }
    while(even--)
    {
        ans+=n-1;
        n--;
    }
    cout<<ans+oddfreq+oddMul<<endl;
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