#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int vertices;
    int** adjMatrix;
} Graph;
typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(sizeof(int) * capacity);
    return stack;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}
void dfsWithStack(Graph* graph, int startVertex) {
    Stack* stack = createStack(graph->vertices);
    int* visited = (int*)malloc(sizeof(int) * graph->vertices);
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }
    push(stack, startVertex);
    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }
        for (int i=0;i<graph->vertices;++i) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(stack, i);
            }
        }
    }
    free(visited);
    free(stack->array);
    free(stack);
}
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; ++i) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; ++j) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}
void freeGraph(Graph* graph) {
    for (int i=0;i<graph->vertices;++i) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}
int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    printf("DFS with Stack: ");
    dfsWithStack(graph, 0);
    freeGraph(graph);
    return 0;
}
