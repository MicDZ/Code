#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 100000+10

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[2][MAXN];

struct edge{
    int x,y;
}b[MAXN];


int main() {}