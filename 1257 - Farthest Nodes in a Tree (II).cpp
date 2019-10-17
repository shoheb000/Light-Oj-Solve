#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define MAX 30000

using namespace std;

int dis[MAX], dis1[MAX], visit[MAX];
int indexx , Track, largest_n, target;
//map< int, int> visit, dis;
vector< int >G[MAX], W[MAX];
queue <int> Q;

void BFS (int start){

    largest_n = 0;
    visit[start] = 1;
    dis[start] = 0;
    Q.push(start);

    while(!Q.empty()){
       int s = Q.front();
       Q.pop();
       Track = 0;

       for(int i = 0; i<G[s].size(); i++){
            if(!visit[G[s][i]]){
                dis[G[s][i]] = max(dis[G[s][i]],(dis[s] + W[s][i]));
                Q.push(G[s][i]);
                visit[G[s][i]] = 1;
                Track = 1;
            }
       }

       if(!Track){
        if(dis[s]>largest_n){
            largest_n = dis[s];
            indexx = s;
        }
       }
    }
}




int main(){

    int t_case, cnt = 0, n, u, v, w;

    scanf("%d", &t_case);
    while(t_case--){
    indexx = 0, cnt++;
    scanf("%d", &n);

    for(int i = 1; i<n; i++){

      scanf("%d %d %d",&u,&v,&w);

      G[u].push_back(v);
      G[v].push_back(u);

      W[u].push_back(w);
      W[v].push_back(w);
     }

     BFS(indexx);

     memset(visit, 0, sizeof(visit));
     memset(dis, 0, sizeof(dis));

     for(int i=0; i<2 ; i++){
      target = indexx;
      BFS(indexx);
      dis[target] = largest_n;

      for(int i=0; i<n ; i++) dis1[i] = max(dis1[i], dis[i]);

      memset(visit, 0, sizeof(visit));
      memset(dis, 0, sizeof(dis));

     }

     printf("Case %d:\n", cnt);

     for(int i=0; i<n ; i++) printf("%d\n", dis1[i]);


     for(int i=0; i<MAX; i++){
        G[i].clear();
        W[i].clear();
        dis1[i] = dis[i] = visit[i] = 0;
     }
  }

 return 0;
}
