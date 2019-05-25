#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#define SIZE 200
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct st {
	char buffer[SIZE];
	int data ;
	struct st *next;
	struct st *prev;	
}node;

node *temp,*temp2,*current = NULL,*head, *nxt_node,*prv_node;


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

void p(char *enex,char *fname){
//	printf("\n\n**%s**\n\n",*fname);
/*
	int len = 0,i;
	char *d_fname;
	 d_fname= fname;
	printf("\n");
	while(*enex!='\0'){
		printf("%c",*enex);
		enex++;
	}
printf("  ");
	
	while(*fname!='\0'){
		len++;
		fname++;
	}
	while(*d_fname!='\0'){
		printf("%c",*d_fname);
		d_fname++;
	}
	for (i =0;i<len;i++){
		printf("*");
	}
	
	
	printf("\n");*/
}

void paddr(char *pname ,node *dummy_p){
	/*printf("\n**Address of ");
		while(*pname!='\0'){
		printf("%c",*pname);
		pname++;
	}
	printf(" is : %p **\n",dummy_p);*/	
}

int node_Count = 0;

int t;
void createNode(){
	p("Enter","createNode");
	temp = (node * )malloc(sizeof(node));
	
	strcpy(temp->buffer,gettime());
	temp->data = ++ node_Count;
	printf("%d Node created",node_Count);
	if(current == NULL){
		head = temp;
		current = temp;
		current->next = temp;
		current->prev = temp;
	}
	else{
		for (current = head;current->next!=head;current = current->next){
		/*paddr("head",head);
		paddr("current",current);
		paddr("current->next",current->next);*/
	}
		current->next = temp;
		temp->prev = current;
		temp->next = head;
		head->prev=temp;	
	p("Exit","createNode");	
	}
	
};
void dispNode(){
	p("Enter","dispNode");
	
	if (head!=NULL){
		current=head;
	int node_pos= 0;
	printf("\n===================================================================");
	
	do{
		node_pos++;
		printf("\n%d ) ",node_pos);
		printf("Data at node %d",current->data);
		printf(" --> %s",current->buffer);
		printf(" at address ");
		paddr("current",current);
		current = current->next;
		printf("\n===================================================================");	
	}
	while(current!= head );		
	}
			
p("Exit","dispNode");	
}	
	
	
	

int get_node_Count(){
	p("Enter","get_node_Count");
	if(head!=NULL){
		int node_count_act = 0;	
	current = head;
	do{
		node_count_act ++;
		current=current->next;
	}
	while (current!=head );
	p("Exit","get_node_Count");
	return node_count_act;
	}
	
}
	



void inserAtPos(int pos){
	
	int total_node,i=0;
	total_node = get_node_Count();
	p("Enter","inserAtPos");
	if(pos <= total_node){
	current = head;	
		
	for (i=0;i<total_node;i++){
		
		if(i + 1 == pos){
		
		temp = (node*)malloc(sizeof(node));
		strcpy(temp->buffer,gettime());
		temp->data = ++ node_Count;
		
		printf("\n%d Node created",node_Count);

		if (pos == 1){
			temp->next = current;
			temp->prev = current->prev;
			current->prev->next = temp;
			current->prev = temp;
			head = temp;
			printf("\nData at head node %d",head->data);
			printf(" --> %s ...",head->buffer);	
		}
		else if(pos == total_node){
			head->prev->next = temp;
			temp->prev = head->prev;
			temp->next =  head;
			head->prev = temp;
			printf("\nData at node %d",current->data);
			printf(" --> %s",current->buffer);
		}
		else{
		current->next->prev = temp;
		temp->next = current->next;
		temp->prev = current;
		current->next = temp;
		}
		break;	
		}
		current = current->next;
	}
		
	}
	printf("\nTotal Nodes:%d",total_node);
	p("Exit","inserAtPos");
}	
	

void deleteAtPos(int delPos){
	
	int total_node,i=0;
	total_node = get_node_Count();

	p("Enter","deleteAtPos");
	if(delPos <= total_node){
	current = head;	
	printf("\n%d th node will be deleted(User choice)",delPos);
	
	if (total_node==1){
		free(current);
		head=NULL;
	}
	else{
		for (i=0;i<total_node;i++){
			printf("\nData at node %d",current->data);
			printf(" --> %s",current->buffer);
		
		if(i + 1 == delPos){
		if (delPos == 1){//Deleting first node
			printf("\nData at node %d",current->data);
			printf(" --> %s will  be deleted...",current->buffer);
			paddr("current",current);
			current=current->next;
			paddr("current",current);
			current->prev = head->prev;
			head->prev->next=current;
			head=current;
			paddr("head",head);
			
			//free(current);
		
		}
		else if(delPos == total_node){//Deleting last node
			
			current->prev->next = head;
			head->prev=current->prev;
			//free(current);
			printf("\nData at node %d",current->data);
			printf(" --> %s willbe deleted...",current->buffer);
		
			
		}
		else{//Delleting any node except first and last
			paddr("current",current);
			paddr("current->prev",current->prev);
			paddr("current->next",current->next);
			paddr("head",head);
			printf("\nData at node %d",current->data);
			printf(" --> %s",current->buffer);
			
			current->prev->next = current->next;
			current->next->prev = current->prev;
			//free(current);
			
			
		}

		
		break;	
		}
		
		current = current->next;
	
	}
		
	}
		
	
	}
	printf("\nTotal Nodes:%d",total_node);
	p("Exit","deleteAtPos");
	
	
}


int main(){	
	p("Enter","main");
	char res = 'y';
	int insert_pos = -1,delete_pos = -1  ;
	
	while(res == 'y'){
		
		createNode();
		
		printf("\nPress y to continue : ");
		scanf("%c",&res);
		
		fflush(stdin);
		paddr("head",head);
	}
	dispNode();
	
	
		printf("\nEnter position to insert:");
	scanf("%d",&insert_pos);
	if ( insert_pos > 0){
		inserAtPos(insert_pos);
		dispNode();
	}
	fflush(stdin);
	
	
	while(get_node_Count()>0){
		printf("\nEnter position to delete:");
	scanf("%d",&delete_pos);
	printf("%d",get_node_Count());		
	if ( delete_pos > 0){
		if(get_node_Count()>0){
		deleteAtPos(delete_pos);
		dispNode();
		}
	}
	}
	
	
	
	
p("Exit","main");
return 0;
}


