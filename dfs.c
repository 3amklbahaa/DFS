#include <stdio.h>
#include <stdlib.h>
void get_array(int **p, int N){
    printf("plz enter the matrix: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",*(p+i)+j);
        }
    }
}
void print_array(int **p,int N){
    printf("the arrays is: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",*(*(p+i)+j));
        }
        printf("\n");
    }
}
int dfs(int **p, int N, int *visited, int start){
    printf("%d ",start);
    visited[start]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(p[start][j]==1&&!visited[j]){
                dfs(p,N,visited,j);
            }
        }
    }
}
int main(){
    int **p, N, *visited, start;
    printf("plz enter N(number of vertices): ");
    scanf("%d",&N);
    p=(int **)malloc(N*sizeof(int *));
    for(int i=0;i<N;i++){
        *(p+i)=(int *)malloc(N*sizeof(int));
    }
    visited=(int *)malloc(N*sizeof(int));
    printf("plz enter start: ");
    scanf("%d",&start);
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    get_array(p,N);
    print_array(p,N);
    printf("result: ");
    dfs(p,N,visited,start);
    return 0;
}
//try 1 1 0, 0 1 1, 1 0 0
