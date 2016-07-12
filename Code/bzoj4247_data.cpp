#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int n=2000;
int range(int l,int r){return rand()%(r-l)+l;}
int main(){
	printf("%d\n",n);
	srand(time(0)^getpid());
	for(int i=1;i<=n;i++)
		printf("%d %d\n",range(0,n),range(-1000,1000));
	return 0;
}
