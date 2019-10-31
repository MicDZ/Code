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

const int MAXN=300000+10;

int a[MAXN];

int main() {
	int n=read();
	REP(i,0,n-1) a[i]=read();
	
	REP(i,0,n-1) 
		a[i+n]=a[i];
	int i=0,j=1,k;
	while(i<n&&j<n) {
		k=0;
		while(k<n-1&&a[i+k]==a[j+k]) k++;
		if(k==n-1) break;
		if(a[i+k]>a[j+k]) i=i+k+1;
		else j=j+k+1;
		if(i==j) j++;
	}

	REP(k,1,n) printf("%d ",a[k+min(i,j)-1]);
	return 0;
}
