#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<ll,int> ans;

queue<ll> q;

pair<int,int> find(ll x) {
	int cnt=0;
	while(x%10) x/=10,cnt++;
	cnt=9-cnt;
	return make_pair((cnt-1)/3+1,cnt%3==0?3:cnt%3);
}

int pos(int x,int y) {
	return y+(x-1)*3;
}

ll _swap(ll s,int a,int b) {
	int m[10];
	DREP(i,9,1) m[i]=s%10,s/=10;
	swap(m[a],m[b]);
	ll ans=0;
	REP(i,1,9) ans=ans*10+m[i];
	return ans;
}

int dx[]={0,1,-1,0,0},
	dy[]={0,0,0,1,-1};

ll s,t;

map<ll,int> vis;

void bfs(ll s) {
	q.push(s);ans[s]=0;
	while(!q.empty()) {
		ll u=q.front();q.pop();
		if(u==t) return ;
		int x=find(u).first,y=find(u).second;
		REP(i,1,4) {
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>3||yy<1||yy>3) continue;
			int uu=_swap(u,pos(x,y),pos(xx,yy));
			if(ans[uu]>ans[u]+1||!vis[uu]) {
				vis[uu]=1;
				ans[uu]=ans[u]+1;
				q.push(uu);
			} 
		}
	}
}

int main() {
	s=read(),t=123804765;
	bfs(s);
	printf("%d\n",ans[t]);
	return 0;
}

