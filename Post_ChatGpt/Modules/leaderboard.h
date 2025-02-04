void leaderBoard(player *tmp,int hash)
{
    if (tmp == NULL)
    {
        return;
    }

    leaderBoard(tmp->rightScore,hash);  // Traverse based on right for ordering
    if (tmp->hash == hash)
    {
        printf("\033[1;37;44mName: %s with a score of %d\033[0m\n", tmp->name, tmp->score[0]+tmp->score[1]+tmp->score[2]);
    }
    else{
        printf("Name: %s with a score of %d\n", tmp->name, tmp->score[0]+tmp->score[1]+tmp->score[2]);
    }
    leaderBoard(tmp->leftScore,hash);   // Traverse based on left for ordering
}