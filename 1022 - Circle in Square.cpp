#include <iostream>
#include <cstdio>
#include <cmath>
#define pi acos(-1.0)

using namespace std;


int main(){

    int T, cnt = 0;
    scanf("%d", &T);

    while(T--){
      cnt++;

      double R;

      scanf("%lf", &R);

      printf("Case %d: %.2lf\n", cnt, ((4 * R * R) - (pi * R * R)));
    }
     return 0;
}
