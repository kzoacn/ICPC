#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
double a[maxn][maxn];
int n,m;
vector<int>G[maxn];
struct edge{int u,v;};
vector<edge>E;
double pE[maxn*maxn];
double pV[maxn];
double eps=1e-6;
int dcmp(double x){return (x>eps)-(x<-eps);}
void Gauss(){
	for(int i=1;i<=n;i++){
		int r=i;
		for(int j=i+1;j<=n;j++){
			if(fabs(a[j][i])>fabs(a[r][i]))
				r=j;
		}
		for(int j=0;j<=n;j++)swap(a[r][j],a[i][j]);
		for(int j=i+1;j<=n;j++){
			if(!dcmp(a[j][i]))continue;
			double t=a[j][i]/a[i][i];
			//k=0
			for(int k=i;k<=n;k++)
				a[j][k]-=a[i][k]*t;
			a[j][0]-=a[i][0]*t;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++)
			a[i][0]-=a[j][0]*a[i][j];
		a[i][0]/=a[i][i];
		pV[i]=a[i][0];
	}	
}
void build(){
	int sz=0;
	sz++;
	a[sz][0]=0;a[sz][n]=1;
	for(int i=1;i<n;i++){
		sz++;
		a[sz][i]=-1;
		for(int j=0;j<G[i].size();j++){
			int v=G[i][j];
			if(v!=n)a[sz][v]=1.0/G[v].size();
		}
	}
	a[2][0]=-1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int u,v;scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		E.push_back((edge){u,v});
	}
	build();
	Gauss();
	double ans=0;
	for(int i=0;i<E.size();i++)
		pE[i]=pV[E[i].u]/G[E[i].u].size()+pV[E[i].v]/G[E[i].v].size();
	sort(pE,pE+m);
	reverse(pE,pE+m);
	for(int i=0;i<m;i++)
		ans+=pE[i]*(i+1);
	printf("%.3lf\n",ans);
	return 0;
}
