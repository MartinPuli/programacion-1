#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * puntero = NULL;
    int block_size= 0;
    double mem_total = 0;

    do{
        mem_total += block_size;

    }while ((puntero=malloc(block_size)) != NULL);

    printf("cantidad de bytes: %d bytes", mem_total);

    return 0;
}
