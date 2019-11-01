#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<bitset>
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

const int MAXN=100000+10;

int trie[300007][29],cnt[300007],k=1;

char a[MAXN];

bitset<1010> id[500007];

void insert(char *w,int x) {
	int len=strlen(w);
	int p=0;
	REP(i,0,len-1) {
		int c=w[i]-'a';
		if(!trie[p][c]) {
			trie[p][c]=k;
			k++;
		}
		p=trie[p][c];
		cnt[p]++;
 	}
	id[p][x]=1;
}

int n;

void search(char *s) {
	int len=strlen(s);
	int p=0,flag=1;
	REP(i,0,len-1) {
		int c=s[i]-'a';
		if(!trie[p][c])
			flag=0;
		p=trie[p][c];
	}
	if(flag) REP(i,1,n) if(id[p][i]) printf("%d ",i);

	puts("");
	return ;
}


int main() {
file("testdata");
	n=read();
	REP(i,1,n) {
		int num=read();
		REP(j,1,num) {
			scanf("%s",a);
			insert(a,i);
		}
	}
	int m=read();
	REP(i,1,m) {
		scanf("%s",a);
		search(a);
	}
	return 0;
}
