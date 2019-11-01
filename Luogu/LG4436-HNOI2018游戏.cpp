#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10,INF=0x3f3f3f;

int vis[MAXN],key[MAXN],_left[MAXN],_right[MAXN];

int n,m,p;

void calc(int x) {	
	int l,r;
	l=r=x;
	while(1) {
		while(l>1&&(!key[l-1]||(l<=key[l-1]&&r>=key[l-1]))) l--;
		while(r<n&&(!key[r]||(l<=key[r]&&r>=key[r]))) {
			r++;
			if(_left[r]) l=min(_left[r],l),r=_right[r];
		}
		if(l==1||(key[l-1]&&(l>key[l-1]||r<key[l-1]))) break;
		
	}
_left[x]=l;
		_right[x]=r;
}

int main() {
	n=read(),m=read(),p=read();

	
	REP(i,1,m) {
		int x=read(),y=read();
		key[x]=y;
	}	
	


	REP(i,1,n) _left[i]=_right[i]=i;

	DREP(i,n,1) calc(i);
	
	REP(i,1,n) {
		printf("%d %d\n",_left[i],_right[i]);
	}

	REP(i,1,p) {
		int s=read(),t=read();
		if(_right[s]>=t&&_left[s]<=t) puts("YES");
		else puts("NO");
	}
	return 0;
}
