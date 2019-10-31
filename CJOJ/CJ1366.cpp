#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=200000+10;
int fa[MAXN];

int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

void link(int x,int y) {
	fa[x]=find(y);
}

int main() {
	int n,m,p;
	scanf("%d%d",&n,&m);
	
	REP(i,1,n) fa[i]=i;

	REP(i,1,m) {
		int x,y;
		scanf("%d%d",&x,&y);
		x=find(x);y=find(y);
		if(x!=y) link(x,y);
	}
	scanf("%d",&p);
	REP(i,1,p) {
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)==find(y)) puts("Yes");
		else puts("No");
	}
}
