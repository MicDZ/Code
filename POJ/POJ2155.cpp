#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) (x&(-x))

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1024+10;

int n,c[MAXN][MAXN];

int ask(int x,int y) {
	int ans=0;
	for(int i=x; i; i-=lowbit(i))
		for(int j=y; j; j-=lowbit(j)) 
			ans+=c[i][j];
	return ans;
}

void change(int x,int y) {
	for(int i=x; i<=n; i+=lowbit(i)) 
		for(int j=y; j<=n; j+=lowbit(j)) 
			c[i][j]++;
}

int main() {
	int t=read();
	while(t--) {
		memset(c,0,sizeof(c));
		n=read();int q=read();
		REP(i,1,q) {
			char op;
			cin>>op;
			if(op=='C') {
				int x1=read()+1,y1=read()+1,x2=read()+1,y2=read()+1;
				change(x2,y2);
				change(x2,y1-1);
				change(x1-1,y2);
				change(x1-1,y1-1);
			}
			if(op=='Q') {
				int x=read(),y=read();
				printf("%d\n",ask(x,y)%2);
			}
		}
		puts("");
	}
	return 0;
}

