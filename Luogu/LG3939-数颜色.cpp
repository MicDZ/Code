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

const int MAXN=300000+10;

int a[MAXN];

vector<int> g[MAXN];

int main() {
	file("P3939_8");
	int n=read(),m=read();
	
	REP(i,1,n) a[i]=read(),g[a[i]].push_back(i);

	REP(i,1,3e5) sort(g[i].begin(),g[i].end());

	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int l=read(),r=read(),c=read();
			int numr=upper_bound(g[c].begin(),g[c].end(),r)-g[c].begin(),numl=lower_bound(g[c].begin(),g[c].end(),l)-g[c].begin();
			printf("%d\n",numr-numl);
		}
		else {
			int x=read();
			if(a[x]!=a[x+1]) {
				vector<int>::iterator it1=upper_bound(g[a[x]].begin(),g[a[x]].end(),x)-1,it2=lower_bound(g[a[x+1]].begin(),g[a[x+1]].end(),x+1);
				(*it1)++;(*it2)--;
				swap(a[x],a[x+1]);
			}
		}
	}
	return 0;
}
