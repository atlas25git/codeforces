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
    

    //taking input from unknown size
    vector<int> num(istream_iterator<int>(cin),{});
    for(auto x: num)cout<<x<<" ";
    //stdin::
    //1 2 3 4 15
    //stdout::
    //1 2 3 4 15 



    //taking input from some char seperated string
    string s;
    getline(cin,s);
    //cout<<s;
    vector<int> v;
    stringstream so(s);
    for(int i;so>>i;){
        v.push_back(i);
        if(so.peek() == ',')
            so.ignore();
    }
    for(auto x: v)cout<<x<<" ";
    //stdin::
    //1,2,32,69,7
    //stdout::
    //1 2 32 69 7 


        
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
            solve();
        }
    }       