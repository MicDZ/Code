#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
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

const int MAXN=1000000+10;

set<pair<int,int> > g[MAXN],s;

int main() {
	int n=read(),k=read();
	REP(i,1,n-1) {
		int u=read(),v=read(),w=read();
		g[u].insert(make_pair(v,w));
		g[v].insert(make_pair(u,w));
	}
	REP(i,1,n) 
		if(g[i].size()==1) s.insert(make_pair((*g[i].begin()).second,i));
	int ans=0,i,j;
	while(n>k||s.size()>2) {
		ans=(*s.begin()).first,i=(*s.begin()).second;
		s.erase(s.begin());
		j=(*g[i].begin()).first;
		g[j].erase(g[j].lower_bound(make_pair(i,0)));
		n--;
		if(g[j].size()<=1) s.insert(make_pair((*g[j].begin()).second+ans,j));
	}

	printf("%d\n",ans);
	return 0;
}
