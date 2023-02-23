#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>


struct Stack {
    int topElement;
    unsigned capacity;
    int *stackArray;
};

struct Stack *initializeStack(int size) {

    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->topElement = -1;
    stack->capacity = size;
    stack->stackArray = (int *) malloc(stack->capacity * sizeof(int));

    return stack;
}

bool isFull(struct Stack *stack) {

    if (stack->topElement == stack->capacity - 1) {

        return true;
    }

    return false;
}

bool isEmpty(struct Stack *stack) {

    if (stack->topElement == -1) {

        return true;
    }

    return false;
}

void push(struct Stack *stack, int valueToPush) {

    if (isFull(stack)) {

        printf("stack is full, unable to push value :%d \n", valueToPush);
        return;
    }

    stack->stackArray[++stack->topElement] = valueToPush;
    printf("%d has been pushed \n", valueToPush);

}

void pop(struct Stack *stack) {

    if (isEmpty(stack)) {

        printf("stack is empty, no items can be popped");
        return;
    }

    int poppedItem = stack->stackArray[stack->topElement--];

    printf("item :%d has been popped", poppedItem);
}

int peek(struct Stack *stack) {

    if (isEmpty(stack)) {
        return INT_MIN;
    }

    return stack->stackArray[stack->topElement];
}

void doPeek(struct Stack *stack) {

    int peekValue = peek(stack);

    if (peekValue != INT_MIN) {

        printf("top value :%d \n", peekValue);
        return;
    }
    printf("stack is empty \n");
}

void doPush(struct Stack *stack, int valueToPush) {

    printf("attempting to push :%d \n", valueToPush);
    push(stack, valueToPush);

}

void doPop(struct Stack *stack) {

    printf("attempting to pop value on stack \n");
    pop(stack);
}

void printMenu() {

    system("cls");
    printf("1 : push\n");
    printf("2 : pop\n");
    printf("3 : peek at value to be popped\n");
    printf("4 : exit\n");
    printf("enter your choice :");

}

void printStartMenu() {
    system("cls");
    printf("enter stack size :");
}

void run() {

    int userChoice;

    struct Stack *stack = NULL;

    printStartMenu();

    scanf("%d", &userChoice);

    stack = initializeStack(userChoice);

    printf("stack initialized with size :%d \n", userChoice);

    Sleep(2000);

    bool isRunning = true;

    while (isRunning) {

        printMenu();

        scanf("%d", &userChoice);

        switch (userChoice) {

            case 1:
                system("cls");
                printf("enter value to push:");
                scanf("%d", &userChoice);
                doPush(stack, userChoice);
                Sleep(2000);
                break;
            case 2:
                system("cls");
                doPop(stack);
                Sleep(2000);
                break;
            case 3:
                system("cls");
                doPeek(stack);
                Sleep(2000);
                break;
            case 4:
                system("cls");
                printf("deallocating memory");
                free(stack);
                Sleep(2000);
                isRunning = false;
                break;
            default:
                system("cls");
                printf("value %d is invalid", userChoice);
                Sleep(2000);
                break;
        }
    }
}

int main() {

    run();

    return 0;
}
