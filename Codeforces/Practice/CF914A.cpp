#include<bits/stdc++.h>
using namespace std;
int n,a,maxx=-1000000;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a>=0)
        {
        	int t=sqrt(a); 
        	if(t*t!=a)maxx=max(maxx,a);
        }
    	else maxx=max(maxx,a);
    }
    cout<<maxx<<endl; 
} 
