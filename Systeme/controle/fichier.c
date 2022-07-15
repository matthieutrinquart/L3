
#include <stdio.h>
int main()
{
    FILE* F;
    int a,b;
    double d;
    printf("-- ecriture1\n");
    F = fopen("test.bin","wb");
    a = 5;
    b = 6;
    d = 5.065;
    fwrite(&a,sizeof(float),1,F);
    fwrite(&d,sizeof(float),1,F);
    fwrite(&b,sizeof(float),1,F);    
    fclose(F);
}