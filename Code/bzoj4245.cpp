#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long LL;
LL a[maxn];
int n,m;
int vis[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]^=a[i-1];
	LL ans=0;
	for(int j=62;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++)if(!(a[i]&(1LL<<j)))			
			if(!vis[i])cnt++;
		if(!(a[n]&(1LL<<j))&&cnt>=m){
			for(int i=1;i<=n;i++)if(a[i]&(1LL<<j))
				vis[i]=1;	
		}else ans|=1LL<<j;
		
	}cout<<ans<<endl;
	return 0;
}
