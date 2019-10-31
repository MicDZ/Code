#include<iostream>
using namespace std	;
int n,m;
char a[1010][1010];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i][0]==a[i+1][0]){
            cout<<"NO";
            return 0;
        }
        for(int j=0;j<m;j++){
            if(a[i][j]!=a[i][0]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}
