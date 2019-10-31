#include<bits/stdc++.h> 
using namespace std;
int main(){
    int a;
    cin>>a;
    for(int i=1;i<=sqrt(2*a);i++){ 
        if(i*(i+1)==2*a){
             cout<<"YES";
             return 0;
        }
    }
    cout<<"NO";
}
