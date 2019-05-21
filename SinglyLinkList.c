#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#define SIZE 200
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct st {
	int data ;
	struct st *next;
	char buffer[SIZE];
	
}node;

node *start = NULL,*temp,*current;
node *p1,*p2,*p3;

char* gettime()
{
	static char s[SIZE]="My name is X";
	time_t timer;
	struct tm* tm_info;
	
	time(&timer);
	tm_info = localtime(&timer);

	strftime(s, 26, "%Y-%m-%d %H:%M:%S", tm_info);
	
	return s;
}


void singlytrav(node *start_pointer){
	printf("\n\n ** location of start: %p1\n",start);
	for(temp = start_pointer; temp!=NULL; temp =temp->next){
		printf("\nNode no: %d",temp->data);
		printf("  Date: %s",temp->buffer);
		printf(" at address %p",temp);
		printf("\n\n ** location of start: %p1\n",start);
		
	}
	
	
}

int node_count = 0;

void Singlycreate(){
		printf("Enter Singlycreate");
		printf("\n\n ** location of start: %p1\n",start);
		temp = (node *)malloc(sizeof(node));
		node_count ++;
		printf("\nNo %d node will be created..",node_count);
		temp->data = node_count;
    		
    	strcpy(temp->buffer,gettime());
		if(start == NULL){
			
			start  = temp;
			current  = temp;	
		}
		else{
			current->next = temp;
			current = temp;
		}
		
		current->next = NULL;
		fflush(stdin);
		printf("\n\n ** location of start: %p1\n",start);
	printf("Exit Singlycreate");
}



void SinglyRevDisplay(){
	printf("Enter SinglyRevDisplay");
	printf("\n\n ** location of start: %p1\n",start);
	int node_count_disp = 0;
	int dummy_j = 0;
	for (temp = start ;temp!=NULL;temp=temp->next){
		node_count_disp ++;
	}
	printf("\nNo of nodes present in the list: %d\n",node_count_disp);
	for ( ; node_count_disp > 0 ; node_count_disp--){
		temp = start;
		//printf("\n node_count_disp :%d",node_count_disp);
		while(dummy_j!=node_count_disp-1){
			dummy_j ++;
			//printf	("\n dummy_j : %d",dummy_j);
			temp = temp->next;
		}
		
		printf	("\nNode : %d -->",temp->data);
		printf(" %s",temp->buffer);
		printf(" at address %p",temp);
		dummy_j =0;	
		
	}
	printf("\n\n ** location of start: %p1\n",start);
	
	printf("Exit SinglyRevDisplay");	
}


void SinglyReverse(){
	printf("Enter SinglyReverse");	
	p1 = start; // p1 pointing to first node which is pointed by start pointer
	p2 = p1->next; // p2 is pointing to to second node
	p3 = p2->next;// p3 is pointing to second node
	
	printf("\n\n ** location of start: %p1\n",start);
	p2->next = p1; // Second node is pointing to First node;
	p1->next = NULL; // First node has been set to NULL;
	printf("\n\nlocation of P1: %p1",p1);
	printf("\nlocation of P2: %p2",p2);
	
	while(p3 != NULL){
		//printf("\nlocation of P3:%p",p3);	
}
	
	/*  []->  []-> []-> []-> []-> []-> []-> NULL */
	printf("Exit SinglyReverse");	
}


int main(int argc, char *argv[]) {
	
	char res = 'y';
	start = NULL;
	printf("\n\n ** location of start: %p1\n",start);
	
		printf("\nPress y to continue creating node:");
		scanf("%c",&res);	
	while (res == 'y'){
		printf("\n\n ** location of start: %p1\n",start);
		printf("res : %c",res);
		Singlycreate();
		
		printf("\nPress y to continue creating node:");
		scanf("%c",&res);	
		}
	
		singlytrav(start);
		SinglyRevDisplay();
		SinglyReverse();
	return 0;
	getch();
	
	
	
	
}
