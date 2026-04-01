#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 32

#include <stdlib.h>
#include "event.h"

typedef struct Queue {
  size_t size;
  size_t head;
  size_t tail;
  event_t *events[MAX_QUEUE_SIZE];
} queue_t;

queue_t *queue_create(void);
void queue_push(queue_t *q, event_t *e);
event_t *queue_pop(queue_t *q);

#endif
