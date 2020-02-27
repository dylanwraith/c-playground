#include <stdio.h>

//List from least to greatest

typedef struct node {
    int value;
    struct node* next;
} node_t;

void insertValue(int value, node_t** head) {
    node_t* currentNode = *head;
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->next = NULL;
    newNode->value = value;
    // Empty list
    if (currentNode == NULL) {
        *head = newNode;
    }
    // Insert in beginning of list
    else if (newNode->value < currentNode->value){
        newNode->next = *head;
        *head = newNode;
    }
    // Insert in middle or end of list
    else {
        while (value > currentNode->value && currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        // Insert at end of list
        if (currentNode->next == NULL && value > currentNode->value) {
            currentNode->next = (node_t*)malloc(sizeof(node_t));
            currentNode->next->value = value;
            currentNode->next->next = NULL;
        }
        // Insert in middle of list
        else {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            int temp = newNode->value;
            newNode->value = currentNode->value;
            currentNode->value = temp;
        }
    }
}

int deleteValue(int value, node_t** head) {
    node_t* currentNode = *head;
    int deletedValue = -1;
    if (currentNode != NULL) {
        // Delete head
        if (currentNode->value == value) {
            currentNode = (*head)->next;
            deletedValue = (*head)->value;
            free(*head);
            *head = currentNode;
            return deletedValue;
        }
        // Delete from middle or end of list
        else if ((*head)->next != NULL){
            node_t* deletedNode = (*head)->next;
            while (value != deletedNode->value && deletedNode->next != NULL) {
                deletedNode = deletedNode->next;
                currentNode = currentNode->next;
            }
            // Delete from end of list
            if (deletedNode->next == NULL && value == deletedNode->value) {
                deletedValue = deletedNode->value;
                currentNode->next = NULL;
                free(deletedNode);
                return deletedValue;
            }
            // Delete from middle of list
            else if (value == deletedNode->value) {
                deletedValue = deletedNode->value;
                currentNode->next = deletedNode->next;
                free(deletedNode);
                return deletedValue;
            }
            // Number does not exist
            else {
                return deletedValue;
            }
        }
        // Number does not exist
        else {
            return deletedValue;
        }
    }
    // Number does not exist
    else return deletedValue;
}

void display(node_t** head) {
    node_t* current = *head;
    if (current != NULL) {
        do {
            printf("%d\n", current->value);
            current = current->next;
        } while (current->next != NULL);
        printf("%d\n", current->value);
    }
}

int main()
{
    node_t* linkedList = (node_t*)malloc(sizeof(node_t));
    linkedList = NULL;
    insertValue(11, &linkedList);
    insertValue(10, &linkedList);
    insertValue(8, &linkedList);
    insertValue(12, &linkedList);
    insertValue(9, &linkedList);
    deleteValue(9, &linkedList);
    display(&linkedList);
    return 0;
}