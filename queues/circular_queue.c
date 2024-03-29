#include <stdio.h>
#include <stdlib.h>

// Structure of a Node
struct Node {
    int data;
    struct Node* link;
};

struct Queue {
    struct Node *front, *rear;
};

// Function to create Circular queue
void enQueue( struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->link = temp;

    q->rear = temp;
    q->rear->link = q->front;
}

// Function to delete element from Circular Queue
int deQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    // If this is the last node to be deleted
    int value; // Value to be dequeued
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else 
    {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->link;
        q->rear->link = q->front;
        free(temp);
    }

    return value;
}

//  displaying 
void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    printf("\nElements in Circular Queue are: ");
    while (temp->link != q->front) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("%d", temp->data);
}


int main() {
    // Create a queue and initialize front and rear
    struct Queue* q = (struct Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;

    // Inserting elements in Circular Queue
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);

    // Display elements present in Circular Queue
    displayQueue(q);

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));

    // Remaining elements in Circular Queue
    displayQueue(q);

    enQueue(q, 9);
    enQueue(q, 20);
    displayQueue(q);

    return 0;
}
