#include <stdio.h>
#include <string.h>
#define MAX 25000

int score=0;

typedef struct players {
        char p1;
        char p2;
    } players;

int switch_case(char input)
{
    switch(input) {
            case 'X':
                return 1;
            case 'Y':
                return 2;
            case 'Z':
                return 3;
            case 'A':
                return 1; 
            case 'B':
                return 2; 
            case 'C':
                return 3; 
        }
}

int outcome(int x1,int x2) {

    if((x2 == 1 && (x1 == 3)) || (x2 == 2 && (x1 == 1)) || (x2 =3 && (x1==2)) )
    {
        return 1;
    }
    else if ( (x2 == 3 && (x1 == 1))|| (x2 == 2 && (x1 == 3)) || (x2 == 1 && (x1 == 2)) )
    {
        return 2;
    }
    else {
        return 3;
    }
    
}

int main()
{  
    int x1,x2;

    FILE* file = fopen("input.txt","r");
    if(file == NULL)
    {
        printf("no such file.\n");
        return 0;
    }

    char buffer[MAX];
    int res;
    fgets(buffer,MAX,file);

    while(!feof(file))
    {
        players p;
        sscanf(buffer,"%c %c", &p.p1, &p.p2);
        fgets(buffer,200,file);

        x1 = switch_case(p.p1);
        x2 = switch_case(p.p1);
        res = outcome(x1,x2);
        printf("res=%d\n",res);
        
        if(res == 1)
        {
            score += (x2 + 6);
        }
        else if(res == 3)
        {
            score += (x2 + 3);
        }
        else if(res == 2)
        {
            score += x2;
        }

        printf("%c= %d ,%c= %d \n",p.p1,x1,p.p2,x2);
    }
    fclose(file);
    printf("%d \n",score);
    return 0;
}