//Virtual Bank Gift Card Management System
#include<stdio.h>
void create();
//void login();
int choice,i=1,j;
struct acccount_details
{
char name[100];
int age;
int balance;
}acc[100];
char temp_name[100];
int temp_age;
int temp_balance;
int main()
{

	while(1)
	{
		printf("\n\nWelcome to Bank Gift Card System\n\n");
		printf("1) Account Creation\n2) Already have the account ? (Login)\n3) Exit\nPlease Enter Your Choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				//login();
				break;
			case 3:
				exit(1);
			default:
				printf("\nPlease Enter valid choice\n");
		}
	}
	
}
void create()
{
	printf("\n\nWelcome to account creation\n\n");
	printf("Enter Your Name\t");
	scanf("%s",temp_name);
	printf("Enter Your Age\t");
	scanf("%d",&temp_age);
	printf("Enter Your Initial deposit\t");
	scanf("%d",&temp_balance);
	for(j=1;j<i;j++)
	{
		if(!(strcmp(acc[j].name,temp_name)))
		{
			printf("\nAccount already existed!! Please Login\n");
			main();
			break;
		}
	}
	if(j==i)
	{
		strcpy(acc[i].name,temp_name);
		acc[i].age=temp_age;
		acc[i].balance=temp_balance;
		printf("\nThank You Your Account is created, Your CustID is %d\n",i);
		printf("\nCustID\t\tBalance\n");
		printf("%d\t\t%d",i,acc[i].balance);
		i++;	
	}
	
}
