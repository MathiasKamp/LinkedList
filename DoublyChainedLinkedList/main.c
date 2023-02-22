#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include<windows.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
};

void printList(struct Node *n) {

    int position = 1;

    while (n != NULL) {

        printf("position : %d data : %d  \n", position, n->data);
        position++;
        n = n->next;
    }
}

struct Node *constructStart() {

    struct Node *head = NULL;

    head = (struct Node *) malloc(sizeof(struct Node));

    head->data = 0;
    head->next = NULL;
    head->previous = NULL;

    return head;
}

struct Node *getNodeBasedOnPosition(struct Node **pNode, int position) {

    struct Node *foundNode = *pNode;
    int counter = 1;

    while (foundNode != NULL) {

        if (position == counter) {

            return foundNode;
        }

        counter++;

        foundNode = foundNode->next;
    }
}


int getNodeDataBasedOnDataValue(struct Node **pNode, int data) {

    struct Node *tempNode = *pNode;

    while (tempNode != NULL) {

        if (tempNode->data == data) {

            return tempNode->data;
        }
        tempNode = tempNode->next;
    }

    return 0;
}

void doSearch(struct Node **pNode, int valueToFind) {

    printf("searching for : %d \n", valueToFind);

    int foundNodeData = getNodeDataBasedOnDataValue(pNode, valueToFind);

    if (foundNodeData != valueToFind) {
        printf("value : %d is not found", valueToFind);
    } else {
        printf("value : %d is found", valueToFind);
    }
}


void insert(struct Node **pNode, int data) {

    struct Node *newData = (struct Node *) malloc(sizeof(struct Node));

    newData->data = data;

    newData->next = (*pNode);
    newData->previous = NULL;

    if ((*pNode) != NULL) {

        ((*pNode)->previous = newData);
    }

    (*pNode) = newData;
}

void doInsert(struct Node **pNode, int data) {

    printf("inserting data : %d \n", data);

    insert(pNode, data);

    printf("data has been inserted\n");
}


void delete(struct Node **pNode, struct Node *delNode) {

    if (*pNode == NULL || delNode == NULL) {

        return;
    }

    // if node to be deleted is the first node (head)
    if (*pNode == delNode) {

        *pNode = delNode->next;
    }

    // change next if node to be deleted is not the last element (NULL)
    if (delNode->next != NULL) {

        delNode->next->previous = delNode->previous;
    }

    // change previous if the deleted node is not the first node
    if (delNode->previous != NULL) {

        delNode->previous->next = delNode->next;
    }

    free(delNode);
}


void doDelete(struct Node **pNode, int position) {

    struct Node *delNode = getNodeBasedOnPosition(pNode, position);
    printf("deleting node at position %d", position);
    delete(pNode, delNode);

}

void menu() {
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
            doSearch(&nodes, userChoice);
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

    menu();

    return 0;
}
