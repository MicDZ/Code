#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define MAXN 100+10
int w[MAXN],v[MAXN],f[MAXN][MAXN*1000];

int main() {
	int t=read(),m=read();
	REP(i,1,m) {
		w[i]=read();
		v[i]=read();
	}
	REP(i,1,t) DREP(t,w[])
}
