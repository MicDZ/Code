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

const int INF=0x3f3f3f,MAXN=10000+10;

int a[MAXN],b[MAXN];

int main() {
	int t=read();
	while(t--) {
		int n=read();
        REP(i,1,4*n) a[i]=read();

        sort(a+1,a+1+4*n);
        bool flag=0;
        int cnt=1;
        //REP(i,1,4*n) printf("%d ",a[i]);puts("");
        for(int i=1; i<=4*n-1; i+=2) {
            if(a[i]==a[i+1]) b[cnt++]=a[i];
            else flag=1;
        }

        //REP(i,1,2*n) printf("%d ",b[i]);puts("");
        int times=b[1]*b[2*n];
        //printf("%d\n",times);
        REP(l,2,n) {
            int r=2*n-l+1;
            if(b[l]*b[r]!=times) flag=1;
        }

        if(flag) puts("NO");
        else puts("YES");
    }
	return 0;
}

