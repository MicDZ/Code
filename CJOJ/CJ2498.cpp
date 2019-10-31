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

const int MAXN=100000+10;

int a[MAXN],dp[MAXN];

int binary_search(int l,int r,int a) {
	while(l<r) {
		int mid=(l+r)/2;
		if(dp[mid]>=a) r=mid;
		else l=mid+1;
	}
	return r;
}

int main() {
	int n=read();

	REP(i,1,n) a[i]=read();
	int k=0;
	REP(i,1,n) {
		if(a[i]>dp[k]) {
			k++;
			dp[k]=a[i];
		}
		else 
			dp[binary_search(1,k,a[i])]=a[i];
	}
//	REP(i,1,n) cout<<dp[i]<<" ";puts("");
	printf("%d\n",k);
}
