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

const ll INF=0x3f3f3f,MAXN=100+10;

int a[MAXN],b[MAXN];

struct projects {
    int a,b;
}p[MAXN];

bool cmp(projects x,projects y) {
    if(x.a!=y.a) return x.a<y.a;
    else return x.b>y.b; 
}

int main() {
    int n=read(),r=read();
    REP(i,1,n) p[i].a=read(),p[i].b=read();

    sort(p+1,p+1+n,cmp);

    REP(i,1,n) {
        if(r>=p[i].a) r+=p[i].b;
        else {puts("NO");return 0;}
    }

    puts("YES");
	return 0;
}

