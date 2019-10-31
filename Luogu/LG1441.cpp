#include<bits/stdc++.h>
using namespace std;
#define MAXN 20+5
#define MAXM 20000+10
#define INF 0x3f3f3f3f

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,m,a[MAXN],ji;

bool have[MAXN],used[MAXN];
int dfs(int lei,int q) {
	int ans=lei;
	//cout<<ans<<endl;
	for(int i=1; i<=n; i++) {
		if(used[i]||i==q)continue;
		ans+=a[i];
		if(!have[ans])ji++;
		have[ans]=1;
		used[i]=1;
		dfs(ans,q);
		used[i]=0;
		ans-=a[i];
	}
}

int main() {
	n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	
	int ans=-INF;
	
	for(int i=1; i<=n; i++) {
		memset(have,0,sizeof(have));
		ji=0;
		dfs(0,i);
		//cout<<"Tab"<<i<<":"<<ji<<endl;
		ans=max(ji,ans);
	}
	cout<<ans;
	return 0;
}
