#include <bits/stdc++.h>
using namespace std;
#define int long long
void print(vector<int> a){
  for(int i=0;i<a.size();i++){
           cout<<a[i]<<" ";   
  }
  cout<<endl;
}
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);   
}
int digitsum(int n){int ret=0;while(n){ret+=n%10;n/=10;}return ret;}
int power(int x,int n){
    if(n==0)    return 1;
    int a=power(x,n/2);
    if(n%2==0)  return (a*a);
    else    return (a*a*x);
}

int isPerfectSquare(int x) {
    int s = (int) sqrtl(x);
    while (s * s < x) s++;
    while (s * s > x) s--;
    return s*s==x;
}

 void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];    
    }

    return;

 }
signed main(){
    char* a;
    a="123";
    cout<<a<<endl;

}
