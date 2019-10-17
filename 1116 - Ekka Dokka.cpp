#include <iostream>
#include <cstdio>
#define ll long long int
#define sf scanf
#define pf printf
using namespace std;

int main(){

  int t, cnt = 0;
  ll n, i;

  sf("%d", &t);
  while(t--){
      cnt ++;
      sf("%lld", &n);

      if(!(n%2)){

         for(i = 2 ; i<= n; i+=2){
            if(!(n%i) && !!((n/i)%2)){
               pf("Case %d: %lld %lld\n", cnt, n/i, i);
               break;
            }
         }

      }
      else pf("Case %d: Impossible\n", cnt);

  }

return 0;
}

