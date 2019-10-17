#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 27

using namespace std;

int visit[MAX], display[MAX], n, k, cnt1;


void Permutations(int Track){

    if(Track == n+1){
         cnt1++;
         for(int j = 1; j<=n; j++){
            printf("%c", display[j]+64);
         }
         printf("\n");
         return ;
    }

     if(cnt1 == k) return ;



    for(int i = 1; i<=n; i++){
        if(!visit[i]){
            display[Track] = i;
            visit[i] = 1;
            Permutations(Track + 1);
            visit[i] = 0;
        }
    }
}

int main(){

   int T, cnt = 0;
   scanf("%d", &T);

   while(T--){

     cnt1 = 0;
     cnt++;
     scanf("%d %d", &n, &k);

     printf("Case %d:\n", cnt);

     Permutations(1);

     memset(visit, 0, sizeof(visit));
     memset(display, 0, sizeof(display));
   }

return 0;
}
