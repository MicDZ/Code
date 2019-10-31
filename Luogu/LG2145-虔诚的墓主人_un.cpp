#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) x&(-x)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+10;

int w,c[MAXN];

void add(int x,int d) {
	while(x<=w) {
		c[x]+=d;
		x+=lowbit(x);
	}
}

int ask(int x) {
	int ans=0;
	while(x) {
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

int x[MAXN],y[MAXN],syx[MAXN],syy[MAXN],c[MAXN][20];

vector<int> s;

int main() {
	read();read();int w=read();
	REP(i,1,w) x[i]=read(),y[i]=read(),syx[i]=x[i],syy[i]=y[i];
	int k=read();
	sort(syx+1,syx+1+w);sort(syy+1,syy+1+w);
	int numx=unqiue(syx+1,syx+1+w)-syx-1,numy=unique(syy+1,syy+1+w)-syy-1;
	
	REP(i,1,w) x[i]=lower_bound(syx+1,syx+1+numx)-syx,y[i]=lower_bound(syy+1,syy+1+numy)-syy;
	
	REP(i,0,w) c[0][i]=0;
	REP(i,1,w) for(int j=1; j<=i&&j<=k) c[i][j]=c[i-1][j]+c[i-1][j-1];

	REP(i,1,w) {
		s[x[i]].push_back(i);
		syy[y[i]]++;
	}
	
	return 0;
}
