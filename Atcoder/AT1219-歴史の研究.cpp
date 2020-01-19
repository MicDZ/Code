#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>

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

const int MAXN=1e5+10;

struct edge {
	int l,r,id;
} ;

bool operator <(edge a,edge b) {
	return a.r<b.r;
}

vector<edge> g[MAXN];

int n,q,gap,pos[MAXN],a[MAXN],b[MAXN],cnt[MAXN];

stack<pair<ll,int> > s; 
ll ans;
void insert(int x,int op) {
	if(op) s.push(make_pair(ans,x));
	cnt[x]++;ans=max(ans,1ll*cnt[x]*b[x]);
}

void undo() {
	cnt[s.top().second]--;
	ans=s.top().first;
	s.pop();
}

ll _ans[MAXN];

int main() {
	n=read(),q=read(),gap=sqrt(n);
	REP(i,1,n) a[i]=b[i]=read();
	sort(b+1,b+1+n);int sz=unique(b+1,b+1+n)-b-1;
	REP(i,1,n) a[i]=lower_bound(b+1,b+1+sz,a[i])-b;
	REP(i,1,n) pos[i]=(i-1)/gap+1;
	REP(i,1,q) {
		int l=read(),r=read();
		g[pos[l]].push_back((edge){l,r,i});
	}
	REP(i,1,pos[n]) {
		int r=gap*i;ans=0;
		sort(g[i].begin(),g[i].end());
		REP(j,1,n) cnt[j]=0;
		REP(j,0,(int)g[i].size()-1) {
			edge k=g[i][j];int l=gap*i+1;
			if(k.r<l) REP(z,k.l,k.r) insert(a[z],1);
			else {
				while(r<k.r) insert(a[++r],0);
				while(l>k.l) insert(a[--l],1);
			}
			_ans[k.id]=ans;
			while(s.size()) undo();
		}
	}

	REP(i,1,q) printf("%lld\n",_ans[i]);
	return 0;
}

