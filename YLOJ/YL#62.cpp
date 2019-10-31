#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000+10
#define MAXM 10000+10
#define INF 0x3f3f3f3f

int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int a[MAXN],have[MAXM];

int ans=INF,sum;

int main() {
	int n=read(),m=read();
	for(int i=1; i<=n; i++)
		a[i]=read();
	int l=1;
	for(int i=1; i<=n; i++) {
		if(!have[a[i]])
			sum++;
		have[a[i]]++;
		if(sum==m) {
			while(have[a[l]]>1) {
				have[a[l]]--;
				l++;
			}
			ans=min(ans,i-l+1);
			have[a[l]]--;
			l++;
			sum--;
		}
		if(ans==m) break;
	}
	if(ans==INF)
		printf("no answer\n");
	else
		printf("%d",ans);
	return 0;
}
