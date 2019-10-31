#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
priority_queue<int> p;
int ans1,ans2;

int my_abs(int x) {
    if(x>0) return x;
    else return -x;
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        int x;
        cin>>x;
        p.push(x);
        q.push(x);
        if(q.top()<x) {
            int t=q.top();
            ans1+=my_abs(t-x);
			q.pop();
			q.push(x);
        }  
		if(p.top()>x) {
            ans2+=p.top()-x;
			p.pop();
			p.push(x);
        }
    }
    printf("%d\n",min(ans1,ans2));
    return 0;
}
