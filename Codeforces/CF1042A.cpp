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
int a[MAXN];
int main() {
    int n=read(),m=read();
    int sum=0;
    for(int i=1; i<=n; i++) {
        a[i]=read();
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    cout<<(max(a[n],(int)ceil((sum+m)*1.0/n)))<<" "<<a[n]+m<<endl;
}