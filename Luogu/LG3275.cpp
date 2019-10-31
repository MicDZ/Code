#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll INF=0x3f3f3f3f3f,MAXN=400000+10;

ll n,head[MAXN],_next[MAXN],to[MAXN],weigh[MAXN],cnt;

void addedge(ll u,ll v,ll w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

ll dis[MAXN],inq[MAXN],cal[MAXN];
queue<ll> q;
bool SPFA() {
	REP(i,1,n) {
		inq[i]=1;
		q.push(i);
		dis[i]=1;
	}
	
	while(!q.empty()) {
		ll u=q.front();q.pop();
		inq[u]=0;
		

		for(ll i=head[u]; i; i=_next[i]) {
			ll v=to[i];
			
			if(dis[v]<dis[u]+weigh[i]) {
				//DEBUG(v);		
				cal[v]++;if(cal[v]>n-1) return 0;
				dis[v]=dis[u]+weigh[i];
				if(!inq[v]) {
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return 1;
}

int main() {
	//file("LG3725");
	n=read();ll k=read();
	
	REP(i,1,k) {
			
		ll op,x,y;scanf("%lld%lld%lld",&op,&x,&y);
		if(op==1) addedge(x,y,0),addedge(y,x,0);
		if(op==2) addedge(x,y,1);
		if(op==3) addedge(y,x,0);
		if(op==4) addedge(y,x,1);
		if(op==5) addedge(x,y,0);
		if(op%2==0&&x==y) {
            printf("-1\n");
            return 0;
        }
	}

	if(!SPFA()) puts("-1");
	else {
		ll ans=0;
		REP(i,1,n) ans+=dis[i];
		printf("%lld\n",ans);
	}
	return 0;
}

