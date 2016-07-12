#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+233;
int n,k;
LL w[maxn];
priority_queue<pair<LL,LL>,vector<pair<LL,LL> >,greater<pair<LL,LL> > >q;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
	while((n-1)%(k-1)!=0)n++;
	for(int i=1;i<=n;i++)q.push(make_pair(w[i],0));
	LL ans1=0,ans2=0;
	while(q.size()>1){
		LL res=0,dep=0;
		for(int i=0;i<k;i++){
			res+=q.top().first;
			dep=max(q.top().second,dep);
			q.pop();
		}
		ans1+=res;
		ans2=max(ans2,dep+1);
		q.push(make_pair(res,dep+1));
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	return 0;
}
