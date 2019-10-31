#include<bits/stdc++.h>
using namespace std;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
	long long n=read(),a,b;
	a=n>>16;
	b=(n-(a<<16)<<16);
	cout<<a+b<<endl;
}
