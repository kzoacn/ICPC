#include<bits/stdc++.h>
using namespace std;
int n=4,m=3;
int range(int l,int r){return rand()%(r-l)+l;}
int main(){
	srand(time(0));
	printf("%d %d\n",m,n);
	while(n--){for(int i=0;i<m;i++)putchar(range(0,2)+'0');putchar(' ');putchar(range(0,2)+'0');puts("");}
	return 0;
}
