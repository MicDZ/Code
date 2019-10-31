#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll read() {
    ll x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define MAXN 200000+10

int a[MAXN];

struct edge {
    int num,id;
}as[MAXN];

bool cmp(edge a,edge b) {
    return a.num>b.num;
}

int main() {
    int n=read(),sum=0;
    REP(i,1,n) {
        a[i]=read();
        as[i].num=a[i];
        as[i].id=i;
        sum+=a[i];
    }
    sort(as+1,as+1+n,cmp);

    queue<int> q;
    int ans=0;

    if(sum-as[1].num-as[2].num==as[2].num) {
        ans++;
        q.push(as[1].id);
    }
    REP(i,2,n) {
        if(sum-as[1].num-as[i].num==as[1].num) {
            ans++;
            q.push(as[i].id);
        }
    
    }

    cout<<ans<<endl;

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}