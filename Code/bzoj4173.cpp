#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
typedef long long LL;
LL phi(LL x){
    LL ans=x;
    for(LL i=2;i*i<=x;i++){
        if(x%i==0){
            ans=ans/i*(i-1);
            while(x%i==0)x/=i;
        }
    }if(x>1)ans=ans/x*(x-1);
    return ans;
}
int main(){
    LL n,m;
    cin>>n>>m;
    cout<<(phi(n)%mo)%mo*(phi(m)%mo)%mo*(n%mo)%mo*(m%mo)%mo<<endl;
    return 0;
}
