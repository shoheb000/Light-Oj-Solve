#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;
vector<int>tree[30000],weight[30000];
queue<int>Q;
int visit[30000],vartex_value[30000],max_dis,index,n;

int BSF(int start){
    visit[start]=1;
    Q.push(start);

    while(!Q.empty()){
        int s=Q.front(),flag=0;
        Q.pop();
        for(int i=0;i<tree[s].size();i++){
            if(!visit[tree[s][i]]){
                Q.push(tree[s][i]);
                flag=1;
                vartex_value[tree[s][i]]+=(weight[s][i]+vartex_value[s]);
                visit[tree[s][i]]=1;
            }
        }

        if(!flag){
            if(vartex_value[s]>max_dis) {
                    max_dis=vartex_value[s];
                    index=s;
            }
        }
    }
  return max_dis;
}
void clr(){
     for(int j=0;j<n;j++){
           visit[j]=vartex_value[j]=0;
           tree[j].clear();
           weight[j].clear();
       }

}

int main(){
    int test_case,u,v,w;
    scanf("%d",&test_case);
    for(int i=1;i<=test_case;i++){
        scanf("%d",&n);

       for(int j=1;j<n;j++){
        scanf("%d %d %d",&u,&v,&w);
        tree[u].push_back(v);
        tree[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
       }
       max_dis=-1;
       BSF(0);

       for(int j=0;j<n;j++){
        visit[j]=vartex_value[j]=0;
       }
       max_dis=-1;

       printf("Case %d: %d\n",i,BSF(index));
       clr();
    }
return 0;
}
