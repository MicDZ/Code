#include<bits/stdc++.h>
using namespace std;
int a[1010101],ans;
int main()
{
    int n,m,d,l;
    cin>>n>>m>>d>>l;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        if(a[i]>=l+ans/m*d) ans++;
    cout<<ans;
}
