// Function to add a new user
void addUser(player *new) {
    do {
        getchar();
        printf("\033[42mName :\033[0m\t");
        fgets(new->name, sizeof(new->name), stdin);
    } while (strlen(new->name) <= 1); // Ensure non-empty name
    sscanf(new->name, "%99[^\n]", new->name);

    do {
        printf("\033[42mID :\033[0m\t");
        fgets(new->id, sizeof(new->id), stdin);
    } while (strlen(new->id) <= 1); // Ensure non-empty ID
    sscanf(new->id, "%99[^\n]", new->id);
}

// Function to verify if a user already exists
int Verify(player *new) {
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

    while (!test && i < n) {
        fgets(line, sizeof(line), file);
        int p = pos(line, '*');
        substr(line, 0, p);

        if (strcmp(sub, new->id) == 0) {
            test = 1; // User already exists
        }

        i++;
    }

    fclose(file);
    return 0;
}

// Function to edit the player file and add the new user
int fileEdit(player *new) {
    FILE *file = fopen("./Modules/stats/players.txt", "a");
    if (file == NULL) {
        perror("Failed to open players file");
        return 1;
    }

    char h[UserMax] = "";
    strcat(h, new->id);
    strcat(h, "*");
    strcat(h, new->name);
    strcat(h, "*\n");

    fprintf(file, "%s", h);
    fclose(file);

    strcpy(h, "./Modules/stats/");
    strcat(h, new->id);
    strcat(h, ".txt");
    
    FILE *userPFile = fopen(h, "w"); // User Personal File
    if (userPFile == NULL) {
        perror("Failed to open user's personal file");
        return 1;
    }

    strcpy(h, "0*0*0*\n");
    fprintf(userPFile, "%s", h);
    fclose(userPFile);

    printf("\033[1;37;44mPlayer %s whose ID is %s was successfully added\033[0m\n", new->name, new->id);
    return 0;
}

// Function to sign up a new user
int signUp(char msg[], root *tree) {
    player *new = malloc(sizeof(player));
    strcpy(new->name, "");
    strcpy(new->id, "");

    addUser(new);
    Verify(new);

    if (test) {
        strcpy(msg, "User already exists");
        return 1;
    }

    fileEdit(new);
    strcpy(msg, "Sign up was successful");
    load(tree);
    return 2;
}
