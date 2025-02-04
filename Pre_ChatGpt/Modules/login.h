int search(player *p, int searchHash,player *currentUser)
{
    if (p == NULL)
    {
        return 0;
    }else if ( ( p->right == NULL ) && ( p->left == NULL ) )
    {
        strcpy(currentUser->name , p->name);
        strcpy(currentUser->id , p->id);
        currentUser->score[0] = p->score[0];
        currentUser->score[1] = p->score[1];
        currentUser->score[2] = p->score[2];
        currentUser->totalScore = p->totalScore;
        currentUser->hash = p->hash;
        //printf("username is %s",p->name);
        return (p->hash == searchHash);
    }
    else if (p->hash == searchHash)
    {
        strcpy(currentUser->name , p->name);
        strcpy(currentUser->id , p->id);
        currentUser->score[0] = p->score[0];
        currentUser->score[1] = p->score[1];
        currentUser->score[2] = p->score[2];
        currentUser->totalScore = p->totalScore;
        currentUser->hash = p->hash;
        //printf("username is %s",p->name);
        return 1;
    }else
    {
        if (searchHash >= p->hash)
        {
            return search(p->right, searchHash,currentUser);
        }else
        {
            return search(p->left, searchHash,currentUser);
        }
    }
}


int login(root *tree,player *currentUser,char msg[])
{
    char loginID[UserMax];
    printf("User ID \t");
    scanf("%s",loginID);
    int i;
    i = search(tree->p, customHash(loginID),currentUser);
    if (i == 0)
    {
        strcpy(msg ,"User doesn't exist");
        return 1;
    }else
    {
        strcpy(msg ,"Login was successful");
        return 0;
    }


    
    return 0;
}