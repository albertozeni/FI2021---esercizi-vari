#include <stdio.h>
 
void fun(FILE *f1, FILE *f2)
{
	int i, v1, v2;
 
	while (fread(&v1, sizeof(int), 1, f1) != 0){
    		fread(&v2, sizeof(int), 1, f1);
    		for (i = 0; i < v2; i++){
    			fprintf(f2, "%c", v1);
		}
    		fprintf(f2, "%c", ' ');
    	}
}
 
int main()
{
	FILE *out, *in;
 
	out = fopen("es1.dat","wb");
	int coppie[] = {'z' ,5,'b',10,'c',3,'j',19};
	fwrite(coppie,sizeof(int),8,out);
	fclose(out);
 
	in = fopen("es1.dat","rb");
	out = fopen("es1.txt","w");
	fun(in,out);
 
	return 0;
}
