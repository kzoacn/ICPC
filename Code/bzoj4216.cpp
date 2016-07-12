#include<cstdio>
using namespace std;
typedef long long LL;
LL abs(LL x){return x>0?x:-x;}
void swap(int &l,int &r){int t=l;l=r;r=t;}
int n,m,t;
LL la=0;
int a[500001];
const int K=110;
LL sum[500001/K];

LL S(int x){
    LL ans=0;
    while(x>=1&&x%K!=0){
        ans+=a[x];
        x--;
    }
    if(x&&x%K==0){
		ans+=a[x];
		ans+=sum[(x-1)/K];
	}
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i/K]+=a[i];
    }
    for(int i=1;i<=n/K;i++)sum[i]+=sum[i-1];
    while(m--){
        int l,r;scanf("%d%d",&l,&r);
        if(t)l=(l^abs(la))%n+1,r=(r^abs(la))%n+1;
        if(l>r)swap(l,r);
        printf("%lld\n",la=(S(r)-S(l-1)));
    }
    return 0;
}
