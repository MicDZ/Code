#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;   
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,t;
long long c,sum;
int main(){
    n=read();
    for(int i=1;i<=n;++i){
        t=read();
        if(t==1)c++;     
        else sum+=c;  
    }
    cout<<sum<<endl;     
    return 0;
	}
