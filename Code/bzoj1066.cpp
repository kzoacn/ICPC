#include<bits/stdc++.h>
using namespace std;
const int maxn=20*20*2+5;
int mp[21][21][2];
int n,m,D;
int s,t;
int h[21][21];
struct edge{
	int u,v,c,f;
	edge(int _u,int _v,int _c,int _f){
		u=_u;v=_v;c=_c;f=_f;
	}
};
vector<edge>E;
vector<int>G[maxn];
void add(int u,int v,int c){
//	cerr<<u<<"->"<<v<<" cap="<<c<<endl;
	E.push_back(edge(u,v,c,0));
	G[u].push_back(E.size()-1);
	E.push_back(edge(v,u,0,0));
	G[v].push_back(E.size()-1);
}
int cur[maxn];
int d[maxn];

bool bfs(){
	queue<int>q;q.push(s);
	memset(d,-1,sizeof d);
	d[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<G[u].size();i++){
			edge e=E[G[u][i]];
			if(e.c==e.f)continue;
			if(d[e.v]==-1){
				d[e.v]=d[u]+1;
				q.push(e.v);
			}
		}
	}return d[t]!=-1;
}
int dfs(int u,int a){
	if(u==t)return a;
	if(!a)return 0;
	int flow=0,f=0;
	for(int &i=cur[u];i<G[u].size();i++){
		edge e=E[G[u][i]];
		if(e.c==e.f)continue;
		if(d[e.v]==d[u]+1){
			f=dfs(e.v,min(a,e.c-e.f));
			E[G[u][i]].f+=f;
			E[G[u][i]^1].f-=f;
			flow+=f;a-=f;if(!a)break;
		}
	}
	if(!flow)d[u]=-1;
	return flow;
}
int dinic(){
	int flow=0;
	while(bfs()){
		int x=0;
		memset(cur,0,sizeof cur);
		while(x=dfs(s,INT_MAX)){
			flow+=x;
			memset(cur,0,sizeof cur);
		}
	}
	return flow;
}
int dis(int x1,int y1,int x2,int y2){return abs(x1-x2)+abs(y1-y2);}
int main(){
	scanf("%d%d%d",&n,&m,&D);
	int tot=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		mp[i][j][0]=++tot;
		mp[i][j][1]=++tot;
	}
	s=0;t=++tot;
	
	for(int i=1;i<=n;i++){
		static char str[21];
		scanf("%s",str+1);
		for(int j=1;j<=m;j++){
			h[i][j]=str[j]-'0';
			if(h[i][j])add(mp[i][j][0],mp[i][j][1],h[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(h[i][j])
	for(int k=0;k<=n+1;k++)
	for(int l=0;l<=m+1;l++){
		if(dis(i,j,k,l)<=D){
			if(k==0||k==n+1||l==0||l==m+1){
				add(mp[i][j][1],t,23333);
			}else{
				if(h[k][l])add(mp[i][j][1],mp[k][l][0],23333);
			//	fprintf(stderr,"(%d,%d)->(%d,%d)\n",i,j,k,l);
			}
		}
	}
	
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		static char str[21];
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
			if(str[j]=='L')
				add(s,mp[i][j][0],1),cnt++;
	}
	int ans=dinic();
	cout<<cnt-ans<<endl;
	return 0;
}
