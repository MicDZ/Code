#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
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

const int MAXN=10000+10;

int n,gap,q,pos[MAXN],a[MAXN];

set<int> s[MAXN];
map<int,int> num[MAXN];

void update(int x) {
	s[x].clear();num[x].clear();
	REP(i,(x-1)*gap+1,min(x*gap,n)) num[x][a[i]]++,s[x].insert(a[i]);
}

int ask(int l,int r) {
	set<int> ans;
	REP(i,l,min(r,pos[l]*gap)) ans.insert(a[i]);
	if(pos[l]!=pos[r]) REP(i,(pos[r]-1)*gap+1,r) ans.insert(a[i]);
	REP(i,pos[l]+1,pos[r]-1) ans.insert(s[i].begin(),s[i].end());
	
	multiset<int>::iterator it=ans.begin();
//	for(; it!=ans.end(); it++) printf("%d ",*it);DE("\n");

	return ans.size();
}

int main() {
	n=read(),gap=sqrt(n),q=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,n) pos[i]=(i-1)/gap+1,s[pos[i]].insert(a[i]);
	REP(i,1,q) {
		char op[3];
		int l,r;
		scanf("%s",op+1);
		l=read(),r=read();
		if(op[1]=='Q') printf("%d\n",ask(l,r));
		else {
			num[pos[l]][a[l]]--;
			if(!num[pos[l]][a[l]]) s[pos[l]].erase(a[l]);
			num[pos[l]][r]++;
			s[pos[l]].insert(r);
			a[l]=r;
		}
	}
	return 0;
}

