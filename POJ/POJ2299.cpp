//////////////////////////////////////////////
// Author: MicDZ 
// Email: micdzcn@gmail.com 
// Last modified: 2019-08-01 07:19
// Filename: POJ2299.cpp
//////////////////////////////////////////////

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
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

int c[MAXN],temp[MAXN],n;

struct edge {
    int id,num;
} a[MAXN];

bool cmp(edge q,edge w) {
    if(q.num==w.num)
        return q.id<w.id;
    return q.num<w.num;
}

void add(int x,int v) {
    while(x<=n) {
        c[x]+=v;
        x+=lowbit(x);
    }
}

int sum(int x) {
    int ans=0;
    while(x) {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}

int main() {
	n=read();
    while(n) {	
		memset(c,0,sizeof(c));
		
		REP(i,1,n) {
        	a[i].num=read();
     		a[i].id=i;
    	}
    
    	sort(a+1,a+1+n,cmp);
    
		REP(i,1,n)
       		temp[a[i].id]=i;
    	   
    	ll ans=0;
    	REP(i,1,n) {
    	    add(temp[i],1);
    	    ans+=i-sum(temp[i]);
    	}
    	printf("%lld\n",ans);
		n=read();
	}
    return 0;
}

