//Day 1 advent of code -- Counting calories till we reach a empty line, then take max value from array.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10
#define MAX 3

char calories[MAX_LINE_LENGTH];
int sum[MAX];
int max=0,i=0,a,output;

int main()
{

    FILE* ptr = fopen("input.txt","r");
    if (ptr == NULL) 
    {
        printf("no such file.\n");
        return 0;
    }

     while (fgets(calories, MAX_LINE_LENGTH, ptr))
    {
        /* Print each line */
        printf("%s", calories);
        sum[i] += atoi(calories);
        if(calories[0] == '\n')
        {
            i++;
        }
    }
    fclose(ptr);
    printf("sums: %d\n",i);
    for(int j=0;j<i;j++)
    {
        if(max < sum[j])
            max = sum[j];
    }
    printf("max: %d",max);
}

