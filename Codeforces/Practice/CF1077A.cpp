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

int main() {
    ll T=read();
    while(T--) {
        ll a=read(),b=read(),k=read();
        if(k%2==0) cout<<(a-b)*k/2<<endl;
        else cout<<(a-b)*(k-1)/2+a<<endl;
    }
    return 0;
}