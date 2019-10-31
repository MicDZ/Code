#include<bits/stdc++.h>
#define MAXN 10000+10
#define INF 0x3f3f3f3f
using namespace std;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[MAXN],s[MAXN][MAXN];
int main() {
	int n=read(),m=read();
	for(int i=1; i<=m; i++) a[i]=read();
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++)
			s[i][j]=read();
	for(int k=1; k<=n; k++)	
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
	//cout<<s[1][2];
	int ans=0;
	for(int i=2; i<=m; i++)
		ans+=s[a[i-1]][a[i]];		
	cout<<ans;
}
