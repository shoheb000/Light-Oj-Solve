#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

int visit_city[MAX], visit[MAX];
vector< int > graph[MAX], city;
queue < int > Q;


  void BFS (int start){

     Q.push(start);

     visit[start]=1;
     visit_city[start]+=1;

     while(!Q.empty()){

        int s=Q.front();

        Q.pop();

     for(int i=0; i<graph[s].size(); i++){

        if(!visit[graph[s][i]]){
            Q.push(graph[s][i]);
            visit_city[graph[s][i]]+=1;
            visit[graph[s][i]]=1;
         }

      }
    }
  }



int main(){

   int test_case, K, N, M, p_city, u, v,sum,cnt=0;

   scanf("%d",&test_case);

   while(test_case--){
        cnt++,sum=0;

    scanf("%d %d %d", &K, &N, &M);

    for(int i=0 ; i<K ; i++){
        scanf("%d",&p_city);
        city.push_back(p_city);
    }

    for(int i=0 ; i<M ; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }

    for(int i=0 ; i<city.size(); i++){

        BFS(city[i]);
        for(int i=0 ; i<MAX; i++) visit[i]=0;
    }

    for(int i=0 ; i<MAX; i++){
        if( visit_city[i]== K)
            sum++;
    }

    printf("Case %d: %d\n", cnt, sum);

    for(int i=0 ; i<MAX; i++){
        visit_city[i]=visit[i]=0;
        graph[i].clear();
        city.clear();
    }

   }

  return 0;
}


