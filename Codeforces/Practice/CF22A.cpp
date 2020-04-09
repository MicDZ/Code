#include<bits/stdc++.h>
using namespace std;
set <int> q;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int s;
		cin>>s;
		q.insert(s);
	}
	q.erase(q.begin());
	if(q.empty())cout<<"NO";
	else cout<<(*q.begin());
}
