// src/enqueue.c
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

    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    sem_wait(sem);

    // Kiểm tra nếu hàng đợi đầy
    if (shared_queue->size == QUEUE_CAPACITY) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        printf("Enter message to enqueue: ");
        char message[SHM_SIZE];
        fgets(message, SHM_SIZE, stdin);

        shared_queue->rear = (shared_queue->rear + 1) % QUEUE_CAPACITY;
        strncpy(shared_queue->queue[shared_queue->rear], message, SHM_SIZE);
        shared_queue->size++;
        printf("Enqueued: %s", message);
    }

    sem_post(sem);

    sem_close(sem);
    shmdt(shared_queue);

    return 0;
}
