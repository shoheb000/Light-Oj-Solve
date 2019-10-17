#include <iostream>
#include <cstdio>
#define ll long long int


using namespace std;

int main(){
    int cnt = 0, t;
    ll n, m;
    scanf("%d", &t);

    while(t--){
        cnt ++;
        scanf("%lld %lld", &n, &m);
        printf("Case %d: %lld\n",cnt, m*(n/(2*m)*m));
    }
return 0;
}
