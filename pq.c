/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Jason O'Brien
 * Email: obriejas@oregonstate.edu
 */

#include <stdlib.h>
#include "dynarray.h"
#include "pq.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */
struct pq{
  struct dynarray* dynamic_arr;
};

struct pq_node{
  int p_value;
  void* data;
};


/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
  struct pq* p_que = malloc(sizeof(struct pq));
  return p_que;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
  dynarray_free(pq->dynamic_arr);
  free(pq);

}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
  if(dynarray_size(pq->dynamic_arr) == 0){
    return 1;
  }
  return 0;
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
  int parent_val_index;
  void* temp_val;
  struct pq_node* node;
  node->data = value;
  node->p_value = priority;

  dynarray_insert(pq->dynamic_arr, -1 , node); //puts value into dynamic_arr
  while(parent_val_index != -1){
    parent_val_index = ((dynarray_size(pq->dynamic_arr)- 2) / 2);

    if(((dynarray_get(pq->dynamic_arr,-1)->node->p_value) < ((dynarray_get(pq->dynamic_arr,parent_val_index)->node->p_value)){
      temp_val = dynarray_get(pq->dynamic_arr,parent_val_index);
      dynarray_get(pq->dynamic_arr,parent_val_index)->node->data = dynarray_get(pq->dynamic_arr,-1)->node->p_data;
      dynarray_get(pq->dynamic_arr,-1)->node->p_data = temp_val;
    }
  }


}



/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq){
  int i;
  return pq->dynamic_arr[0]->data->node->data;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
 int pq_first_priority(struct pq* pq){
  return pq->dynamic_arr[0]->data->node->p_value;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
  int first_value = pq_first(pq);
  int least_val, repl_value, least_idx;
  void* temp_val;
  size = dynarray_size((pq->dynamic_arr)- 1)

  dynarray_set(pq, 0, pq->dynamic_arr[dynarray_size((pq->dynamic_arr)- 1]->data->node->data))
  dynarray_remove(pq, -1);

  int replace_idx = 0;
   do {
     if(!pq_isempty()){
       int left_idx = 2*replace_idx+1;
       int right_idx = 2*replace_idx+2;
       //struct pq_node* left_node = pq->dynamic_arr[2*i+1]->data->node;
       //struct pq_node* right_node = pq->dynamic_arr[2*i+2]->data->node;
       if(left_idx > size && right_idx > size){
         return NULL;
       }

       if((pq->dynamic_arr[left_idx]->data->node->p_value) > (pq->dynamic_arr[right_idx]->data->node->p_value)){
         least_val = pq->dynamic_arr[right_idx]->data->node->p_value;
         least_idx = right_idx;
       } else {
         least_val = pq->dynamic_arr[left_idx]->data->node->p_value;
         least_idx = left_idx;
       }

       repl_value = pq->dynamic_arr[repl_idx]->data->node->p_value

       if(repl_value > least_val){
         temp_val = pq->dynamic_arr[repl_idx]->data;
         pq->dynamic_arr[repl_idx]->data->node->data = pq->dynamic_arr[least_idx]->data->node->p_data;
         pq->dynamic_arr[least_idx]->data->node->p_data = temp_val;
         replace_idx = least_idx;

       }
    }
   } while(repl_value > least_val);




  return NULL;
}
