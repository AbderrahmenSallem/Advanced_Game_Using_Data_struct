int gettingStarted(root *tree, char msg[], player *currentUser) {
    char *display[] = {"\033[42m---------------------------------\033[0m\n",
                       "             Welcome             \n",
                       "        To Log-In Input 1       \n",
                       "        To SignUp Input 2      \n"};
    int i;

    do {
        system("cls");
        if (strlen(msg) != 0) {
            printf("%s\n", msg);
        }
        strcpy(msg, "");

        for (i = 0; i < 5; i++) {
            if (i < 4) {
                printf("%s", *(display + i));
                printf("\n");
            } else {
                printf("%s", *(display));
            }
        }

        i = -1;
        printf("Your answer is\t");
        scanf("%d", &i);

        if (i != 1 && i != 2) {
            strcpy(msg, "Make sure to select either 1 or 2");
        }
    } while (i != 1 && i != 2);

    if (i == 1) {
        return login(tree, currentUser, msg);
    } else {
        return signUp(msg, tree);
    }
}

void start(root *tree, char msg[], player *currentUser) {
    char *display[] = {"\033[42m---------------------------------\033[0m\n",
                       "   To Pick Gaming Input 1       \n",
                       "   To Pick Greek Input 2      \n",
                       "   To Pick Football Input 3      \n"};
    int i;

    do {
        system("cls");
        if (strlen(msg) != 0) {
            printf("%s\n", msg);
        }
        strcpy(msg, "");

        for (i = 0; i < 5; i++) {
            if (i < 4) {
                printf("%s", *(display + i));
                printf("\n");
            } else {
                printf("%s", *(display));
            }
        }

        i = -1;
        printf("Your answer is\t");
        scanf("%d", &i);

        if (i != 1 && i != 2 && i != 3) {
            strcpy(msg, "Make sure to select either 1, 2, or 3");
        }
    } while (i != 1 && i != 2 && i != 3);

    ques *list;
    if (i == 1) {
        list = tree->t1->q;
    } else if (i == 2) {
        list = tree->t2->q;
    } else {
        list = tree->t3->q;
    }

    int typeholder = i;
    int score = 0;

    for (ques *tmp = list; tmp != NULL; tmp = tmp->q) {
        do {
            system("cls");
            i = -1;
            if (strlen(msg) != 0) {
                printf("%s\n", msg);
            }
            strcpy(msg, "");
            printf("%s\n", tmp->question);
            printf("1) %s\n", tmp->answer1);
            printf("2) %s\n", tmp->answer2);
            printf("3) %s\n", tmp->answer3);
            printf("4) %s\n", tmp->answer4);
            printf("Your pick : ");
            scanf("%d", &i);

            if (i != 1 && i != 2 && i != 3 && i != 4) {
                strcpy(msg, "Make sure to select either 1, 2, 3, or 4");
            }
        } while (i != 1 && i != 2 && i != 3 && i != 4);

        if (i == tmp->correct) {
            strcpy(msg, "Answer Correct");
            score++;
        } else {
            printf("You failed. Better luck next time.\n");
            updateScore(currentUser, score, typeholder - 1, tree);
            break;
        }
    }

    if (score == 10) {
        printf("You conquered this Type\n");
        updateScore(currentUser, score, typeholder - 1, tree);
    }
}

int menu(root *tree, player *p, char msg[], player *currentUser) {
    char *display[] = {"\033[42m---------------------------------\033[0m\n",
                       "         To play Input 1       \n",
                       "   To Check Leaderboard Input 2      \n",
                       "  To Check your progress Input 3       \n",
                       "        to quit press 4             \n"};
    int i;

    do {
        system("cls");
        if (strlen(msg) != 0) {
            printf("%s\n", msg);
        }
        strcpy(msg, "");

        for (i = 0; i < 6; i++) {
            if (i < 5) {
                printf("%s", *(display + i));
                printf("\n");
            } else {
                printf("%s", *(display));
            }
        }

        i = -1;
        printf("Your answer is\t");
        scanf("%d", &i);

        if (i != 1 && i != 2 && i != 3 && i != 4) {
            strcpy(msg, "Make sure to select either 1, 2, 3, or 4");
        }
    } while (i != 1 && i != 2 && i != 3 && i != 4);

    if (i == 4) {
        return 0;
    } else if (i == 2) {
        do {
            system("cls");
            leaderBoard(p, currentUser->hash);
            printf("Would you like to continue yes(1)/no(0) :  ");
            scanf("%d", &i);
        } while (i != 0 && i != 1);
        return i;
    } else if (i == 3) {
        do {
            system("cls");
            progress(currentUser);
            printf("Would you like to continue yes(1)/no(0) :  ");
            scanf("%d", &i);
        } while (i != 0 && i != 1);
        return i;
    } else {
        do {
            start(tree, msg, currentUser);
            do {
                printf("Would you like to continue yes(2)/no(0)/menu(1) :  ");
                scanf("%d", &i);
            } while (i != 0 && i != 1 && i != 2);
        } while (i == 2);
    }
}

int rungame(root *tree, char msg[], player *currentUser) {
    int checker;

    do {
        checker = gettingStarted(tree, msg, currentUser);
    } while (checker != 0);

    printf("LoggedIn user name is %s", currentUser->name);

    do {
        checker = menu(tree, tree->leaderBoardTree, msg, currentUser);
    } while (checker != 0);

    return 0;
}
