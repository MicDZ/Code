#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
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

const int MAXN=1000000+10;

char a[MAXN],b[MAXN];

int kmp[MAXN],f[MAXN];

int main() {
	scanf("%s%s",a+1,b+1);
	int lena=strlen(a+1),lenb=strlen(b+1);
	kmp[1]=0;int j=0;
	REP(i,2,lenb) {
		while(j&&b[i]!=b[j+1]) j=kmp[j];
		if(b[i]==b[j+1]) j++;
		kmp[i]=j;
	}
	j=0;
	REP(i,1,lena) {
		while(j&&a[i]!=b[j+1]) j=kmp[j];
		if(a[i]==b[j+1]) j++;
		f[i]=j;
		if(f[i]==lenb) printf("%d\n",i-lenb+1);
	}
	REP(i,1,lena) printf("%d ",kmp[i]);
	return 0;
}

