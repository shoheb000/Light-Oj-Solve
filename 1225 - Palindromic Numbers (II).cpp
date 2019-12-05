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

        int flag = 1;
        string s;
        cin >> s;

        for(int i=0; i< s.length()/2; i++){
              if(s[i] != s[s.length()-1-i]) {
                    flag = 0;
                    break;
              }
        }
        if(!flag)
           printf("Case %d: No\n",++track);
        else
           printf("Case %d: Yes\n",++track);

    }
    return 0;
}
