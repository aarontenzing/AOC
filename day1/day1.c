//Day 1 advent of code -- Counting calories till we reach a empty line, then take max value from array.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10
#define MAX 1000

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
        //printf("%s", calories);
        sum[i] += atoi(calories);
        if(calories[0] == '\n')
        {
            i++;
        }
    }
    fclose(ptr);

    int z=0,tmp=0,tot=0,j=0;
    while(z < 3)
    {
        for(j=0;j<i;j++)
        {
            if(max < sum[j])
                max = sum[j];
                tmp = j;
        }
        printf("max=%d  index=%d\n",max,tmp);
        tot += max;
        max=0;
        j=0;
        sum[tmp] = 0;
        z++;
    }
    printf("tot: %d, sum%d",tot,i);
}

