#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

int visit[MAX], cost[MAX], in[MAX], out[MAX], n, a, b, c, Track = 0 , cnt_Track = 0, cnt1 = 0, Right = 0, Left = 0;
vector <int> G[MAX], W[MAX];

void DFS (int s){

     visit[s] = 1;

     cnt_Track++;

     if(cnt_Track == 3) visit[Track] = 0;

  for(int i = 0; i<G[s].size(); i++){

    if(!visit[G[s][i]]){

        cost[G[s][i]] = cost[s] + W[s][i];

        if(in[G[s][i]] == 2 || out[G[s][i]] == 2){

              cnt1++;

             if( cnt1%2 == 0 )
                Right += cost[G[s][i]];
             else
                Left += cost[G[s][i]];

             cost[G[s][i]] = 0;

        }
       DFS(G[s][i]);
    }

  }

}

int main(){
    int T, cnt = 0;

    scanf("%d", &T);


    while(T--){
        cnt++;
        getchar();

        scanf("%d", &n);

        for(int i = 1; i<=n; i++){

            scanf("%d %d %d", &a, &b, &c);

            in[b]++;
            out[a]++;


            G[a].push_back(b);
            G[b].push_back(a);

            W[a].push_back(c);
            W[b].push_back(c);


            if(in[b] == 2) Track = b;
            if(out[a] == 2) Track = a;
        }

        DFS(Track);

        printf("Case %d: %d\n",cnt,min(Right,Left));


        for(int i = 0; i<MAX; i++){
            G[i].clear();
            W[i].clear();
            visit[i] = 0;
            cost[i] = 0;
            in[i] = 0;
            out[i] = 0;
        }

        Track = 0, Right = 0, Left = 0 , cnt1 = 0, cnt_Track = 0;
    }


 return 0;
}
