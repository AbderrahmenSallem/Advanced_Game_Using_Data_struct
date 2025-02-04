#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////




int pos(char line[],char x)
{
    int i;
    for(i = 0; i < strlen(line); i++)
    {
        if (line[i] == x)
        {
            return i;
        }
    }
    return -1;
}
void  substr( char string[],int x, int y)
{
    int i;
    //char ch[strlen(string)+1];
    if(y != -1)
    {
        char ch[y-x+1];
        for(i = x; i < y; i++)
        {
            ch[i-x] = string[i];
        }
        ch[y-x]= '\0';
        strcpy(sub, ch);
    }
    else
    {
        int n = strlen(string);
        char ch[n-x+1];
        for(i = x; i < n; i++)
        {
            ch[i-x] = string[i];
        }
        ch[n-x]= '\0';
        strcpy(sub, ch);
    }
    
    
}

int updatePlayer(char id[],int score, int k)
{
    player *new;
    new = malloc(sizeof(player));
    char line[UserMax];
    strcpy(line,"./Modules/stats/");
    strcat(line,id);
    strcat(line,".txt");
    FILE *file = fopen(line,"r");
    if (file == NULL)
    {
        printf("Failed to open personal file for update 1");
        return 1;
    }
    int PlayerStatsTab[] = {1,1,1};
    fgets(line,sizeof(line),file);
    int p = pos(line,'*');
    substr(line,0,p);
    PlayerStatsTab[0] = atol(sub);
    substr(line,p+1,-1);
    strcpy(line,sub);
    //
    p = pos(line,'*');
    substr(line,0,p);
    PlayerStatsTab[1] = atol(sub);
    substr(line,p+1,-1);
    strcpy(line,sub);
    //
    p = pos(line,'*');
    substr(line,0,p);
    PlayerStatsTab[2] = atol(sub);
    PlayerStatsTab[k] = score;
    strcpy(line,"./Modules/stats/");
    strcat(line,id);
    strcat(line,".txt");
    FILE *fileToUpdate = fopen(line,"w");
    if (fileToUpdate == NULL)
    {
        printf("Failed to open personal file for update 2");
        return 1;
    }
    char h[UserMax];
    strcpy(line,"");
    sprintf(line, "%d",PlayerStatsTab[0]);
    strcat(h,line);
    strcat(h,"*");
    sprintf(line, "%d",PlayerStatsTab[1]);
    strcat(h,line);
    strcat(h,"*");
    sprintf(line, "%d",PlayerStatsTab[2]);
    strcat(h,line);
    strcat(h,"*\n");
    fprintf(fileToUpdate, "%s",h);
    fclose(fileToUpdate);
}

int customHash(const char *str)
{
    unsigned int hash = 0;
    int c;
    int position = 1; // Starting position, assuming positions start at 1

    while ((c = *str++))
    {
        hash += (c * position); // Multiply ASCII value by position
        position++;
    }

    return hash;
}
