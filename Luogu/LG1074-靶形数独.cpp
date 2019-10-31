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

const int MAXN=10+10;

int a[MAXN][MAXN],line[MAXN][MAXN],rall[MAXN][MAXN],box[MAXN][MAXN];

int mark(int x,int y){	
	int u=ceil(x*1.0/3),v=ceil(y*1.0/3);
	return (u-1)*3+v;
}

bool found=0;

const int score[11][11]={
	{0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,9,10,9,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,6,6,6,6,6,6,6,6}
};

int ans=-1,cnt;

void print() {
	cnt++;
	int sum=0;
	REP(i,1,9) REP(j,1,9) sum+=a[i][j]*score[i][j];
	ans=max(ans,sum);
}

int s[100][4];
int u=0;
void dfs(int p,int score){
    if(p==u) {
        if(score>ans) ans=score;        
		return;
	}
    REP(i,1,9) {
        if(!line[s[p][0]][i]&&!rall[s[p][1]][i]&&!box[s[p][3]][i]) {
            line[s[p][0]][i]=rall[s[p][1]][i]=box[s[p][3]][i]=1;
            dfs(p+1,score+(s[p][2]*i));
            line[s[p][0]][i]=rall[s[p][1]][i]=box[s[p][3]][i]=0; 
        }
    }
    return;
}
void dfs1(int x,int y) {
	if(x==10) y++,x=1;
	if(y==10&&x==1){
		print();
		found=1;
		return ;
	}
	if(a[x][y]){
		dfs(x+1,y);
		return ;
	}
	int q=mark(x,y);
	DREP(i,9,1) {
		if(!line[x][i]&&!rall[y][i]&&!box[q][i]){
			line[x][i]=1,rall[y][i]=1,box[q][i]=1,a[x][y]=i;
			dfs(x+1,y);
			line[x][i]=0,rall[y][i]=0,box[q][i]=0,a[x][y]=0;
		}
	}
}

struct _line {
	int sum,id;
} cou[11];

bool cmp(_line a,_line b) {
	return a.sum<b.sum;
}

int main() {
	//file("44");
	int h=0;
	REP(i,1,9) REP(j,1,9) {
		a[i][j]=read();
		if(a[i][j]!=0) {
			line[i][a[i][j]]=1;
			rall[j][a[i][j]]=1;
			box[mark(i,j)][a[i][j]]=1;
			h+=a[i][j]*score[i][j];
		}
		else cou[i].sum++;
	}
	REP(i,1,9) cou[i].id=i;
	sort(cou+1,cou+1+9,cmp);

	REP(i,1,9) REP(j,1,9) {
		if(a[cou[i].id][j]==0) 
		s[u][0]=cou[i].id,s[u][1]=j,s[u][2]=score[cou[i].id][j],s[u++][3]=mark(cou[i].id,j);
	}
	dfs(0,h);
	printf("%d\n",ans);
	return 0;
}
