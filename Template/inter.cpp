#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[1001];
LL var[1001];
LL A[101][101];
LL ans[101];
LL base=720*720;
LL tmp[101];
LL F[101];
LL D[101];
struct line{
	char var;
	char ran;
	int dep;
	bool lag;
	void deb(){
		printf("%c %c %d %d\n",var,ran,dep,lag);
	}
}L[1001];
int For(int l,int r);
int solve(int l,int r){
	int c=l;
	while(c+1<=r&&L[c+1].dep>L[l].dep)c++;
	int ans=For(l,c);
	if(c+1<=r)
		ans+=solve(c+1,r);
	return ans;
}
int For(int l,int r){
	if(L[l].lag)return 1;
	int ran=isdigit(L[l].ran)?L[l].ran-'0':var[L[l].ran-'a'];
	int ans=0;
	for(var[L[l].var-'a']=0;var[L[l].var-'a']<ran;var[L[l].var-'a']++)
		ans+=solve(l+1,r);
	return ans;
}
int T;

int main(){
	freopen("fygon.in","r",stdin);
	freopen("fygon.out","w",stdout);
	while(gets(s)){
		T++;
		int b=0;
		while(s[b]==' ')b++;
		L[T].dep=b/4;
		if(s[b]=='l'){
			L[T].lag=1;
		}else{
			L[T].var=s[b+4];
			L[T].ran=s[b+15];
		}
//		L[T].deb();
	}
	for(var['n'-'a']=0;var['n'-'a']<=6;var['n'-'a']++){
		F[var['n'-'a']]=solve(1,T);
//		cerr<<F[var['n'-'a']]<<endl;
	}

	for(int i=0;i<=6;i++){
		A[i][0]=F[i];
		D[i]=1;
		for(int j=0;j<=6;j++){
			if(i==j)continue;
			for(int k=1;k<=6;k++)
				tmp[k]=A[i][k-1]+A[i][k]*(-j);
			A[i][0]=A[i][0]*(-j);
			for(int k=1;k<=6;k++)
				A[i][k]=tmp[k];
			D[i]*=(i-j);
		}
//		for(int j=0;j<=6;j++)
//			printf("%d ",A[i][j]);puts("");
	}
	for(int i=0;i<=6;i++){
		for(int j=0;j<=6;j++){
			ans[i]+=A[j][i]*(518400/D[j]);
		}
	}
	printf("(%I64d%+I64d*n%+I64d*n*n%+I64d*n*n*n%+I64d*n*n*n*n%+I64d*n*n*n*n*n%+I64d*n*n*n*n*n*n)*1/518400\n",ans[0],ans[1],ans[2],ans[3],ans[4],ans[5],ans[6]);
	return 0;
}
