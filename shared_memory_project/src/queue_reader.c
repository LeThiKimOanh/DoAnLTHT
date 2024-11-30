// src/dequeue.c
#include "../include/shared_memory.h"

int main() {
    int shm_id = shmget(SHM_KEY, sizeof(SharedQueue), 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    SharedQueue *shared_queue = (SharedQueue *)shmat(shm_id, NULL, 0);
    if (shared_queue == (SharedQueue *)-1) {
        perror("shmat");
        exit(1);
    }

    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    sem_wait(sem);

    // Kiểm tra nếu hàng đợi rỗng
    if (shared_queue->size == 0) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        shared_queue->front = (shared_queue->front + 1) % QUEUE_CAPACITY;
        printf("Dequeued: %s", shared_queue->queue[shared_queue->front]);
        shared_queue->size--;
    }

    sem_post(sem);

    sem_close(sem);
    shmdt(shared_queue);

    return 0;
}
