#ifndef INTLIST_H
#define INTLIST_H
typedef struct IntList IntList;

struct IntList {
  IntList *next;
  int num;
};

IntList* recursiveMakeIntListFromArray(int *numbers, int length);
IntList* makeIntListFromArray(int *numbers, int length);
void freeIntList(IntList *list);
#endif
