#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll read() {
    ll x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define MAXN 10000+10

int a[MAXN];

int main() {
    int n=read();
    REP(i,1,n) a[i]=read();

    int ans=0;
    REP(i,2,n-1) {
        if(a[i-1]==1&&a[i]==0&&a[i+1]==1) {
            ans++;
            a[i+1]=0;
        }
    }

    cout<<ans<<endl;
    return 0;
}