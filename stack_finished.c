#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

void initialize(stack *s) {
  s->head = NULL; 
}

void push(int x, stack *s) {
  node *q_push = (node *)malloc(sizeof(node)); //malloc is used to allocate memory for a node
  if (q_push == NULL) { //If it isn't possible to allocate memory. Malloc returns NULL
    printf("Unable to allocate memory.\n");
    return;
}
  q_push->data = x; //New node gets value of x
  q_push->next = s->head; //New node becomes new head
  s->head = q_push; //Updating the stack, so new node is the top
}
//*q_push is the pointer pointing to the newly allocated memory

int pop(stack *s) {
  if (empty(s)){
    printf("Cannot pop from an empty stack.\n");
    exit(EXIT_FAILURE);
  }

  int q_pop = s->head->data; //Take the top value
  node *temp = s->head; //Make a place holder and make it equal to top node
  s->head = s->head->next; //Move the head to the next node
  free(temp); //Frees the memory of the popped node
 
  return q_pop;
}

bool empty(stack *s) {
  return s->head == NULL; //Returns true if head is NULL, which it is if empty
}

bool full(stack *s) {
  node *q_full = (node *)malloc(sizeof(node));
  if (q_full == NULL){
    //If malloc cannot allocate more memory it returns NULL
    return true;
  }
  free(q_full);
  return false; //When using linked lists, the stack is never technically full unless no more memory is available
}

int main(){
stack s;

initialize(&s);
assert(empty(&s) == true); //After initializing the stack must be empty

push(10,&s);
assert(pop(&s) == 10);
//x = 10 and y = 10. The stack also looks the same as before the test.

push(20, &s);
push(30, &s);
assert(pop(&s) == 30);
assert(pop(&s) == 20);
//x0 = 20, x1 = 30, y0 = 30 and y = 20. The stack looks the same as before all four commands.
printf("All tests passed.\n");

return 0;


}