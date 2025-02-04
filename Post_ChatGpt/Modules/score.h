int updateScore(player *p, int value, int type, root *tree) {
    if (value <= p->score[type]) {
        return 0;
    } else {
        p->score[type] = value;
        char line[MAX];
        strcpy(line, "./Modules/stats/");
        strcat(line, p->id);
        strcat(line, ".txt");
        FILE *fileToUpdate = fopen(line, "w");

        if (fileToUpdate == NULL) {
            printf("Failed to open personal file for update 2");
            return 1;
        }

        char h[UserMax];
        sprintf(h, "%d*%d*%d*\n", p->score[0], p->score[1], p->score[2]);
        fprintf(fileToUpdate, "%s", h);
        fclose(fileToUpdate);

        load(tree);
    }
    return 0;
}
