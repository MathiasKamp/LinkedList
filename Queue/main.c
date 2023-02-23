#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>


struct Queue {

    unsigned firstElement;
    unsigned lastElement;
    unsigned size;
    unsigned capacity;
    int *queueArray;
};


struct Queue *initializeQueue(unsigned capacity) {

    struct Queue *queue = (struct Queue *) malloc(
            sizeof(struct Queue));
    queue->capacity = capacity;
    queue->firstElement = queue->size = 0;

    queue->lastElement = capacity - 1;
    queue->queueArray = (int *) malloc(
            queue->capacity * sizeof(int));

    printf("queue initialized with size :%d", capacity);

    return queue;
}

int queueIsFull(struct Queue *queue) {
    return (queue->size == queue->capacity);
}

int queueIsEmpty(struct Queue *queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int value) {

    if (queueIsFull(queue)) {

        printf("queue is full, not able to enqueue :%d\n", value);
        return;
    }
    // count lastElement up
    queue->lastElement = (queue->lastElement + 1) % queue->capacity;
    // put the value in the queue Array on the lastElement´s spot
    queue->queueArray[queue->lastElement] = value;
    // count up the size
    queue->size = queue->size + 1;


    printf("%d has been enqueued\n", value);
}

int dequeue(struct Queue *queue) {

    if (queueIsEmpty(queue)) {

        printf("theres no items on the queue");
        return INT_MIN;
    }

    int dequeuedItem = queue->queueArray[queue->firstElement];
    queue->firstElement = (queue->firstElement + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return dequeuedItem;
}

int peek(struct Queue *queue) {

    return queue->queueArray[queue->firstElement];

}

void printMenu() {

    system("cls");
    printf("1 : enqueue\n");
    printf("2 : dequeue\n");
    printf("3 : peek at element to be dequeued\n");
    printf("4 : exit\n");
    printf("enter your choice :");

}

void printStartMenu() {
    system("cls");
    printf("enter queue size :");
}

void doEnqueue(struct Queue *queue, int value) {

    printf("attempting to enqueue %d\n", value);

    enqueue(queue, value);

}

void doDequeue(struct Queue *queue) {

    printf("attempting to dequeue item \n");
    int dequeuedItem = dequeue(queue);

    if (dequeuedItem != INT_MIN) {

        printf("dequeued item value is %d", dequeuedItem);
    } else {
        printf("theres no items in the queue");
    }
}

void doPeek(struct Queue *queue) {

    if (queueIsEmpty(queue)) {

        printf("no items in queue");
        return;
    }
    int firstValue = peek(queue);

    printf("the first value on the queue is :%d", firstValue);
}

void run() {


    printStartMenu();

    int inputNumber;

    scanf("%d", &inputNumber);


    bool isRunning = true;

    struct Queue *queue = initializeQueue(inputNumber);

    printf("queue initialized with size :%d", inputNumber);

    Sleep(2000);

    while (isRunning) {

        printMenu();

        scanf("%d", &inputNumber);

        switch (inputNumber) {

            case 1:
                system("cls");
                printf("enter (integer) value to enqueue :");
                scanf("%d", &inputNumber);
                doEnqueue(queue, inputNumber);
                Sleep(2000);
                break;
            case 2:
                system("cls");
                doDequeue(queue);
                Sleep(2000);
                break;
            case 3:
                system("cls");
                doPeek(queue);
                Sleep(2000);
                break;
            case 4:
                system("cls");
                printf("deallocating queue memory\n");
                free(queue);
                Sleep(2000);
                printf("exiting program\n");
                isRunning = false;
                break;
            default:
                system("cls");
                printf("the value :%d is not valid try again", inputNumber);
                Sleep(2000);
                break;
        }
    }
}

int main() {

    run();

    return 0;
}
