// You are using GCC
#include <bits/stdc++.h>
// #include <stdio.h>
// #include <stdlib.h>

#define scan(n) scanf("%d", &(n))
#define newn allocate()
#define MAX_SIZE 100

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

typedef struct Node {
    struct Node *l, *r;
    int val;
} node;

node *allocate() {
    return (node *)malloc(sizeof(node));
}

typedef struct Queue {
    node *arr[MAX_SIZE];
    int f, r;
} q;

void init(q *queue) {
    queue->r = -1;
    queue->f = -1;
}

int isFull(q *queue) {
    return queue->f == (queue->r + 1) % MAX_SIZE;
}

int isEmpty(q *queue) {
    return queue->f == -1 || queue->r == -1;
}

int isSingular(q *queue) {
    return queue->r == queue->f;
}

void enqueue(q *queue, node *newnode) {
    if (isFull(queue)) {
        printf("Queue Full %d not added\n", newnode->val);
        return;
    }

    if (isEmpty(queue)) {
        queue->f = 0;
    }

    queue->r = (queue->r + 1) % MAX_SIZE;
    node *t = newnode;
    queue->arr[queue->r] = t;
    // printf("Enqueued %d\n", t->val);
}

node *dequeue(q *queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty!\n");
        return NULL;
    }

    if (isSingular(queue)) {
        node *ret = queue->arr[queue->f];
        queue->arr[queue->f] = NULL;
        init(queue);
        return ret;
    }

    node *ret = queue->arr[queue->f];
    queue->arr[queue->f] = NULL;
    queue->f = (queue->f + 1) % MAX_SIZE;
    return ret;
}

node *dequeue_back(q *queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty!\n");
        return NULL;
    }

    if (isSingular(queue)) {
        node *ret = queue->arr[queue->r];
        queue->arr[queue->r] = NULL;
        init(queue);
        return ret;
    }

    node *ret = queue->arr[queue->r];
    queue->arr[queue->r] = NULL;
    if (queue->r == 0) queue->r = MAX_SIZE - 1;
    else queue->r--;
    return ret;
}

void inorder(node *root) {
    if (!root) {
        return;
    }

    inorder(root->l);
    printf("%d ", root->val);
    inorder(root->r);
}

void reverse_inorder(node *root) {
    if (!root) {
        return;
    }

    reverse_inorder(root->r);
    printf("%d", root->val);
    reverse_inorder(root->l);
}

typedef struct Stack {
    node *arr[MAX_SIZE];
    int t;
} s;

void init(s *stack) {
    stack->t = -1;
}

int isFull(s *stack) {
    return stack->t == MAX_SIZE - 1;
}

int isEmpty(s *stack) {
    return stack->t == -1;
}

void push(s *stack, node *newnode) {
    if (isFull(stack)) {
        printf("Stack FULL %d not stacked\n", stack->arr[stack->t]->val);
        return;
    }

    stack->arr[++stack->t] = newnode;
}

node *pop(s *stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty\n");
        return NULL;
    }

    node *ret = stack->arr[stack->t];
    stack->arr[stack->t--] = NULL;
    return ret;
}

void construct_tree(node *root, node *newnode) {
    if (root->val > newnode->val) {
        if (root->l == NULL) {
            root->l = newnode;
            return;
        }
        construct_tree(root->l, newnode);
    }
    if (root->val < newnode->val) {
        if (root->r == NULL) {
            root->r = newnode;
            return;
        }
        construct_tree(root->r, newnode);
    }
}

void find_value(node *root, int *val) {
    if (!root) return;
    if (root->l) {
        find_value(root->l, val);
    }
    if (root->r) {
        *val += root->r->val;
        find_value(root->r, val);
    }
}

void queueup(q *queue, node *root) {
    if (!root) return;
    if (root->r) enqueue(queue, root->r);
    if (root->l) enqueue(queue, root->l);
    queueup(queue, root->r);
    queueup(queue, root->l);
}

int main(void) {
    q que;
    q *queue = &que;
    init(queue);

    s stk;
    s *stack = &stk;
    init(stack);

    int n, val;
    scan(n);
    n--;

    node *root = newn, *t, *curr;
    scan(root->val);
    enqueue(queue, root);

    int i = 0;
    while (i < n) {
        t = dequeue(queue);

        if (t != NULL) {
            if (i < n) {
                t->l = newn;
                scan(val);
                t->l->val = val;
                enqueue(queue, t->l);
                i++;
            }

            if (i < n) {
                t->r = newn;
                scan(val);
                t->r->val = val;
                enqueue(queue, t->r);
                i++;
            }
        }
    }

    // printf("%d", root->r->val);
    init(queue);
    enqueue(queue, root);
    queueup(queue, root);
    while (!isEmpty(queue)) {
        printf("%d ", dequeue_back(queue)->val);
    }
    // reverse_inorder(root);
}
