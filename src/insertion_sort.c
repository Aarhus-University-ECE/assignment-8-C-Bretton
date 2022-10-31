#include "insertion_sort.h"
#include "linked_list.h"




void sort(linked_list *llPtr)
{
 // Add your sort function here
    node_t *list = llPtr->head; //initializes the lists first element
    linked_list *sorted = (linked_list*)malloc(sizeof(linked_list)); //creats a new linked list, where the sorted element are saved
    sorted->head = NULL; //initializes a sorted list

    while(list != NULL) //while the lists element is not NULL
    {
        
        node_t *curr = createNode(list->data); //save the current list data as curr

        insertFront(curr, sorted); //puts the current list element in front of the sorted list, which is now the sorted->head

        node_t *check = sorted->head; //sets the first element of sorted (curr) as check, which we want to sort
        node_t *next_element = check->next; //initializes the next element in the list, we want to compare check with
        
        if (next_element != NULL && check->data > next_element->data)
        {
            node_t *prev = swap(check, next_element); //check's and next_element's next's are swapped. so next_element points at check,
            //and check's next is now next_element's next. Next_element is now the previous element before check (prev)
            next_element = check->next; //the new next element is set as checks next 
            sorted->head = prev; //prev is now the first element in the sorted list. as check was swapped in infront of next_element, which
            //now has become the previous (prev)
            
            while(next_element != NULL && check->data > next_element->data) //while the new next element is less than check and not NULL 
            {
            
                prev->next = swap(check, next_element); //check and next_element swaps, and prev next now points at next_element
                
                next_element = check->next; //next element is now set as checks next
                prev = prev->next; //prev is now the prev->next, which was the next_element swapped infront of check
            }

            //the prev pointer is made, as the sorted->head would otherwise always point at the current list element, being sorted.
            //the prev now makes it so when the current check element is swapped, the previous points to the swapped element, which 
            //then points to the current check element.
        }

        list = list->next; //goes to the next list element, and runs the first while loop, if the next element is not NULL

    }

    //prints the sorted list
    node_t *n = sorted->head;
    while(n != NULL)
    {
        printf("| %d ", n->data);
        n = n->next;
    }
    printf("|\n");

    llPtr->head = sorted->head; //Sets the original list to the sorted list

}
