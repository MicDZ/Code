#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=100000+10;

int a[MAXN],b[MAXN],_next[MAXN];

priority_queue<pair<int,int> > q;

map<int,int> last,have;

int main() {
	int m=read(),n=read();
	REP(i,1,n) _next[i]=n+1;

	REP(i,1,n) a[i]=read();
	REP(i,1,n) _next[last[a[i]]]=i,last[a[i]]=i;	
	
	int cnt=0,ans=0;

	REP(i,1,n) {
		if(have[a[i]]) q.push(make_pair(_next[i],a[i]));
		else {
			if(cnt==m) {
				cnt--;
				while(!q.empty()) {
					int s=q.top().second;
					q.pop();
					have[s]=0;
					break;
				}
			}
			ans++;
			q.push(make_pair(_next[i],a[i]));
			cnt++;
			have[a[i]]=1;
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
