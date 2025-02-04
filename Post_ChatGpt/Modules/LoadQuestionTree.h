// Function to free the allocated memory for questions
void freeQuestions(ques *q) {
    while (q != NULL) {
        ques *temp = q;
        q = q->q;
        free(temp);
    }
}

// Define your array of file paths
char *types_ques[] = {"./Modules/Types/gaming.txt", "./Modules/Types/greek.txt", "./Modules/Types/football.txt"};

// Function to fill a question structure
void fillQuestion(ques *q, char line[]) {
    int p;

    // Repeatedly extract parts from the line
    p = pos(line, '*');
    substr(line, 0, p);
    strcpy(q->question, sub);
    substr(line, p + 1, -1);
    strcpy(line, sub);
    //
    p = pos(line, '*');
    substr(line, 0, p);
    strcpy(q->answer1, sub);
    substr(line, p + 1, -1);
    strcpy(line, sub);
    //
    p = pos(line, '*');
    substr(line, 0, p);
    strcpy(q->answer2, sub);
    substr(line, p + 1, -1);
    strcpy(line, sub);
    //
    p = pos(line, '*');
    substr(line, 0, p);
    strcpy(q->answer3, sub);
    substr(line, p + 1, -1);
    strcpy(line, sub);
    //
    p = pos(line, '*');
    substr(line, 0, p);
    strcpy(q->answer4, sub);
    substr(line, p + 1, -1);
    strcpy(line, sub);

    // Parse and store the correct answer
    p = pos(line, '*');
    substr(line, 0, p);
    q->correct = atol(sub);
}

// Function to load questions from a file into a type structure
int loadQuestion(int type_integer, type *s) {
    int n = 0;
    char line[MAX];
    FILE *file = fopen(types_ques[type_integer], "r");

    if (file == NULL) {
        perror("Unable to open the file");
        return 1;
    }

    // Count the number of lines in the file
    while (fgets(line, sizeof(line), file) != NULL) {
        n = n + 1;
    }

    rewind(file);

    ques *head = NULL;
    ques *current = NULL;

    // Loop to read and fill each question
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), file);

        ques *q = malloc(sizeof(ques));
        if (q == NULL) {
            // Handle memory allocation failure
            perror("Memory allocation error");
            fclose(file);
            freeQuestions(head);  // Cleanup allocated memory
            return 1;
        }

        fillQuestion(q, line);

        if (head == NULL) {
            head = q;
            current = q;
        } else {
            current->q = q;
            current = q;
        }
    }

    s->q = head;

    fclose(file);
    return 0;
}


// Function to load questions for all types into a root structure
int loadQuestions(root *tree) {
    type *n1 = malloc(sizeof(type));
    tree->t1 = n1;
    type *n2 = malloc(sizeof(type));
    tree->t2 = n2;
    type *n3 = malloc(sizeof(type));
    tree->t3 = n3;

    // Load questions for each type
    if (loadQuestion(0, n1) || loadQuestion(1, n2) || loadQuestion(2, n3)) {
        // Handle any errors during loading
        free(n1);
        free(n2);
        free(n3);
        return 1;
    }

    return 0;
}
