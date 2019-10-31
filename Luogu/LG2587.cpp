#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int a[MAXN],b[MAXN];

int main() {
	int n=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,n) b[i]=read();
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);

	int l=1,r=n,L=1,R=n,ans=0;
	while(l<=r) {
		if(a[r]>b[R]) {
			ans+=2;
			r--;
			R--;
		}
		else if(a[l]>b[L]) {
			ans+=2;
			l++;
			L++;
		}
		else {
			if(a[l]==b[R]) ans++;
			l++;
			R--;
		}
	}

	printf("%d ",ans);


	
	l=1,r=n,L=1,R=n,ans=0;
	while(l<=r) {
		if(b[r]>a[R]) {
			ans+=2;
			r--;
			R--;
		}
		else if(b[l]>a[L]) {
			ans+=2;
			l++;
			L++;
		}
		else {
			if(b[l]==a[R]) ans++;
			l++;
			R--;
		}
	} 
	printf("%d ",2*n-ans);

	return 0;
}
