#include <cstdio>
#include <iostream>
using namespace std;

int main(){

    int ts, n;
    cin>> ts;

    while(ts--){
        cin>>n;

        if(n > 10)
            printf("%d %d\n",10 , n-10);
         else
            printf("%d %d\n",0 , n);

    }
    return 0;
}
