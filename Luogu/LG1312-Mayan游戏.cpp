#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

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

int a[6][8],cnt[6];

bool clear() {
	return !cnt[1]&&!cnt[2]&&!cnt[3]&&!cnt[4]&&!cnt[5];
}

struct edge {
	int x,y,id;
} s[55];
int top;

void fall() {
	REP(i,1,5) {
		int x=0;
		REP(j,1,7) 
			if(a[i][j]) a[i][++x]=a[i][j];
		REP(j,x+1,7) a[i][j]=0;
		cnt[i]=x;
	}
}
void DE_BUG() {
	REP(i,1,5) {
		REP(j,1,cnt[i]) printf("%d ",a[i][j]);
		REP(j,cnt[i]+1,7) printf("%d ",0);
		puts("");
	}
	puts("");
}
void delt() {
	REP(i,1,5) {
		cnt[i]=0;
		while(a[i][cnt[i]+1]) 
			cnt[i]++;
	}	

	int book[6][8];
	memset(book,0,sizeof(book));
		
	REP(i,2,4) REP(j,1,cnt[i]) if(a[i][j]==a[i-1][j]&&a[i][j]==a[i+1][j]) book[i][j]=book[i+1][j]=book[i-1][j]=1;
	
	REP(i,1,5) REP(j,2,cnt[i]-1) if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j-1]) book[i][j]=book[i][j+1]=book[i][j-1]=1;
	bool flag=0;
	REP(i,1,5) REP(j,1,cnt[i]) if(book[i][j]) a[i][j]=0,flag=1;
	fall();
	if(flag) delt();
}

int n;



void dfs(int x) {
	REP(i,1,5) {
		cnt[i]=0;
		while(a[i][cnt[i]+1]) {
			cnt[i]+=1;
		}
	}	
	
	if(x==n+1) {
		if(clear()) {
			REP(i,1,n) printf("%d %d %d\n",s[i].x-1,s[i].y-1,s[i].id);
			exit(0);
		}		
		return ;
	}
	if(clear()) return ;	
	int temp_a[6][8],temp_cnt[6];
	
	REP(i,1,5) REP(j,1,7) temp_a[i][j]=a[i][j];
	REP(i,1,5) REP(j,1,7) temp_cnt[i]=cnt[i];
	
	REP(i,1,5) REP(j,1,cnt[i]) {
		if(i!=5) {
			swap(a[i][j],a[i+1][j]);
			s[++top]=(edge){i,j,1};
			fall();delt();
			dfs(x+1);
			top--;
			REP(i,1,5) REP(j,1,7) a[i][j]=temp_a[i][j];
			REP(i,1,5) REP(j,1,7) cnt[i]=temp_cnt[i];
		}
		if(i!=1&&!a[i-1][j]) {
			swap(a[i][j],a[i-1][j]);
			s[++top]=(edge){i,j,-1};
			fall();delt();
			dfs(x+1);
			top--;
			REP(i,1,5) REP(j,1,7) a[i][j]=temp_a[i][j];
			REP(i,1,5) REP(j,1,7) cnt[i]=temp_cnt[i];		
		}
	}
}

int main() {
	n=read();
	REP(i,1,5) {
		int x=read();
		while(x) {
			a[i][++cnt[i]]=x;
			x=read();
		}
	}
	dfs(1);
	puts("-1");
	return 0;
}
