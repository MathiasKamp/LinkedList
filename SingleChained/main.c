#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include<windows.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *n) {

    int position = 1;

    while (n != NULL) {

        printf("position : %d data : %d \n", position, n->data);
        position++;
        n = n->next;
    }
}

int Search(struct Node *n, int numberToFind) {

    while (n != NULL) {

        if (n->data == numberToFind) {

            return n->data;
        }

        n = n->next;
    }
    return 0;
}

void insert(struct Node **n, int dataToInsert) {

    // new node construction
    struct Node *newDataNode = (struct Node *) malloc(sizeof(struct Node));

    // set data of new data node
    newDataNode->data = dataToInsert;

    // set next of new node to n node
    newDataNode->next = (*n);

    // move n node to point to new data node
    (*n) = newDataNode;
}

void doInsert(struct Node **n, int dataToInsert) {

    printf("inserting data : %d \n", dataToInsert);

    insert(n, dataToInsert);

    printf("data has been inserted\n");
}

void Delete(struct Node **nodes, int position) {

    struct Node *temp;
    struct Node *previous;

    temp = *nodes;
    previous = *nodes;

    for (int i = 0; i < position; ++i) {

        if (i == 0 && position == 1) {

            *nodes = (*nodes)->next;
            free(temp);
            printf("position : %d has been deleted", position);
        } else {
            if (i == position - 1 && temp) {

                previous->next = temp->next;
                free(temp);
                printf("position : %d has been deleted",position);
            } else {
                previous = temp;

                if (previous == NULL) {
                    break;
                }
                temp = temp->next;
            }
        }
    }
}


void doDelete(struct Node **nodes, int position) {

    printf("deleting node at position %d", position);
    Delete(nodes, position);
}

void doSearch(struct Node *n, int numberToFind) {

    printf("searching for : %d \n", numberToFind);

    int searchResult;

    searchResult = Search(n, numberToFind);

    if (numberToFind != searchResult) {
        printf("value : %d is not found", numberToFind);
    } else {
        printf("value : %d is found", searchResult);
    }
}

struct Node *constructStart() {

    struct Node *head = NULL;

    head = (struct Node *) malloc(sizeof(struct Node));

    // start dummy data
    head->data = 0;
    head->next = NULL;

    return head;
}

void mainMenu() {

    int userChoice;

    bool mainMenuRunning = true;

    struct Node *nodes = constructStart();

    while (mainMenuRunning) {

        system("cls");
        printf("1 : search\n");
        printf("2 : insert\n");
        printf("3 : delete\n");
        printf("4 : print list\n");
        printf("5 : exit\n");

        printf("choose an action :");

        scanf("%d", &userChoice);

        if (userChoice == 1) {

            system("cls");
            printf("insert number to search for : ");
            scanf("%d", &userChoice);
            system("cls");
            doSearch(nodes, userChoice);
            Sleep(2000);
        } else if (userChoice == 2) {

            system("cls");
            printf("insert number to insert :");
            scanf("%d", &userChoice);
            system("cls");
            doInsert(&nodes, userChoice);
            Sleep(2000);
            system("cls");

        } else if (userChoice == 3) {
            system("cls");
            printf("the list has the following positions : \n");
            printList(nodes);
            printf("insert position to delete :");
            scanf("%d", &userChoice);
            system("cls");
            doDelete(&nodes, userChoice);
            Sleep(2000);

        } else if (userChoice == 4) {
            system("cls");
            printf("the list has the following data : \n");
            printList(nodes);
            Sleep(2000);
        } else if (userChoice == 5) {
            printf("exiting program..");
            Sleep(2000);
            mainMenuRunning = false;
        } else {
            printf("%d is not a valid number", userChoice);
            Sleep(2000);
        }
    }
}


int main() {

    mainMenu();

    return 0;
}




