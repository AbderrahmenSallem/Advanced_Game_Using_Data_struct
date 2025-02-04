int updateScore(player *p,int value, int type,root *tree)
{
    if(value <= p->score[type])
    {
        return 0;
    }else
    {
    p->score[type] = value;
    char line[MAX];
    strcpy(line,"./Modules/stats/");
    strcat(line,p->id);
    strcat(line,".txt");
    FILE *fileToUpdate = fopen(line,"w");
    if (fileToUpdate == NULL)
    {
        printf("Failed to open personal file for update 2");
        return 1;
    }
    char h[UserMax];
    strcpy(line,"");
    sprintf(line, "%d",p->score[0]);
    strcat(h,line);
    strcat(h,"*");
    sprintf(line, "%d",p->score[1]);
    strcat(h,line);
    strcat(h,"*");
    sprintf(line, "%d",p->score[2]);
    strcat(h,line);
    strcat(h,"*\n");
    fprintf(fileToUpdate, "%s",h);
    fclose(fileToUpdate);
    load(tree);
    }
}