#include <stdio.h>
#include <stdlib.h>
#define MAX 4096

char outcomes1[9][3] = {    
    {'A','X',4},
    {'A','Y',8},
    {'A','Z',3},
    {'B','X',1},
    {'B','Y',5},
    {'B','Z',9},
    {'C','X',7},
    {'C','Y',2},
    {'C','Z',6},
};

char outcomes2[9][3] = {
    {'A','X',3},
    {'A','Y',4},
    {'A','Z',8},
    {'B','X',1},
    {'B','Y',5},
    {'B','Z',9},
    {'C','X',2},
    {'C','Y',6},
    {'C','Z',7},
};

int main(void)
{  
    FILE* file = fopen("input.txt","r");
    char buffer[MAX], p1, p2; 
    int score1=0, score2=0;

    while(fgets(buffer,MAX,file))
    {
        sscanf(buffer,"%c %c", &p1, &p2);
        for(int i=0; i<9; i++)
        {
            if(outcomes1[i][0] == p1 && outcomes1[i][1] == p2)
            {
                score1 += (int)(outcomes1[i][2]);
            }
            if(outcomes2[i][0] == p1 && outcomes1[i][1] == p2)
            {
                score2 += (int)(outcomes2[i][2]);
            }
        }
    }
    printf("score1= %d, score2= %d",score1,score2);
}

