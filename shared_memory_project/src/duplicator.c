// src/duplicator.c
#include "../include/shared_memory.h"

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    char *shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("fopen");
        shmdt(shared_memory);
        exit(1);
    }

    fprintf(file, "%s", shared_memory);
    fclose(file);
    printf("Shared memory content duplicated to 'output.txt'.\n");

    shmdt(shared_memory);
    return 0;
}
