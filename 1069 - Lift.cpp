#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main(){
    int ts, track = 0;
    cin>> ts;

    while(ts--){

        int a, b, keep;
        cin>>a>>b;
        keep = abs(a-b)*4 + 10 + 9 + a*4;

           printf("Case %d: %d\n",++track, keep);
        }
    return 0;
}
