#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct LCT{
    struct node{
        bool rev;
        int val,all,any;
        node *f,*c[2];
        bool d(){return this==f->c[1];}
        bool rt(){return !f||(f->c[0]!=this&&f->c[1]!=this);}
        void sets(node *x,int d){pd();if(x)x->f=this;c[d]=x;rz();}
        void makerv(){rev^=1;swap(c[0],c[1]);}
        void makeal(){val=1;any=1;}
        void pd(){
            if(rev){
                if(c[0])c[0]->makerv();
                if(c[1])c[1]->makerv();
                rev=0;
            }
            if(all){
				if(c[0])c[0]->makeal();
				if(c[1])c[1]->makeal();
				all=0;
			}
        }
        void rz(){
			 any=val;
			 if(c[0])any|=c[0]->val;
			 if(c[1])any|=c[1]->val;
        }
    }nd[maxn];
    void rot(node *x){
        node *y=x->f;if(!y->rt())y->f->pd();
        y->pd();x->pd();bool d=x->d();
        y->sets(x->c[!d],d);
        if(y->rt())x->f=y->f;
        else y->f->sets(x,y->d());
        x->sets(y,!d); 
    }
    void splay(node *x){
        while(!x->rt())
            if(x->f->rt())rot(x);
            else if(x->d()==x->f->d())rot(x->f),rot(x);
            else rot(x),rot(x);
    }
    node* access(node *x){
        node *y=0;
        for(;x;x=x->f){
            splay(x);
            x->sets(y,1);y=x;
        }return y;
    }
    void makert(node *x){
        access(x)->makerv();
        splay(x);
    }
    void link(node *x,node *y){
        makert(x);
        x->f=y;
        access(x);
    }
    void cut(node *x,node *y){
        makert(x);access(y);splay(y);
        y->c[0]=x->f=0;
        y->rz();
    }
    void link(int x,int y){link(nd+x,nd+y);}
    void cut(int x,int y){cut(nd+x,nd+y);}
    bool con(node *x,node *y){
		makert(x);
		access(y);
		splay(y);
		while(x->f)x=x->f;
		return x==y;
	}
	bool con(int x,int y){return con(nd+x,nd+y);}
}T;
struct qes{
	int ty,u,v;
}Q[maxn];
int n,m,q;
struct ed{
	int u,v;
	bool operator<(const ed &o)const{
		return u<o.u?u<o.u:v<o.v;
	}
};
multiset<ed>S;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		S.insert((ed){u,v});
	}
	for(int i=1;i<=q;i++){
		char op[2];scanf("%s",op);
		int u,v;scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		if(*op=='Z'){
			S.erase(S.find((ed){u,v}));
			Q[i].ty=-1;
			Q[i].u=u;
			Q[i].v=v;
		}else{
			Q[i].ty=1;
			Q[i].u=u;
			Q[i].v=v;
		}
	}
	static int anss[maxn];
	for(int i=q;i>=1;i--){
		if(Q[i].ty==1){
			
		}else{
		
		}
	}
	reverse(anss+1,anss+1+anss[0]);
	for(int i=1;i<=anss[0];i++)
		puts(anss[i]?"Yes":"No");
	return 0;
}
