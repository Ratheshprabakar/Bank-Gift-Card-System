//Virtual Bank Gift Card Management System
#include<stdio.h>
void acc_create();
void card_create();
void card_topup();
void card_close();
int choice,i=1,j;
struct acccount_details
{
	char name[100];
	int age;
	int balance;
}acc[100];
struct card_details
{
	int id,pin;
	int amount;
	int status;
}card[100];
char temp_name[100];
int temp_age;
int temp_balance;
int card_no=1;
int main()
{

	while(1)
	{
		printf("\n\nWelcome to Bank Gift Card System\n\n");
		printf("1) Account Creation\n2)Gift Card\n3)Exit\nPlease Enter Your Choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				acc_create();
				break;
			case 2:
				printf("\n1)Create gift card\n2)Top-Up gift card\n3)Close gift card\n4)Back\nPlease Enter your choice\t");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						card_create();
						break;
					case 2:
						card_topup();
						break;
					case 3:
						card_close();
						break;
					case 4:
						main();
						break;
					default:
						printf("\nPlease Enter valid choice\n");		
				}
				break;
			case 3:
				exit(1);
			default:
				printf("\nPlease Enter valid choice\n");
		}
	}
	
}
void acc_create()
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
void card_create()
{
	int id;
	printf("Enter Your CustID\t");
	scanf("%d",&id);
	if(id<i && id!=0)
	{
		printf("\n\nYour Acount contains %d balance",acc[id].balance);
		printf("\n\nEnter the Amount which you want to buy as gift card\t");
		scanf("%d",&temp_balance);
		if(temp_balance<=acc[id].balance)
		{
			card[card_no].id=id;
			printf("Enter the PIN\t");
			scanf("%d",&card[card_no].pin);
			card[card_no].amount=temp_balance;
			acc[id].balance-=temp_balance;
			temp_balance=0;			
			card[card_no].status=1;
			printf("Your Gift Card is successfully purchased\nCardNo\tAmount\n%d\t%d",card_no,card[card_no].amount);
			card_no++;
		}
		else
		{
			printf("\n\nSorry, Your account doesn't contain sufficient balance to buy the card\n\n");
			main();
		}
		
	}
	else
	{
		printf("\n\nSorry Your CustID is not found, Please create an account!!\n\n");	
	}
}
void card_topup()
{
	int id,temp_card,temp_pass,k,temp_amount;
	printf("Enter Your CustID\t");
	scanf("%d",&id);
	if(id<i && id!=0)
	{
		printf("\nYour Gift Cards are\nCard No.\tAmount\n");
		for(k=1;k<card_no;k++)
		{
			if(card[k].id==id && card[k].status==1)
			{
				printf("%d\t%d\n",k,card[k].amount);
			}
		}
		printf("\nWhich Card You wish to topup\nEnter the card No\t");
		scanf("%d",&temp_card);
		printf("\nEnter the password\t");
		scanf("%d",&temp_pass);
		if(card[temp_card].pin==temp_pass && card[temp_card].status==1)
		{
			printf("Enter the amount you which to topup\t");
			scanf("%d",&temp_amount);
			if(temp_amount<=acc[id].balance)
			{
				card[temp_card].amount+=temp_amount;
				acc[id].balance-=temp_amount;
				printf("\nThank You! Your topup is successful, Amount credited to your gift card\n");			
			}
			else
			{
				printf("\n\nSorry, Your account doesn't contain sufficient balance to topup your card\n\n");
				main();
			}			
		}
		else
		{
			printf("\nInvalid PIN or Card\n");
			main();
		}
	}
	else
	{
		printf("\n\nSorry Your CustID is not found, Please create an account!!\n\n");	
	}
}
void card_close()
{
	int id,temp_card,temp_pass,k;
	printf("Enter Your CustID\t");
	scanf("%d",&id);
	if(id<i && id!=0)
	{
		printf("\nYour Gift Cards are\nCard No.\tAmount\n");
		for(k=1;k<card_no;k++)
		{
			if(card[k].id==id && card[k].status==1)
			{
				printf("%d\t%d\n",k,card[k].amount);
			}
		}
		printf("\nWhich Card You wish to close\nEnter the card No\t");
		scanf("%d",&temp_card);
		printf("\nEnter the password\t");
		scanf("%d",&temp_pass);	
		if(card[temp_card].pin==temp_pass)
		{
			acc[id].balance+=card[temp_card].amount;
			card[temp_card].status=0;
			printf("\nThank You! Your CardID %d is successful closed and amount %d credited to your bank account\n",temp_card,card[temp_card].amount);
			card[temp_card].amount=-1;			
		}
		else
		{
			printf("\nInvalid PIN\n");
			main();
		}
	}
	else
	{
		printf("\n\nSorry Your CustID is not found, Please create an account!!\n\n");	
	}
}
