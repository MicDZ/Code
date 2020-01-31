#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
#define mp(x,y) make_pair(x,y)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=500+10,MAXM=3000000+10;

priority_queue<pair<int,int> > q[MAXN];

int main() {
	freopen("data.in","r",stdin);
	int n=read(),m=read(),_k=read();
	while(_k--) {
		DE("%d\n",_k);
		
		char op[5];
		scanf("%s",op+1);
		if(op[1]=='A') {
			int n=read(),k=read(),w=read();
			q[n].push(mp(-w,k));
		}
		else if(op[1]=='D') {
			vector<pair<int,int> > g;
			int n=read(),k=read(),w=read();
			while(q[n].top().second!=k) g.push_back(q[n].top()),q[n].pop();
			pair<int,int> x=q[n].top();
			q[n].pop();
			x.first+=w;q[n].push(x);
			while(g.size()) q[n].push(g.back()),g.pop_back();
		}
		else if(op[1]=='T') {
			int n1=read(),n2=read(),flag=0;
			if(q[n1].size()>q[n2].size()) swap(n1,n2),flag=1;
			while(q[n1].size()) {
				q[n2].push(q[n1].top());
				q[n1].pop();
			}
			if(flag) swap(q[n1],q[n2]);
		}
		else if(op[1]=='M') {
			int n=read();
			printf("%d\n",-q[n].top().first);
		}
		else {
			int n=read(),w=read();
		}
	} 
	
	return 0;
}

