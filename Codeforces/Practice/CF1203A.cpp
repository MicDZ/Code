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

const int INF=0x3f3f3f,MAXN=200+10;

int p[MAXN];

int main() {
	int t=read();
	while(t--) {
		int n=read();
		REP(i,1,n) p[i]=read();
		bool flag1=0,flag2=0;
		
		int pos;
		REP(i,1,n) if(p[i]==1) pos=i;
		int cnt=1;
		REP(i,1,n-1) {
			int now=(i+pos)%n;
			if(now==0) now=n;
			cnt++;
			if(p[now]!=cnt) flag1=1;
			//cout<<now<<" ";
		}
	//puts("");
		cnt=n+1;

		REP(i,1,n-1) {
			int now=(pos+i+n)%n;
			if(now==0) now=n;
			cnt--;
			if(p[now]!=cnt) flag2=1;
		}

		if(!flag1||!flag2) puts("YES");
		else puts("NO"); 
	}
	return 0;
}

