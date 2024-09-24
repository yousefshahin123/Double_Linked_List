/********************#defines sectioon****************************/
#include<stdio.h>
#include<stdlib.h>
/********************#defines sectioon****************************/

/********************typedef section******************************/
typedef struct node_t{
    struct node_t *next;
    struct node_t *prev;
    unsigned int data;
}node;
typedef enum{
    NOK,
    OK
}fun_status;
/********************typedef section******************************/

/******************function declaration section*******************/
fun_status insert_at_beginning(node **D_List);
fun_status insert_at_ending(node **D_List);
fun_status insert_after_index(node **D_List);

void delete_at_beginning(node **D_List);
void delete_at_ending(node **D_List);
void delete_by_index(node **D_List);
void delete_by_value(node **D_List);

unsigned int search_element(node *list);

unsigned int get_list_length(node *D_List);

void display_D_List_F(node *D_List);
void display_D_List_R(node *D_List);
/******************function declaration section*******************/

int main(){

    node *D_List_1=NULL;
    printf("\nHello to Double Linked List\n");
    while(1){
        printf("\n**************************************************************\n");
        printf("Please select a number to do your operation\n");
        printf("1) Insert at beginning\n");
        printf("2) Insert at ending\n");
        printf("3) Insert at index\n");
        printf("******************************\n");
        printf("4) Delete at beginning\n");
        printf("5) Delete at ending\n");
        printf("6) delete by index\n");
        printf("7) delete by value\n");
        printf("******************************\n");
        printf("8) Search element\n");
        printf("9) Get list length\n");
        printf("10) Display list forward\n");
        printf("11) Display list Reverse\n");
        printf("12) End the program\n");
        printf("**************************************************************\n");
        unsigned int user_choice=0;
        printf("\nyour choice : ");
        scanf("%i",&user_choice);
        switch(user_choice){
            case 1 :
                insert_at_beginning(&D_List_1);
                break;
            case 2 :
                insert_at_ending(&D_List_1);
                break;
            case 3 :
                insert_after_index(&D_List_1);
                break;
            case 4 :
                delete_at_beginning(&D_List_1);
                break;
            case 5 :
                delete_at_ending(&D_List_1);
                break;
            case 6 :
                delete_by_index(&D_List_1);
                break;
            case 7 :
                delete_by_value(&D_List_1);
                break;
            case 8 :
                printf("Element index is ( first element index is 1 ) : %i \n",search_element(D_List_1));
                break;
            case 9 :
                printf("List Length is : %i\n",get_list_length(D_List_1));
                break;
            case 10 :
                display_D_List_F(D_List_1);
                break;
            case 11 :
                display_D_List_R(D_List_1);
                break;
            case 12 :
                printf("The program is closed successfully\n");
                exit(1);
            default :
                printf("Invalid choice!!!\n");
                break;
        }
    }
    return 0;
}

/******************function definition section*******************/
fun_status insert_at_beginning(node **D_List){
    fun_status fun_return=NOK;
    node *new_node=NULL;
    new_node=(node *)malloc(sizeof(node));
    if(NULL==new_node){
        printf("Couldn't allocate the memory\n");
        fun_return=NOK;
    }
    else{
        printf("Please, enter element value : ");
        scanf("%i",&(new_node->data));
        new_node->prev=NULL;
        if(NULL==*D_List){
            new_node->next=NULL;
            *D_List=new_node;
        }
        else{
            new_node->next=*D_List;
            (*D_List)->prev=new_node;
            *D_List=new_node;
        }        
        fun_return=OK;
    }
    return fun_return;
}
fun_status insert_at_ending(node **D_List){
    fun_status fun_return=NOK;
    node *new_node=NULL;
    new_node=(node *)malloc(sizeof(node));
    if(NULL==new_node){
        printf("Couldn't allocate the memory\n");
        fun_return=NOK;
    }
    else{
        if(NULL==*D_List){
           fun_return=insert_at_beginning(D_List);
        }
        else{
            printf("Please, enter element value : ");
            scanf("%i",&(new_node->data));
            new_node->next=NULL;
            node *traverse_node=*D_List;
            while(traverse_node->next){
                traverse_node=traverse_node->next;
            }
            traverse_node->next=new_node;
            new_node->prev=traverse_node;
            fun_return=OK;
        }
    }
    return fun_return;
}
fun_status insert_after_index(node **D_List){
    fun_status fun_return=NOK;
    unsigned int index=0;
    printf("Please, enter element index ( first element index is 1 ) : ");
    scanf("%i",&index);
    if(index>get_list_length(*D_List)||0==index){
        printf("Invalid index!\n");
        fun_return=NOK;
    }
    else{
        if(get_list_length(*D_List)==index){
            fun_return=insert_at_ending(D_List);
        }
        else{
            node *treverse_node=*D_List;
            unsigned int counter=1;
            for(counter=1;counter<index;counter++){
                treverse_node=treverse_node->next;
            }
            node *new_node=NULL;
            new_node=(node *)malloc(sizeof(node));
            if(NULL==new_node){
                printf("Couldn't allocate memory\n");
                fun_return=NOK;
            }
            else{
                printf("Please, enter element value :  ");
                scanf("%i",&(new_node->data));
                new_node->next=treverse_node->next;
                new_node->prev=treverse_node;
                (treverse_node->next)->prev=new_node;
                treverse_node->next=new_node;
                fun_return=OK;
            }
        }
    }
    return fun_return;
}

void delete_at_beginning(node **D_List){
    if(NULL==*D_List){
        printf("List is empty!\n");
    }
    else if(NULL==(*D_List)->next){
        printf("Element %i has been deleted successfully\n",(*D_List)->data);
        free(*D_List);
        *D_List=NULL;
    }
    else{
        printf("Element %i has been deleted successfully\n",(*D_List)->data);
        *D_List=(*D_List)->next;
        free((*D_List)->prev);
        (*D_List)->prev=NULL;
    }
}
void delete_at_ending(node **D_List){
    if(NULL==*D_List){
        printf("List is empty!\n");
    }
    else if(NULL==(*D_List)->next){
        printf("Element %i has been deleted successfully\n",(*D_List)->data);
        free(*D_List);
        *D_List=NULL;
    }
    else{
        node *traverse_node=*D_List;
        while(traverse_node->next->next){
            traverse_node=traverse_node->next;
        }
        printf("Element %i has been deleted successfully\n",traverse_node->next->data);
        free(traverse_node->next);
        traverse_node->next=NULL;
    }
}
void delete_by_index(node **D_List){
    unsigned index = 0;
    unsigned length = get_list_length(*D_List);
    if(NULL==*D_List){
        printf("The list is empty!\n");
    }
    else{
        printf("Please enter element index to be dalated ( first element index is 1 ) : ");
        scanf("%i",&index);
        if(index>length||index==0){
            printf("Invalid index!!!\n");
        }
        else if(1==index){
            delete_at_beginning(D_List);
        }
        else if(index==length){
            delete_at_ending(D_List);
        }
        else{
            node *temp_node=*D_List;
            while(index-2){
                index--;
                temp_node=temp_node->next;
            }
            printf("Element %i has been deleted successfully\n",temp_node->next->data);
            temp_node->next=temp_node->next->next;
            free(temp_node->next->prev);
            temp_node->next->prev=temp_node;
        }
    }
}
void delete_by_value(node **D_List){
    unsigned int length=get_list_length(*D_List);
    signed int element=0;
    unsigned int index=0;
    unsigned char found=0;
    printf("Please, enter element to be deleted : ");
    scanf("%i",&element);
    if(NULL==D_List){
        printf("The list is empty!\n");
        index=0;
        found=0;
    }
    else{
        node *treverse_node=*D_List;
        while(treverse_node){
            index++;
            if(treverse_node->data==element){
                printf("FOUND\n");
                found=1;
                break;
            }
            treverse_node=treverse_node->next;
        }
    }
    if(!found){
        index=0;
    }
    if(0==index){
        printf("Element is not found!\n");
    }
    else if(1==index){
        delete_at_beginning(D_List);
    }
    else if(index==length){
        delete_at_ending(D_List);
    }
    else{
        node *temp_node=*D_List;
        while(index-2){
            index--;
            temp_node=temp_node->next;
        }
        printf("Element %i has been deleted successfully\n",temp_node->next->data);
        temp_node->next=temp_node->next->next;
        free(temp_node->next->prev);
        temp_node->next->prev=temp_node;
    }
}

unsigned int search_element(node *D_List){
    signed int element=0;
    unsigned int index=0;
    unsigned char found=0;
    printf("Please, enter element you want to search for : ");
    scanf("%i",&element);
    if(NULL==D_List){
        printf("The list is empty!\n");
        index=0;
        found=0;
    }
    else{
        node *treverse_node=D_List;
        while(treverse_node){
            index++;
            if(treverse_node->data==element){
                printf("FOUND\n");
                found=1;
                break;
            }
            treverse_node=treverse_node->next;
        }
    }
    if(!found){
        index=0;
    }
    return index;
}

unsigned int get_list_length(node *D_List){
    unsigned int length=0;
    if(NULL==D_List){
        length=0;
    }
    else{
        node *travrese_node=D_List;
        while(travrese_node){
            length++;
            travrese_node=travrese_node->next;
        }
    }
    return length;
}

void display_D_List_F(node *D_List){
    if(NULL==D_List){
        printf("The List is empty!\n");
    }
    else{
        node *traverse_node=D_List;
        printf("The list elements are : [\t");
        while(traverse_node){
            printf("%i\t",traverse_node->data);
            traverse_node=traverse_node->next;
        }
        printf("]\n");
    }
}
void display_D_List_R(node *D_List){
    if(NULL==D_List){
        printf("The List is empty!\n");
    }
    else{
        node *traverse_node=D_List;
        while(traverse_node->next){
            traverse_node=traverse_node->next;
        }
        printf("The list elements are : [\t");
        while(traverse_node){
            printf("%i\t",traverse_node->data);
            traverse_node=traverse_node->prev;
        }
        printf("]\n");
    }
}
/******************function definition section*******************/