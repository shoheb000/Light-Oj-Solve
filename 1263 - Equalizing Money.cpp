#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAX 1001

using namespace std;

int mny[MAX], visit[MAX], t_mny, crry, T, cnt = 0 , n, m, u, v, track , flag, cnt1, iden;;
vector < int > G[MAX], store;
queue <int> Q;

int BFS(int s){

    t_mny = crry = 0;
    t_mny += mny[s];
    crry ++;
    visit[s] = 1;
    Q.push(s);

    while(!Q.empty()){

        s = Q.front();
        Q.pop();

        for(int i = 0; i< G[s].size(); i++){
           if(!visit[G[s][i]]){
            t_mny += mny[G[s][i]];
            crry ++;
            visit[G[s][i]] = 1;
            Q.push(G[s][i]);
           }
        }
    }

    if(!(t_mny%crry))
      return t_mny/crry;
    else return -1;
}

void clr(){
    for(int i = 1; i <= MAX; i++){

            visit[i] = mny[i] = 0;
            G[i].clear();
    }
    store.clear();
}


int main(){

    scanf("%d", &T);

    while(T--){
        cnt ++;
        track = flag = cnt1 = 0;
        scanf("%d %d", &n, &m);

        for(int i = 1; i <= n; i++) scanf("%d", &mny[i]);

        for(int i = 1; i <= m; i++){
          scanf("%d %d", &u, &v);
          G[u].push_back(v);
          G[v].push_back(u);
        }

        if(!m){
           for(int i = 1; i < n; i++)
              if(mny[i] != mny[i+1]) track = 1;

           if(!!track) printf("Case %d: No\n", cnt);
           else printf("Case %d: Yes\n", cnt);

           clr();
           continue;
        }



        for(int i = 1; i <= n; i++){
             if(G[i].size()!= 0 && !visit[i]){
                int bfs_v = BFS(i);
                if(bfs_v != (-1))
                    store.push_back(bfs_v);
                else
                    track = 1;
            }
        }

        if(!!track){
           printf("Case %d: No\n", cnt);
           clr();
           continue;
        }

        for(int i = 0; i<store.size()-1; i++)
             if(store[i] != store[i+1]) track = 1;

        if(!!track){
           printf("Case %d: No\n", cnt);
           clr();
           continue;
        }


           for(int i = 1; i <= n; i++){
                if(!visit[i]){
                    cnt1 ++;
                    if(cnt1 == 1)
                     iden = mny[i];
                    else{
                      if(iden != mny[i]) flag = 1;
                    }
                }
            }

            if(!cnt1) printf("Case %d: Yes\n", cnt);
            else{
                if(!flag && iden == store[0]) printf("Case %d: Yes\n", cnt);
                else printf("Case %d: No\n", cnt);
            }

            clr();
    }

 return 0;
}

