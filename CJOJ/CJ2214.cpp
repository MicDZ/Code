#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=800000+10;

struct route {
	int l,r;
} e[MAXN];

bool cmp(route a,route b) {
	if(a.l==b.l) return a.r>b.r;
	return a.l<b.l;
}

int a[MAXN],size;
void push(int x) {
	x=-x;
	a[++size]=x;
	int k=size;
	while(k>1) {
		if(a[k]>=a[k/2]) return ;
		else {
			swap(a[k],a[k/2]);
			k=k/2;
		}
	}
}
int pop() {
	int ans=a[1];
	a[1]=a[size--];
	int k=1,son;
	while(2*k<=size) {
		son=k<<1;
		if(son<size&&a[son]>a[son+1]) son++;
		if(a[k]<=a[son]) break;
		swap(a[k],a[son]);
		k=son;
	}
	return ans;
}

int top() {
	return -a[1];
}
priority_queue <int,vector<int>,greater<int> > q;

int main() {
	int n=read(),m=read();

	REP(i,1,n) e[i].l=read(),e[i].r=-1;
	REP(i,n+1,n+m) e[i].l=read(),e[i].r=read();
	int ans=0;
	sort(e+1,e+1+m+n,cmp);


	REP(i,1,n+m) {
		if(e[i].r!=-1) q.push(e[i].r);
		else {
			while(!q.empty()&&q.top()<e[i].l) q.pop();
			if(!q.empty()) {ans++;q.pop();}
		}
	}

	printf("%d\n",ans);
	
	return 0;
}

