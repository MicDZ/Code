#include<bits/stdc++.h>

#define MAXN 1000+10
using namespace std;
int n,m,a[MAXN][MAXN],ans;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
    n=read();
    m=read();
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=i; j++) {
			a[i][j]=read();
		}
	
    for(int i=n-1; i>=1; i--) {
    	for(int j=1; j<=i; j++) {
    		a[i][j]=min(a[i+1][j+1]+a[i][j],a[i+1][j]+a[i][j]);
    		//cout<<a[i][j];
		}
		//cout<<endl;
	}
    	
	int ans=a[1][1];
    if(m>ans) cout<<m-ans;
    else cout<<"OrZ";
}
