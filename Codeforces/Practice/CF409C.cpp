#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5],i;
    for (i = 0; i <= 4; ++i)
        cin >> a[i];
    a[2]/=2;
    a[3]/=7;
    a[4]/=4;
    cout<<*min_element(a,a+5);
    return 0;
}