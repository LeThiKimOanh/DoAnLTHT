// src/cleaner.c
#include "../include/shared_memory.h"

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    printf("Shared memory segment deleted.\n");

    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
    } else {
        sem_close(sem);
        sem_unlink(SEM_NAME);
        printf("Semaphore deleted.\n");
    }

    return 0;
}
