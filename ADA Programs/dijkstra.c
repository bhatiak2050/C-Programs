#include<stdio.h>
#include<stdbool.h>
#define INT_MAX 999

int min_wt(int nv, int dist[], bool vlist[]){
	int min = INT_MAX;
	int min_index, i;

	for(i=0; i<nv; i++)
	if(vlist[i] == false && dist[i] < min){
		min = dist[i];
		min_index = i;
	}
	return min_index;
}

void dijkstra(int nv, int graph[nv][nv], int src){
	int dist[nv], i;
	bool vlist[nv];

	for(i=0; i<nv; i++){
		dist[i] = INT_MAX;
		vlist[i] = false;
	}

	dist[src] = 0;

	for(i=0; i<nv-1; i++){
		int u = min_wt(nv, dist, vlist);
		vlist[u] = true;

		for(int v=0; v<nv; v++)
		if(	graph[nv][nv] != INT_MAX &&
			vlist[v] == false 	 &&
			dist[u] != INT_MAX 	 &&
			(dist[u] + graph[u][v]) < dist[v])
		{
			dist[v] = dist[u] + graph[u][v];
		}
	}

    for(i=0; i<nv; i++)
	(i!=src)?printf("%d - %d = %d\n", src, i, dist[i]):0;
}

int main(){
	int nv, src, i, j;
	printf("Enter the number of vertices: ");
	scanf("%d", &nv);

	int graph[nv][nv];
	 printf("Enter the matrix:\n");
        for(i=0; i<nv; i++)
        for(j=0; j<nv; j++)
                if(i==j) graph[i][j] = INT_MAX;
                else scanf("%d", &graph[i][j]);

	printf("Select the source vertex (in INDEX notation): ");
	scanf("%d", &src);

	dijkstra(nv, graph, src);
	return 0;
}
