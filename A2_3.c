#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *pre;
	struct node *next;
}NODE;

//create node
NODE* create(int n)
{
	NODE *t=(NODE *)malloc(sizeof(NODE));
	t->data=n;
	t->pre=NULL;
	t->next=NULL;
	return(t);
}

//append node
void append(NODE **p)
{
	NODE *c,*t;
	int n;
	printf("Enter the data to be appended = ");
	scanf("%d",&n);
	c=create(n);
	if(*p==NULL)
	{
		*p=c;
		return;
	}
	t=*p;
	while(t->next!=NULL)
		t=t->next;
	t->next=c;
	c->pre=t;
	return;
}

//Create linked list
void createlist(NODE **p)
{
	char ch;
	do
	{
		append(p);
		printf("Want to insert another node ? (Y/N)  ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	return;
}

//Display
void display(NODE *p)
{
	NODE *t=p;
	if(p==NULL)
	{
		printf("Linked list is empty.\n");
		return;
	}
	while(t!=NULL)
	{
		printf("%d ->",t->data);
		t=t->next;
	}
	printf("NULL\n");
	return;
}

//prepend node
void prepend(NODE **p)
{
	NODE *c;
	int n;
	printf("Enter the data to be preAppend = ");
	scanf("%d",&n);
	c=create(n);
	if(*p!=NULL)
		(*p)->pre=c;
	c->next=*p;
	*p=c;
	return;
}

//insert after position
void insertafterposition(NODE *p,int k)
{
	NODE *c,*t=p;
	int n,count=1;
	while(count!=k&&t->next!=NULL)
	{
		t=t->next;
		count++;	
	}
	if(count<k)
	{
		printf("linked list doesnot contain %d elements\n",k);
		return;
	}
	printf("Enter the data to be inserted = ");
	scanf("%d",&n);
	c=create(n);
	c->next=t->next;
	c->pre=t;
	if(t->next)
		t->next->pre=c;
	t->next=c;
	return;
}

//insert after data
void insertafterdata(NODE *p,int k)
{
	NODE *c,*t=p;
	int n;
	while(t->data!=k&&t->next!=NULL)
		t=t->next;
	if(t->data!=k)
	{
		printf("Data %d not present in the linked list\n",k);
		return;
	}
	printf("Enter the data to be inserted = ");
	scanf("%d",&n);
	c=create(n);
	c->next=t->next;
	c->pre=t;
	if(t->next)
		t->next->pre=c;
	t->next=c;
	return;
}

//insert before position
void insertbeforeposition(NODE **p,int k)
{
	NODE *c,*t=*p;
	int n,count=1;;
	while(count!=k&&t->next!=NULL)
	{
		count++;
		t=t->next;
	}
	if(count<k)
	{
		printf("linked list does not contain %d elements\n",k);
		return;
	}
	printf("Enter the data to be inserted = ");
	scanf("%d",&n);
	c=create(n);
	c->next=t;
	c->pre=t->pre;
	if(t->pre)
		t->pre->next=c;
	else
		*p=c;
	t->pre=c;
	return;
}

//insert before data
void insertbeforedata(NODE **p,int k)
{
	NODE *c,*t=*p;
	int n;
	while(t->data!=k&&t->next!=NULL)
		t=t->next;
	if(t->data!=k)
	{
		printf("Data %d not present in the linked list\n",k);
		return;
	}
	printf("Enter the data to be inserted = ");
	scanf("%d",&n);
	c=create(n);
	c->next=t;
	c->pre=t->pre;
	if(t->pre)
		t->pre->next=c;
	else
		*p=c;
	t->pre=c;
	return;
}

//Delete first element
void deletefirst(NODE **p)
{
	NODE *c=*p;
	if(*p==NULL)
	{
		printf("Linked list is empty. Cant perform delete operation\n");
		return;
	}
	*p=c->next;
	if(c->next)
		c->next->pre=NULL;
	free(c);
	return;
}

//Delete last element
void deletelast(NODE **p)
{
	NODE *c=*p;
	if(*p==NULL)
	{
		printf("Linked list is empty. Cant perform delete operation\n");
		return;
	}
	while(c->next!=NULL)
		c=c->next;
	if(c->pre)
		c->pre->next=NULL;
	else
		*p=NULL;
	free(c);
	return;
}

//delete by data
void deletedata(NODE **p,int n)
{
	NODE *c=*p;
	if(*p==NULL)
	{
		printf("Linked list is empty. Cant perform delete operation\n");
		return;
	}
	while(c->data!=n&&c->next!=NULL)
		c=c->next;
	if(c->data!=n)
	{
		printf("Data %d does not exists in linked list\n",n);
		return;
	}
	if(c->pre)
		c->pre->next=c->next;
	else
		*p=c->next;
	if(c->next)
		c->next->pre=c->pre;
	free(c);
	return;
}

//delete by position
void deleteposition(NODE **p,int n)
{
	NODE *c=*p;
	int count=1;
	if(*p==NULL)
	{
		printf("Linked list is empty. Cant perform delete operation\n");
		return;
	}
	while(count!=n&&c->next!=NULL)
	{
		count++;
		c=c->next;
	}
	if(count<n)
	{
		printf("linked list does not contain %d elements\n",n);
		return;
	}
	if(c->pre)
		c->pre->next=c->next;
	else
		*p=c->next;
	if(c->next)
		c->next->pre=c->pre;
	free(c);
	return;
}

//Delete before kth position
void deletebeforeposition(NODE **p,int k)
{
	NODE *c;
	int count=2;
	c=*p;
	if(c==NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	if(k==1)
	{
		printf("There is no node before 1st node.\n");
		return;
	}
	while(count!=k&&c->next!=NULL)
	{
		count++;
		c=c->next;
	}
	if(count<k)
	{
		printf("Linked list do not contain %d element\n",k);
		return;
	}
	if(k==2)
	{
		(*p)=(*p)->next;
		(*p)->pre=NULL;
		free(c);
	}
	else
	{
		c->pre->next=c->next;
		c->next->pre=c->pre;
		free(c);	
	}
	return;
}

//Delete before kth position
void deleteafterposition(NODE *p,int k)
{
	NODE *t,*c;
	int count=1;
	c=p;
	if(c==NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	while(count!=k&&c->next!=NULL)
	{
		count++;
		c=c->next;
	}
	if(count<k)
	{
		printf("Linked list do not contain %d element\n",k);
		return;
	}
	if(c->next==NULL)
	{
		printf("There is no node after last node.\n");
		return;
	}
	t=c->next;
	c->next=c->next->next;
	if(t->next)
		t->next->pre=c;
	free(t);
	return;
}

//reverse linked list iterative
void reverse(NODE **p)
{
	NODE *c=*p,*t;
	if(*p==NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	while(c!=NULL)
	{
		t=c->next;
		c->next=c->pre;
		c->pre=t;
		*p=c;
		c=t;
	}
	return;
}

int main()
{
	NODE *head,*head1,*head2,*head3;
	head=NULL;
	int option,k;
	do
	{
		printf("\n\nSelect option number.\nPress 0 for exit.\n");
		printf("Enter 1 for create linked list.\n");
		printf("Press 2 for display.\n");
		printf("Press 3 for add at front.\n");
		printf("Press 4 for add at end.\n");
		printf("Press 5 for insert after position.\n");
		printf("Press 6 for insert after a value.\n");
		printf("Press 7 for insert before position.\n");
		printf("Press 8 for insert before data.\n");
		printf("Press 9 for delete 1st node.\n");
		printf("Press 10 for delete last node.\n");
		printf("Press 11 for delete before kth node.\n");
		printf("Press 12 for delete after kth node.\n");
		printf("Press 13 for delete kth node.\n");
		printf("Press 14 for delete node by value.\n");
		printf("Press 15 for reverse.\n");
		scanf("%d",&option);
		switch(option)
		{
			case 0:
				break;
			case 1:
				createlist(&head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				prepend(&head);
				break;
			case 4:
				append(&head);
				break;
			case 5:
				printf("Enter the serial number after which data you want to insert the new node : ");
				scanf("%d",&k);
				insertafterposition(head,k);
				break;
			case 6:
				printf("Enter after which data you want to insert the new node : ");
				scanf("%d",&k);
				insertafterdata(head,k);
				break;
			case 7:
				printf("Enter the serial number before which data you want to insert the new node : ");
				scanf("%d",&k);
				insertbeforeposition(&head,k);
				break;
			case 8:
				printf("Enter the data before which data you want to insert the new node : ");
				scanf("%d",&k);
				insertbeforedata(&head,k);
				break;
			case 9:
				deletefirst(&head);
				break;
			case 10:
				deletelast(&head);
				break;
			case 11:
				printf("Enter the position before which you want to delete :\n");
				scanf("%d",&k);
				deletebeforeposition(&head,k);
				break;
			case 12:
				printf("Enter the position after which you want to delete :\n");
				scanf("%d",&k);
				deleteafterposition(head,k);
				break;
			case 13:
				printf("Enter the position to be deleted :\n");
				scanf("%d",&k);
				deleteposition(&head,k);
				break;
			case 14:
				printf("Enter the data to be deleted :\n");
				scanf("%d",&k);
				deletedata(&head,k);
				break;
			case 15:
				printf("Reverse iterative :-\n");
				reverse(&head);
				break;
			default:
				printf("Enter right option betwee 0 to 16.\n");
				break;
		}
	}while(option!=0);
	return(0);
}
