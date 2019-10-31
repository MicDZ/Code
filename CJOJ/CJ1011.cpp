#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=10000+10;
int a[MAXN],b[MAXN],dp1[MAXN],dp2[MAXN];

int main() {
	int n=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,n) b[i]=a[n+1-i];
	dp1[1]=1;	
	REP(i,2,n) {
		dp1[i]=1;		
		REP(j,1,i-1) 
			if(a[j]<a[i]) dp1[i]=max(dp1[j]+1,dp1[i]);
	}
	dp2[1]=1;
	REP(i,2,n) {
		dp2[i]=1;		
		REP(j,1,i-1) 
			if(b[j]<b[i]) dp2[i]=max(dp2[j]+1,dp2[i]);
	}
	
	int ans=0;

	REP(i,1,n) 
		ans=max(ans,dp1[i]+dp2[n+1-i]);
	printf("%d\n",n-ans+1);
}
