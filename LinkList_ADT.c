#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef enum {False,True} MyBool;
struct node 
{
    int data;

    struct node *next;
};

void InsertAtEnd(struct node **ptr,int value)
{
    struct node *temp = NULL;
    struct node *p = NULL;
    p = *ptr;
    temp = (struct node *)malloc(sizeof(struct node));

    if (NULL == temp)
    {
        printf("Memory Allocation failed ");
        exit(1);
    }
    memset(temp,0,sizeof(struct node));

    temp->data = value;
    temp->next = NULL;
    if (NULL == *ptr)
    {
        *ptr = temp;
    }
    else
    {
        while (NULL != p->next)
        {
            p = p->next;
        }
        p->next = temp;
    }

}
void DisplayLinkList(struct node *ptr)
{

    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            printf("%d-->",ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void DisplayLinkListRecursion(struct node *ptr)
{
    static int flag = 0;
    if (NULL != ptr)
    {
        flag =1;
        printf("%d--->",ptr->data);
        DisplayLinkListRecursion(ptr->next);
    }
    else if ((NULL == ptr)&&
            (0 == flag))
    {
        printf("EMPTY LINK LIST\n");
    }
    else if ((NULL == ptr)&&
            (1 == flag))
    {
        printf("NULL\n");
    }

}

int NodeCount(struct node *ptr)
{
    int count =0;
    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            count ++;
            printf("%d--->",ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
    return count;

}

void SearchElement(struct node *ptr, int value)
{
    int count           = 0;
    MyBool isValueFound = False;
    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            count++;
            if (value == ptr->data)
            {
                printf("Element %d found at node %d\n",value,count);
                isValueFound = True;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
    if (True != isValueFound)
    {
        printf("Element %d not found \n",value);
    }
}

int SumLinkList (struct node *ptr)
{
    int sum = 0;
    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            sum += ptr->data;
            ptr = ptr->next;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
    return sum;

}


void MaxMinLinkList (struct node *ptr)
{
    int max = ptr->data;
    int min = ptr->data;
    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            if (min > ptr->data)
            {
                min = ptr->data;
            }
            if (max < ptr->data)
            {
                max = ptr->data;
            }

            ptr = ptr->next;
        }

        printf("Max Element = %d\nMin Element = %d\n",max,min);
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void InsertAtBeg(struct node **ptr,int value)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node ));

    if (NULL == temp)
    {
        printf("Memory Allocation failed ");
        exit(1);
    }
    memset(temp,0,sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (NULL == *ptr)
    {
        printf ("Empty link List Adding first element \n");
        *ptr = temp;
    }
    else 
    {
        printf ("Link List exist Adding Element at the beg \n");
        temp->next = *ptr;
        *ptr = temp;
    }

}

void InsertAtPos(struct node **ptr,int value,int pos)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    int index            = 0;
    temp = (struct node *)malloc(sizeof(struct node ));

    if (NULL == temp)
    {
        printf("Memory Allocation failed ");
        exit(1);
    }
    memset(temp,0,sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    current = *ptr;
    if (NULL !=current)
    {
        if (1 == pos) 
        {
            InsertAtBeg(ptr,value);
        }
        else
        {
            while(++index < pos-1)
            {
                current = current->next;
            }
            temp->next    = current->next;
            current->next = temp;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void DeleteAtend(struct node **ptr)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    
    current = *ptr;
    if(NULL!= *ptr)
    {
        while(current->next !=NULL)
        {
            temp       = current;
            current    = current->next;
        }
        temp->next = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void DeleteAtBeg(struct node **ptr)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    current = *ptr;
    if (NULL != *ptr)
    {
        temp = current;
        *ptr = current->next;
        free(temp);
        temp = NULL;
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void DeleteAtPos(struct node **ptr,int pos)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    int index            = 0;
    int count            = 0;
    count = NodeCount(*ptr);
    current = *ptr;
    if (NULL != *ptr)
    {
        if (1 == pos)
        {
            DeleteAtBeg(ptr);
        }
        else if (count = pos)
        {
            DeleteAtend(ptr);
        }
        else
        {
            while (++index < pos)
            {
                temp       = current;
                current    = current->next;
            }
            temp->next = current->next;
            free(current);
            current = NULL;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

int isSortedLinkList(struct node **ptr)
{
    struct node *current = *ptr;
    int index            = 0;
    int comparator       = INT_MIN;
    MyBool isSorted      = True;
    if (NULL != *ptr)
    {
        while(NULL != current)
        {
            if (comparator > current->data)
            {
                isSorted = False;
                break;
            }
            comparator = current->data;
            current = current->next;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
    }
        if(True == isSorted)
            return 0;
        else
            return 1;
}

void sortingLinkList(struct node **ptr)
{
    struct node *current = NULL;
    struct node *ahead   = NULL;
    int temp             = 0;

    if (NULL != *ptr)
    {
        for (current = *ptr ; current != NULL; current=current->next)
        {
            for (ahead = current->next; ahead != NULL; ahead = ahead->next)
            {
                if (ahead->data < current->data)
                {
                    temp          = ahead->data;
                    ahead->data   = current->data;
                    current->data = temp;
                }
            }
        }
    }

    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
    }
}

void InsertInSorted(struct node **ptr,int value)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    struct node *trailP  = NULL;
    temp = (struct node *)malloc(sizeof(struct node));

    if (NULL == temp)
    {
        printf("Memory Allocation failed ");
        exit(1);
    }
    memset(temp,0,sizeof(struct node));

    temp->data = value;
    temp->next = NULL;

    current = *ptr;

    
    if (NULL != *ptr)
    {
        if (0 != isSortedLinkList(ptr))
        {
            printf("Link List is not sorted....!!!\nSorting LinkList...!!!\n");
            sortingLinkList(ptr);
            printf("Link List after sorting\n");
            DisplayLinkList(*ptr);
        }

        while((NULL != current) && value > current->data)
        {
            trailP     = current;
            current    = current->next;
        }
        temp->next   = trailP->next;
        trailP->next = temp;
    }
    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
    }
}

void DeleteByValue(struct node **ptr,int value)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    struct node *trailP  = NULL;

    current = *ptr;
    if (NULL != *ptr)
    {
        while((NULL != current) && value != current->data)
        {
            trailP     = current;
            current    = current->next;
        }

        trailP->next = current->next;
        temp         = current;

        if (NULL != temp)
        {
            free(temp);
            temp = NULL;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
    }
}


void removingDuplicateNode(struct node **ptr)
{
    struct node *current   = NULL;
    struct node *ahead     = NULL;
    struct node *temp      = NULL;
    struct node *trailP    = NULL;
    MyBool isDuplicate     = False;

    if (NULL != *ptr)
    {
        current = *ptr;
        while(NULL != current)
        {
            isDuplicate = False;
            ahead  = current->next;
            trailP = current; 
            while (NULL != ahead )
            {
                if (current->data == ahead->data)
                {
                    isDuplicate = True;
                    break;
                }
                else
                {
                    trailP = ahead;
                    ahead  = ahead->next;
                }
            }
            if (True == isDuplicate)
            {
                trailP->next = ahead->next;
                temp         = ahead;

                if (NULL != temp)
                {
                    free(temp);
                    temp = NULL;
                }
            }
            current = current->next;
        }
    }

    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
    }
}


void reversingByElements(struct node **ptr)
{
    struct node *current = NULL;
    int index            = 0;
    int *a               = NULL;
    int size             = 0;
    
    size = NodeCount(*ptr);
    a = (int *)malloc(size);

    if (NULL == a)
    {
        printf("Memory Allocation failed ");
        exit(1);
    }

    if (NULL != *ptr)
    {
        index   = size-1; 
        current = *ptr;
        while((NULL != current) && (0 <= index))
        {
            a[index] = current->data;
            current  = current->next;
            index--;
        }
        current = *ptr;
        index   = 0; 
        while((NULL != current)&& (index < size))
        {
            current->data = a[index];
            current = current->next;
            index++;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
    }

    if (NULL != a)
    {
        free(a);
        a = NULL;
    }

}

void reversingByLinks(struct node **ptr)
{
    struct node *current = NULL;
    struct node *prev    = NULL;
    struct node *ahead   = NULL;

    ahead = *ptr;
    if (NULL != *ptr)
    {
        while(NULL != ahead)
        {
            prev    = current;
            current = ahead;
            ahead   = ahead->next;
            current->next = prev;
        }
        *ptr = current;
    }
    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
    }
}

/*tortoise hare algorethm (Floyd's Algo)*/
int checkLoop(struct node **ptr)
{
    struct node *hare     = NULL;
    struct node *tortoise = NULL;
    MyBool isloopFound    = False;

    tortoise = *ptr;
    hare     = *ptr;
    
    if (NULL != *ptr)
    {
        while(NULL != hare)
        {
            tortoise = tortoise->next;
            if (hare == tortoise)
            {
                isloopFound = True;
                tortoise = *ptr;
            }
            hare = hare->next;
        }
    
    }
    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
    }
    if (True == isloopFound)
    {
        return  0;
    }
    else 
    {
        return  1;
    }
}

int main()
{
    struct node *head = NULL;
    int choice = 0; 
    int value  = 0; 
    int cont   = 0; 
    int ele    = 0;
    int pos    = 0;

    do
    {
        printf("1.InsertAtEnd\n2.Display\n3.Display using Recursion\n");
        printf("4.No. of nodes\n5.Searching\n6.Sum of LL\n7.Max and Min\n");
        printf("8.Insert at beg\n9.Insert at pos\n10.Delete at pos\n11.Delete at beg\n");
        printf("12.Delete at end\n13.Insert in sorted list\n14.check if link list is sorted\n");
        printf("15.Delete by data\n16.Sort Link List\n17.Removing Duplicate node\n18.Reversing LinkList by elements\n");
        printf("19.Reversing Link List by links\n20.Checking for loop\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter Data to be inserted \n");
                scanf("%d",&value);
                InsertAtEnd(&head,value);
                break;
            }
            case 2:
            {
                printf("******************************** \n");
                printf("********SINGLE LINK LIST******** \n");
                printf("******************************** \n");
                DisplayLinkList(head);
                break;
            }
            case 3:
            {
                printf("******************************** \n");
                printf("********SINGLE LINK LIST******** \n");
                printf("******************************** \n");
                DisplayLinkListRecursion(head);
                break;
            }
            case 4:
            {
                printf("No. of nodes in the LINK LIST = %d\n",NodeCount(head));
                break;
            }
            case 5:
            {
            
                printf("Enter element for searching : ");
                scanf("%d",&ele);
                SearchElement(head,ele);
                break;
            }
            case 6:
            {
            
                printf("Sum of LL = %d\n", SumLinkList(head));
                break;
            }
            case 7:
            {
                MaxMinLinkList(head);
                break;
            }
            case 8:
            {
                printf("Enter Data to be inserted \n");
                scanf("%d",&value);
                InsertAtBeg(&head,value);
                break;
            }
            case 9:
            {
                printf("Enter Data to be inserted :");
                scanf("%d",&value);
                printf("Enter Pos : ");
                scanf("%d",&pos);
                InsertAtPos(&head,value,pos);
                break;
            }
            case 10:
            {
                printf("Enter Pos : ");
                scanf("%d",&pos);
                DeleteAtPos(&head,pos);
                break;
            }
            case 11:
            {
                DeleteAtBeg(&head);
                break;
            }
            case 12:
            {
                DeleteAtend(&head);
                break;
            }
            case 13:
            {
                printf("Enter Data to be inserted \n");
                scanf("%d",&value);
                InsertInSorted(&head,value);
                printf("Link List After Inserting\n");
                DisplayLinkList(head);
                break;
            }
            case 14:
            {
                if (0 == isSortedLinkList(&head))
                {
                    printf("Sorted List \n");
                }
                else
                {
                    printf("Un-Sorted List \n");
                }
                break;
            }
            case 15:
            {
                printf("Enter Data of node to be deleted \n");
                scanf("%d",&value);
                printf("Link List Before Deletion\n");
                DisplayLinkList(head);
                DeleteByValue(&head,value);
                printf("Link List after Deletion\n");
                DisplayLinkList(head);
                break;
            }
            case 16:
            {
                printf("Link List Before sorting\n");
                DisplayLinkList(head);
                sortingLinkList(&head);
                printf("Link List after sorting\n");
                DisplayLinkList(head);
                break;
            }
            case 17:
            {
                printf("Link List Before Removing Duplicate Node\n");
                DisplayLinkList(head);
                removingDuplicateNode(&head);
                printf("Link List after Removing Duplicate Node\n");
                DisplayLinkList(head);
                break;
            }
            case 18:
            {
                printf("Link List Before Reversing\n");
                DisplayLinkList(head);
                reversingByElements(&head);
                printf("Link List after Reversing\n");
                DisplayLinkList(head);
                break;
            }
            case 19:
            {
                printf("Link List Before Reversing \n");
                DisplayLinkList(head);
                reversingByLinks(&head);
                printf("Link List after Reversing\n");
                DisplayLinkList(head);
                break;
            }
            case 20:
            {
                if (0 == checkLoop(&head))
                {
                    printf("Link list have loops \n");
                }
                else
                {
                    printf("No loops found \n");
                }
                break;
            } 

            default:
                printf("Wrong Choice : \n");
        
        }
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);

    if (NULL != head)
    {
        printf("Freeing Link List\n");
        free(head);
        head = NULL;
    }

    return 0;
}
