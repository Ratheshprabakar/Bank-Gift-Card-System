//Virtual Bank Gift Card Management System
#include<stdio.h>
void create();
void login();
int main()
{
	int choice;
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
				login();
				break;
			case 3:
				exit(1);
			default:
				printf("\nPlease Enter valid choice\n");
		}
	}
	
}
