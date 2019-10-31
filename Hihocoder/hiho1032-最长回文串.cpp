#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=11000000+10;

char a[MAXN],b[MAXN<<1];

int n,hw[MAXN<<1];

void manacher() {
	int maxright=0,mid;

	REP(i,1,n-1) {
		if(i<maxright) hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
		else hw[i]=1;

		while(b[i+hw[i]]==b[i-hw[i]]) hw[i]++;

		if(hw[i]+i>maxright) {
			maxright=hw[i]+i;
			mid=i;
		}
	}

}

int main() {
	int t=read();
	while(t--) {
		scanf("%s",a);
		n=strlen(a);
		b[0]=b[1]='#';
		REP(i,0,n-1) b[i*2+2]=a[i],b[i*2+3]='#';
		n=n*2+2;
		
		b[n]=0;
		
		manacher();	
		int ans=1;

		REP(i,1,n) ans=max(ans,hw[i]);

		printf("%d\n",ans-1);
	}
	return 0;
}
