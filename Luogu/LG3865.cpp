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
int f[MAXN][40+5];

int main() {
    int n=read(),m=read();
    for(int i=1; i<=n; i++) {
        int a=read();
        f[i][0]=a;
    }
    int t=(int)(log(n)/log(2));
    for(int j=1; j<=t; j++)
        for(int i=1; i+(1<<j)<=n+1; i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int i=1; i<=m; i++) {
        int l=read(),r=read();
        int s=(int)(log(r-l+1)/log(2));
        printf("%d\n",max(f[l][s],f[r+1-(1<<s)][s]));
    }
    return 0;
}//使用luogu vsc提交

