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

const ll INF=0x3f3f3f,MAXN=200+10;

char s[MAXN],t[MAXN],now[MAXN];
int lens,lent;

bool check(int l,int r) {
    int cnt=0;
    REP(i,1,l-1) now[++cnt]=s[i];
    REP(i,r+1,lens) now[++cnt]=s[i];
    
    int find=1;
    //printf("cnt: %d\n",cnt);
    REP(i,1,cnt) {
        if(now[i]==t[find]) find++;
    }
    if(find==lent+1) return 1;
    return 0;
}

int main() {
    scanf("%s",s+1);
    scanf("%s",t+1);
    
    lens=strlen(s+1),lent=strlen(t+1);

    int ans=0;

    REP(i,1,lens) REP(j,i,lens) {
        if(check(i,j)) {
            ans=max(ans,j-i+1);
            //printf("%d %d\n",i,j);
        }
    }   
    printf("%d\n",ans);
	return 0;
}

