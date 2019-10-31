#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)

int read() {
    int ch=getchar(),x=0,f=1;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define MAXN 200000+10
#define INF 0x3f3f3f3f
int a[MAXN];

int main() {
    int n=read();
    REP(i,1,n) a[i]=read();
    int maxx=-INF,minn=a[1];

    REP(i,2,n) {
        maxx=max(maxx,a[i]-minn);
        minn=min(minn,a[i]);
    }

    printf("%d\n",maxx);
    return 0;
}
