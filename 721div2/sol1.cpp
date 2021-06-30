#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;cin>>n;
        if(n==1){cout<<0<<endl;continue;}
        long long sb=0;
        long long n1=n;
        while(n1)n1=n1>>1,sb++;
        //cout<<sb;
        long long aux=1;
        while(sb-2)aux=aux|aux<<1,sb--;
        // cout<<"BP"<<__builtin_popcount(n);
        // cout<<"AUX"<<aux;
        long long ans=n-aux;
        cout<<n-ans<<endl;
 
    }
 
}
