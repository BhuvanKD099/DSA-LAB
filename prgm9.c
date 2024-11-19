
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
struct node
{
	int coef;
	int pow_x;
	int pow_y;
	int pow_z;
struct node*next;
};
typedef struct node*polyptr;
polyptr insertterm(polyptr poly,int coef,int pow_x,int pow_y,int pow_z)
{
	polyptr cur;
	polyptr newNode=(polyptr)malloc(sizeof(struct node));
	newNode->coef=coef;
	newNode->pow_x=pow_x;   
	newNode->pow_y=pow_y;   
	newNode->pow_z=pow_z; 
	newNode->next=NULL;
	cur=poly;
	   while(cur->next!=poly)
   {
      cur=cur->next;
   }
   cur->next=newNode;
   newNode->next=poly;
   return poly;
}  
void display(polyptr poly)
{
   if(poly->next==poly)
   {
      printf("polynomial is empty\n");
      return;
   }
   polyptr cur=poly->next;
   do
   {
      printf("%dx^%dy^%dz^%d",cur->coef,cur->pow_x,cur->pow_y,cur->pow_z);
      cur=cur->next;
      if(cur!=poly)
      {
         printf("+");
      }
   }while(cur!=poly);
}
int evaluate(polyptr poly,int x,int y,int z)
{
   int result=0;
   if(poly->next==poly)
   {
      return result;
   }
   polyptr cur=poly->next;
   do
   {
      int val=cur->coef*pow(x,cur->pow_x)*pow(y,cur->pow_y)*pow(z,cur->pow_z);
      result=result+val;
      cur=cur->next;
   }
   while(cur!=poly);
   return result;
}
bool matchterm(polyptr p1,polyptr p2)
{
   bool bmatches=true;
   if(p1->pow_x!=p2->pow_x)
   bmatches=false;
   if(p1->pow_y!=p2->pow_y)
   bmatches=false;
   if(p1->pow_z!=p2->pow_z)
   bmatches=false;
   return bmatches;
}  
polyptr addpoly(polyptr poly1,polyptr poly2,polyptr polysum)
{
   polyptr cur1=poly1->next;
   polyptr cur2=poly2->next;
   do
   {
      polysum=insertterm(polysum,cur1->coef,cur1->pow_x,cur1->pow_y,cur1->pow_z);
      cur1=cur1->next;
}while(cur1!=poly1);
do 
{
   cur1=polysum->next;
   bool matchfound=false;
   do
   {
      if(matchterm(cur1,cur2))
      {
        cur1->coef+=cur2->coef;
        matchfound=true;
        break;
       }
       cur1=cur1->next;
   }while(cur1!=polysum);
   if(!matchfound)
   {
   	polysum=insertterm(polysum,cur2->coef,cur2->pow_x,cur2->pow_y,cur2->pow_z);
   }
   cur2=cur2->next;
}while(cur2!=poly2);
return polysum;
}
int main()
{
	polyptr poly1=(polyptr)malloc(sizeof(struct node));   
	poly1->next=poly1;
        polyptr poly2=(polyptr)malloc(sizeof(struct node));   
        poly2->next=poly2;
        polyptr polysum=(polyptr)malloc(sizeof(struct node));   
        polysum->next=polysum;
        poly1=insertterm(poly1,6,2,2,1);
        poly1=insertterm(poly1,-4,0,1,5); 
        poly1=insertterm(poly1,3,3,1,1);      
        poly1=insertterm(poly1,2,1,5,1);
        poly1=insertterm(poly1,-2,1,1,3);
        printf("poly1(x,y,z)=");
        display(poly1);
        
        poly2=insertterm(poly2,1,1,1,1);
        poly2=insertterm(poly2,4,3,1,1);  
        printf("poly2(x,y,z)=");
        display(poly2);
        
        polysum=addpoly(poly1,poly2,polysum);
        printf("polysum(x,y,z)=");
        display(polysum);
        
        int x=1,y=1,z=1;
        int ires=evaluate(polysum,x,y,z);
        printf("\nresult of polysum=%d\n",ires);
        return 0;
}


        

