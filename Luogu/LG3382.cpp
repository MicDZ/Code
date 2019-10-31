#include<bits/stdc++.h>
using namespace std;
int n;
double l,r,t[14];
double js(double x)
{
    double ans=0;
    for(int i=n;i>=0;i--)
        ans+=t[i]*pow(x,i);
    return ans;
}
int main()
{
    cin>>n>>l>>r;
    for(int i=n;i>=0;i--)
        cin>>t[i];
    double a,b;
    while(r-l>1e-10)
    {
        a=l+(r-l)/3,b=r-(r-l)/3;
        if(js(a)<=js(b)) l=a;
        else r=b;
    }
    printf("%.5lf",l);
    return 0;
}
