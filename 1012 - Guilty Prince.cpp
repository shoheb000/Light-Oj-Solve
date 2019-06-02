#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
queue<pair<int,int> >Q;
pair<int,int>p;
char matrix[22][22];
int visit[22][22],cnt,column,row;;


int BFS(int x,int y){


  for(int i=1;i<=row;i++)
        for(int j=1;j<=column;j++)
            visit[i][j]=0;

  Q.push(make_pair(x,y));
  visit[x][y]=1;
  cnt=1;
  while(!Q.empty()){
    p=Q.front();
    Q.pop();
    x=p.first;
    y=p.second;

       if(y+1<=column && !visit[x][y+1]){
         if(matrix[x][y+1]=='.'){
              Q.push(make_pair(x,y+1));
              cnt++;
         }

            visit[x][y+1]=1;
      }
      if(y-1>=1 && !visit[x][y-1]){
            if(matrix[x][y-1]=='.'){
                 Q.push(make_pair(x,y-1));
                 cnt++;
            }

                visit[x][y-1]=1;
      }
      if(x-1>=1 && !visit[x-1][y]){
        if(matrix[x-1][y]=='.'){
              Q.push(make_pair(x-1,y));
              cnt++;
           }

            visit[x-1][y]=1;
      }
      if(x+1<=row && !visit[x+1][y]){
        if(matrix[x+1][y]=='.'){
            Q.push(make_pair(x+1,y));
            cnt++;
        }

            visit[x+1][y]=1;
      }

  }
  return cnt;

}

int main(){
    int t,x,y,ts=0;
    cin>>t;
    while(t--){

        cin>>column>>row;
        for(int i=1;i<=row;i++)
        for(int j=1;j<=column;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]=='@'){
                x=i;
                y=j;
            }
        }
       ts++;
       printf("Case %d: %d\n",ts,BFS(x,y));

    }
    return 0;
}


