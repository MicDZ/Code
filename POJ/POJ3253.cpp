#include<iostream>
#include<cstdio>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
const int MAXN=100000+10;

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[MAXN],size;

void push(int x) {
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

int main() {
	int n=read();
	//size=n;
	REP(i,1,n) push(read());	
	int ans=0;
	while(size>1) {
		int x=pop(),y=pop();
		//cout<<x<<" "<<y<<endl;
		push(x+y);
		ans+=(x+y);
	}

	printf("%d\n",ans);
}

