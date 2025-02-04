#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#define MAX  600 // Max number of characters for the variable Line(text File Line container)
#define QMAX 100 // Max String Length For each of the question's Struct Strings
#define TNbrQ 100 // table Nbr max questions

typedef struct question 
{
    char question[QMAX];
    char answer1[QMAX];
    char answer2[QMAX];
    char answer3[QMAX];
    char answer4[QMAX];
    int correct;
}ques;
///////////////////
int readQuestion(int);
int addQuestion();
int pos(char[],char);
///////////////////
ques T[TNbrQ];
char sub[MAX];
char *types_ques[] = {"./Modules/Types/gaming.txt", "./Modules/Types/greek.txt", "./Modules/Types/football.txt"};
///////////////////
int main()
{
    //addQuestion();
    readQuestion(1);
    return 0;
}

int addQuestion() {
    int a = 0;
    while (a == 0) {
        ques q;

        printf("[Question] = \t");
        fgets(q.question, sizeof(q.question), stdin);
        sscanf(q.question, "%99[^\n]", q.question);

        printf("[answer1] = \t");
        fgets(q.answer1, sizeof(q.answer1), stdin);
        sscanf(q.answer1, "%99[^\n]", q.answer1);

        printf("[answer2] = \t");
        fgets(q.answer2, sizeof(q.answer2), stdin);
        sscanf(q.answer2, "%99[^\n]", q.answer2);

        printf("[answer3] = \t");
        fgets(q.answer3, sizeof(q.answer3), stdin);
        sscanf(q.answer3, "%99[^\n]", q.answer3);

        printf("[answer4] = \t");
        fgets(q.answer4, sizeof(q.answer4), stdin);
        sscanf(q.answer4, "%99[^\n]", q.answer4);

        printf("[correct] = \t");
        scanf("%d", &q.correct);

        FILE *file = fopen("questions.txt", "a");
        if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1; 
        }
        char strr[20];
        sprintf(strr, "%d", q.correct);
        char h[MAX] = "";
        strcat(h,q.question);
        strcat(h,"*");
        strcat(h,q.answer1);
        strcat(h,"*");
        strcat(h,q.answer2);
        strcat(h,"*");
        strcat(h,q.answer3);
        strcat(h,"*");
        strcat(h,q.answer4);
        strcat(h,"*");
        strcat(h,strr);
        strcat(h,"*\n");

        fprintf(file, "%s",h);
        fclose(file);
        do
        {
            printf("would you like to continue : \n");
            printf("Pick 0 for yes \n");
            printf("Pick 1 for no \n");
            printf("Your Answer : \t");
            scanf("%d",&a);    
        }while(a != 0 && a != 1); 
        getchar();
    }
    return 0;
}
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
void fillQuestion(ques *q, char line[])
{
    int p = pos(line,'*');
    substr(line,0,p);
    strcpy(q->question,sub);
    substr(line,p+1,-1);
    strcpy(line,sub);
    //
    p = pos(line,'*');
    substr(line,0,p);
    strcpy(q->answer1,sub);
    substr(line,p+1,-1);
    strcpy(line,sub);
    //
    p = pos(line,'*');
    substr(line,0,p);
    strcpy(q->answer2,sub);
    substr(line,p+1,-1);
    strcpy(line,sub);
    //
    p = pos(line,'*');
    substr(line,0,p);
    strcpy(q->answer3,sub);
    substr(line,p+1,-1);
    strcpy(line,sub);
    //
    p = pos(line,'*');
    substr(line,0,p);
    strcpy(q->answer4,sub);
    substr(line,p+1,-1);
    strcpy(line,sub);
    //
    p = pos(line,'*');
    substr(line,0,p);
    q->correct = atol(sub);
    printf("%s\n",q->question);
    printf("%s\n",q->answer1);
    printf("%s\n",q->answer2);
    printf("%s\n",q->answer3);
    printf("%s\n",q->answer4);
    printf("%d\n",q->correct);

    
}
int readQuestion(int type_integer) {
    int n = 0; 
    int i;
    char line[MAX];
    FILE *file = fopen(*(types_ques+type_integer), "r");
    if (file == NULL) {
    printf("Unable to open the file.\n");
    return 1; 
    }
    while(fgets(line,sizeof(line),file) != NULL)
    {
        n = n +1;
    }
    rewind(file);
    for (i = 0; i < n; i++)
    {
        fgets(line,sizeof(line),file);
        ques *q;
        q = malloc(sizeof(ques));
        fillQuestion(q,line);
    }
    return 0;
}