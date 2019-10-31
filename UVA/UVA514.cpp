#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
int n,h[MAXN];
int main(){
    //freopen("a.in","r",stdin);
//freopen("a.txt","w",stdout);
    while(cin>>n&&n){
        int book=0;
        while(1)
        {
            stack<int>s;
            for(int i=1;i<=n;i++){
                cin>>h[i];
                if(h[1]==0){
                    book=1;
                    break;
                }
            }
            if(book)break;
            int ok=1;
            int A=1,B=1;//参照了lrj书上的写法 （A代表每节车厢，B则代表给定出栈顺序的下标）
            while(B<=n)
            {
                if(A == h[B])
            	{
                	A++;
                	B++;
            	}
            	else if(!s.empty() && s.top() == h[B])
            	{
                	s.pop();
                	B++;
            	}
            	else if(A <= n)s.push(A++);
            	else{
                	ok = 0;
                	break;
            	}
            }
            if(ok)
                cout<<"Yes\n";
            else
                cout<<"No\n";
            
        }
        cout<<"\n";
    }//STL!
    return 0;
}//PS:LRJ太可爱，放个错误代码示例，竟然还愉快的抄了起来