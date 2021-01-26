#ifndef MaxQSize
#define MaxQSize 5
#endif

typedef ElementType  = int;
typedef struct queue{
  int QFront, QRear, QSize;
  ElementType array[MaxQSize];
}

void CreateQueue(queue*);
int EmptyQueue(queue);
void Enqueue(ElementType, queue*);
ElementType Dequeue(queue*);
ElementType Front(queue);
