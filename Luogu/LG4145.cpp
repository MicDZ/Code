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

const int MAXN=500000+10;

int n,m,pos[MAXN],s[MAXN],tag[MAXN],fla[MAXN],size[MAXN];

void update(int x) {
	size[x]=0;bool book=1;
	REP(i,(x-1)*m+1,x*m) {if(s[i]!=1&&s[i]!=0) book=0;size[x]+=s[i];}
	fla[x]=book;
}

void change(int l,int r) {
	REP(i,l,min(r,pos[l]*m)) s[i]=sqrt(s[i]);
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) s[i]=sqrt(s[i]);
	update(pos[l]);update(pos[r]);
	REP(i,pos[l]+1,pos[r]-1) if(!fla[i]) {
		REP(j,(i-1)*m+1,i*m) s[j]=sqrt(s[j]);
		update(i);
	}
}

int ask(int l,int r) {
	int ans=0;
	REP(i,l,min(r,pos[l]*m)) ans+=s[i];
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) ans+=s[i];
	
	REP(i,pos[l]+1,pos[r]-1) ans+=size[i];
	return ans;
}

signed main() {
	n=read(),m=sqrt(n);
	REP(i,1,n) s[i]=read();
	REP(i,1,n) pos[i]=(i-1)/m+1;
	REP(i,1,pos[n]) update(i);
	int q=read();	
	REP(i,1,q) {
		int op=read(),l=read(),r=read();
		if(l>r) swap(l,r);
		if(op==0) change(l,r);
		else printf("%d\n",ask(l,r));
	}
	
	return 0;
}

/*
4
1 2 2 3
0 1 3 1
1 1 4 4
0 1 2 2
1 1 2 4
*/
