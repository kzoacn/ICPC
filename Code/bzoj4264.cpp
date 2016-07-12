#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m;
pair<int,int> ed[maxn];
long long ran[maxn],h[maxn];
int main(){
	srand(233);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)ran[i]=((long long)rand()<<32)|rand();
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		ed[i].first=u;
		ed[i].second=v;
	}
	sort(ed+1,ed+1+m);
	m=unique(ed+1,ed+1+m)-ed-1;
	for(int i=1;i<=m;i++){
		int u=ed[i].first;
		int v=ed[i].second;
		if(u==v)continue;
		h[u]^=ran[v];
		h[v]^=ran[u];
	}
	long long ans=0;
	for(int i=1;i<=m;i++){
		int u=ed[i].first;
		int v=ed[i].second;
		if(u==v)continue;
		if((h[u]^ran[v])==(h[v]^ran[u]))
			ans++;
	}
	sort(h+1,h+1+n);
	long long cnt=0;
	for(int i=1;i<=n;i++){
        cnt++;
        if(i==n||h[i]!=h[i+1])
            ans+=cnt*(cnt-1)/2,cnt=0;
	}cout<<ans<<endl;
	return 0;
}
