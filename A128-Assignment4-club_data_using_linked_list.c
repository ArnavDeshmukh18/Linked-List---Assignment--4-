#include<stdio.h>
#include<stdlib.h>


//creating node 
struct member{
    char name[10];
    int prn;
    int rollno;
    struct member *next;
};



//functions
struct member * create_President(struct member *p);//function for accepting President
struct member *  create_list(struct member *p,int n);//function for accepting  members
void display(struct member *p);//function for displaying data
void reverse(struct member *p);//function for displaying reverse list

struct memeber *Create_Scretary (struct member *p,int n);
struct member *Delete(struct member *p,int target);


int main()
{int choice;
int target;
struct member *first=NULL;
first=(struct member *)malloc(sizeof(struct member));

do{

printf("1.Add President \n");
printf("2.Add members \n");
printf("3.Add Secretary \n");
printf("4.Delte Member \n");
printf("5.Reverse \n");
printf("6.Display List \n");
printf("7.Exit\n");
printf("Enter Your Choice : ");

scanf("%d",&choice);
switch (choice)
{

  //creating secretary
case 1:
first=create_President(first);
  
  break;


//adding member
case 2:
printf("Number Members : \n");
int n;
scanf("%d",&n);
first=create_list(first,n);
break;

//adding secretary
case 3:
first=Create_Scretary(first,n);
break;


case 4:

printf("Enter Roll No of Member You Want to Delete\n");
scanf("%d",&target);
first=Delete(first,target);
break;


case 5:
printf("Name\tPRN\tRoll\n");
reverse(first);
break;




case 6:
printf("Name\tPRN\t\tRoll\n");
display(first);
break;

case 7:
 exit;
 break;



default:
printf("INVALID INPUT\n");
  break;
}

}while(choice!=7);







}


struct member *  create_list(struct member *p,int n)
{
    struct member *t,*last;
    last=p;
    for(int i=1;i<n;i++)
    {
      t=(struct member *)malloc(sizeof(struct member));
      printf("Enter Name OF Member\n");
      scanf("%s",t->name);
      printf("Enter PRN OF Member\n");
      scanf("%d",&t->prn);
      printf("Enter Roll No OF Member\n");
      scanf("%d",&t->rollno);
    last->next=t;
    last=t;

    }
   return p;

    
}

struct member * create_President(struct member *p)
{
    struct member *t,*last;
    
    t=(struct member *)malloc(sizeof(struct member));
      printf("Enter Name OF President\n");
      scanf("%s",t->name);
      printf("Enter PRN OF President\n");
      scanf("%d",&t->prn);
      printf("Enter Roll No OF President\n");
      scanf("%d",&t->rollno);
         p=t;
 return p;
}


struct memeber *Create_Scretary (struct member *p,int n)
{
  struct member *t,*temp;
  temp=p;
  for(int i=1;i<n;i++)
  {
    temp=temp->next;

  }
 t=(struct member *)malloc(sizeof(struct member));
   printf("Enter Name OF Secretary\n");
      scanf("%s",t->name);
      printf("Enter PRN OF Secretary\n");
      scanf("%d",&t->prn);
      printf("Enter Roll No OF secretary\n");
      scanf("%d",&t->rollno);
      t->next=NULL;
    temp->next=t;
    return p;

}

void display(struct member *p)
{
  if(p!=NULL)
  {
    printf("%s\t%d\t%d\n",p->name,p->prn,p->rollno);
    display(p->next);
  }
}


void reverse(struct member *p)
{
  if(p!=NULL)
  {
    
    reverse(p->next);
    printf("%s\t%d\t%d\n",p->name,p->prn,p->rollno);
  }
}

struct member *Delete(struct member *p,int target)
{
  struct member *t,*temp;
  t=(struct member *)malloc(sizeof(struct member));
  temp=p;
  t=p->next;
  while(t->rollno!=target)
  { 
    t=t->next;
    temp=temp->next;
  }
  temp->next=t->next;
  free(t);


return p;
} 