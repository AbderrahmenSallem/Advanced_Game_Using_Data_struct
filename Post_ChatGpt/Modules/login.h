#include <stdio.h>
#include <string.h>

// Function to copy player data from source to destination
void copyPlayerData(player *source, player *destination) {
    printf("Debug: Copying player data...\n");
    printf("Debug: Source name: %s, ID: %s, Hash: %d\n", source->name, source->id, source->hash);
    strcpy(destination->name, source->name);
    strcpy(destination->id, source->id);
    destination->score[0] = source->score[0];
    destination->score[1] = source->score[1];
    destination->score[2] = source->score[2];
    destination->totalScore = source->totalScore;
    destination->hash = source->hash;
    printf("Debug: Copied data to destination. Destination name: %s, ID: %s, Hash: %d\n", destination->name, destination->id, destination->hash);
}

// Recursive function to search for a player in the tree by hash
int search(player *p, int searchHash, player *currentUser) {
    if (p == NULL) {
        printf("Debug: Reached NULL node\n");
        return 0; // Case: Empty tree, user not found
    } else if ((p->right == NULL) && (p->left == NULL)) {
        // Case: Leaf node
        copyPlayerData(p, currentUser);
        printf("Debug: Leaf node found. Hash: %d\n", p->hash);
        return (p->hash == searchHash);
    } else if (p->hash == searchHash) {
        // Case: User found
        copyPlayerData(p, currentUser);
        printf("Debug: User found. Hash: %d\n", p->hash);
        return 1;
    } else {
        // Case: Recursive search
        if (searchHash >= p->hash) {
            printf("Debug: Going right. Current hash: %d\n", p->hash);
            return search(p->right, searchHash, currentUser);
        } else {
            printf("Debug: Going left. Current hash: %d\n", p->hash);
            return search(p->left, searchHash, currentUser);
        }
    }
}


// Function to handle the login process
int login(root *tree, player *currentUser, char msg[]) {
    char loginID[UserMax];
    printf("User ID \t");
    scanf("%s", loginID);

    // Custom hash function to convert the user ID to a hash value
    int userHash = customHash(loginID);
    printf("Debug: Hash generated for user ID %s: %d\n", loginID, userHash);

    // Check if the user exists in the tree
    int userExists = search(tree->p, userHash, currentUser);

    if (!userExists) {
        strcpy(msg, "User doesn't exist");
        printf("Debug: %s\n", msg);
        return 1;
    } else {
        strcpy(msg, "Login was successful");
        printf("Debug: %s. Hash: %d\n", msg, userHash);
        return 0;
    }
}
