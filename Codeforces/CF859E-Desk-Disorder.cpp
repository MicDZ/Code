#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
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

const int MAXN=200000+10,MOD=1e9+7;

int fa[MAXN],size[MAXN],selfloop[MAXN],loop[MAXN];

int find(int x) {
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
int link(int x,int y) {
	fa[find(x)]=find(y);
}

int main() {
	int n=read();
	
	REP(i,1,(n<<1)) fa[i]=i,size[i]=1;
	
	ll ans=1;
	
	REP(i,1,n) {
		int u=read(),v=read();
		if(u==v) {selfloop[u]=1;continue;}
		u=find(u),v=find(v);
		if(u!=v) fa[u]=v,selfloop[v]|=selfloop[u],size[v]+=size[u];
		else loop[u]=1;
	}

	REP(i,1,(n<<1)) 
		if(find(i)==i&&!selfloop[i]) {
			if(loop[i]) ans=1ll*ans*2;
			else ans=1ll*ans*size[i];
			ans%=MOD;
		}
	printf("%lld\n",ans);
	return 0;
}
