#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
bitset<maxn>bs[maxn];
int n,m;
void Gauss(){
	int r=0;
	for(int i=0;i<m;i++){
		int tmp=0;
		for(int j=i;j<n;j++)if(bs[j][i]){
			swap(bs[i],bs[j]);
			r=max(j,r);
			tmp=1;
			break;
		}
		if(tmp==0)return void(puts("Cannot Determine"));
		for(int j=i+1;j<n;j++)if(bs[j][i])
			bs[j]^=bs[i];
	}
	
	for(int i=m-1;i>=0;i--){
		for(int j=i+1;j<m;j++)if(bs[i][j]){
			bs[i][m]=bs[i][m]^bs[j][m];
		}
	}
	
	printf("%d\n",r+1);
	for(int i=0;i<m;i++)
	if(bs[i][m])puts("?y7M#");
	else puts("Earth");
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		static char str[2010];
		scanf("%s",str);
		reverse(str,str+strlen(str));
		bs[i]=bitset<maxn>(string(str));
		int x;scanf("%d",&x);
		bs[i][m]=x;
	}
	
//	for(int i=0;i<n;i++)
//	for(int j=0;j<=m;j++)
//	printf("%d%c",int(bs[i][j])," \n"[j==m]);
	
	Gauss();
	return 0;
} 
