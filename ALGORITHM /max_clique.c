#include<stdio.h>
#include <stdlib.h>

#define S 10

int choosenVertices[S], choice;

void max_clique(int [][S], int);
void findMAxCliqueUsingCombinations(int [][S], int, int, int, int);

int main()
{
    int i, j, n, G[S][S];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: ");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("\n");

    max_clique(G, n);

    return 0;
}

void max_clique(int G[][S], int n) {
    int cliqueSize, u, v;

     for(cliqueSize = n; cliqueSize >=2; cliqueSize--) {
        findMAxCliqueUsingCombinations(G, n, cliqueSize, 1, 0);
    }
}

void findMAxCliqueUsingCombinations(int G[][S], int n, int cliqueSize, int currentValue, int position) {
    int i = 0, j=0, lastValue, value, u, v, edgeCount = 0;

    if(position == cliqueSize -1)
    {
        for(lastValue = choosenVertices[position-1] + 1; lastValue <= n; lastValue++) {
            choosenVertices[position] = lastValue;

         
            for(i = 0; i < cliqueSize; i++) {
                for(j = 0; j != i && (j < cliqueSize); j++) {
                    if(G[choosenVertices[i]][choosenVertices[j]])
                        edgeCount++;
                }
            }

         
            if(edgeCount == cliqueSize*(cliqueSize - 1)/2) {
                printf("Max clique of size %d is present\n", cliqueSize);
                printf("The nodes forming the clique are: "); 
                for(u = 0; u < cliqueSize; u++) {
                    printf("%d ", choosenVertices[u]);
                }
                printf("\n\n");
                
                exit(0);
        }
        edgeCount=0;
    }
    }
    else {
        
        for(value = currentValue; value < n; value++) {
            choosenVertices[position] = value;
            findMAxCliqueUsingCombinations(G, n, cliqueSize, choosenVertices[position] + 1, position + 1); 
        }
    }
}
