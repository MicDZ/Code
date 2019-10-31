#include<bits/stdc++.h>
using namespace std;

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define REP(i,e,s) for(register int i=e; i<=s; i++)

#define MXAN (10000+10)

int s[MXAN],q;

int main () {
    int n=read(),t;
    REP(i,1,n) s[i]=read();
    t=read();
    int ans=0;
    REP(i,1,t) {
        q=read();
        REP(i,1,n)if(q==s[i]) {ans++;break;}
    }

    printf("%d\n",ans);
}
