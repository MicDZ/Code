#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[200001];
int main() {
	int m,cnt=0;
	m=read();
	while(m) {
		cnt++;
		a[cnt]=(m+1)/2;
		m/=2;
	}
	printf("%d\n",cnt);
	DREP(i,cnt,1)
		printf("%d ",a[i]);
	return 0;
}
