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

const ll INF=0x3f3f3f,MAXN=150000+10;

int a[MAXN],have[MAXN];

int main() {
    int n=read();
    REP(i,1,n) a[i]=read();
    sort(a+1,a+1+n);
    int ans=0;
    REP(i,1,n) {
        if(have[a[i]-1]||a[i]-1<=0) {
            if(have[a[i]]) {
                if(have[a[i]+1]) continue;
                else have[a[i]+1]=1,ans++;
            }
            else have[a[i]]=1,ans++;
        }
        else have[a[i]-1]=1,ans++;
    }

    printf("%d\n",ans);
	return 0;
}

