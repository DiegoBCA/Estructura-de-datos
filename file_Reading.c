
#include <stdio.h>
#include <stdlib.h>

float totalSale(float sales[],int n){
    float total = 0.0;
    for(int i=0;i<n;i++){
        total += sales[i];
    }
    return total;
}

float maxSales(float sales[], int n){
    float max = sales[0];
    for(int i=1;i<n;i++){
        if(sales[i] > max){
            max = sales[i];
        }
    }
    return max;
}

int main(){
    FILE *fp;
    int lineas=0;
    float *sales;
    float total, max;

    fp=fopen("saless.txt","r");
    if(fp==NULL){
        printf("No se pudo abrir el archivo");
        return 1;
    }

    while (!feof(fp)){
        float valor;
        if(fscanf(fp, "%f", &valor) == 1)
            lineas++;
    }

    sales = (float *) malloc(lineas * sizeof(float));
    if(sales == NULL){
        printf("No se pudo reservar memoria");
        fclose(fp);
        exit(1);
    }
    rewind(fp);
    
    for(int i=0;i<lineas;i++){
        fscanf(fp, "%f", &sales[i]);
    }
    total=totalSale(sales, lineas);
    max=maxSales(sales, lineas);
    printf("Total de sale: %.2f\n", total);
    printf("maximo de sales: %.2f\n", max);
    fclose(fp);
    free(sales);
    return 0;
}

