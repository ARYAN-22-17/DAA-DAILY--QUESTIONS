
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int hasCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int main() {
    int n, i, value, pos;
    struct Node *head = NULL, *tail = NULL, *newNode, *temp;
    struct Node *cycleNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The linked list is empty or invalid.\n");
        return 0;
    }

    printf("Enter node values: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter position to create cycle (0 for no cycle, 1 to %d): ", n);
    scanf("%d", &pos);

    if (pos >= 1 && pos <= n) {
        temp = head;

        for (i = 1; i < pos; i++) {
            temp = temp->next;
        }

        tail->next = temp;
    }

    if (hasCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle in the linked list.\n");
    }

    /* Free memory safely, even if a cycle exists. */
    if (tail != NULL) {
        tail->next = NULL;
    }

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
