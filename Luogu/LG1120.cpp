#include<bits/stdc++.h>
#define MAXN 50000+10 
using namespace std;
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[MAXN],V;
bool have[MAXN];
bool cmp(int a,int b) {return a>b;}
int n,x;

int dfs(int t,int k,int tot,int now) {
	if(k>x) return 1;
	if(tot==t) return dfs(t,k+1,0,1);
	int latest_stick=0;
	for(int i=now; i<=n; i++) {
		if(have[i]||tot+a[i]>t||latest_stick==a[i]) continue;
		have[i]=1;		
		if(dfs(t,k,tot+a[i],i)) return 1;
		have[i]=0;
		latest_stick=a[i];
		if(tot==0) return 0;
	}	
	return 0;
} 
int main() {
	int m=read();
	memset(a,0,sizeof(a));
	int sum=0,maxx=-1,cnt=0;
	for(int i=1; i<=m; i++) {
		int q=read();
		if(q<=50) {
			n++;
			a[n]=q;
			sum+=a[n];
			maxx=max(maxx,a[n]);
		}
	}	
	sort(a+1,a+1+n,cmp);
	for(int i=maxx; i<=sum; i++) {
		if(sum%i!=0) continue;
		x=sum/i;		
		memset(have,0,sizeof(have));
		if(dfs(i,1,0,1)) {
			printf("%d\n",i);
			break;		
		}	
	}
	return 0;
}

/*
40
21 10 1 9 7 44 25 15 25 43 6 9 47 3 6 25 44 10 48 16 10 35 46 47 35 9 8 48 46 35 8 28 50 39 27 11 6 21 49 3
*/
