#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000


void vet_printer(int *vet, int size){
    int i;
    int temp;
    for (i=0; i<size;i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

// shellsort function
void shellSort(int *vet, int size) {
    
    int i, j, value;
    int h = 1;
    while(h < size) {
        h = 3*h+1;
    }
    while (h >= 1) {
        //printf("%d\n",h);
        for(i = h; i < size; i++) {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = value;
            //vet_printer(vet,size);
        }
        h = h/3;
    }
}

int main(){

    clock_t start_t, end_t, total_t;
    FILE *myFile;
    myFile = fopen("crescente.txt", "r");

    //read file into array
    
    int numberArray[SIZE];
    int i;
    //reading part
    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < SIZE; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
    }

    fclose(myFile);
    
    //sorting part
    start_t = clock();
    printf("Starting shellsort, start_t = %ld\n", start_t);

    shellSort(numberArray, SIZE);
    end_t = clock();

    vet_printer(numberArray, SIZE);

    printf("End of shellsort, end_t = %ld\n", end_t);
   
    total_t = (end_t - start_t);
    printf("Total time taken by CPU in clocks: %ld\n", total_t  );
    printf("Exiting of the program...\n");


    return 0;
}