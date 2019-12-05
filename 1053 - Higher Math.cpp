#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;

int main(){
    int ts, track = 0;
    cin>> ts;

    while(ts--){

        int a, b, c, flag = 0;
        cin>>a>>b>>c;

        if((a*a + b*b) == c*c) flag = 1;
        else if((a*a + c*c) == b*b) flag = 1;
        else if((b*b + c*c) == a*a) flag = 1;

        if(!flag)
           printf("Case %d: no\n",++track);
        else
           printf("Case %d: yes\n",++track);
    }
    return 0;
}
