void progress(player *p)
{
    printf("\033[42m------------------------------------------------------------------\033[0m\n");
    printf("Player : \033[1;37;44m%s\033[0m\n",p->name);
    printf("Overall Score : \033[1;37;44m%d\033[0m\n",p->totalScore);
    printf("you've completed \033[1;37;44m%d\033[0m questions out of 10 From Gaming questions\n",p->score[0]);
    printf("you've completed \033[1;37;44m%d\033[0m questions out of 10 From Greek questions\n",p->score[1]);
    printf("you've completed \033[1;37;44m%d\033[0m questions out of 10 From Football questions\n",p->score[2]);
    printf("\033[42m------------------------------------------------------------------\033[0m\n");
}