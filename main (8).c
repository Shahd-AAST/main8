#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct Queue Queue;
struct Queue{
	Node* head;
	Node* tail;
	int count, size;
};
struct Node{
	int data;
	Node* next;
};

Node* makeNode(int data){
	Node* p = (Node*) malloc(sizeof(Node));
	p -> data = data;
	p -> next = NULL;
	return p;
}

Queue initQueue(int size){
	Queue q = {NULL, NULL, 0, size};
	return q;
}

void enQueue(Queue* q, int data){
	if(q->count >= q->size){
		printf("Queue is Full\n");
		return;
	}
	Node* p = makeNode(data);
	if(q->count == 0){
		q->head = p;
	}
	else{
		q->tail->next = p;
	}
	q->tail = p;
	q->count++;
}
int deQueue(Queue* q){
	if(q->count == 0){
		return -999;
	}
	int x = q->head->data;
	Node* del = q->head;
	q->head = q->head->next;
	free(del);
	return x;
}
int main(){
	Queue q1 = initQueue(10);
	enQueue(&q1, 1);
	enQueue(&q1, 2);
	enQueue(&q1, 3);
	printf("%d\n", deQueue(&q1));
	printf("%d\n", deQueue(&q1));
	printf("%d\n", deQueue(&q1));
	return 0;
}
