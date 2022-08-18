#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int top;
    int *a;
    int Mindex;
}ST;
void display(ST s){
    if(s.top==-1){
        printf("\nStack is empty\n");
    }
    else{
        printf("\nStack\n:");
        for(int i=s.top;i>=0;i--){
            printf("%d\n",s.a[i]);
        }
    }
    return;
}
void create(ST *s){
    int n;
    printf("\nEnter the size of the stack \n");
    scanf("%d",&n);
    s->top=-1;
    s->Mindex=n;
    s->a=(int *)malloc(sizeof(int)*n);

    return;
}
bool isfull(ST s){
    if(s.top==s.Mindex-1)
    return true;
    else
    return false;
}
bool isempty(ST s){
    if(s.top==-1)
    return true;
    else
    return false;
}
void push(ST *st,int ele){
    if(isfull(*st)){
        printf("\nstack overflow\n");
        return;
    }
    st->top++;
    st->a[st->top]=ele;
    printf("\nElement is successfully pushes\n....");
    display(*st);
    return;
}
int pop(ST *s){
    if(isempty(*s)){
        printf("\nStack is underflow...\n");
        return;
    }
    int x=s->a[s->top];
    s->top--;
    return x;
}
int peek(ST *s){
    if(isempty(*s)==true){
        printf("\nStack is underflow......\n");
        return -1;
    }
    return s->a[s->top];
}
int main(){
    ST *p;
    p=(ST *)malloc(sizeof(ST));
    int x,n,choice,count=0;
    do{
        printf("\nEnter the choice \n1.Exit\n2.Create \n3.PUSH\n4.POP\n5.PEEK\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                break;
            case 2:
                create(p+count);
                count++;
                p=(ST *)realloc(p,sizeof(ST)*(count+1));
                printf("\nSystem has %d stack\n",count);
                break;
            case 3:
                printf("\nSystem has %d stacks \n",count);
                if(count==0){
                    printf("\nSystem has no stacks \n");
                    break;
                }
                do{
                    printf("\nenter the stack in which u want to push ..\n");
                    scanf("%d",&n);
                    if(n>count)
                    printf("\nsystem has %d stack \n\nTry Again \n",count);

                }while(n>count);
                printf("\nEnter the element u want to pushed \n:");
                scanf("%d",&x);
                push(p+(n-1),x);
                break;
        }

    }while(choice!=1);
    return 0;
}