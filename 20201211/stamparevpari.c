#include <stdio.h>

void fun(FILE *f1, FILE *f2);


int main(){

	int values1[]={1,4,57,51,72,5,6}, values2[7]={0};

	FILE *f1 = fopen("input.dat","wb");
	fwrite(values1, sizeof(int),7,f1);
	fclose(f1);

	f1 = fopen("input.dat","rb");
	FILE *f2 = fopen("out.dat","wb"); 

	fun(f1,f2);

	fclose(f1);
	fclose(f2);

	f1 = fopen("out.dat", "rb");

	int i,j;
	i = fread(values2,sizeof(int),7,f1);

	for(j = 0; j < i; j++){
		printf("%d ", values2[j]);
	}
	printf("\n");

	return 0;
}


void fun(FILE *f1, FILE *f2){
	
	int a,b;

	a = fseek(f1, -sizeof(int), SEEK_END);

	while(a==0){
		if(fread(&b, sizeof(int),1,f1)!=0 && (b%2==0))
			fwrite(&b,sizeof(int),1,f2);
		
		a = fseek(f1, -2*sizeof(int),SEEK_CUR);
	}
}

// 1 6 4
 
