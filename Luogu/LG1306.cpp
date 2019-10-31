#include<bits/stdc++.h>
#define MAXN 1000000+50
#define ETS 100000000
#define FTS 150000000
using namespace std;

unsigned long long read() {
    unsigned long long x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

long long a[MAXN];
int main() {
	unsigned long long t=__gcd(read(),read());
	a[1]=1; a[2]=1;
	if(t<3) {
		cout<<1<<endl;
		return 0;
	}
	int a=1,b=1,s=0;
	for(int i=3; i<=t; i ++) {
        s=a;
        a=b;
        b=(b+s)%ETS;
    }
	cout<<b<<endl;
}