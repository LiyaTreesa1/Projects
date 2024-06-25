#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"EncodeDecode.h"

	
int main()
{
	char str[]="hello";
	int len;
	len=strlen(str);
	dll list={NULL,NULL};//Initializing with NULL for tail and head
	
	unsigned char key=0xAA;
	encode_the_string(&list,str,key);
	//Print the encoded data
	
	//printf("%d",list.head->data);
	
	print_the_encoded(&list);
	printf("\n");
	char *output=(char*)malloc(sizeof(char)*len+1);
	
	decoded_string(&list,output,key);
	
	printf("Decoded string is %s", output);
	 freethelist(&list); 

}
	