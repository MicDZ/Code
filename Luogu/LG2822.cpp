#include<bits/stdc++.h>
#define MAXN 2000+10

using namespace std;

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN][MAXN],s[MAXN][MAXN];
int main() {
    int t=read(),k=read();
    for(int i=0;i<=2000;i++) {
        a[i][i]=1;
        a[i][0]=1;
    }
    for(int i=1; i<=2000; i++)
        for(int j=1; j<i; j++)
            a[i][j]=(a[i-1][j]+a[i-1][j-1])%k;
    for(int i=1; i<=2000; i++)
        for(int j=1; j<=2000; j++) {
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(a[i][j]==0&&j<=i) s[i][j]++;
        }
    for(int i=1; i<=t ;i++) {
        int n=read(),m=read();
        printf("%d\n",s[n][m]);
    }
    return 0;
}

