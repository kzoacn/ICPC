#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int n;
struct arr{
	int a[maxn*2];
	int &operator[](int x){return a[min(max(x,-n),n)+2000];}
	void set(){memset(a,0xaf,sizeof a);}
};
arr f;
int main(){
	scanf("%d",&n);	
	f.set();
	f[1]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(x)
		for(int j=n;j>=-n;j--){
			f[j+x-1]=max(f[j+x-1],f[j]+y);
			if(j+x-1>=0)ans=max(ans,f[j+x-1]);
		}else
		for(int j=-n;j<=n;j++){
			f[j+x-1]=max(f[j+x-1],f[j]+y);
			if(j+x-1>=0)ans=max(ans,f[j+x-1]);
		}	
	}
	cout<<ans<<endl;
	return 0;
}
