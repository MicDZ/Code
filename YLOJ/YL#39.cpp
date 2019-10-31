#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000+10
#define ll long long 
ll read() {
    ll x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main() {
	ll t=read(),k=read();
	while(t--) {
		ll u=read(),v=read();
		if(k==1) printf("%lld\n",min(u,v));
		else {
			while(u!=v) {
				if(u<v) swap(u,v);
				u=(u+k-2)/k;
			}
			printf("%lld\n",u);
		}
	}
    return 0;
}

