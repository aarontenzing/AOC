#include <stdio.h>

int main()
{
    char p1,p2;
    FILE* file = fopen("input.txt","r");
    if(file == NULL)
    {
        printf("no such file.\n");
        return 0;
    }

    while(fscanf(file,"%c %c",p1,p2))
    {
        printf("%c %c",p1,p2);   
    }
}