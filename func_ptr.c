// Gage Lynch <gagelynch@gmail.com>
#include <stdio.h>
#include <stdlib.h>

#include "IntList.h"

void map(int (*fp)(int), IntList *list) {
  while(list) {
    list->num = fp(list->num);
    list = list->next;
  }
}

int add1(int num) {
  return num + 1;
}

int printNum(int num) {
  (void)fprintf(stdout, "%i\n", num);
  return num;
}

int main(int argc, char** argv) {
  int nums[5] = {0, 1, 2, 3, 4};
  IntList *list = makeIntListFromArray(nums, 5);
  
  (void)fprintf(stdout, "Before add1:\n");
  map(printNum, list);
 
  map(add1, list);

  (void)fprintf(stdout, "After add1:\n");

  map(printNum, list);

  freeIntList(list);
  return 0;
}
