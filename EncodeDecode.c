#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "EncodeDecode.h"

//Function to encode
void encode_the_string(dll *list, char* str, unsigned char key)
{
	unsigned char encoded_value;
	for(int i=0;str[i]!='\0';i++)
	{
		   encoded_value=str[i]^key;
		   
		   append_to_list(list,encoded_value);
	}
}
//Function add the encoded data to the double linked list
void append_to_list(dll *list,unsigned char encoded_value)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=encoded_value;
	newnode->prev=list->tail;
	newnode->next=NULL;
	if (list->tail==NULL)
	{
		list->head=newnode;
	}
	else
	{
		list->tail->next=newnode;
	}
	list->tail=newnode;
}

void print_the_encoded(dll *list)
{
	node *temp=list->head;
	while(temp!=NULL)
	{
		printf("%02x",temp->data);
		temp=temp->next;
	}
	
}

void decoded_string(dll *list, char *output , unsigned char key)
{
	node *temp =list->head;
	int index=0;
	while(temp !=NULL)
	{
		output[index++]=temp->data^key;
		temp=temp->next;
	}
	output[index]='\0';

	
}



//function to free the list
void freethelist(dll *list)
{
	node *current=(node*)malloc(sizeof(node));
	current=list->head;
	while(current)
	{  
        node *temp=current->next;
		free(current);
		current=temp;
		
	}
	list->head=NULL;
	list->tail=NULL;
}