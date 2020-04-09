#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000+10


int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

char a[MAXN],b[MAXN];

int main() {
	int n=read();
	gets(a+1);
	gets(b+1);
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(a[i]=='0'&&b[i]=='0') ans++;
		if(a[i]=='0'&&b[i]=='1') ans++;
	}
	cout<<ans*2<<endl;
}
