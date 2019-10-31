#include<bits/stdc++.h>
using namespace std;
int n,m,word,ans,le,ri,b[1005];
bool a[1005];
int main()
{
    cin>>m>>n;
    le=0;ri=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&word);
        if (a[word]==0) 
        {
            ans++;
            ri++;b[ri]=word;a[word]=1;
            if (ri>m)
			{
                le++;
				a[b[le]]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}

