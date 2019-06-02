#include <iostream>
#include <stdio.h>
#include <queue>
#define mp make_pair
using namespace std;

char G[21][21];
int visit[21][21] ,cost [21][21], ROW, COLUMN, a, b;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

pair < int,int > girl[3], p, h;
queue < pair<int,int> > Q;

int BFS (int x, int y){

   visit[x][y]=1;
   Q.push(mp(x,y));

   while(!Q.empty()){

     p = Q.front();
     x = p.first;
     y = p.second;

      Q.pop();

      for(int i=0; i<4; i++){

         a = x + dx[i];
         b = y + dy[i];

             if((a>=1 && a<=ROW) && (b>=1 && b<=COLUMN)){
                  if(G[a][b] != 'm' &&  G[a][b] != '#' && !visit[a][b]){
                          cost[a][b] += cost[x][y]+1;
                          visit[a][b] = 1;
                          Q.push(mp(a,b));
                       }
                   }
               }
      }

   return cost[h.first][h.second];
}


int main(){

  int T_case, cnt=0 ;

  cin>>T_case;

  while(T_case--){
        cnt++;

    cin>>ROW>>COLUMN;

    for(int i=1; i<=ROW; i++){
        for(int j=1; j<=COLUMN; j++){

             cin>>G[i][j];

            if(G[i][j] == 'a') girl[0]= mp(i,j);
            if(G[i][j] == 'b') girl[1]= mp(i,j);
            if(G[i][j] == 'c') girl[2]= mp(i,j);
            if(G[i][j] == 'h') h= mp(i,j);
        }
    }

    int msr=0;
    for(int i=0 ; i<3 ;i++){

        msr = max(msr,BFS(girl[i].first,girl[i].second));

        for(int t=0 ; t<21 ;t++)
           for(int j=0 ; j<21 ;j++){
            visit[t][j] = cost[t][j] = 0;
         }
    }

    printf("Case %d: %d\n", cnt, msr);
  }
  return 0;

}

