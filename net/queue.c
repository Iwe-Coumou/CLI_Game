#include <stdlib.h>
#include "event.h"
#include "queue.h"


queue_t *queue_create(void) {
  queue_t *q = malloc(sizeof(queue_t));
  if (!q) return NULL;
  q->size = 0;
  q->head = 0;
  q->tail = 0;
  return q;
}

void queue_free(queue_t *q) {
  if (!q) return;
  free(q);
}

void queue_push(queue_t *q, event_t *e) {
  if (!q) return;
  if (!e) return;

  if (q->size == MAX_QUEUE_SIZE) return;
  q->events[q->tail] = e;
  q->tail = (q->tail+1) % MAX_QUEUE_SIZE;
  q->size++;
}

event_t *queue_pop(queue_t *q) {
  if (!q) return NULL;
  if (q->size == 0) return NULL;
  event_t *e = q->events[q->head];
  q->head = (q->head+1) % MAX_QUEUE_SIZE;
  q->size--;
  return e;
}
