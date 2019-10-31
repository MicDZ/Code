#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)

int read() {
    int ch=getchar(),x=0,f=1;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
    stack<int> s;
    char a[1000+10];
    while(scanf("%s",a+1)!=EOF) {
        if(a[1]=='+') {
            int x,y;
            x=s.top();
            s.pop();
            y=s.top();
            s.pop();
            
            s.push(x+y);
        }
        else if(a[1]=='-') {
            int x,y;
            x=s.top();
            s.pop();
            y=s.top();
            s.pop();
            s.push(y-x);
        }
        else if(a[1]=='*') {
            int x,y;
            x=s.top();
            s.pop();
            y=s.top();
            s.pop();
            s.push(x*y);
        }
        else
            s.push(atoi(a+1));
    }
    cout<<s.top()<<endl;
}