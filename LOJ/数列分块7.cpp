#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1000000+10,MOD=10007;

int n,m,pos[MAXN],s[MAXN],tag1[MAXN],tag2[MAXN];

void pushdown(int x) {
	REP(i,(x-1)*m+1,min(x*m,n)) s[i]=(s[i]*tag2[x]%MOD+tag1[x])%MOD;
	tag2[x]=1;tag1[x]=0;
}

void add(int l,int r,int c) {
	pushdown(pos[l]);
	REP(i,l,min(r,pos[l]*m)) s[i]=(s[i]+c)%MOD;
	if(pos[l]!=pos[r]) {pushdown(pos[r]);REP(i,(pos[r]-1)*m+1,r) s[i]=(s[i]+c)%MOD;}
	REP(i,pos[l]+1,pos[r]-1) tag1[i]=(tag1[i]+c)%MOD;
}

void times(int l,int r,int c) {
	pushdown(pos[l]);
	REP(i,l,min(r,pos[l]*m)) s[i]=(s[i]*c)%MOD;
	if(pos[l]!=pos[r]) {pushdown(pos[r]);REP(i,(pos[r]-1)*m+1,r) s[i]=(s[i]*c)%MOD;}
	REP(i,pos[l]+1,pos[r]-1) tag1[i]=(tag1[i]*c)%MOD,tag2[i]=(tag2[i]*c)%MOD;
}

int ask(int x) {
	return (s[x]*tag2[pos[x]]%MOD+tag1[pos[x]])%MOD;
}

signed main() {
	file("a42");
	n=read(),m=sqrt(n);
	REP(i,1,n) s[i]=read();
	REP(i,1,n) pos[i]=(i-1)/m+1;
	REP(i,1,pos[n]) tag2[i]=1,tag1[i]=0;
	REP(i,1,n) {
		int op=read(),l=read(),r=read(),c=read();
		if(op==0) add(l,r,c); 
		else if(op==1) times(l,r,c);
		else printf("%d\n",ask(r));
		REP(j,1,pos[n]) pushdown(i);
	}
	return 0;
}
