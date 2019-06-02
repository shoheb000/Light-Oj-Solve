#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#define MAX 20001
using namespace std;
vector<int>graph[MAX];
queue<int>Q;
int visit[MAX],nodes[MAX];

int BSF(int start){
 int vemp=1,lyrs=0;
 visit[start]=1;
 nodes[start]=0;

 Q.push(start);

 while(!Q.empty()){
    int s=Q.front();
    for(int i=0;i<graph[s].size();i++){
        if(!visit[graph[s][i]]){
            if(visit[s]==1){
                lyrs++;
                visit[graph[s][i]]=2;
            }
            else{
                vemp++;
                visit[graph[s][i]]=1;
            }
         Q.push(graph[s][i]);
         nodes[graph[s][i]]=0;
        }
    }
    Q.pop();
 }
     return max(vemp,lyrs);
}

int main(){
  int t,cnt=0,n,u,v,sum;
  scanf("%d",&t);
  while(t--){
    cnt++,sum=0;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      scanf("%d %d",&u,&v);
      graph[u].push_back(v);
      graph[v].push_back(u);
      nodes[v]=1; nodes[u]=1;
   }
   for(int i=0;i<MAX;i++){
      if(nodes[i]==1)
       sum+=BSF(i);
   }
    printf("Case %d: %d\n",cnt,sum);

    for(int i=0;i<MAX;i++){
      nodes[i]=visit[i]=0;
      graph[i].clear();
    }

  }

return 0;
}
