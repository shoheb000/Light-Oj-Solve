#include <iostream>
#include <cmath>
#include <cstdio>
#define ll long long int

using namespace std;

int main(){

      int T, cnt = 0;
      ll n, row, column, prev_n, position, m;
      scanf("%d", &T);


       while(T--){
        cnt ++;
        scanf("%lld", &n);

        m = sqrt(n);

        for( ll i = m; i <= m+1; i++){
            if(n <= i*i ){
                m = i;
                cout<<m*m<<endl;
                break;
            }
        }


        prev_n = (m - 1) * (m - 1);
        position = n - prev_n;

        if( !( m % 2 ) ){
            if( position <= m){
                row = m;
                column = position;
            }
            else{
                row = m * m - n + 1;
                column = m;
            }
        }
        else{

            if( position <= m){
                row = position;
                column = m;
            }
            else{
                column = m * m - n + 1;
                row = m;
            }
        }
        printf("Case %d: %lld %lld\n", cnt, column, row);

    }

 return 0;
}
