#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,num) for(register int i=(e); i<=(num); i++)
#define DREP(i,e,num) for(register int i=(e); i>=(num); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","to",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=200000+10;

int n,gap,pos[MAXN],a[MAXN],num[MAXN],to[MAXN];

int ask(int x) {
	int ans=0;
	while(x<=n) 
		ans+=num[x],x=to[x];
	return ans;
}

void change(int x,int y) {
	a[x]=y;
	DREP(i,x,(pos[x]-1)*gap+1) 
	if(i+a[i]>min(pos[x]*gap,n)) num[i]=1,to[i]=i+a[i];
	else num[i]=num[i+a[i]]+1,to[i]=to[i+a[i]];
}

int main() {
	n=read(),gap=sqrt(n);
	REP(i,1,n) a[i]=read(),pos[i]=(i-1)/gap+1;
	
	REP(i,1,pos[n]) DREP(j,min(i*gap,n),(i-1)*gap+1) 
	if(j+a[j]>min(i*gap,n)) num[j]=1,to[j]=j+a[j];
	else num[j]=num[j+a[j]]+1,to[j]=to[j+a[j]];
	int q=read();
	REP(i,1,q) {
		int op=read(),x=read();
		if(op==1) printf("%d\n",ask(x+1));
		else {
			int y=read();
			change(x+1,y);
		}
	}
	return 0;
}

