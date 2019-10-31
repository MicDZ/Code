#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (ll)1e6+9
const ll t=(ll)1e9;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct pii{
    ll fi,se;
    pii(){fi=0,se=0;}//se高位fi低位
    pii(ll b){fi=b%t;se=b/t;}
    friend pii operator + (pii a,pii b){
        pii c;
        c.fi=a.fi+b.fi;
        c.se=a.se+b.se;
        if(c.fi<0 and c.se>0)c.se--,c.fi+=t;
        if(c.fi>=t and c.se>=0)c.se+=c.fi/t,c.fi%=t;
        if(c.fi>0 and c.se<0)c.se++,c.fi-=t;
        if(c.fi<=-t and c.se<=0)c.se+=c.fi/t,c.fi%=t;
        return c;
    }
    friend bool operator <(pii a,pii b){
        if(a.se!=b.se)return a.se<b.se;
        return a.fi<b.fi;
    }
    friend pii max(pii a,pii b){
        if(a<b)return b;
        return a;
    }
};
//#define pii ll 
pii data[maxn],w[maxn],q[maxn],s[maxn];
int main(){
    ll n=read(),p=read();
    for(int i=1;i<=n;i++){
        data[i]=read();
    }
    s[1]=w[1]=q[1]=data[1];
    //data[i]表示每个小朋友的分数
    //w[i]表示以i为结尾的最长连续字段和 
    //q[i]表示1~i中的最长连续字段和
    //s[i]表示前i个小朋友的最大分数+特征值 
    for(int i=2;i<=n;i++){
        w[i]=max(w[i-1]+data[i],data[i]);
        q[i]=max(w[i],q[i-1]);
        if(i==2)s[i]=s[1]+s[1];
        else s[i]=max(s[i-1],s[i-1]+q[i-1]);
    }
    pii sum(1-t);
    for(int i=1;i<=n;i++)
        sum=max(sum,s[i]);
    cout<<(sum.se%p*t%p+sum.fi%p)%p<<endl;
    //cout<<sum%p<<endl;
}//f[i][j]=max(f[i-1][j],f[i][j-1])