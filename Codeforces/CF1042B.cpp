#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000+10
#define INF 0x3f3f3f3f
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[MAXN],s[MAXN],dp[15];

int main() {
    int n=read();
    for(int i=1; i<8; i++) dp[i]=INF;
    for(int i=1; i<=n; i++) {
        scanf("%d ",&a[i]);
        char ch;
        while(scanf("%c",&ch)&&ch!='\n'){
            if(ch=='A') s[i]+=1;
            if(ch=='B') s[i]+=2;
            if(ch=='C') s[i]+=4;
        }
    }
    dp[0]=0;
    for(int i=1; i<=n; i++) 
        for(int j=7; j>=0; j--) {   
            dp[j|s[i]]=min(dp[j|s[i]],dp[j]+a[i]);
        }
    cout<<(dp[7]==INF?-1:dp[7])<<endl;
    return 0;
}