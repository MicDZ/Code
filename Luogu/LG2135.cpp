#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

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

const int MAXN=1000+10;

int c[MAXN],num[MAXN],a[MAXN],f[MAXN][MAXN][MAXN],pre[MAXN],id[MAXN];

int calc(int i,int j,int k) {
	if(i>j) return 0;
	if(f[i][j][k]) return f[i][j][k];
	f[i][j][k]=max(f[i][j][k],calc(i,j-1,0)+(k+1)*(k+1));
	for(int x=pre[j]; x>=i; x=pre[x]) f[i][j][k]=max(f[i][j][k],calc(i,x,k+1)+calc(x+1,j-1,0));
	return f[i][j][k];
}

int main() {
	//file("block");
	int t=1;
	REP(tt,1,t) {
		memset(f,0,sizeof(f));
		memset(id,0,sizeof(id));
		memset(pre,0,sizeof(pre));
		int cn=read(),n=0;

		REP(i,1,cn) c[i]=read();
		REP(i,1,cn) num[i]=read();
		
		REP(i,1,cn) {
			REP(j,1,num[i]) a[++n]=c[i];
		}
		REP(i,1,n) pre[i]=id[a[i]],id[a[i]]=i;
		
		printf("%d\n",calc(1,n,0));
	}
	
	return 0;
}
