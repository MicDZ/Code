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

const int MAXN=100000+10;

int n,m,a[MAXN],pos[MAXN],s[MAXN],tag[MAXN];

void change(int l,int r,int c) {
	REP(i,l,min(r,pos[l]*m)) s[i]+=c;
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) s[i]+=c;
	REP(i,pos[l]+1,pos[r]-1) tag[i]+=c;
}

int main() {
	n=read(),m=sqrt(n);
	REP(i,1,n) s[i]=read();
	REP(i,1,n) pos[i]=(i-1)/m+1;
	REP(i,1,n) {
		int op=read(),l=read(),r=read(),c=read();
		if(op==0) change(l,r,c);
		else printf("%d\n",tag[pos[r]]+s[r]);
	}
	return 0;
}


