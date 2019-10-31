#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000+10

int a[MAXN][MAXN],l[MAXN],r[MAXN],high[MAXN];

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
	int n=read(),m=read();
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			a[i][j]=read();

	int ans=0;
	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=m; j++) {
//			
//			
//		}
		for(int j=1; j<=m; j++) {
			if(a[i][j]) high[j]=0;
			else high[j]++;
		}
		
		for(int j=1; j<=m; j++) {
//			for(int k=j-1; k>=1; k--) {
//				if(high[j]<=high[k]) l[j]=l[k];
//			}
			l[j]=j;
			while(l[j]>1&&high[j]<=high[l[j]-1])
				l[j]=l[l[j]-1];
		}
		for(int j=m; j>=1; j--) {
//			for(int k=j+1; k<=m; k++) {
//				if(high[j]<=high[k]) r[j]=r[k];
//			}
			r[j]=j;
			while(r[j]<m&&high[j]<=high[r[j]+1])
				r[j]=r[r[j]+1];
		}
		
		for(int j=1; j<=m; j++)
			ans=max(ans,high[j]*(r[j]-l[j]+1));
	}
	
	cout<<ans<<endl;
	
	return 0;
}
