extern "C"{
    // Add the header files required to run your main 
    #include "linked_list.c"
    #include "insertion_sort.c"
    #include "list_queue.c"
    #include <assert.h>
    
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{

    linked_list *test_list = (linked_list*)malloc(sizeof(linked_list));
    test_list->head = NULL;

    int n = 7;
    int t[n] = {-3,22,11,33,3,2,1}; 
    for (int i = 0; i < n; i++)
    {
        node_t *test_value = (node_t*)malloc(sizeof(node_t));
        test_value->data = t[6-i];
        test_value->next = NULL;
        insertFront(test_value, test_list);
    }
    printLL(test_list);

    sort(test_list);
    
    
    //Part queue test

    printf("\n\nTest For QUEUE\n\n");

    // 3) b) test of list_queue
    int x = 6; //test value
    queue *qtest;

    // 3)b)A)
    init_queue(qtest);
    assert(empty(qtest) == 1);
    printf("A) queue is empty \n\n");

    // 3)b)B)
    enqueue(qtest, x);
    int y = dequeue(qtest);

    assert(empty(qtest) == 1 && x == y);
    printf("B) queue is empty and x = %d y = %d are equal\n\n", x, y);

    // 3)b)C)
    int x0 = 4; //test values
    int x1 = 8; //test values

    enqueue(qtest, x0);
    enqueue(qtest, x1);
    int y0 = dequeue(qtest);
    int y1 = dequeue(qtest);

    assert(empty(qtest) == 1 && x0 == y0 && x1 == y1);
    printf("C) queue is empty, and\n");
    printf("x0 = %d and y0 = %d are equal\n", x0, y0);
    printf("x1 = %d and y1 = %d are equal\n", x1, y1);



    return 0;
}