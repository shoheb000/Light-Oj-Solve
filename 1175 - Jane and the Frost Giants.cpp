#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAX 201
using namespace std;

int value[MAX][MAX], visit[MAX][MAX], row, column, n, m, a, b, track, val, child, keep;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char G[MAX][MAX];
pair < int, int > p, J;
vector < pair< int,int> > v, s;

    void fire(){

          for(int i=0; i<v.size(); i++){
             for(int j = 0; j<4 ; j++){

               a = v[i].first + dx[j];
               b = v[i].second + dy[j];

               if((a>=1 && a<= row ) &&(b>=1 && b<=column)){

                     if(G[a][b] != '#' && G[a][b] != 'F'){
                         s.push_back(make_pair(a,b));
                         G[a][b] = 'F';
                     }
                  }
               }
            }
        v = s;
        s.empty();

   }


 void BFS(int x, int y){

 queue < pair<int,int> > Q, R;


 value[x][y] = 0;
 Q.push(make_pair(x,y));
 visit[x][y] = 1;
 track = 0;
 val = MAX;

    if(x == 1 || x == row || y == 1 || y == column){
        track = 1;
        val = 0;
        return ;
    }

   fire();

   do{

   child = 0;

   while(!Q.empty()){

   p = Q.front();
   x = p.first;
   y = p.second;
   Q.pop();


   for(int i = 0; i<4 ; i++){

        n = x + dx[i];
        m = y + dy[i];

        if((n>=1 && n<= row ) &&(m>=1 && m<=column)){

          if(G[n][m] != '#' && G[n][m] != 'F' && !visit[n][m]){

                  R.push(make_pair(n,m));
                  value[n][m] = value[x][y] + 1;
                  visit[n][m] = 1;
                  child++ ;
                  G[n][m] = '*';

                  if(n == 1 || n == row || m == 1 || m == column){
                            track = 1;
                            val = min(val,value[n][m]);
                     }
                }
           }
       }
    }


     if(child != 0){

        fire();
           while(!R.empty()){
                p = R.front();
                x = p.first;
                y = p.second;
                R.pop();

            for(int i = 0; i<4 ; i++){

                   n = x + dx[i];
                   m = y + dy[i];

                 if((n>=1 && n<= row ) &&(m>=1 && m<=column)){

                 if(G[n][m] != '#' && G[n][m] != 'F' && !visit[n][m]){


                          Q.push(make_pair(n,m));
                          value[n][m] = value[x][y] + 1;
                          visit[n][m] = 1;
                          G[n][m] = '&';

                     if(n == 1 || n == row || m == 1 || m == column){
                            track = 1;
                            val = min(val,value[n][m]);
                       }
                    }
                 }
               }
            }

         fire();

         }
   }while(child);

 }




int main(){

    int T, cnt = 0;
    scanf("%d", &T);

    while(T--){

        cnt++;

        scanf("%d %d", &row, &column);


      for(int i = 1; i<=row; i++){
        for(int j = 1; j<=column; j++){
            cin>>G[i][j];

            if(G[i][j] == 'J')
                J = make_pair(i,j);
            if(G[i][j] == 'F')
                v.push_back(make_pair(i,j));
        }
      }

      BFS(J.first,J.second);


        if(!track)
            printf("Case %d: IMPOSSIBLE\n",cnt);
        else
            printf("Case %d: %d\n",cnt, val+1);

        for(int j=1 ; j<=row; j++)
           for(int t=1; t<=column; t++)
              visit[j][t] = value[j][t] = 0;
        v.clear();
        s.clear();

    }
return 0;
}
