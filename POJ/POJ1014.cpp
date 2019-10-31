#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 100000+10
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int dp[MAXN],a[10];

int main() {
    int cnt=0;
    while(1) {
        int sum=0;
        for(int i=1; i<=6; i++) {
            a[i]=read();
            sum+=a[i]*i;
        }
        if(sum==0) break;
        cnt++;
        printf("Collection #%d:\n",cnt);
        memset(dp,0,sizeof(dp));
        if(sum%2==1) printf("Can't be divided.\n");
        else {
            dp[0]=1;
            sum/=2;
            for(int i=1; i<=6; i++) {
                if(a[i]==0) continue;
                for(int j=1; j<=a[i]; j*=2) {
                    for(int k=sum; k>=0; k--) {
                        if(dp[k]==0 || k+i*j>sum) continue;
                        dp[k+i*j]=1;
                    }
                    a[i]-=j;
                }
                if(a[i]>0) {
                    for(int j=sum; j>=0; j--) {
                        if(dp[j]==0||j+i*a[i]>sum) continue;
                        dp[j+i*a[i]]=1;
                    }
                }
            }
            if(dp[sum]==1) printf("Can be divided.\n");
            else printf("Can't be divided.\n");
        }
        puts("");
    }
    return 0;
}