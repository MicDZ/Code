//////////////////////////////////////////////
// Author: MicDZ 
// Email: micdzcn@gmail.com 
// Last modified: 2019-08-01 05:30
// Filename: CJ1346.cpp
//////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

#define MAXN 500000+10
#define lowbit(x) (x&(-x))
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int c[MAXN],a[MAXN],n,m;

void add(int x,int v) {
	int ox=x;
    while(x<=n) {
        c[x]=c[x]^v^a[ox];
        x+=lowbit(x);
    }
}

int sum(int x) {
    int ans=0;
    while(x) {
        ans=ans^c[x];
        x-=lowbit(x);
    }
    return ans;
}

int main() {
    n=read(),m=read();
    REP(i,1,n) {int x=read(); add(i,x); a[i]=x;}
	REP(i,1,m) {
		int task_id=read();
		if(task_id) {
			int l=read(),r=read();
			printf("%d\n",(sum(r)^sum(l-1)));
		}
		else {
			int x=read(),w=read();
			add(x,w);
			a[x]=w;
		}
	}
    return 0;
}

