#include <stdio.h>
#include <stdlib.h>
void fill_matrix(int **p,int N){
    int i, j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("plz enter the T[%d][%d] elemet: ",i+1,j+1);
            scanf("%d",*(p+i)+j);
        }
    }
}
void print_matrix(int **p, int N){
    int j,i;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d",*(*(p+i)+j));
        }
        printf("\n");
    }
}
int dfs(int **p,int N,int start,int *visited){
    printf("%d\t",start);
    visited[start]=1;
    for(int j=0;j<N;j++){
        if(*(*(p+start)+j)==1&&!visited[j]){
            dfs(p,N,j,visited);
        }
    }
}
int main(){
    int **p,N,i,start,*visited;
    printf("plz enter N: ");
    scanf("%d",&N);
    printf("plz enter where u start: ");
    scanf("%d",&start);
    p=(int **)malloc(N*sizeof(int *));
    for(i=0;i<N;i++){
        *(p+i)=(int *)malloc(N*sizeof(int));
    }
    visited=(int*)malloc(N*sizeof(int));
    fill_matrix(p,N);
    print_matrix(p,N);
    dfs(p,N,start,visited);
}
