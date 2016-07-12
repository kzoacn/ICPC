#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int a[maxn];
int bs[maxn],sz;
int n,m;
void add(int x){
	int X=x;
	for(int i=0;i<sz;i++){
		x%=bs[i];
	}
	if(x!=0)bs[sz++]=X;
}
bool ok(long long x){
	for(int i=0;i<sz;i++){
		x%=bs[i];
		if(!x)return true;
	}return false;
}
int main(){
	scanf("%d",&n);
	int x=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),x=__gcd(x,a[i]);
	
	scanf("%d",&m);
	while(m--){
		long long b;
		scanf("%lld",&b);
		puts(b%x==0?"Yes":"No");
	}
	return 0;
}
