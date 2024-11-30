// src/deleter.c
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

    printf("Current shared memory content: %s\n", shared_memory);
    printf("Enter a word to delete: ");
    char keyword[100];
    scanf("%s", keyword);

    char *pos = strstr(shared_memory, keyword);
    if (pos) {
        size_t len = strlen(keyword);
        memmove(pos, pos + len, SHM_SIZE - (pos - shared_memory + len));
        printf("Keyword '%s' deleted from shared memory.\n", keyword);
    } else {
        printf("Keyword not found in shared memory.\n");
    }

    shmdt(shared_memory);
    return 0;
}
