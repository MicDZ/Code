#include<bits/stdc++.h>
using namespace std;

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[11],f[256*256];

int main() {
    int n=read();
    for(int i=1; i<=n; i++) {
        a[i]=read();
        if(a[i]==1) {
            cout<<0<<endl;
            return 0;
        }
    }
    f[0]=1;
    for(int i=1; i<=n; i++) 
        for(int j=a[i]; j<=256*256; j++) 
            f[j]=f[j]||f[j-a[i]];
    int ans=0;
    for(int i=256*256; i>=1; i--) {
        if(f[i]==0) {
            if(i>=256*256-2*256) cout<<0<<endl;
            else cout<<i<<endl;
        return 0;
        }
    }
}
