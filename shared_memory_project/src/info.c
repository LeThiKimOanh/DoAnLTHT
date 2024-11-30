// src/info.c
#include "../include/shared_memory.h"

int main() {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    struct shmid_ds shm_info;
    if (shmctl(shm_id, IPC_STAT, &shm_info) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Shared Memory Info:\n");
    printf("Key: %d\n", SHM_KEY);
    printf("Size: %zu bytes\n", shm_info.shm_segsz);
    printf("Last attach time: %ld\n", shm_info.shm_atime);
    printf("Last detach time: %ld\n", shm_info.shm_dtime);
    printf("Last change time: %ld\n", shm_info.shm_ctime);
    printf("Attached processes: %lu\n", shm_info.shm_nattch);

    return 0;
}
