#include <iostream>
#include <cstdio>
#include<string.h>
#include<string>
#include <queue>
#include <map>
#define MAX 501
using namespace std;

int VISIT[MAX][MAX], ROW, COLUMN, qury, track , x1, y1, m, n;
char G[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue< pair< int,int> > Q;
pair <int, int> p;
map <int, int> M;

void BFS (int x, int y){

    int crystal = 0;
    Q.push(make_pair(x,y));
    VISIT[x][y] = track;

    while(!Q.empty()){

      p = Q.front();
      x = p.first;
      y = p.second;

      Q.pop();

        for( int i=0 ;i<4 ;i++){
             m = x+dx[i];
             n = y+dy[i];
           if((m>=1 && m<= ROW) && (n>=1 && n<= COLUMN)){

            if(G[m][n] != '#' && !VISIT[m][n]){
                Q.push(make_pair(m, n));
                VISIT[m][n] = track;

                if(G[m][n] == 'C')
                   crystal++;

            }
         }
       }
    }

   M[track] = crystal;
   track++;
}


int main(){

  int t_case, cnt = 0;

  scanf("%d",&t_case);

  while(t_case--){
      track = 1, cnt++;

         scanf("%d %d %d",&ROW, &COLUMN, &qury);

      for(int i=1; i<=ROW; i++)
        for(int j=1; j<=COLUMN ; j++){

            cin>>G[i][j];

            VISIT[i][j] = 0;
        }

      for(int i=1; i<=ROW; i++)
        for(int j=1; j<=COLUMN ; j++){
            if(G[i][j] == '.' && !VISIT[i][j]){
                BFS(i, j);
            }
        }

      printf("Case %d:\n", cnt);
      for(int i=1; i<=qury; i++){

         scanf("%d %d",&x1, &y1);

        cout<<M[VISIT[x1][y1]]<<endl;
      }

        M.clear();
  }

return 0;
}
