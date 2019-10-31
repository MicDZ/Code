#include<bits/stdc++.h>
using namespace std;
#define MAXN 250+10
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[MAXN][MAXN],f[MAXN][MAXN],sum[MAXN];

int main(int argc,char **argv) {
    int n=read();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) a[i][j]=getchar()-'0';
        getchar();
    }
    
    for(int i=1; i<=n; i++) {
        f[i][0]=a[i][0];
        f[0][i]=a[0][i];
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i][j]==1) {
                f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
                sum[f[i][j]]++;
            }
        }
    }
    //cout<<"init is OK";
    for(int i=n; i>=1; i--)
   		sum[i-1]+=sum[i];
    for(int i=2; i<=n; i++) {
        if(sum[i]) {
            cout<<i<<" "<<sum[i]<<endl;
        }
    }
}

