// Assuming the number of element at present will never exceed the capacity

#define CAP 100005

int q[CAP];
int front = 0, rear = 0;

#define push(q, x, front, rear)  q[rear] = (x), rear = (rear + 1) % CAP
#define pop(q, front, rear)      (q[front]), front = (front + 1) % CAP
#define empty(front, rear)       (front == rear)
#define size(front, rear)        ((rear - front + CAP) % CAP)