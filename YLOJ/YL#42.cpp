#include<bits/stdc++.h>

using namespace std;
#define MAXN 1000000+10
#define ll long long 
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll a[MAXN],b[MAXN],n;

void check(ll x) {
	for(ll i=1; i<=n; i++) {
		if(a[i]%x>=1&&b[i]%x>=1) 
			return ;
	}
	cout<<x<<endl;
	exit(0);
}

void find(ll x) {
	bool book=0;
	for(ll i=2; i*i<=x; i++) {
		if(x%i==0) {
			while(x%i==0) x/=i;
			//cout<<i<<endl;
			check(i);	
		}
	}
	if(x>1) check(x);
}

int main() {
	n=read();
	for(ll i=1; i<=n; i++) {
		a[i]=read();
		b[i]=read();
	}
	find(a[1]);
	find(b[1]);
	cout<<-1<<endl;
    return 0;
}

