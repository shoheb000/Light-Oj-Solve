#include <cstdio>
#include <iostream>
using namespace std;

int main(){

    int ts, track = 0;
    cin>> ts;

    while(ts--){
        int a, b;
        cin>>a>>b;
        printf("Case %d: %d\n",++track,a+b);
    }
    return 0;
}
