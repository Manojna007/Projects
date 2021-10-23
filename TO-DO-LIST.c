#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void saveToDo();
void updateToDo();
void delToDo();
void createToDo();
void seeToDo();
void welcomeUser();

typedef struct ToDo todo;

struct ToDo{
 char data[100];
 todo *link;
 int count;
};

todo *start=NULL;
int main()
{
    int choice;
    welcomeUser();
    for(;;){
        system("color 2f");
        system("cls");
        printf("\n1.SEE YOUR TO-DO LIST");
        printf("\n2.CREATE YOUR TO-DO's");
        printf("\n3.DELETE YOUR TO-DO's");
        printf("\n4.UPDATE YOUR TO-DO's");
        printf("\n5.SAVE TO-DO");
        printf("\n6.EXIT");
        printf("\n\nENTER YOUR CHOICE..");
        scanf("%d",&choice);
        switch(choice){
      case 1:
          seeToDo();
        break;
      case 2:
          createToDo();
        break;
      case 3:
          delToDo();
        break;
      case 4:
         updateToDo();
         break;
      case 5:
          saveToDo();
        

      case 6:
        exit(0);
        }
    }
}

void welcomeUser(){
   system("color 2f");
   printf("\n\n\n\n\n");
   printf("\t------------------------------------------------------------------------------------------------------\n\n");
   printf("\t#################################### YOUR TODO LIST APP ##############################################\n\n");
   printf("\t------------------------------------------------------------------------------------------------------");
   printf("\n\n\n\t\t**********************************WELCOME*************************************\n\n\n\n\n\n\n\n\n\t");
   system("pause");
}

void seeToDo(){
   todo *temp;
   temp=start;
        if(start==NULL){
           printf("\nEMPTY TODO LIST\n\n");
        }

       while(temp!=NULL){
          printf("%d)",temp->count);
          puts(temp->data);
          fflush(stdin);
          temp=temp->link;
       }
       printf("\n\n\n");
       system("pause");
   }

void createToDo(){
    char k;
    todo *t,*temp;
    while(1){
        printf("\nWANT TO ADD?y/n\n");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       else{
        if(start==NULL)
	{
        t=(todo *)calloc(1,sizeof(todo));
        start=t;
        printf("\nADD IT..\n");
        fflush(stdin);
        gets(t->data);
        t->count=1;
        start->link=NULL;
       }
       else{
       temp=(todo *)calloc(1,sizeof(todo));
       printf("\nADD IT..\n");
       fflush(stdin);
       gets(temp->data);
       temp->link=NULL;
       t->link=temp;
       t=t->link;
     }
     fixcount();
    }
   }
}

void delToDo(){
  int d;
  todo *temp1,*temp;
  if(start==NULL)
  {
  	printf("TODO LIST EMPTY");
  	printf("\n\n\n\n\n");
  	system("pause");
  	return;
  }
  printf("\nENTER THE NUMBER OF THE TO-DO YOU WANT TO REMOVE\n");
  scanf("%d",&d);
  temp1=start;
  temp=start->link;
  while(1){
  if(temp1->count==d){
    start=start->link;
    free(temp1);
    fixcount();
    break;
  }
    if(temp->count==d){
        temp1->link=temp->link;
        free(temp);
        fixcount();
        break;
    }
    else{
        temp1=temp;
        temp=temp->link;
    }
}
system("pause");
}

void fixcount(){
  todo *temp;
  int i=1;
  temp=start;
  while(temp!=NULL){
    temp->count=i;
    i++;
    temp=temp->link;
  }
}

void updateToDo(){
  todo *temp,*t;
  char k;
  while(1){
        printf("\nWANT TO ADD?y/n\n");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       printf("\nADD it..\n");
       temp=(todo *)calloc(1,sizeof(todo));
       fflush(stdin);
       gets(temp->data);
       temp->link=NULL;
       t=start;
      while(t->link!=NULL){
        t=t->link;
      }
      t->link=temp;
      fixcount();
}
printf("\n\n");
system("pause");
}

void saveToDo(){
  FILE *fptr;
  todo *temp;
  temp=start;
  time_t t;   // not a primitive datatype
  time(&t);
 
   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("D:\\program2.txt","w");
   fprintf(fptr," TO-DO-LIST for  %s  contains:\n\n\n",ctime(&t));


   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

  
   else{
      while(temp!=NULL){
        fprintf(fptr, "%d",temp->count);
        fprintf(fptr," %s \n",temp->data);
        temp=temp->link;
      }
       fclose(fptr);
    }
   return 0; 
   
}


