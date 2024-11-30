// src/status.c
#include "../include/shared_memory.h"

int main() {
    // Kiểm tra shared memory
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id < 0) {
        perror("shmget");
        printf("Shared memory not found.\n");
    } else {
        struct shmid_ds shm_info;
        shmctl(shm_id, IPC_STAT, &shm_info);
        printf("Shared memory size: %ld bytes\n", shm_info.shm_segsz);
        printf("Attached processes: %ld\n", shm_info.shm_nattch);
    }

    // Kiểm tra semaphore
    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        printf("Semaphore not found.\n");
    } else {
        int sem_value;
        sem_getvalue(sem, &sem_value);
        printf("Semaphore value: %d\n", sem_value);
        sem_close(sem);
    }

    return 0;
}
