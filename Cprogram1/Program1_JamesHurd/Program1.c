/*
 * Program1.c
 *
 *  Created on: Feb 11, 2023
 *      Author: james
 */

#include <stdio.h>
#define INFILE "input.txt"

const char months[12][10] = {"January", //{{{1
                      "February",
                      "March",
                      "April",
                      "May",
                      "June",
                      "July",
                      "August",
                      "September",
                      "October",
                      "November",
                      "December"};
//1}}}

void print_sales_report(const float *data) { //{{{1
printf("Monthy sales report for 2022:\n%-10s\tSales\n","Month");
  for (int i=0; i<=11; ++i)
  {
    printf("%-10s\t$%.2f\n", *(months + i), *(data + i));
  }

}//1}}}

void print_min(const float *data) { //{{{1

float min = *data;
int month = 0;

for (int i=0; i<=11; ++i) {
 float elem = *(data+i);
 if (min >= elem) {
  min = elem;
  month = i;
 }
}

printf("%-10s\t$%.2f\t(%s)\n", "Minimum sales:", min, *(months + month));

} //1}}}

void print_max(const float *data) { //{{{1

float max = *data;
int month = 0;

for (int i=0; i<=11; ++i) {
 float elem = *(data+i);
 if (max <= elem) {
  max = elem;
  month = i;
 }
}

printf("%-10s\t$%.2f\t(%s)\n", "Maximum sales:", max, *(months + month));

} //1}}}

void print_avg(const float *data) { //{{{1

float sum = 0;

for (int i=0; i<=11; ++i)
  sum = sum + *(data +i);

printf("%-10s\t$%.2f\n", "Average sales:", sum/12);
} //1}}}

void print_summary(const float *data) { //{{{1

printf("Sales Summary:\n");
print_min(data);
print_max(data);
print_avg(data);


}//1}}}

void print_six_mon_mov_avg(const float *data) { //{{{1

printf("Six-Month Moving Average Report\n");
for (int i=0; i<=6; ++i) {
  float sum = 0;
  for (int j=0; j<=5; ++j)
    sum = sum + *(data + i + j);
  printf("%-10s\t- %-10s\t$%.2f\n", *(months+i), *(months+i+5), sum/6);
 }
} //1}}}

void print_sorted_sales(const float *data) { //{{{1
printf("Sales Report (Highest to Lowest):\n%-10s\t  Sales\n","  Month");

//indices of both arrays.
int indices[12] = {0,1,2,3,4,5,6,7,8,9,10,11};

//bubble sort.
for(int i=0; i<=11; ++i) {
for(int j=0; j<11-i; ++j) {
  if(*(data + *(indices + j)) > *(data + *(indices +j + 1))) {
   int temp = *(indices + j);
   *(indices + j) = *(indices + j + 1);
   *(indices + j + 1) = temp;
 }
}
}

//print highest to lowest.
for(int i=11; i>=0; --i) {
  int index = *(indices + i);
  printf("%-10s\t$%.2f\n", *(months + index), *(data + index));
}
} //}}}1

int main() { //{{{1


float data[12];

//read input file into data array. {{{2
FILE* infile;
infile = fopen(INFILE, "r");

if ( infile == NULL )
{
  printf("INFILE could not be opened\n");
  return 1;
}

else {

  for (int i=0; i<=11; i++)
  {
    fscanf(infile, "%f", data + i);
  }

fclose(infile);
//2}}}
print_sales_report(data);
printf("\n");
print_summary(data);
printf("\n");
print_six_mon_mov_avg(data);
printf("\n");
print_sorted_sales(data);

return 0;
}

} //1}}}

