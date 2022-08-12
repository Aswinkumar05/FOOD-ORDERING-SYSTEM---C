#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <time.h>
 
#include <ctype.h>
#include <stdlib.h>
 
struct client
{
char username[20];
char password[20];
char email[20];
int  age;
char phone[10];
};
 
struct hotel
{
char hotel_name[15];
char food_name[3][15];
int  cost[3];
};
 
 
void sign();     
void login();
int  task2(char[]);
void manager();
void food_search();
void hotel_search();
 
int main ()
{
printf("\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t############              Food Ordering System in C            ############");
    printf("\n\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t---------------------------------------------------------------------------\n");
  int choice,choice2,run=1;
  printf("\nEnter\n \n1 --- Customer \n\n 2 --- Manager : ");
  scanf("%d",&choice);
  if(choice==2)
     manager();
  if(choice==1) 
  {
     printf("enter\n 1 --- Login \n 2 --- Sign up : ");   
     scanf("%d",&choice2);
     if(choice2!=1)
   sign();
 else
   login();
while(run)
 { 
   printf(" 1 - Search by food\n 2 - Search by hotel : ");
   scanf("%d",&choice2);
    if(choice2==1)
       food_search();
    else if(choice2==2)
       hotel_search();
        else printf("Invalid option");   
   printf("\n\nEnter 0 to exit \n 1 to continue :");
   scanf("%d",&run);
     }
   }
   printf("\n\n");
   return 0;
}
 
/*********************************************************************************************
********************************************************************************************/
 
void sign()
{
  struct client me;           
  FILE *f;
  int loop,run=1;
  
  f=fopen("client_info.txt","w");  
while(run)
{
 printf("\nEnter the username :\n");       
 scanf("%s",me.username);
 if(strlen(me.username)>=8)              
   for(loop=0;loop<strlen(me.username);loop++)
          {
          	if(isalpha(me.username[loop]))   
          	  run =0;
          	else
          	  {
          	  	printf("%c is not a character ",me.username[loop]);
          	  	run =1;                      
          	  	break;
  }
          }
     else
       printf("!!User name should be above 8 char ");
}
 
run =1;
while(run) 
{
printf("\nEnter the age above 0 : ");  
scanf("%d",&me.age);    
if(me.age>0)            
   run =0;	             
} 
 
run=1;
while(run)
{
printf("\nEnter the email id : ");   
scanf("%s",me.email);                
if(strstr(me.email,"@gmail.com"))    
   run =0;                           
else
   {
   	printf("Email id does not contain \'@gmail.com\'");
   }
}
 
run=1;
while(run)
{
int num=0,spe=0,cap=0,small=0;
printf("\nEnter the password :");  
scanf("%s",me.password);
if(strlen(me.password)>=8&&strlen(me.password)<=12)  
  {
   for(loop=0;loop<strlen(me.password);loop++)    
          { 
            if(isupper(me.password[loop]))
              cap=1;
            else if(islower(me.password[loop]))
              small=1;
            else if(isdigit(me.password[loop]))
              num=1;
            else
              spe=1;	    
          }
       if(cap==1&&small==1&&num==1&&spe==1)	  
  run =!task2(me.password);         
       else
          {
          	printf("\nPassword should contain upper,lower,num,special char !!!\n");
    run =1;
      }
     }
  else
    printf("\nEnter password between 8 and 12 \n");
}
 
 
run=1;
while(run)
{
printf("\nEnter the phone number : ");    
    scanf("%s",me.phone);
    if(strlen(me.phone)==10)        
     run=0;                        
    else
     {
     	printf("It should contain 10 digits");
     	run=1;
 }
}
 
  fwrite(&me,sizeof(struct client),1,f);      
  fclose(f);                                  
  
  fread(&me,sizeof(struct client),1,f);
  printf("\nUsername  : %s",me.username);
  printf("\nAge : %d",me.age);               
  printf("\nEmail   : %s ",me.email);
  printf("\nPassword   : %s",me.password);
  printf("\nPhone number : %s\n",me.phone);
  printf("\n\tWELCOME");
  fclose(f);
}
 
void login()
{
FILE *f;
struct client me;
char tusername[20];          
char tpassword[20];
int choice;

printf("Enter the  username : ");  
scanf("%s",tusername);
printf("Enter the password : ");
scanf("%s",tpassword);

f=fopen("client_info.txt","r");    
fread(&me,sizeof(struct client),1,f);
if(!strcmp(tusername,me.username))     
 {
  if(!strcmp(tpassword,me.password))
    printf("\nYour login is valid\n WELCOME\n");
 }
if(strcmp(tusername,me.username)||strcmp(tpassword,me.password))  
    {
      printf("\nLogin is not valid !!");
      printf("\nEnter\n 1 for re-login\n 2 for sign up\n");
  scanf("%d",&choice);
  if(choice==1)
    login();                     
  if(choice==2)
    sign();
}
fclose(f);
}
 
int task2(char pass[])   
{
int loop,flag=1;
    char againpass[20];
    printf("Enter the password again :");  
    scanf("%s",againpass);
    for(loop=0;loop<strlen(pass);loop++)
       { if(pass[loop]!=againpass[loop])
           { flag =0;
     break;
   }	  
       }  
    	return(flag);
}
 
void food_search()
{
    FILE *ptr;
    char read_food[15];
    struct hotel read;
    int loop,choice,f,i,j;
    
    ptr = fopen("food_menu.txt","r");
    printf("\n\nLIST OF FOOD ITEMS\n\n");
    while(fscanf(ptr,"%s",read_food)!=EOF)
        {
    	printf("%s",read_food);
    	printf("\n");
    }	    
    fclose(ptr);
 
char tar_food[15];
int pay[5],no_items,flag=0,k=0,z[10],q=0,p;
int selected_cost[5];
int count=0;
printf("\nEnter  the number of items you want to order : ");
scanf("%d",&f);
for( i = 0; i < f; i++)
{
ptr=fopen("hotel_info.txt","r");
printf("\nEnter the food you want : ");
scanf("%s",tar_food);
while(fread(&read,sizeof(struct hotel),1,ptr))
      {
    	 for(loop=0;loop<3;loop++)
            {
              if(!strcmp(tar_food,read.food_name[loop]))
    {
      printf("%s  - %d\n",read.hotel_name,read.cost[loop]);
      selected_cost[count]=read.cost[loop];
  count+=1;
}	
            }
  }
fclose(ptr);
  
printf("\nEnter  your amount  : ");
 
scanf("%d",&p);
for(loop=0;loop<5;loop++)
    {
      if(p==selected_cost[loop])
  {
  	printf("Enter the no of items");
  	scanf("%d",&z[i]);
  	pay[i]=z[i]*p;
  	printf("\n\nFood -   %s",tar_food);
  	printf("\nNo_items -   %d",z[i]);
  	flag=1;
  	break;
  }
    } }
    for ( j = 0; j < f; j++)
    {
         k += pay[j];
         q += z[j];
 
    }
   printf("\n******************************BILL*********************************");
    printf("\n Total items orderd are-%d",q);
  printf("\nTotal bill  -   %d",k);
     printf("\n*****************************************************************");
if(flag==0)
   printf("\nYou entered wrong");
   
 
}
 
void hotel_search()
{
    FILE *ptr;
    struct hotel read;
    int choice,no_items,bill[10],bill1=0,n,m[5],m1=0,i;
    char tar_hotel[15];
  ptr=fopen("hotel_info.txt","r");
  printf("\n\tHOTELS\n");
  while(fread(&read,sizeof(struct hotel),1,ptr))
      {
    	 printf("%s\n",read.hotel_name);
  }
  fclose(ptr);
  ptr=fopen("hotel_info.txt","r");	  
  printf("\n\nType the name of hotel : ");	  
  scanf("%s",tar_hotel);
  printf("\n");
  while(fread(&read,sizeof(struct hotel),1,ptr))
       {
 
    	 if(!strcmp(tar_hotel,read.hotel_name))
    	   {
    	   	 printf("\n1)%s -  %d",read.food_name[0],read.cost[0]);
    	   	 printf("\n2)%s -  %d",read.food_name[1],read.cost[1]);
    	   	 printf("\n3)%s -  %d",read.food_name[2],read.cost[2]);
             printf("\nNo. of items you want to order ?\t");   
             scanf("%d",&n);
             for( i=0;i<n;i++){   
    	   	 printf("\n\nEnter your choice : ");
    	   	 scanf("%d",&choice);
    	   	 printf("\nEnter the no_items : ");
    	   	 scanf("%d",&m[i]);
    	   	 bill[i]=m[i]*read.cost[choice-1];
    	   	 
    	   	 printf("\nFood   - %s",read.food_name[choice-1]);
    	   	 }
             for ( i = 0; i < n; i++)
             {
                m1 += m[i]; 
 
                bill1 += bill[i];
             }
                printf("\n******************************BILL*********************************");
             printf("\n\nHotel  - %s",read.hotel_name);
             printf("\nNo_items  - %d",m1);
    	   	 printf("\nTotal bill  -  %d",bill1);
    	   	    printf("\n*******************************************************************");
    	   	 break;
   } 
  } 
fclose(ptr);		
}
 
void manager()
{
  	
  FILE *ptr,*ptr2;
  struct hotel *h;
  int loop,loop2,loop3,no_of_hotel,no_of_food;	
  int choice,run=1;
  char password[15],admin_ID[15]; 
                                      
while(run)
    {
  	printf("\nEnter the username : ");
  	scanf("%s",admin_ID);
  	printf("Enter the password : ");
  	scanf("%s",password);
  	if(!strcmp(password,"keyword")&&!strcmp(admin_ID,"1234"))
  	   {
 printf("\nVerified\n\t WELCOME TO ADMIN PANEL\n");
 run=0;
   }
  	else 
  	  printf("\n!!Incorrect  password/username");
    }
  
  
  h=(struct hotel*)malloc(10*sizeof(struct hotel));
run=1;
while(run)
{
  
  printf("\n\nEnter 1 for add hotel");
  printf("\nEnter 2 for update : ");
  printf("\nEnter 3 for display the menu :");
  printf("\nEnter 4 for delete : \n");
  
  scanf("%d",&choice);
  if(choice==1)
    {
     printf("Enter the number of hotels : ");
 scanf("%d",&no_of_hotel);	
     ptr = fopen("hotel_info.txt","a");
     for(loop=0;loop<no_of_hotel;loop++)
        {
      	 printf("\nEnter the name of hotel : ");
      	 scanf("%s",h[loop].hotel_name);
      	 for(loop2=0;loop2<3;loop2++)
            {
           	 printf("Enter the food %d name : ",loop2+1);
           	 scanf("%s",h[loop].food_name[loop2]);
           	 printf("Enter the cost : ");
           	 scanf("%d",&h[loop].cost[loop2]);	
            }
        fwrite(&h[loop],sizeof(struct hotel),1,ptr);
        }
    }
  int add;
 
 
  
  
  if(choice==2)
    {
     char target_hotel[20];
     int choice;
     struct hotel read;
     printf("eneter the target hotel : ");
     scanf("%s",target_hotel);
  	 ptr = fopen("hotel_info.txt","r");
  	 ptr2=fopen("temp_file.txt","w");
     while(fread(&read,sizeof(struct hotel),1,ptr))
     {
    	if(!strcmp(target_hotel,read.hotel_name))
    	  {
    	  	printf("\nfood : %s\t %s\t%s",read.food_name[0],read.food_name[1],read.food_name[2]);
    	  	printf("\ncost : %d  %d  %d",read.cost[0],read.cost[1],read.cost[2]);
    	  	printf("\n\nselect your option : ");
    	  	printf("1)hotel name change\t2)food change");
    	  	scanf("%d",&choice);
    	  	switch(choice)
    	  	    {
    	  	      case 1: printf("enter the new name :");
    	  	              scanf("%s",read.hotel_name);
    	  	              break;
    	  	      case 2: for(loop=0;loop<3;loop++)
                             {
                             	printf("enter the food name %d : ",loop+1);
                             	scanf("%s",read.food_name[loop]);
                             	printf("enter the cost : ");
                             	scanf("%d",&read.cost[loop]);
                             	printf("\n");
                             }	
                            break;
}
  }
fwrite(&read,sizeof(struct hotel),1,ptr2); 
 }
  	 fclose(ptr);
  	 fclose(ptr2);
  	 
  	 ptr2=fopen("temp_file.txt","r");
  	 ptr = fopen("hotel_info.txt","w");
  	 
  	 while(fread(&read,sizeof(struct hotel),1,ptr2))
  	     fwrite(&read,sizeof(struct hotel),1,ptr);
  	 
  	 fclose(ptr);
  	 fclose(ptr2);
  	 
    }

  if(choice==3)
    {
    	ptr = fopen("hotel_info.txt","r");
        printf("\n\nlist of hotels\n\n");
        struct hotel read;
        
        while(fread(&read,sizeof(struct hotel),1,ptr))
        {
    	printf("hotel name : %s",read.hotel_name);
    	printf("\nfood available : %s  %s  %s",read.food_name[0],read.food_name[1],read.food_name[2]);
    	printf("\nfoos cost :%d  %d  %d",read.cost[0],read.cost[1],read.cost[2]);
    	printf("\n\n");
    }
fclose(ptr);
}
if(choice==4)
   {
 char target_hotel[20];
     int choice;
     struct hotel read;
     printf("Enter the target hotel : ");
     scanf("%s",target_hotel);
  	 ptr = fopen("hotel_info.txt","r");
  	 ptr2=fopen("temp_file.txt","w");
     while(fread(&read,sizeof(struct hotel),1,ptr))
     {
    	if(strcmp(target_hotel,read.hotel_name))
    	  {
    	  	fwrite(&read,sizeof(struct hotel),1,ptr2);		
  }
 
 }
 
  	 fclose(ptr);
  	 fclose(ptr2);
  	 
  	 ptr2=fopen("temp_file.txt","r");
  	 ptr = fopen("hotel_info.txt","w");
  	 
  	 while(fread(&read,sizeof(struct hotel),1,ptr2))
  	     fwrite(&read,sizeof(struct hotel),1,ptr);
  	 
  	 fclose(ptr);
  	 fclose(ptr2);
   }
printf("\nenter 1 to continue 0 to exit : ");
scanf("%d",&run);
} 
}

