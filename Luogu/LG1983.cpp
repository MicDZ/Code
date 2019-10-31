#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=1000+10;

int top[MAXN][MAXN],a[MAXN],book[MAXN],in[MAXN],s[MAXN];

int main() {
	int n=read(),m=read();
	REP(i,1,m) {
		int s=read();
		memset(book,0,sizeof(book));
		REP(j,1,s) a[j]=read(),book[a[j]]=1;
		REP(j,a[1],a[s]) if(!book[j]) REP(k,1,s) if(!top[j][a[k]]) top[j][a[k]]=1,in[a[k]]++;
	}

	memset(book,0,sizeof(book));
	int ans=0;
	while(1) {
		int cnt=0;
		REP(i,1,n) if(!in[i]&&(!book[i])) {
			cnt++;
			s[cnt]=i;
			book[i]=1;
		}
		REP(i,1,cnt) REP(j,1,n) if(top[s[i]][j]) top[s[i]][j]=0,in[j]--;
		if(!cnt) break;
		ans++;
	}
	
	printf("%d\n",ans);
	return 0;
}
if(u==_root&&u==son_num>=2) flag[u]=1;
			if(u!=_root&&low[v]>=dfn[u]) flag[u]=1;
