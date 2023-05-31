#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j, **graph, *queue, *visited;
    int q_st = 0;//queue start
    int q_end = 0;//queue end
    int start = 0;
    int vertex = 1;
    FILE *f;
    char file[] = "D://clion projects//practice//6//practice6.txt";
    //char file[] = "practice6.txt";
    int n = 7;//matrix size
    f = fopen(file, "r");

    if (f == NULL) {
        printf("Cannot open file");
        return 0;
    }
	
	graph = (int**)malloc(sizeof(int*)*n);
    for(i = 0; i < n; i++)
        graph[i] = (int*)malloc(sizeof(int)*n);
        
    printf("Matrix from my txt file\n");

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
        	fscanf(f, "%d ", &graph[i][j]);
            printf("%4d", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Enter start for the bfs:");
    scanf("%d", &start);
    start--;
    queue = (int*)malloc(sizeof(int)*n);
    visited = (int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        queue[i] = 0;
        visited[i]=0;
    }
    printf("Path:");
    visited[start] = 1;
    vertex += start;
    printf("%d ", vertex);
    q_end++;
    queue[q_end] = start;

    while (q_st != q_end) {
        q_st++;
        for (i = 0; i < n; i++) {
            if (graph[queue[q_st]][i] && !visited[i]) {
                visited[i] = 1;
                vertex = i + 1;
                printf("%d ", vertex);
                q_end++;
                queue[q_end] = i;
            }
        }
    }
    fclose(f);
    return 0;
}