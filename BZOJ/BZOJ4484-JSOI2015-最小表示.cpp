#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<queue>
#include<vector>
using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=30000+10,MAXM=100000+10;

bitset<MAXN> s[MAXN];

int head[MAXN],_next[MAXM],to[MAXM],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int in[MAXN],f[MAXN];

vector<int> g,tmp[MAXN];
queue<int> q;

bool cmp(int a,int b) {return f[a]>f[b];}

int main() {
	freopen("1.in","r",stdin);
	int n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v);
		tmp[u].push_back(v);
		in[v]++;
	}
	
	REP(i,1,n) if(!in[i]) q.push(i);
	
	while(!q.empty()) {
		int u=q.front();q.pop();g.push_back(u);
		for(int i=head[u]; i; i=_next[i]) {
			in[to[i]]--;
			if(in[to[i]]==0) q.push(to[i]);
		}
	}
	
	int ans=0;
	DREP(i,n-1,0) {
		int u=g[i];s[u][u]=1;
		sort(tmp[u].begin(),tmp[u].end(),cmp);
		REP(i,0,(int)tmp[u].size()-1) {
			f[u]=max(f[tmp[u][i]]+1,f[u]);
			if(s[u][tmp[u][i]]) ans++;
			else s[u]|=s[tmp[u][i]];
		}
	}

	printf("%d\n",ans);
	return 0;
}

