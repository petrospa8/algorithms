#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

void CreateQueue(queue *q){
    q->QFront = 0;
    q->QRear = -1;
    q->QSize = 0;

}

int isEmptyQueue(queue q){
  return (q.Size == 0);
}

void Enqueue(queue *q,ElementType p){
  if (q->QSize == MaxQSize){
    printf("error: Full Qu (eue: %d\n",QSize);
    exit(EXIT_FAILURE);
  }
  Q->QSize++;
  Increment (&q->QRear));
  q->array[q->QRear] = x;
}

ElementType Front(queue q){
  if(EmptyQueue(q)){
    printf("error: Empty Queue\n");
    exit(EXIT_FAILURE);
  }
  return(q.array[q.QFront]);
}
