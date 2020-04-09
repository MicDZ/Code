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

const ll INF=0x3f3f3f,MAXN=200000000+10;

char s[MAXN],t[MAXN],lens,lent;

int f[MAXN],g[MAXN];

int main() {
    scanf("%s",s+1);
    scanf("%s",t+1);
    
    lens=strlen(s+1),lent=strlen(t+1);
    int pos=1;
    REP(i,1,lens) if(s[i]==t[pos]) f[pos]=i,pos++;
    pos=lent;
    DREP(i,lens,1) if(s[i]==t[pos]) g[pos]=i,pos--;
    
    int ans=0;
    ans=max(ans,max(lens-f[lent]-1,g[0])); 
    g[lent+1]=lens+1;
    REP(i,1,lent) ans=max(ans,g[i+1]-f[i]-1);

    printf("%d\n",ans);
    return 0;
}