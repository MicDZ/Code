#include<bits/stdc++.h>
using namespace std;
#define MAXN (100000+10)

struct task{
    string name;
    int time;
}a[MAXN];

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define REP(i,e,s) for(register int i=e; i<=s; i++)

queue<task> w;

int main() {
    int n=read(),q=read();
    REP(i,1,n) {
        cin>>a[i].name;
        a[i].time=read();
        w.push(a[i]);
    }
    int _time=0;
    while(!w.empty()) {
        if(w.front().time<=q) {
            cout<<w.front().name<<" ";
            _time+=w.front().time;
            w.pop();
            printf("%d\n",_time);
        }
        else {
            _time+=q;
            w.front().time=w.front().time-q;
            w.push(w.front());
            w.pop();
        }
    }
}