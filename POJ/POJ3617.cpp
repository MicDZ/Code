#include<iostream>
#include<cstdio>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=500000+10;

char a[MAXN];

int main() {
		freopen("1.out","w",stdout);
	int n=read();
	REP(i,1,n) {a[i]=getchar();getchar();}
	bool mark=1;
	REP(i,2,n) if(a[i]!=a[1]) mark=0;
	if(mark) {
		REP(i,1,n) {
			printf("%c",a[1]);
			if(i%80==0) puts("");
		}
		return 0;
	}
	int l=1,r=n,cnt=0;
	while(l<r) {
		cnt++;
		if(a[l]<a[r]) {
			printf("%c",a[l]);
			l++;
		}
		else if(a[r]<a[l]) {
			printf("%c",a[r]);
			r--;
		}
		else {
			int ll=l,rr=r;
			while(ll<rr&&a[ll]==a[rr]) {ll++;rr--;}
			if(a[ll]<a[rr]) {
				printf("%c",a[l]);
				l++;
			}
			else {
				printf("%c",a[r]);
				r--;
			}
		}
		if(cnt%80==0) puts("");
	}

	printf("%c",a[l]);
	return 0;
}
