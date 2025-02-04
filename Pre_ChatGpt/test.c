#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Modules/modules.h"
#include "./Modules/functionc.h"
#include "./Modules/LoadQuestionTree.h"
#include "./Modules/LoadPlayerTree.h"
#include "./Modules/load.h"
#include "./Modules/signup.h"
#include "./Modules/login.h"
#include "./Modules/leaderboard.h"
#include "./Modules/score.h"
#include "./Modules/progress.h"
#include "./Modules/rungame.h"

char msg[PMAX];


int main()
{
    root *tree = malloc(sizeof(root));
    load(tree);
    //updateScore(tree->p,3,1);
    player *currentUser;
    currentUser = malloc(sizeof(player));
    //leaderBoard(tree->p,tree->p->hash);
    /*printf("the name is %s\n",tree->leaderBoardTree->name);
    printf("the name is %s\n",tree->leaderBoardTree->leftScore->name);
    printf("the name is %s\n",tree->leaderBoardTree->leftScore->rightScore->name);
    printf("the name is %s\n",tree->leaderBoardTree->leftScore->rightScore->name);
    printf("the name is %s\n",tree->leaderBoardTree->leftScore->rightScore->rightScore->name);*/
    rungame(tree,msg,currentUser);
    //login(tree,currentUser,msg);
    //printf("the has of p  is %d \n",tree->p->right->hash);
    //printf("the hash of scoreTree  is %d \n",tree->leaderBoardTree->leftScore->hash);
    //printf("%s",n->q->question);
    /*for (ques *tmp = tree->t3->q; tmp != NULL ; tmp = tmp->q)
    {
            printf("%s\n",tmp->question);
            printf("1) %s\t\t\t",tmp->answer1);
            printf("2) %s\n",tmp->answer2);
            printf("3) %s\t\t\t",tmp->answer3);
            printf("4) %s\n",tmp->answer4);
            printf("////////////////////////////////////////////////////\n");
    }
    printf("\033[42mHello, colored background!\033[0m\n");
    printf("\033[1;37;44mHello, colored terminal!\033[0m\n");*/

    //system("cls");
    //signUp();
    //updateScore(tree->p,3,2);

}

