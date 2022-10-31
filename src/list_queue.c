#include "list_queue.h"
#include <assert.h>
#include <stdio.h>

void init_queue(queue *q)
{
  // Add your init_ queue
  q->size = 0; //sets size of queue to 0
  q->front = NULL; //Initializes front
  q->rear = NULL; //Initializes rear
  
}

int empty(queue *q)
{
  // Add your empty function  

  if(q->size == 0){
    return 1; //if queue size is NULL return true (1)
  }
  else{
    return 0; //else return false (0)
  }

}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  if(q->front == NULL) //if queue is empty
  {
    qnode *element = (qnode*)malloc(sizeof(qnode)); //creates a new list element
    element->data = x; //elements data is equal variable x
    element->next = NULL; //element points to NULL as its the front element
    q->front = element; //element is set as the queue front
    q->rear = q->front; //queues rear is also the rear as its the only element
  }
  else //else the queue already has elements then
  {
    qnode *element = (qnode*)malloc(sizeof(qnode)); //creates a new element
    element->data = x; //sets its data equal to variable x
    element->next = q->rear; //elements next points at the rear
    q->rear = element;  //the new rear is then set to the new element
  }

  q->size = q->size + 1; //adds 1 to the size of the queue

}

int dequeue(queue *q)
{
  // Add your dequeue function
  assert(q->size > 0); //checks that the size of queue is larger than zero
  qnode *behind = q->rear; //qnode pointing to the rear of queue
  qnode *first = q->front; //qnode pointing to the front

  int front_item = q->front->data; //saves the front of the queues data which should be returned

  if(q->size == 1) //if the size of the queue is one
  {
    q->front = NULL; //no more elements are in the queue, front is NULL
    q->rear = NULL; //no more elements are in the queue, so the rear is NULL
  }
  else if(q->size > 1) //else if the queue size is larger than one
  {
    for(int i = 0; i < q->size - 2; i++) //the for loop goes to the element before the front element
    {
      behind = behind->next; //goes through the elements from the rear
    }

    q->front = behind; //the front is now set as behind, which is the element before the front which is dequeued
  }

  free(first); //frees the front

  q->size = q->size - 1; //substracts 1 from the size of the queue


  return front_item; //returns the dequeued front data

}
