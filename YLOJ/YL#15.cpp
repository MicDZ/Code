#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000+10
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
	int n=read();
	if(n==1) cout<<1<<endl;
	cout<<3*n*n+6*n+4<<endl;
	return 0;
}
