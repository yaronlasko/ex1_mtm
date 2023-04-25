#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "IsraeliQueue.h"



/**Error clarification:
 * ISRAELIQUEUE_SUCCESS: Indicates the function has completed its task successfully with no errors.
 * ISRAELIQUEUE_ALLOC_FAILED: Indicates memory allocation failed during the execution of the function.
 * ISRAELIQUEUE_BAD_PARAM: Indicates an illegal parameter was passed.
 * ISRAELI_QUEUE_ERROR: Indicates any error beyond the above.
 * */

typedef struct node
{
    void* data;
    int friends;
    int rivals;
    struct node* next;
    struct node* prev;
}Node_t;

typedef struct
{
    Node_t* head;
    Node_t* tail;
    FriendshipFunction* friendsFunctions;
    ComparisonFunction compareFunction;
    int friendship_th;
    int rivalry_th;
    int size;
}IsraeliQueue_t;


/**Creates a new IsraeliQueue_t object with the provided friendship functions, a NULL-terminated array,
 * comparison function, friendship threshold and rivalry threshold. Returns a pointer
 * to the new object. In case of failure, return NULL.*/
IsraeliQueue IsraeliQueueCreate(FriendshipFunction *friendsArray, ComparisonFunction compare, int friendship_th, int rivalry_th)
{
    IsraeliQueue_t* ptrIsraeliQueue = (IsraeliQueue_t*)malloc(sizeof(IsraeliQueue_t));
    if(ptrIsraeliQueue!=NULL)
    {
        ptrIsraeliQueue->friendsFunctions = friendsArray;
        ptrIsraeliQueue->compareFunction = compare;
        ptrIsraeliQueue->friendship_th = friendship_th;
        ptrIsraeliQueue->rivalry_th = rivalry_th;
        ptrIsraeliQueue->head = NULL;
        ptrIsraeliQueue->tail = NULL;
        ptrIsraeliQueue->size = 0;
    }
    return (IsraeliQueue)ptrIsraeliQueue;
}

/**Returns a new queue with the same elements as the parameter. If the parameter is NULL or any error occured during
 * the execution of the function, NULL is returned.*/
//IsraeliQueue IsraeliQueueClone(IsraeliQueue q)


/**@param IsraeliQueue: an IsraeliQueue created by IsraeliQueueCreate
 *
 * Deallocates all memory allocated by IsraeliQueueCreate for the object pointed to by
 * the parameter.*/
//void IsraeliQueueDestroy(IsraeliQueue);

/**@param IsraeliQueue: an IsraeliQueue in which to insert the item.
 * @param item: an item to enqueue
 *
 * Places the item in the foremost position accessible to it.*/
IsraeliQueueError IsraeliQueueEnqueue(IsraeliQueue queue, void *data)
{
    IsraeliQueue_t *ptrQueue = (IsraeliQueue_t*) queue;
    Node_t* newNode = (Node_t*)malloc(sizeof (Node_t));
    if(newNode == NULL)
    {
        return ISRAELIQUEUE_ALLOC_FAILED;
    }

    newNode->data = data;
    newNode->friends = 0;
    newNode->rivals = 0;
    newNode->next = NULL;
    newNode->prev = ptrQueue->tail;
    if(ptrQueue->tail==NULL)
    {
        ptrQueue->tail=newNode;
        ptrQueue->head = newNode;
    }
    else
    {
        ptrQueue->tail->next = newNode;
    }

    ptrQueue->tail = newNode;
    ptrQueue->size++;
    return ISRAELIQUEUE_SUCCESS;
}

/**@param IsraeliQueue: an IsraeliQueue to which the function is to be added
 * @param FriendshipFunction: a FriendshipFunction to be recognized by the IsraeliQueue
 * going forward.
 *
 * Makes the IsraeliQueue provided recognize the FriendshipFunction provided.*/
//IsraeliQueueError IsraeliQueueAddFriendshipMeasure(IsraeliQueue, FriendshipFunction);

/**@param IsraeliQueue: an IsraeliQueue whose friendship threshold is to be modified
 * @param friendship_threshold: a new friendship threshold for the IsraeliQueue*/
//IsraeliQueueError IsraeliQueueUpdateFriendshipThreshold(IsraeliQueue, int);

/**@param IsraeliQueue: an IsraeliQueue whose rivalry threshold is to be modified
 * @param friendship_threshold: a new rivalry threshold for the IsraeliQueue*/
//IsraeliQueueError IsraeliQueueUpdateRivalryThreshold(IsraeliQueue, int);

/**Returns the number of elements of the given queue. If the parameter is NULL, 0
 * is returned.*/
int IsraeliQueueSize(IsraeliQueue queue)
{
    if(queue == NULL)
    {
        return 0;
    }
    return ((IsraeliQueue_t*)queue)->size;
}

/**Removes and returns the foremost element of the provided queue. If the parameter
 * is NULL or a pointer to an empty queue, NULL is returned.*/
void* IsraeliQueueDequeue(IsraeliQueue queue)
{
    IsraeliQueue_t* ptrQueue = (IsraeliQueue_t*) queue;
    if(IsraeliQueueSize(queue)==0 || queue==NULL)
    {
        return NULL;
    }
    Node_t* ptrNode = ptrQueue->head;
    void* data = ptrQueue->head->data;

    ptrQueue->head = ptrQueue->head->next;
    free(ptrNode);
    if(ptrQueue->head!=NULL)
    {
        ptrQueue->head->prev = NULL;
    }
    ptrQueue->size--;

    return data;

}

/**@param item: an object comparable to the objects in the IsraeliQueue
 *
 * Returns whether the queue contains an element equal to item. If either
 * parameter is NULL, false is returned.*/
//bool IsraeliQueueContains(IsraeliQueue, void *);

/**Advances each item in the queue to the foremost position accessible to it,
 * from the back of the queue frontwards.*/
//IsraeliQueueError IsraeliQueueImprovePositions(IsraeliQueue);

/**@param q_arr: a NULL-terminated array of IsraeliQueues
 * @param ComparisonFunction: a comparison function for the merged queue
 *
 * Merges all queues in q_arr into a single new queue, with parameters the parameters described
 * in the exercise. Each queue in q_arr enqueues its head in the merged queue, then lets the next
 * one enqueue an item, in the order defined by q_arr. In the event of any error during execution, return NULL.*/
//IsraeliQueue IsraeliQueueMerge(IsraeliQueue*,ComparisonFunction);

