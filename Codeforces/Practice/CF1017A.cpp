#include<bits/stdc++.h>

using namespace std;

#define MAXN 1000+10

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct student{
    int sum,id;
}s[MAXN];

bool cmp(student a,student b) {
    if(a.sum==b.sum) return a.id<b.id;
    return a.sum>b.sum;
}

int main() {
    int n=read();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=4; j++) {
            int a;
            cin>>a;
            s[i].sum+=a;
            s[i].id=i;
        }
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1; i<=n; i++) {
		//cout<<s[i].id<<" "<<s[i].sum<<endl;
        //cout<<" ";
        if(s[i].id==1) cout<<i<<endl;
    }
}
