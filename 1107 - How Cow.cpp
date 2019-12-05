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

        printf("Case %d:\n",++track);

        int a, b, c, d, M;

        cin >> a >> b >> c >> d >> M;

        while(M--){

            int x, y;
            cin >> x >> y;

            if(( x>a && x< c) && (y> b && y<d)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }

    }

    return 0;
}
