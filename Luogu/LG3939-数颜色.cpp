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

const int MAXN=300000+10;

int n,m,pos[MAXN],s[MAXN],tag[MAXN];

void update(int x) {
	if(tag[x]!=-1) REP(i,(x-1)*m+1,x*m) s[i]=tag[x];
	tag[x]=-1;
}

void change(int l,int r,int c) {
	REP(i,l,min(r,pos[l]*m)) s[i]=c,tag[pos[l]]=-1;
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) s[i]=c,tag[pos[r]]=-1;
	REP(i,pos[l]+1,pos[r]-1) tag[i]=c;
}

int ask(int l,int r,int c) {
	int ans=0;update(pos[l]),update(pos[r]);
	REP(i,l,min(r,pos[l]*m)) if(s[i]==c) ans++;
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) if(s[i]==c) ans++;
	
	REP(i,pos[l]+1,pos[r]-1) 
	if(tag[i]!=-1) {
		if(tag[i]==c) ans+=(i*m-((i-1)*m+1)+1);
	}
	else REP(j,(i-1)*m+1,min(i*m,n)) if(c==s[j]) ans++;
	
	return ans;
}

int main() {
	file("data");
	n=read(),m=sqrt(n);
	int q=read();
	memset(tag,-1,sizeof(tag));
	REP(i,1,n) s[i]=read();
	REP(i,1,n) pos[i]=(i-1)/m+1;
	REP(i,1,q) {
		int op=read();
		if(op==1) {
			int l=read(),r=read(),c=read();
			printf("%d\n",ask(l,r,c));
		}
		else {
			int x=read();
			swap(s[x],s[x+1]);
			update(pos[x]),update(pos[x+1]);
		}
	}

	return 0;
}
