#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=30000+10;

int fa[MAXN],d[MAXN],s[MAXN];

int find(int x) {
	if(fa[x]==x) return fa[x];
	int t=find(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=t;
}

void link(int x,int y) {
	int xx=find(x),yy=find(y);
	if(xx!=yy) {
		fa[xx]=yy;
		d[xx]=s[yy];
		s[yy]+=s[xx];
	}
}

int main() {
	REP(i,1,30000) {fa[i]=i;d[i]=0;s[i]=1;}
	int p=read();
	
	REP(i,1,p) {
		char op;cin>>op;
		if(op=='M') {
			int x=read(),y=read();
			link(x,y);
		}
		else if(op=='C') {
			int x=read();find(x);
			printf("%d\n",d[x]);
		}
	}

	return 0;
}
