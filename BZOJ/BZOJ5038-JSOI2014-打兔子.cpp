#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=4000+10;

int n,k;

int a[MAXN];

namespace tepan1 {
	void main() {
		sort(a+1,a+4);
		printf("%d\n",a[2]+a[3]);
		return ;
	}
}

namespace tepan2 {
	void main() {
		int sum=0;
		REP(i,1,n) sum+=a[i];
		printf("%d\n",sum);
	}
}

namespace _main {
	int f[MAXN][MAXN][2];
	void calc() {
		REP(i,1,n) REP(j,0,k) {
			f[i+1][j][0]=max(f[i+1][j][0],max(f[i][j][0],f[i][j][1]));
			if(k>=j+1) f[i+1][j+1][1]=max(f[i+1][j+1][1],f[i][j][0]+a[i+1]);
			if(n>=i+2) f[i+2][j+1][1]=max(f[i+2][j+1][1],f[i][j][1]+a[i+1]+a[i+2]);
		}
	}

	void main() {
		memset(f,-126,sizeof(f));f[1][0][0]=0;calc();
		int ans1=max(f[n][k][0],f[n][k][1]);
		a[0]=a[n];a[n-1]+=a[n];a[n]=0;
		memset(f,-126,sizeof(f));
		f[1][1][1]=a[1];
		calc();
		a[n]=a[0];a[n-1]-=a[n];
		int ans2=f[n][k][0];
		reverse(a+1,a+1+n);
		a[0]=a[n];a[n-1]+=a[n];a[n]=0;
		memset(f,-126,sizeof(f));
		f[1][1][1]=a[1];
		calc();
		int ans3=f[n][k][0];
		printf("%d\n",max(ans1,max(ans2,ans3)));
	}
}

int main() {
	n=read(),k=read();
	REP(i,1,n) a[i]=read();
	if(n==3&&k==2) tepan1::main();
	else if(n+1<=2*k) tepan2::main(); 
	else _main::main();
	return 0;
}

