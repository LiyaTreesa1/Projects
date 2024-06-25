#ifndef ENCODE_H
#define ENCODE_H
typedef struct node
{
	char data;
	struct node *prev;
	struct node*next;
}node;
typedef struct{
	node *head;
	node *tail;
}dll;
	
void encode_the_string(dll *list, char *str, unsigned char key);
void append_to_list(dll *list,unsigned char encoded_value);
void print_the_encoded(dll *list);
void decoded_string(dll *list, char *output , unsigned char key);
void freethelist(dll *list);

#endif