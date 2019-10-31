#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include <algorithm> // max
#include <cassert>   // assert
#include <iostream>  // cin,cout
#include <string>    // string类
#include <vector>    // vector类
using namespace std;
#define maxn 1002
#define base 10000
#define PP 8
#define reg register
typedef long long LL;
const int carry=1e8;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

 
struct BigInteger {
    typedef unsigned long long LL;
 
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
 
    BigInteger& clean(){while(!s.back()&&s.size()>1)s.pop_back(); return *this;}
    BigInteger(LL num = 0) {*this = num;}
    BigInteger(string s) {*this = s;}
    BigInteger& operator = (long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger& operator = (const string& str) {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return (*this).clean();
    }
 
    BigInteger operator + (const BigInteger& b) const {
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if (i < s.size()) x += s[i];
            if (i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator - (const BigInteger& b) const {
        assert(b <= *this); // 减数不能大于被减数
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = s[i] + g;
            if (i < b.s.size()) x -= b.s[i];
            if (x < 0) {g = -1; x += BASE;} else g = 0;
            c.s.push_back(x);
        }
        return c.clean();
    }
    BigInteger operator * (const BigInteger& b) const {
        int i, j; LL g;
        vector<LL> v(s.size()+b.s.size(), 0);
        BigInteger c; c.s.clear();
        for(i=0;i<s.size();i++) for(j=0;j<b.s.size();j++) v[i+j]+=LL(s[i])*b.s[j];
        for (i = 0, g = 0; ; i++) {
            if (g ==0 && i >= v.size()) break;
            LL x = v[i] + g;
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c.clean();
    }
    BigInteger operator / (const BigInteger& b) const {
        assert(b > 0);  // 除数必须大于0
        BigInteger c = *this;       // 商:主要是让c.s和(*this).s的vector一样大
        BigInteger m;               // 余数:初始化为0
        for (int i = s.size()-1; i >= 0; i--) {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
			m -= b*c.s[i];
        }
        return c.clean();
    }
    BigInteger operator % (const BigInteger& b) const { //方法与除法相同
        BigInteger c = *this;
        BigInteger m;
        for (int i = s.size()-1; i >= 0; i--) {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return m;
    }
    // 二分法找出满足bx<=m的最大的x
    int bsearch(const BigInteger& b, const BigInteger& m) const{
        int L = 0, R = BASE-1, x;
        while (1) {
            x = (L+R)>>1;
            if (b*x<=m) {if (b*(x+1)>m) return x; else L = x;}
            else R = x;
        }
    }
    BigInteger& operator += (const BigInteger& b) {*this = *this + b; return *this;}
    BigInteger& operator -= (const BigInteger& b) {*this = *this - b; return *this;}
    BigInteger& operator *= (const BigInteger& b) {*this = *this * b; return *this;}
    BigInteger& operator /= (const BigInteger& b) {*this = *this / b; return *this;}
    BigInteger& operator %= (const BigInteger& b) {*this = *this % b; return *this;}
 
    bool operator < (const BigInteger& b) const {
        if (s.size() != b.s.size()) return s.size() < b.s.size();
        for (int i = s.size()-1; i >= 0; i--)
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }
    bool operator >(const BigInteger& b) const{return b < *this;}
    bool operator<=(const BigInteger& b) const{return !(b < *this);}
    bool operator>=(const BigInteger& b) const{return !(*this < b);}
    bool operator!=(const BigInteger& b) const{return b < *this || *this < b;}
    bool operator==(const BigInteger& b) const{return !(b < *this) && !(b > *this);}
};
 
ostream& operator << (ostream& out, const BigInteger& x) {
    out << x.s.back();
    for (int i = x.s.size()-2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}
 
istream& operator >> (istream& in, BigInteger& x) {
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}
struct Bign{
    int z[505],len;
    Bign(){
        memset(z,0,sizeof(z));
        len=0;
    }
    Bign(int x) { *this=x; }
    Bign operator = (int x){
        Bign re;
        re.len=1;
        re.z[0]=x;
        *this=re;
    }
    Bign operator = (char *c){
        int len=strlen(c);
        char tmp[PP+5];
        Bign now;
        memset(tmp,0,sizeof(tmp));
        while(len>=PP){
            strncpy(tmp,c+len-PP,PP);
            now.z[now.len++]=atoi(tmp);
            len-=PP;
        }
        if(len){
            memset(tmp,0,sizeof(tmp));
            strncpy(tmp,c,len);
            now.z[now.len++]=atoi(tmp);
        }
        *this=now;
    }
    friend Bign operator + (Bign x,Bign y){
        Bign re;
        re.len=max(x.len,y.len)+1;
        for(int i=0;i<re.len;i++){
            re.z[i]+=x.z[i]+y.z[i];
            if(re.z[i]>=carry) re.z[i]-=carry,re.z[i+1]++;
        }
        while(re.len>1 && re.z[re.len-1]==0) re.len--;
        return re;
    }
    friend Bign operator * (Bign x,int y){
        LL tmp;
        Bign re;
        re.len=x.len+1;
        for(int i=0;i<x.len;i++){
            tmp=(LL)x.z[i]*y;
            if(tmp+re.z[i]>=carry) re.z[i+1]=(re.z[i]+tmp)/carry,re.z[i]=(re.z[i]+tmp)%carry;
            else re.z[i]+=tmp;
        }
        while(re.len>1 && re.z[re.len-1]==0) re.len--;
        return re;
    }
    friend Bign operator / (Bign x,int y){
        LL tmp=0;
        Bign re;
        int pos=x.len-1;
        while(pos>=0){
            tmp*=carry;
            re.z[pos]+=(x.z[pos]+tmp)/y;
            tmp=(x.z[pos]+tmp)%y;
            pos--;
        }
        re.len=x.len;
        while(re.len>1 && re.z[re.len-1]==0) re.len--;
        return re;
    }
    friend bool operator < (Bign x,Bign y){
        if(x.len!=y.len) return x.len<y.len;
        for(int i=x.len-1;i>=0;i--)
            if(x.z[i]!=y.z[i]) return x.z[i]<y.z[i];
        return 0;
    }
    void Print(){
        printf("%d",z[len-1]);
        for(int i=len-2;i>=0;i--)
            printf("%0*d",PP,z[i]);
		puts("");
    }
};
const int MAXN=100000+10;
struct minister {
	int l,r;
} a[MAXN];

bool cmp(minister a,minister b) {
	return a.l*a.r<b.l*b.r;
}


int main() {
	int n;
	n=read();
	a[0].l=read(),a[0].r=read();
	
	REP(i,1,n) a[i].l=read(),a[i].r=read();
	sort(a+1,a+1+n,cmp);
	Bign prod=a[0].l,ans=0;
	REP(i,1,n) {
		if(ans<prod/a[i].r) ans=prod/a[i].r;
		prod=prod*a[i].l;
	}

	ans.Print();
	return 0;
}
