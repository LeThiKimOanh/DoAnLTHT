// src/initializer.c
#include "../include/shared_memory.h"

int main() {
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    SharedQueue *shared_queue = (SharedQueue *)shmat(shm_id, NULL, 0);
    if (shared_queue == (SharedQueue *)-1) {
        perror("shmat");
        exit(1);
    }

    // Khởi tạo các thông số của hàng đợi
    shared_queue->front = -1;
    shared_queue->rear = -1;
    shared_queue->size = 0;
    printf("Queue initialized.\n");

    shmdt(shared_queue);

    return 0;
}
