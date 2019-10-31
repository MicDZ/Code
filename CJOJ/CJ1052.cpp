// luogu-judger-enable-o2
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

const int MAXN=45+5;

int ans=0,st[MAXN],ed[MAXN];

void move(int id,int from,int to) {
    if(from==to) return;
    DREP(i,id-1,1) {
        if(st[i]==from) move(i,st[i],6-st[i]-to);
        if(st[i]==to) move(i,st[i],6-st[i]-from);
    }
    st[id]=to;

    printf("move %d from %c to %c\n",id,from+'A'-1,to+'A'-1);
    ans++;
}

int main() {
    int n=read();
    REP(i,1,3) {int x=read();REP(j,1,x)st[read()]=i;}
    REP(i,1,3) {int x=read();REP(j,1,x)ed[read()]=i;}

    DREP(i,n,1) move(i,st[i],ed[i]);
    printf("%d\n",ans);
    return 0;
}

