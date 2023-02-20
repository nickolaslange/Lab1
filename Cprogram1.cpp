#include <stdio.h>
#include <string.h>

int main () {

/*read input and store in list*/
FILE* fpntr;
fpntr = fopen("input1.txt", "r");

int file_line = 0;
char sales[12][500];
/*char sales[12][500];*/

/*if the file we're handed exists*/
while (!feof(fpntr) && !ferror(fpntr)) {
    if (fgets(sales[file_line], 50, fpntr) != NULL) 
        file_line++; 
}

fclose(fpntr);

/*array of each month (as an int), each month has contains an array of len 1, which will contain its value*/
char months[12][10] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

/*monthly sales report*/
printf("\nMonthly sales report for 2023: \n\n");
printf("Month       Sales\n\n");
for (int i = 0; i < 12; i++) {
        printf("%-10s  ", months[i]);
        printf("$%s", sales[i]);
    }


/*sales summary*/
printf("\n\nSales summary: \n\n");
/*find min and max and add all nums together (divide them later)*/
/*go through each num in the array, if its smaller than the one already stored it is the smallest one*/
char* min = sales[0];
char* max = sales[0];
/*char* end;*/
int min_month, max_month;
char total_sales;
for (int i = 0; i < 12; i++) {
    if (sales[i] < min) {
        min = sales[i];
        min_month = i;
    }
    if (sales[i] > max) {
        max = sales[i];
        max_month = i;
    }
    /*total_sales = sales[i];*/
}

printf("Minumum sales: $%s (%s)", min, months[min_month]);
printf("\nMaximum sales: $%s (%s)", max, months[max_month]);
/*printf("\nAverage sales: $%s", total_sales);*/

char a[100];
char strcpy(a, sales[0]);
printf("%s", a);


/*take each num*/

/*Six-month moving average*/

/*sales report*/

    return 0;

}