#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a=0;
    long double x;
    while(scanf("%Lf",&a)!=EOF)a=x*1e6+a;
    printf("%.5lf",(double)a/1e6);
}
