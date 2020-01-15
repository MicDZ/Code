#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>

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
#define int ll
const int MAXN=500000+10;

int n,m,s[MAXN],tag[MAXN],pos[MAXN],tot[MAXN];

void change(int l,int r,int c) {
	REP(i,l,min(r,pos[l]*m)) s[i]+=c,tot[pos[i]]+=c;
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) s[i]+=c,tot[pos[i]]+=c;
	REP(i,pos[l]+1,pos[r]-1) tag[i]+=c;
}

int ask(int l,int r,int c) {
	int ans=0;
	REP(i,l,min(r,pos[l]*m)) ans=(ans+s[i]+tag[pos[i]])%(c+1);
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) ans=(ans+s[i]+tag[pos[i]])%(c+1);
	REP(i,pos[l]+1,pos[r]-1) ans=(ans+tag[i]*(min(i*m,n)-((i-1)*m+1)+1)%(c+1)+tot[i])%(c+1);
	return ans;
}

signed main() {
	file("data");
	n=read(),m=sqrt(n);
	REP(i,1,n) s[i]=read();
	REP(i,1,n) pos[i]=(i-1)/m+1;
	REP(i,1,n) tot[pos[i]]+=s[i];	
	REP(i,1,n) {
		int op=read(),l=read(),r=read(),c=read();
		if(op==0) change(l,r,c);
		if(op==1) printf("%lld\n",ask(l,r,c));
	}
	return 0;
}



