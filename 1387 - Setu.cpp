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

        int taka, keep = 0, n;
        string s;


        printf("Case %d:\n",++track);

        cin >> n;
        while(n--){
        cin >> s;

         if(s == "donate") {

             cin >> taka;
            keep += taka;
         }
         else
            cout << keep <<endl;
        }
    }
    return 0;
}
