#include<stdio.h>
#include<stdbool.h>

#define S 10

int queenPosition[S][S];

void placeChessQueen(int, int);
void printPositions(int);
bool positionIsAvailable(int, int, int);

int main()
{
	int totalQueens, i, j;
	
	printf("Enter the number of queens: ");
	scanf("%d", &totalQueens);

    for(i=1; i<=totalQueens; i++)
        for(j=0; j<=totalQueens; j++)
            queenPosition[i][j]= 0;

    if(totalQueens<=3)
    {
        printf("\nSolution does not exist !\n\n");
        return 0;
    }
    else
        placeChessQueen(totalQueens, 1);

	return 0;
}


void placeChessQueen(int totalQueens, int queenNo)
{
	int column;
    
 
    if(queenNo== totalQueens+1)                             
    {
        printPositions(totalQueens);
    }
    else
		for(column=1; column<= totalQueens; column++)
		if(positionIsAvailable(totalQueens, queenNo, column))
		{
		
			queenPosition[queenNo][column]= 1;              

			
			placeChessQueen(totalQueens, queenNo+1);        

	
			queenPosition[queenNo][column]= 0;             
		}
}


bool positionIsAvailable(int totalQueens, int queenNo, int column)
{
    int queen, itsColumn;

    
    for(queen=1; queen< queenNo; queen++)
        if(queenPosition[queen][column])
            return false;
    

    for(queen= queenNo-1, itsColumn= column+1; queen>= 1 && itsColumn<=totalQueens; queen--, itsColumn++ )
        if(queenPosition[queen][itsColumn])
            return false;
    
    for(queen= queenNo-1, itsColumn= column-1; queen>= 1 && itsColumn>=1; queen--, itsColumn-- )
        if(queenPosition[queen][itsColumn])
            return false;
    
    return true;
}


void printPositions(int totalQueens)
{                     
    int k, j;
    static int solutionNo= 1;

    printf("\n\nSolution : %d\n\n", solutionNo++);
    for(k=1; k<=totalQueens; k++)
    {
        for(j=1; j<=totalQueens; j++)
        {
            printf("%d ", queenPosition[k][j]);
        }
        printf("\n");
    }
}
