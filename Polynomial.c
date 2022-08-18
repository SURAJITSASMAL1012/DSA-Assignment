#include<stdio.h>
#include<stdlib.h>

typedef struct record{
    int coeff,exp;
    struct record* next;
}node;

node* getnode(int co,int exp){
    node* temp;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    temp->coeff= co;
    temp->exp = exp;
    temp->next=NULL;

    return temp;
}
node* createpolynomial(){
    node* temp,*head=NULL,*prev=NULL;
    int ch,co,exp;
    do{
        printf("Enter the coefficint and exponenet : ");
        scanf("%d%d",&co,&exp);
        temp=(node*)malloc(sizeof(node));
        temp=getnode(co,exp);
        if(head==NULL){
            head=temp;
            prev=head;
        }
        else{
            prev->next=temp;
            prev=temp;
        }
        printf("\nEnter 1 for continue otherwisw 0\n");
        scanf("%d",&ch);

    }while(ch==1);
    return head;
}
void display(node* head){
    node* c = head;
    if(c==NULL){
        printf("\nPolynomial is not created \n");
    }
    else{
        while(c){
            printf("%dX^(%d)",c->coeff,c->exp);
            if(c->next)
            printf(" + ");

            c=c->next;
        }
    }
    printf("/n");
}
node *addpolynomial(node* p1,node* p2){
    node *c1=p1;
    node *c2=p2;
    node* p3= NULL,*prev;
    node *temp,*prev;
    if(c1==NULL&&c2==NULL)
    return  NULL;
    if(c1==NULL)
    return c2;
    if(c2==NULL)
    return c1;
    while(c1!=NULL || c2!=NULL){
        if(c1!=NULL && c2!=NULL){
            if(c1->exp==c2->exp){
                temp=getnode(c1->coeff+c2->coeff,c1->exp);
                c1=c1->next;
                c2=c2->next;
            }
            else if(c1->exp>c2->exp){
                temp = getnode(c1->coeff,c1->exp);
                c1=c1->next;
            }
            else{
                temp = getnode(c2->coeff,c2->exp);
                c2=c2->next;
            }
        }
    }
    if(c1==NULL){
        temp=getnode(c2->coeff,c2->exp);
        c2=c2->next;
    }
    else{
        temp=getnode(c1->coeff,c1->exp);
        c1=c1->next;
    }
    if(p3==NULL){
        p3=temp;
        prev=p3;
    }
    else{
        prev->next=temp;
        prev=temp;
    }
}
int main(){
    node* poly1=NULL;
    node* poly2=NULL;

    poly1=createpolynomial();
    poly2=createpolynomial();
    display(poly1);
    display(poly2);

    return 0;
}