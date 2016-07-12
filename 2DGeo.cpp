#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const double pi=acos(-1);
const double eps=1e-8;
int sgn(double x){return (x>eps)-(x<-eps);}
int sgn(double x,double y){return sgn(x-y);}
double sqr(double x){return x*x;}
struct L;
struct P{
	double x,y;
	P(double _x,double _y){
		x=_x;y=_y;
	}
	P(){}
	void read(){scanf("%lf%lf",&x,&y);}
	double len()const{return sqrt(x*x+y*y);}
	double len2()const{return x*x+y*y;}
	double ang()const{return atan2(y,x);}
	P turn90(){return P(-y,x);}
	P operator!();
	void print(){printf("%.2f %.2f",x,y);}
};
P operator+(const P &a,const P &b){
	return P(a.x+a.y,b.x+b.y);
}
P operator-(const P &a,const P &b){
	return P(a.x-b.x,a.y-b.y);
}
P operator*(const P &a,double p){
	return P(a.x*p,a.y*p);
}
P operator/(const P &a,double p){
	return P(a.x/p,a.y/p);
}
P operator<<(const P &a,double r){
	return P(a.x*cos(r)-a.y*sin(r),a.x*sin(r)+a.y*cos(r));
}
double operator*(const P &a,const P &b){
	return a.x*b.y-a.y*b.x;
}
double operator^(const P &a,const P &b){
	return a.x*b.x+a.y*b.y;
}
bool operator==(const P &a,const P &b){
	return !sgn(a.x,b.x)&&!sgn(a.y,b.y);
}
bool operator<(const P &a,const P &b){
	return !sgn(a.x,b.x)?a.y<b.y:a.x<b.x;
}
P P::operator!(){
	return *this/len();
}
double operator>>(const P &a,const P &b){
	return sqrt((a-b)^(a-b));
}
double dis2(const P &a,const P &b){
	return sqr(a>>b);
}
double angle(const P &a,const P &b){
	return acos((a^b)/a.len()/b.len());
}
double S(P a,P b,P c){
	return fabs((b-a)*(c-a))/2;
}
struct L{
	P a,b;
	L(P _a,P _b){
		a=_a;b=_b;
	}
	L(){}
	P operator!(){return b-a;}
	void read(){a.read();b.read();}
};
bool operator&&(P p,L l){
	return !sgn((l.a-p)*(l.b-p));
}
bool OnSeg(P p,L l){
	return (p&&l)&&sgn((l.a-p)^(l.b-p))<=0;
}
bool SegXSeg(L l1,L l2){

}
P operator|=(P p,L l){
	return l.a+(!l)*((p-l.a)^(!!l));
}
double operator>>(P p,L l){
	return p>>(p|=l);
}
bool operator||(L l1,L l2){
	return sgn((!l1)^(!l2).turn90())==0;
}
bool operator==(L l1,L l2){
	return (l1||l2)&&(l1.a&&l2);
}
P operator&(L l1,L l2){
	double s1=(l1.b-l1.a)*(l2.a-l1.a);
	double s2=(l1.b-l1.a)*(l2.b-l1.a);
	return (l2.a*s2-l2.b*s1)/(s2-s1);
}
struct C{
	P O;
	double r;
};
int main(){
	return 0;
}

