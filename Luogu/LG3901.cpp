#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=100000+10;
struct edge{
	int l,r,id;
}ask[MAXN];

bool cmp(edge a,edge b) {
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}

int a[MAXN];

int main() {
	int n=read(),q=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,q) ask[i].l=read(),ask[i].r=read(),ask[i].id=i;
	sort(ask+1,ask+1+n,cmp);
	
}
