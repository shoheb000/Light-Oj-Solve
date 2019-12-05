#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int ts, track = 0;
    cin>> ts;

    while(ts--){

        int n;

        cin >> n;

        int cnt = 0;

        while ( n > 0){

            if((n % 2) == 1) cnt++;

            n /= 2;
        }

         if(!(cnt%2))
           printf("Case %d: even\n",++track);
         else
           printf("Case %d: odd\n",++track);
    }

    return 0;
}
