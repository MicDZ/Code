#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>

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

const int MAXN=4e7+10,INF=0x3f3f3f3f,MOD=1<<30;

int a[MAXN],b[MAXN],p[MAXN],l[MAXN],r[MAXN];

stack<char> st;

void write(__int128 a) {
	while(a) st.push(a%10+'0'),a/=10;
	while(st.size()) putchar(st.top()),st.pop();
}

int s[MAXN];

ll sum[MAXN];

ll calc(int k) {return 2*sum[k]-sum[s[k]];}

int q[MAXN];

int main() {
	int n=read(),type=read();
	if(!type) REP(i,1,n) a[i]=read();
	else {
		int x=read(),y=read(),z=read(),m;
		b[1]=read(),b[2]=read(),m=read();

		REP(i,1,m) p[i]=read(),l[i]=read(),r[i]=read();
		REP(i,3,n) b[i]=(1ll*x*b[i-1]+1ll*y*b[i-2]+z)%MOD;
		p[m]=n;p[0]=0;
		REP(j,1,m) REP(i,p[j-1]+1,p[j]) a[i]=(b[i]%(r[j]-l[j]+1))+l[j];
	}

	REP(i,1,n) sum[i]=sum[i-1]+a[i];
	int head=1,tail=1;

	REP(i,1,n) {
		while(head<tail&&calc(q[head+1])<=sum[i]) head++;
		s[i]=q[head];
		while(head<tail&&calc(q[tail])>=calc(i)) tail--;
		q[++tail]=i;
	}
	__int128 ans=0;
	for(int i=n; i>=1; i=s[i]) {__int128 x=sum[i]-sum[s[i]]; ans=ans+x*x;}

	write(ans);	
	return 0;
}

