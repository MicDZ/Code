#include<bits/stdc++.h>
using namespace std;
string a,b,s1="z",s2;

int main()
{
    cin>>a>>b;

    for(int i=0;i<a.length();i++)
    {
        for(int j=0;j<b.length();j++)
        {
            s2=a.substr(0,i+1)+b.substr(0,j+1);
            s1=min(s1,s2);
        }
    }
    cout<<s1<<endl;
    return 0;
}
