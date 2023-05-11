#include "queue.h"

Queue* newQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

bool enqueue(Queue* q, int data) {
    if (q == NULL) return false;

    QNode* node = (QNode*) malloc(sizeof(QNode));
    node->data = data;
    node->next = NULL;

    if (q->tail != NULL) {
        q->tail->next = node;
    } else {
        q->head = node;
    }

    q->tail = node;

    return true;
}

bool is_empty(Queue* q) {
    return q->head == NULL && q->tail == NULL;
}

int dequeue(Queue* q) {
    if (q == NULL) return INT_MIN;

    if (q->head != NULL) {
        QNode* node = q->head;
        q->head = q->head->next;
        node->next = NULL;
        int data = node->data;
        free(node);

        if (q->head == NULL) {
            q->tail = NULL;
        }

        node = NULL;
        return data;
    }

    return INT_MIN;
}

void print_queue(Queue* q) {
    QNode* current = q->head;

    printf("[");

    while (current != NULL) {
        if (current->next == NULL)
            printf("%d", current->data);
        else
            printf("%d, ", current->data);

        current = current->next;
    }

    printf("]\n");
}
