#include <stdio.h>
#include <stdlib.h>

#include "IntList.h"

IntList* recursiveMakeIntListFromArray(int *numbers, int length) {
  if (length > 0) {
    IntList *out = (IntList*)malloc(sizeof(IntList));
    out->num = numbers[0];
    // Pointer arithmetic; equivalent to &numbers[1].
    out->next = makeIntListFromArray(numbers + 1, length - 1);

    return out;
  } else {
    return NULL;
  }
}

IntList* makeIntListFromArray(int *numbers, int length) {
  if (length > 0) {
    IntList *head = NULL;

    for (int k = length - 1; k >= 0; k -= 1) {
      IntList *temp = (IntList*)malloc(sizeof(IntList));
      temp->num = numbers[k];
      temp->next = head;
      head = temp;
    }

    return head;
  } else {
    return NULL;
  }
}

void freeIntList(IntList *list) {
  IntList *head = list;
  while(head) {
    head = head->next;
    free(list);
    list = head;
  }
}
