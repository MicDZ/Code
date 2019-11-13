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
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1000000+10;

char a[MAXN],b[MAXN];
int kmp[MAXN];
int main() {
	scanf("%s",a+1);
	scanf("%s",b+1);
	int lena=strlen(a+1),lenb=strlen(b+1),j;
	j=0;
	REP(i,2,lenb) {
		while(j&&b[i]!=b[j+1]) j=kmp[j];
		if(b[j+1]==b[i]) j++;
		kmp[i]=j;
	}
	j=0;
	REP(i,1,lena) {
		while(j&&b[j+1]!=a[i]) j=kmp[j];
		if(b[j+1]==a[i]) j++;
		if(j==lenb) printf("%d\n",i-lenb+1);
	}

	REP(i,1,lenb) printf("%d ",kmp[i]);
	return 0;
}
/*
ABABABC
ABA
*/
