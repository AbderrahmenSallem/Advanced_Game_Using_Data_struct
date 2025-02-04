// Function to initialize a player node with information from another player
void initPlayerNode(player *dest, player *src) {
    dest->hash = src->hash;
    strcpy(dest->id, src->id);
    strcpy(dest->name, src->name);
    dest->score[0] = src->score[0];
    dest->score[1] = src->score[1];
    dest->score[2] = src->score[2];
    dest->left = NULL;
    dest->right = NULL;
}
// Function to fill player information from the input strings
void fillPlayer(player *pl, char line[], char details[]) {
    int p = pos(line, '*');
    substr(line, 0, p);
    pl->score[0] = atol(sub);
    substr(line, p + 1, -1);
    strcpy(line, sub);

    p = pos(line, '*');
    substr(line, 0, p);
    pl->score[1] = atol(sub);
    substr(line, p + 1, -1);
    strcpy(line, sub);

    p = pos(line, '*');
    substr(line, 0, p);
    pl->score[2] = atol(sub);

    p = pos(details, '*');
    substr(details, 0, p);
    strcpy(pl->id, sub);
    substr(details, p + 1, -1);
    strcpy(details, sub);

    p = pos(details, '*');
    substr(details, 0, p);
    strcpy(pl->name, sub);

    pl->hash = customHash(pl->id);
    pl->totalScore = pl->score[0] + pl->score[1] + pl->score[2];
}

// Function to create a player node in the binary tree
void binaryTreeCreator(player *p, player *pp) {
    if (p == NULL) {
        p = malloc(sizeof(player));
        initPlayerNode(p, pp);
        return;
    }

    if (pp->hash >= p->hash) {
        if (p->right != NULL) {
            binaryTreeCreator(p->right, pp);
        } else {
            p->right = malloc(sizeof(player));
            initPlayerNode(p->right, pp);
        }
    } else {
        if (p->left != NULL) {
            binaryTreeCreator(p->left, pp);
        } else {
            p->left = malloc(sizeof(player));
            initPlayerNode(p->left, pp);
        }
    }
}

// Function to create a player node in the leaderboard binary tree
void binaryTreeCreatorLeaderBoard(player *p, player *pp) {
    if (p == NULL) {
        p = malloc(sizeof(player));
        initPlayerNode(p, pp);
        return;
    }

    if (pp->totalScore >= p->totalScore) {
        if (p->rightScore != NULL) {
            binaryTreeCreatorLeaderBoard(p->rightScore, pp);
        } else {
            p->rightScore = malloc(sizeof(player));
            initPlayerNode(p->rightScore, pp);
        }
    } else {
        if (p->leftScore != NULL) {
            binaryTreeCreatorLeaderBoard(p->leftScore, pp);
        } else {
            p->leftScore = malloc(sizeof(player));
            initPlayerNode(p->leftScore, pp);
        }
    }
}


// Function to load player information from a file into a tree
int loadPlayers(root *tree) {
    FILE *file = fopen("./Modules/stats/players.txt", "r");
    if (file == NULL) {
        perror("Failed to open players file");
        return 1;
    }

    int n = 0;
    char line[UserMax];
    while (fgets(line, sizeof(line), file) != NULL) {
        n = n + 1;
    }
    rewind(file);

    int i = 0;
    player *pl;
    for (i = 0; i < n; i++) {
        fgets(line, sizeof(line), file);
        int p = pos(line, '*');
        substr(line, 0, p);
        char tmpchar[UserMax];
        strcpy(tmpchar, "");
        strcat(tmpchar, "./Modules/stats/");
        strcat(tmpchar, sub);
        strcat(tmpchar, ".txt");

        FILE *personal = fopen(tmpchar, "r");
        if (personal == NULL) {
            perror("Failed to open personal file");
            return -1;
        }

        fgets(tmpchar, sizeof(tmpchar), personal);
        player *pp = malloc(sizeof(player));
        fillPlayer(pp, tmpchar, line);

        if (i == 0) {
            tree->p = pp;
            pp->right = NULL;
            pp->left = NULL;
            tree->leaderBoardTree = pp;
        } else {
            binaryTreeCreator(tree->p, pp);
            binaryTreeCreatorLeaderBoard(tree->leaderBoardTree, pp);
        }
    }

    // Close the file
    fclose(file);
    return 0;
}
