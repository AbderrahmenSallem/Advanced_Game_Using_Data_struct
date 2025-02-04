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
    player *currentUser;
    currentUser = malloc(sizeof(player));
    rungame(tree,msg,currentUser);
}

