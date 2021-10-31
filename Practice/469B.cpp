#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
const int N=110;
int p,q,l,r,ans,tl,tr;
int pool[10000],pa[10000],pb[10000],*vis=pool+5000,*a=pa+5000,*b=pb+5000;
int main() {
	scanf("%d%d%d%d",&p,&q,&l,&r);
	rep(i,0,p) {
		scanf("%d%d",&tl,&tr);
		rep(j,tl,tr) a[j]=1;
	}
	rep(i,0,q) {
		scanf("%d%d",&tl,&tr);
		rep(j,tl,tr) b[j]=1;
	}
	rep(i,0,1001) rep(j,0,1001) if (a[i]&&b[j]) vis[i-j]=vis[i-j-1]=1;
	rep(k,l,r+1) ans+=vis[k]|vis[k-1];
	printf("%d\n",ans);
}