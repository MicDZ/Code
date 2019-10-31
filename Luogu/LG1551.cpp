#include<bits/stdc++.h>
using namespace std;
#define MAXN 5000+10

int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int fa[MAXN];

int find(int x) {
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}

void link(int u,int v) {
	fa[find(u)]=find(v);
}
int main() {
	int n=read(),m=read(),p=read();
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		int u=read(),v=read();
		//i10 20 10
	//	if(u<v)swap(u,v);
		link(u,v);
	}
	cout<<endl;
	for(int i=1; i<=p; i++) {
		int x=read(),y=read();
	//	cout<<"x:"<<x<<" y:"<<y<<" fa[x]:"<<fa[x]<<" fa[y]:"<<fa[y]<<endl;
		if(find(x)==find(y)) cout<<"Yes\n";
		else cout<<"No\n";
	}
}
