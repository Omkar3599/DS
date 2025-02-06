#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int insertBefore(Node** head, int data, int element) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (temp->data == element) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        Node* prev = temp;
        while (temp->data != element && temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data != element) {
            printf("Element not found\n");
            return 0;
        } else {
            newNode->next = temp;
            newNode->prev = prev;
            prev->next = newNode;
            temp->prev = newNode;
        }
    }
}

int insertAfter(Node** head, int data, int element) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (temp->data == element) {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    } else {
        while (temp->data != element && temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->data != element) {
            printf("Element not found\n");
            return 0;
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL)
                temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
}

int deleteNode(Node** head, int element) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return 0;
    }
    Node* temp = *head;
    if ((*head)->data == element) {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
    } else {
        while (temp->data != element && temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->data != element) {
            printf("Element not found\n");
            return 0;
        } else {
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
        }
    }
}

void traverse(Node** head) {
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("The last element is: %d\n", temp->data);
}

void reverseList(Node** head) {
    Node* temp = NULL;
    Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        *head = temp->prev;
}

void deleteAlt(Node** head) {
    Node* temp = *head;
    while (temp != NULL && temp->next != NULL) {
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        if (temp2->next != NULL)
            temp2->next->prev = temp;
        free(temp2);
        temp = temp->next;
    }
}

void bubbleSort(Node** head) {
    if (*head == NULL) {
        return;
    }

    int swapped;
    Node* ptr;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr = *head;

        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main(){
    int i,data,ele,n,choice;
    Node* head=NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data of all nodes: ");
    scanf("%d" ,&data);

    head = createNode(data);
    for(i=1;i<n;i++)
        {
            scanf("%d", &data);
            insertAtEnd(&head,data);
        }
        printList(head);

    while(1){

            printf("\nMENU:\n1.Insert node after an element \n2.PRINT list\n");
            printf("3.Insert node before an element \n4.Reverse the list \n");
            printf("5.Delete element \n6.Delete alternate node \n");
            printf("7.Sort the list \n8.Insert element in the sorted list \n");
            printf("9.Traverse the list\n10.Exit\n");
            printf("\nEnter your choice:");

            scanf("%d", &choice);

            switch(choice)
            {
            case 1:
                printf("Enter the data to insert after an element: ");
                scanf("%d" , &data);
                printf("Enter the element to be searched: ");
                scanf("%d",&ele);
                insertAfter(&head,data,ele);
                break;

            case 2:
                printList(head);
                break;

            case 3:
                printf("Enter the data to insert before an element: ");
                scanf("%d" , &data);
                printf("Enter the element to be searched: ");
                scanf("%d",&ele);
                insertBefore(&head,data,ele);
                break;

            case 4:
                reverseList(&head);

                break;

            case 5:
                printf("Enter the element to delete: ");
                scanf("%d" , &ele);
                deleteNode(&head,ele);
                break;

            case 6:
                deleteAlt(&head);
                break;

            case 7:
                bubbleSort(&head);
                break;

            case 8:
                insertAfter(&head,data,ele);
                break;

            case 9:
            printf("Enter a number to traverse the list: ");
            scanf("%d" , &n);
            traverse(&head);
            break;

            case 10:
                printf("\t\tExiting...\n\n");
                exit(0);

            default: printf("Invalid choice\n");
            }
        }
    return 0;

    }

