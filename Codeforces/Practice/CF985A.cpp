#include<bits/stdc++.h>
#define MAXN 100+10
using namespace std;

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN];
int ji[MAXN],ou[MAXN];

int main() {
    int n=read();
    int x=0,y=0;
    for(int i=1; i<=n/2; i++)
    	a[i]=read();
    sort(a+1,a+n/2+1);
    for(int i=1; i<=n/2; i++) {
        ji[i]=i*2-1;
        ou[i]=i*2;
        x+=abs(ji[i]-a[i]);
        y+=abs(ou[i]-a[i]);
    }
    cout<<min(x,y)<<endl;
    return 0;
}