#include<stdio.h>

int stack[100],n,choice,x,top;
void push(void);
void pop(void);
void display(void);

int main(){
    top=-1;
    printf("\nEnter the size of the stack  : ");
    scanf("%d",&n);
    printf("\n\tSTACK Operation using Array \n\t");
    printf("\n\t---------------------------------\n");
    printf("\n\t 1.PUSH \n\t2.POP \n\t3.DISPLAY \n\t4.EXIT\n\t");
    do{
        printf("\nEnter a choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tEXIT POINT\n");
                break;
            default:
                printf("\n\tPlease Enter a valid choice 1/2/3/4\n\t");
        }
    }while(choice!=4);

    return 0;
}
void push(){
    if(top>=n-1){
        printf("\nSTACK overflow \n");
    }
    else{
        printf("\nEnter the element You want to push in the stack : ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top<=-1){
        printf("\nSTACK Underflow\n");
    }
    else{
        printf("\n\tPOPed element from the stack : %d ",stack[top]);
        top--;
    }
}
void display(){
    if(top>=0){
        for(int i=top;i>=0;i--){
            printf("\n%d\n",stack[i]);
        }
    }
    else{
        printf("\n No element in the stack to display \n");
    }
}