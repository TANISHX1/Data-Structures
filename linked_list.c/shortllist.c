// SHORTS THE JOBS BASED ON THE NUMBER OF tICKETS USING BUBBLE SORTING ALGORITHM
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    char *name;
    int ticket;
    struct node*next;
}node_t;

node_t *create_node(char *name, int ticket){
    node_t *node = malloc(sizeof(node_t));
    if(node == NULL)
    {
        printf("Node allocation failed..\n");
        exit(0);
    }
    node->name = strdup(name);
    node->ticket = ticket;
    node->next = NULL;
    return node;    
}

void append_node(node_t **head,char* name,int ticket){
    node_t *newnode = create_node(name,ticket);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
     node_t *temp = *head;
     while(temp->next != NULL){
        temp = temp->next;
     }
     temp->next = newnode;
}
void print_node(node_t*head){
    node_t*temp = head;
    while(temp != NULL)
    {
        printf("Ticket name :%s    |Ticket number :%d\n",temp->name,temp->ticket);
        temp = temp->next;
    }
}
void shorting(node_t **head){
    if(*head == NULL || (*head)->next ==NULL) return ;

    int flag;
    node_t **ptr = head;
    do{
        flag =0;
    
    
    while((*ptr)->next != NULL)
    {
        node_t *temp = *ptr;
        node_t *temp1 = temp->next;
        if(temp->ticket > temp1->ticket)
        {
            temp->next = temp1->next;
            temp1->next = temp;
            *ptr = temp1;
            flag =1;
        }
        ptr = &(*ptr)->next;

    }}while(flag);
}

int main(){
    node_t *list =NULL;
    append_node(&list,"joba",80);
    append_node(&list,"jobb",70);
    append_node(&list,"jobc",60);
    append_node(&list,"jobd",40);
    append_node(&list,"jobe",50);
    append_node(&list,"jobe",100);
    append_node(&list,"jobf",10);
    append_node(&list,"jobg",90);
    append_node(&list,"jobh",0);
    append_node(&list,"jobi",60);
    append_node(&list,"jobj",200);
    append_node(&list,"jobk",45);
    for(int i=0;i<8;i++)
    {shorting(&list);}
    print_node(list);
    return 0;
}