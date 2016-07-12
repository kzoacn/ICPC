#include<bits/stdc++.h>
using namespace std;
int range(int l,int r){return rand()%(r-l)+l;}
int main(){
	int n=20,m=20,d=range(1,5);
	printf("%d %d %d\n",n,m,d);
	static int h[23][23];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		printf("%d",h[i][j]=rand()%3>0?0:range(0,3));
		puts("");
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		printf("%c",h[i][j]?(range(0,2)?'L':'.'):'.');
		puts("");
	}
}
