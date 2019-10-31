#include<bits/stdc++.h>
using namespace std;
	int bottom,id,ans=0;
	s.push((edge){1,a[1]});id=1,bottom=a[1];

	REP(i,2,n) {
		if(a[i]>bottom) ans=max(ans,i-id+1);
		else ans=max(ans,1);
		if(a[i]>s.top().s) s.push((edge){i,a[i]});
		else {
			while(s.size()&&a[i]<s.top().s) s.pop();
			s.push((edge){i,a[i]});
			if(s.size()==1) {bottom=s.top().s;id=s.top().id;}
		}
	}

	printf("%d\n",ans);
}

/*
6
2 8 4 5 1 9
7
1 8 3 4 6 5 7
*/
