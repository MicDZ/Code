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

const int MAXN=500000+10;

int n,m,s[MAXN],tag[MAXN],pos[MAXN];

vector<int> g[MAXN];

void update(int x) {
	g[x].clear();
	REP(i,(x-1)*m+1,min(x*m,n)) g[x].push_back(s[i]);
	sort(g[x].begin(),g[x].end());
}

void change(int l,int r,int c) {
	REP(i,l,min(r,pos[l]*m)) s[i]+=c;
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) s[i]+=c;
	REP(i,pos[l]+1,pos[r]-1) tag[i]+=c;
	update(pos[l]),update(pos[r]);
}

int ask(int l,int r,int c) {
	int ans=-1;
	REP(i,l,min(r,pos[l]*m)) if(s[i]+tag[pos[i]]<c&&s[i]+tag[pos[i]]>ans) ans=s[i]+tag[pos[i]];
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*m+1,r) if(s[i]+tag[pos[i]]<c&&s[i]+tag[pos[i]]>ans) ans=s[i]+tag[pos[i]];

	REP(i,pos[l]+1,pos[r]-1) {
		vector<int>::iterator it=lower_bound(g[i].begin(),g[i].end(),c-tag[i]);
		if(it==g[i].begin()) continue;
		int p=it-g[i].begin()-1;if(p==-1) continue;
		if(g[i][p]+tag[i]<c&&g[i][p]+tag[i]>ans) ans=g[i][p]+tag[i];
	}
	return ans;
}

int main() {
	file("data");
	n=read(),m=sqrt(n);
	REP(i,1,n) s[i]=read();
	REP(i,1,n) pos[i]=(i-1)/m+1;
	
	REP(i,1,n) g[pos[i]].push_back(s[i]);
	REP(i,1,m) sort(g[i].begin(),g[i].end());
	REP(i,1,n) {
		int op=read(),l=read(),r=read(),c=read();
		if(op==0) change(l,r,c);
		if(op==1) printf("%d\n",ask(l,r,c));
	}
	return 0;
}


