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
       int max1=-1,mi=0;
        cin>>n;
        vector<int>arr(n);
       for(i=0;i<n;i++)
            {
                cin>>arr[i];
                
                // if(arr[i]>=max1)
                //     {
                //         if(arr[i]==max1)
                //         {
                //             int minE1 = INT_MIN;
                //             int minE2 = INT_MIN;

                //             if(mi<n-1)
                //                 minE1 = arr[mi+1];
                //             if(mi>0)
                //                 minE2 = arr[mi-1];
                //             minE1 = max(minE1,minE2);

                //             int minE22 = INT_MIN;
                //             int minE21 = INT_MIN;

                //             if(i<n-1)
                //                 minE21 = arr[i+1];
                //             if(i>0)
                //                 minE22 = arr[i-1];
                //             minE21 = max(minE21,minE22);

                //             if(minE21 > minE1)
                //             {
                //                 max1=arr[i];
                //                  mi = i;
                //             }

                //         }
                //         else
                //         {
                //         max1=arr[i];
                //         mi = i;
                //         }
                //     }

            }
            for(int i=1;i<n;i++)
                
            
            cout<<max1<<endl;

            // int min1 = INT_MIN;
            // int min2 = INT_MIN;

            // if(mi<n-1)
            //     min1 = arr[mi+1];
            // if(mi>0)
            //     min2 = arr[mi-1];
            // cout<<max1*max(min1,min2)<<endl;
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