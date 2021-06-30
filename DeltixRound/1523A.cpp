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
        
        //basically the question is of the kind where they are deceiving
        //readers in the terms of complexity, here the solution could be formulated in O(n2)
        //since the iterations would only run till n, whose sum over all the test cases is 
        //ascertained to not be more than 10^4

        cin>>n>>m;
        string s;
        cin>>s;
        //n^2 solution
        while(m)
        {   
               string s2=s;
               int d=0;
               for(int i=0;i<n;i++)
               {
                   if(s[i]=='0'){
                       int c=0;
                       if(i-1>-1 && s[i-1]=='1')++c;
                       if(i+1<n && s[i+1]=='1')++c;
                       if(c==1)s2[i]='1',d++;
                   }
               } 
            if(!d)break;
            m--;
            s=s2;
        }
        cout<<s<<endl;

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