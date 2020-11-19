#include<stdio.h>

void conv(int A[][100], int B[][100], int K[3][3], int nr, int nc);
void printMatrix(int mat[][100], int nr, int nc);


int main(){

	int K[3][3] ={{0,-1,0},{-1,5,-1},{0,-1,0}};
	int A[6][100] = {{7,6,5,5,6,7},{6,4,3,3,4,6},{5,3,2,2,3,5},{5,3,2,2,3,5},{6,4,3,3,4,6},{7,6,5,5,6,7}};
	int B[6][100];

	conv(A,B,K,6,6);
	printf("A: \n");
	printMatrix(A,6,6);
	printf("B: \n");
        printMatrix(B,6,6);	
	return 0;

}

void printMatrix(int mat[][100], int nr, int nc){
	int i, j;
	for(i = 0; i < nr; i++){
                for(j = 0; j < nc; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

void conv(int A[][100], int B[][100], int K[3][3], int nr, int nc){
	
	int i,j,l,m;
	for(i = 0; i < nr; i++){
		for(j = 0; j < nc; j++){
			int temp = 0;
			for(l = 0; l < 3; l++){
				for(m = 0; m < 3; m++){
					int ArowIndex=i-1+l;
					int AcolIndex=j-1+m;
					
					if(ArowIndex < 0 || ArowIndex >= nr)
						ArowIndex = i;
					if(AcolIndex < 0 || AcolIndex >= nc)
                                                AcolIndex = j;

					temp += A[ArowIndex][AcolIndex]*K[l][m];	
				}
			}
			B[i][j] = temp;
		}
	}

}
