#include<bits/stdc++.h>

#define MAXN 100000+10
using namespace std;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[MAXN],b[MAXN],c[MAXN];
int main() {
	int n=read();
	for(int i=1; i<=n; i++)
		a[i]=read(),b[i]=a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
		c[i]=b[i]-a[i];
	int is2=0,is02=0,s=0;
	for(int i=1; i<=n; i++) {
		if(c[i]==2) is2++;
		else if(c[i]==-2) is02++;
	}
	int q=min(is2,is02);
	//cout<<is2<<" "<<is02<<endl;
	//for(int i=1; i<=n; i++) cout<<c[i]<<" ";
	for(int i=1; i<=n; i++) {
		if(c[i]>0&&c[i]!=2&&c[i]!=-2) s+=c[i];
	}
	if(is2>is02) s+=(is2-is02)*2;
	cout<<s+q;
}
