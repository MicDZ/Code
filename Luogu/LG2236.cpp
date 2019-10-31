/*
V1.0
#include<bits/stdc++.h>
#define xs 1e-10
using namespace std;
int ans=0;
long double n,m,x,y,s;bool have[101011];
void dfs(int k,long double sum,int now){
    //cout<<"start:"<<sum<<endl;
    if(sum-s>xs)return;
    double t=(double)(n-k+1);
    if(sum+t/(double)(now+1)+xs<s)return;
    if((sum+t/(double)m)>s+xs)return;
    if(k>n){
        if(abs(sum-s)<xs){
            ans++;
            //cout<<"b"<<endl;
        }
            return;
    }
    for(int i=now+1;i<=m;i++){
        if(!have[i]){
            have[i]=1;
            dfs(k+1,sum+1.0/(long double)i,i);
            have[i]=0;
        }

    }
}
int read()
{
    int k=0;
    char f=1;
    char c=getchar();
    while(c>'9'||c<'0')
        if(c=='-')
        {
            f=-1;
            c=getchar();
        }
    while(c<='9'&&c>='0')
    {
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
int main()
{
    n=read();m=read();x=read();y=read();
    //cout<<n<<" "<<m<<" "<<x<<" "<<y<<endl;
    s=x/y;
    //cout<<s<<endl;
    dfs(1,0,0);
    cout<<ans;
}*/
//v2.1
#include<bits/stdc++.h>
using namespace std;
#define xs 1e-10

int n,m,x,y,ans;
double tar,a[10010];

void dfs(int x,int y,double sum) {
    if(sum+a[x+(m-y)-1]-a[x-1]-tar<-xs||sum+a[n]-a[n-(m-y)]-tar>xs)return;//精度卡死人啊！
    if(y==m){
        ans++;
        return;
    }
    dfs(x+1,y+1,sum+1.0/x);dfs(x+1,y,sum);
}
int read()
{
    int k=0;
    char f=1;
    char c=getchar();
    while(c>'9'||c<'0')
        if(c=='-')
        {
            f=-1;
            c=getchar();
        }
    while(c<='9'&&c>='0')
    {
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}//模板快读
int main()
{
    m=read(),n=read(),x=read(),y=read();
    tar=1.0*x/y;
    for(int i=1;i<=n;++i) a[i]=a[i-1]+1.0/i;
    dfs(1,0,0.0);
    printf("%d\n",ans);
    return 0;
}
