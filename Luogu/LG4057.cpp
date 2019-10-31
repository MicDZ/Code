#include<bits/stdc++.h>
using namespace std;
long long gys(long long l,long long r)
{
    long long s;
    for(;l%r!=0;){
        s=r;
        r=l%r;
        l=s;
    }
    return r;
}
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    a=a*b/gys(a,b);
    a=a*c/gys(a,c);
    cout<<a;
}
