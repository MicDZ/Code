#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int unsigned ll
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

const int MAXN=1000000+10;

int l,r;

int cnt=0,a[MAXN];

void dfs(int x) {
	if(x>r) return ;
	if(x) a[++cnt]=x;
	dfs(x*10+6);
	dfs(x*10+8);
}

int book[MAXN],ans;

int gcd(int a,int b) {return a?gcd(b%a,a):b;};
int lcm(int a,int b) {return a*b/gcd(a,b);}

void calc(int k,int num,int x) {
	if(k==cnt+1) {
		if(num%2) ans+=(r/x-(l-1)/x);
		else if(num) ans-=(r/x-(l-1)/x);
		return ;
	}
	int t=lcm(a[k],x);
	calc(k+1,num,x);
	if(t<=r) calc(k+1,num+1,t);
}

signed main() {
	l=read(),r=read();
	dfs(0);
	sort(a+1,a+1+cnt);
	REP(i,1,cnt) REP(j,1,i-1) {
		if(a[i]%a[j]==0) {
			book[i]=1;
			break;
		}
	}
	
	int t=0;
	REP(i,1,cnt) if(!book[i]) a[++t]=a[i]; 
	cnt=t;
	reverse(a+1,a+1+cnt);
	calc(1,0,1);
	printf("%lld\n",ans);
	//printf("%d\n",dfs());
	return 0;
}
