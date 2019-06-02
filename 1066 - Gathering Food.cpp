#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#define MAX 11
using namespace std;

int visit[MAX][MAX], dis[MAX][MAX], N, cnt_food, x1, y1;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char G[MAX][MAX], b_line;
pair< int, int > p['Z'-'A'+2], s;

int BFS(int x, int y){

    queue< pair<int,int> >Q;

    dis[x][y] = 0;
    visit[x][y] = 1;
    Q.push(make_pair(x,y));

    while(!Q.empty()){
        s = Q.front();
        x = s.first;
        y = s.second;

        Q.pop();

        for(int i = 0; i<4; i++){
            x1 = x+dx[i];
            y1 = y+dy[i];
            if((x1>=1 && x1<=N) && (y1>=1 && y1<=N)){

                if(G[x1][y1] != '#' && !visit[x1][y1]){

                    dis[x1][y1] += dis[x][y] + 1;
                    visit[x1][y1] = 1;
                    Q.push(make_pair(x1,y1));
                    if(G[x1][y1] != '.'){
                       return dis[x1][y1];
                    }
                }
            }
        }
    }
    return -1;
}



int main(){

    int t_case, cnt = 0;
    cin>>t_case;

    while(t_case--){
    getchar();
    int sum = 0, Track = 0, basket;

    cnt_food = 0,  cnt++;


    cin>>N;


    for(int i = 1; i<=N; i++)
     for(int j = 1; j<=N; j++){
        cin>>G[i][j];
        if(G[i][j] != '.' && G[i][j] != '#'){
            int l = G[i][j]-('A'-1);
            p[l] = make_pair(i,j);
            visit[i][j] = 1;
            cnt_food += 1;

        }
     }

   for(int i=1; i< cnt_food; i++){

      visit[p[i+1].first][p[i+1].second] = 0;
      basket = BFS(p[i].first,p[i].second);

      if (basket != (-1))
        sum += basket;
      else{
        Track = 1;
        break ;
      }

       G[p[i].first][p[i].second] = '.';

      for(int t = 1; t<=N; t++)
        for(int j = 1; j<=N; j++){
           dis[t][j] = 0; visit[t][j] = 0;
           if(G[t][j] != '.' && G[t][j] != '#')
                visit[t][j] = 1;
        }
     }

     if(!Track)
        printf("Case %d: %d\n", cnt, sum);
     else
        printf("Case %d: Impossible\n", cnt);



     memset(visit,0,sizeof(visit));
     memset(dis,0,sizeof(dis));

    }

   return 0;
}
