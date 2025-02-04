#define MAX  600       // Max number of characters for the variable Line (text File Line container)/ variable sub
#define QMAX 100       // Max String Length For each of the question's Struct Strings
#define TNbrQ 100       // table Nbr max questions
#define PMAX 100        // player data
#define NbrQType 3      // Nbr types of questions
#define UserMax 100     // Max Nbr Chars players.txt/id.txt per line

char sub[MAX];
int test = 0;           // used for testing

typedef struct player {
    char id[PMAX];
    char name[PMAX];
    int score[NbrQType];
    int totalScore;
    int hash;
    struct player *left;
    struct player *right;
    struct player *leftScore;
    struct player *rightScore;
} player;

typedef struct question {
    char question[QMAX];
    char answer1[QMAX];
    char answer2[QMAX];
    char answer3[QMAX];
    char answer4[QMAX];
    int correct;
    struct question *q;
} ques;

typedef struct type {
    ques *q;
} type;

typedef struct rooter {
    type *t1;
    type *t2;
    type *t3;
    player *p;
    player *leaderBoardTree;
} root;
