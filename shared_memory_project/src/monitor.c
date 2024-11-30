// src/monitor.c
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

    printf("Monitoring changes in shared memory...\n");
    char last_content[SHM_SIZE] = {0};

    while (1) {
        if (strcmp(last_content, shared_memory) != 0) {
            printf("Shared memory updated: %s\n", shared_memory);
            strncpy(last_content, shared_memory, SHM_SIZE);
        }
        sleep(1);
    }

    shmdt(shared_memory);
    return 0;
}
