#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,e,s) for(register int i=e; i<=s; i++)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=1000+10;
int ans[MAXN];

int main() {
	int n=read();
	REP(i,1,n){
		REP(j,1,i/2) ans[i]+=ans[j];
		ans[i]++;
	}
	printf("%d\n",ans[n]);
}
