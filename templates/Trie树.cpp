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

const int MAXN=1000000+10;

int trie[MAXN][29],cnt[MAXN],k=1;

char s[MAXN];

void insert(char *w) {
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
}
 
int search(char *s) {
	int len=strlen(s);
	int p=0;
	REP(i,0,len-1) {
		int c=s[i]-'a';
		if(!trie[p][c])
			return 0;
		p=trie[p][c];
	}
	return cnt[p];
}

int main() {
	int n=read();
	REP(i,1,n) {
		scanf("%s",s);
		insert(s);
	}
	int m=read();
	REP(i,1,m) {
		scanf("%s",s);
		int ans=search(s);
		printf("%d\n",ans);
	}
	return 0;
}
