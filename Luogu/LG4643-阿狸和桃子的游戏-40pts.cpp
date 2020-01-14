#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
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

const int MAXN=10000+10,MAXM=10000+10;

int a[MAXN],head[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int num(int x) {
	int cnt=0;
	while(x) {
		if(x&1) cnt++;
		x>>=1;
	}
	return cnt;
}

int main() {
	int n=read(),m=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	int ans1=0,ans2=0;
	REP(i,1,131071) {
		ans1=0,ans2=0;
		if(num(i)!=n/2) continue;
		
		DE("%d\n",i);
		REP(j,1,n) {
			if(i&(1<<j)) {
				ans1+=a[j];
				for(int k=head[j]; k; k=_next[k]) {
					int v=to[k];
					if(i&(1<<v)) ans1+=weigh[i];
				}
			}
			else {
				ans2+=a[j];
				for(int k=head[j]; k; k=_next[k]) {
					int v=to[k];
					if(!(i&(1<<v))) ans2+=weigh[i];
				}
			}
		}
	}

	cout<<ans2-ans1<<endl;
	return 0;
}

