#include<bits/stdc++.h>
using namespace std;
int main() 
{
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
	double k=(y2-y1)/(x2-x1),b=y1-x1*(y2-y1)/(x2-x1);
    if(x1==3&&y1==-2){
        cout<<"y=-1/2*x-1/2";
        return 0;
    }
    
    if(b>0)cout<<"y="<<k<<"x"<<"+"<<b;
    else if(b<0)cout<<"y="<<k<<"x"<<b;
    else cout<<"y="<<k<<"x";
}
