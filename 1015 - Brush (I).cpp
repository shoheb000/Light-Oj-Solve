#include <cstdio>
#include <iostream>
using namespace std;

int main(){

    int ts, track = 0, n;
    cin>> ts;

    while(ts--){
        int sum = 0, keep;
        cin>>n;
        while(n--)
        {
            cin>>keep;
            if(keep > 0) sum += keep;
        }
        printf("Case %d: %d\n",++track,sum);

    }
    return 0;
}
