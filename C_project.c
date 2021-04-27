//intendation, new additions - should not add the duplicate data, sort the contacts, edit function

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact{
	
	char names[30];
	char phone[30];
	char whatsup[30];
	char email[30];
	int fav;
}cnt[100],temp;

char empty[100]="";
void adding();
void deleting();
void searching();
void display();
void sort();
void editing();
void view_favorites();
int contact_check(char *, char *);
int validate_name(char *);
int validdate_pho(char *);
int validate_whatup(char *);
int validate_email(char *);
int i = 0,no_of_fav= 0;
int main()
{
	
	char name[40],search[40];
	int choice,j=0;
	
	printf("\t\t\tWelcome to Contact Management System\n");
	printf("\t\t\t====================================\n");
	printf("\t\t\t1.Add Contact\n\t\t\t2.View Contact\n\t\t\t3.Delete Contact\n\t\t\t4.Search Contact\n\t\t\t5.Edit Contact\n\t\t\t6.View Favourites\n\t\t\t7.Exit\n");
	
	
	while(1)
	{
		
		printf("Enter the choice:");
    	scanf("%d",&choice);
	switch(choice)
	{
	
		case 1: 
		{
			adding();
			i++;
			break;
		}
		case 2:
			{
				display();
				break;
				
			}
		case 3:
			{
				
				deleting();
				break;
			}
		case 4:
			{
				
				searching();
				break;
			}
		case 5:
			{
				editing();
			    break;
			}
		case 6:
			{
				view_favorites();
				break;
			}
		case 7:
			{
				exit(1);
			}
		default:
			{
				printf("Please enter a valid operation!!");
				break;
			}
	}
}
	
}

//Add contact
void adding()
{
	int n = 1,p = 1,w = 1,e = 1,check = 1;
	name:
		printf("Enter your contact name:");
		scanf("%s",cnt[i].names);
		
		
		n=validate_name(cnt[i].names);
		if(n == 0)
		{
			printf("Please enter a valid name!!\n");
			goto name;
		}
		else
		{
			goto phone;
		}
	phone:
			printf("Enter your phone number:");
			scanf("%s",cnt[i].phone);
			p = validate_pho(cnt[i].phone);
			if(p == 0)
			{
				printf("Please enter a valid phone number!!\n");
				goto phone;
			}
			else
			{
				check = contact_check(cnt[i].names,cnt[i].phone);
				if(check == 0)
				{
					printf("Contact already exists!!\n");
					goto name;
				}
				else
				{
					goto whatsup;
				}
			}
	whatsup:
			printf("Enter your whatsapp number:");
			scanf("%s",cnt[i].whatsup);
			w = validate_whatsup(cnt[i].whatsup);
			if(w == 0)
			{
				printf("Please enter a valid whatsup number!!\n");
				goto whatsup;
			}
			else
			{
				goto email;
			}
	email:
			printf("Enter your email-id:");
			scanf("%s",cnt[i].email);
			e = validate_email(cnt[i].email);
			if(e == 0)
			{
				printf("Please enter a valid email-id!!\n");
				goto email;
			}
			
	printf("Do you want to add to favorite list?(0/1):");
	scanf("%d",&cnt[i].fav);
			
		printf("Contact inserted successfully!!\n");
			
}
//View contact
void display()
{
	sort();
	int j;
	printf("\t\t\tThe List of Contacts\n");
	printf("\t\t\t====================\n");
			for(j=0;j<i;j++)
				{
					if(strcmp(cnt[j].names,empty))
				{
				
					printf("Name:%s\n",cnt[j].names);
					printf("Phone:%s\n",cnt[j].phone);
					printf("Whatsapp number:%s\n",cnt[j].whatsup);
					printf("Email-id:%s\n",cnt[j].email);
				}
				printf("------------------------------\n");
}
printf("\n");
}

//Deleting Contact
void deleting()
{
	char name[30];
	int j,flag = 0;
	printf("Enter a contact name to delete:");
	scanf("%s",name);
	
	for(j=0;j<i;j++)
	{
		if(strcmp(cnt[j].names, name) == 0)
		{
			strcpy(cnt[j].names,empty);
			strcpy(cnt[j].phone,empty);
			strcpy(cnt[j].whatsup,empty);
			strcpy(cnt[j].email,empty);
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		printf("Contact not found!!\n");
	else
		printf("Contact deleted successfully!!\n");
	
}
//Searching for a contact
void searching()
{
	char search[30];
	printf("Enter the contact to view:");
	scanf("%s",search);
	int j,flag =0;
	
	for(j=0;j<i;j++)
	{
		if(strcmp(cnt[j].names,search) == 0)
		{
			flag = 1;
			printf("Name:%s\n",cnt[j].names);
			printf("Phone:%s\n",cnt[j].phone);
			printf("Whatsapp number:%s\n",cnt[j].whatsup);
			printf("Email-id:%s\n",cnt[j].email);
		}
		
	}
	if(flag == 0)
	{
		printf("Contact not Found!!\n");
	}

}

int contact_check(char *names, char *phone)
{
	int j;
	if(i > 2)
	{
	
	for(j = 0;j<i;j++)
	{
		if(!((strcmp(cnt[j].names,names)) && (strcmp(cnt[j].phone,phone))))
		{
			return 0;
		}
		
	}
}
}

void sort()
{
		int k,j;
	for(k = 1;k<i;k++)
	{
		for(j = 0;j< i - k;j++)
		{
			if(strcmp(cnt[j].names, cnt[j+1].names) > 0)
			{
				temp = cnt[j];
				cnt[j] = cnt[j+1];
				cnt[j+1] = temp;
			}
		}
	}
}


void view_favorites()
{
	int j;
	printf("\t\t\tThe List of Favourite Contacts\n");
	printf("\t\t\t====================\n");
			for(j=0;j<i;j++)
				{
	
				if(cnt[j].fav == 1)
				{
				
				    printf("Name:%s\n",cnt[j].names);
					printf("Phone:%s\n",cnt[j].phone);
					printf("Whatsapp number:%s\n",cnt[j].whatsup);
					printf("Email-id:%s\n",cnt[j].email);
			 }
				printf("------------------------------\n");
}
printf("\n");
}

void editing()
{
	int choice,j,flag = 0,valid_n,valid_phone,valid_whatsup,valid_email_id,ind;
	char name[30],new_name[30],new_phone[10],new_whatsup[10],new_email[30];
	
	
	printf("Enter a contact name to edit:");
	scanf("%s",name);
	
	for(j=0;j<i;j++)
	{
		if(strcmp(cnt[j].names,name) == 0)
		{
			flag = 1;
			ind = j;
			break;
		}
	}
	if(flag == 1)
	{
			printf("\t\t\t1.Edit name\n\t\t\t2.Edit phone number\n\t\t\t3.Edit whatsup number\n\t\t\t4.Edit email\n\t\t\t5.Home\n");
			while(1)
			{
			 printf("Enter a choice:");
			 scanf("%d",&choice);
			 switch(choice)
			{
				case 1:
				{
				new_name:
					printf("Enter a new name:");
					scanf("%s",new_name);
					strcpy(cnt[ind].names,new_name);
					printf("%s",cnt[ind].names);
					valid_n = validate_name(cnt[ind].names);
					if(valid_n == 0)
					{
						printf("Please enter a valid name!!\n");
						goto new_name;
						
					}
					else
					{
						break;
					}
				}
				case 2:
					{
					 new_phone:
						printf("Enter a new phone number:");
						scanf("%s",new_phone);
						strcpy(cnt[j].phone,new_phone);
						valid_phone = validate_pho(cnt[j].phone);
						if(valid_phone == 0)
					{
						printf("Please enter a valid phone number!!");
						goto new_phone;
						
					}
					else
					{
						break;
					}
				}
				case 3:
					{
					 new_whatsup:
						printf("Enter a new whatsup number:");
						scanf("%s",new_whatsup);
						strcpy(cnt[j].whatsup,new_whatsup);
						valid_whatsup = validate_whatsup(cnt[j].whatsup);
						if(valid_whatsup == 0)
					{
						printf("Please enter a valid whatsup number!!");
						goto new_whatsup;
						
					}
					else
					{
						break;
					}
				}
					case 4:
					{
					 new_email:
						printf("Enter a new email id:");
						scanf("%s",new_email);
						strcpy(cnt[j].email,new_email);
						valid_email_id = validate_email(cnt[j].email);
						if(valid_email_id == 0)
					{
						printf("Please enter a valid email id!!");
						goto new_email;
						
					}
					else
					{
						break;
					}
				}
				case 5:
					{
						main();
						break;
					}
	      }
	      
		}
	}
	else
	{
		printf("Contact not found!!\n");
	}
	
}
int validate_name(char *names)
{
	int j;
	for(j = 0;names[j]!='\0';j++)
	{
		if(!((names[j] >= 'a' && names[j]!= 'z') || (names[j] >= 'A' && names[j] <= 'Z') ))
		{
			return 0;
		}
	
	else
	{
		return 1;
	}
}
}
//Validating phone_number
int validate_pho(char * phone)
{
	int j,count =0;
		if(strlen(cnt[i].phone) != 10)
	{
		return 0;
	}
	else if(strlen(cnt[i].phone) == 10)
		{
			for(j=0;cnt[i].phone[j]!='\0';j++)
			{
				if(cnt[i].phone[j] == '0')
				{
					count++;
				}
				else if(cnt[i].phone[j] >= 'a' && cnt[i].phone[j] <= 'z' || cnt[i].phone[j] >= 'A' && cnt[i].phone[j] <= 'Z')
				{
					return 0;
				}
			}
			if(count == strlen(cnt[i].phone))
				return 0;
			else
				return 1;
		}
	
}
//Validating whatsup_number
int validate_whatsup(char * whatsup)
{
	int j,count =0;
	if(strlen(cnt[i].whatsup) != 10)
	{
		return 0;
	}
    else if(strlen(cnt[i].whatsup) == 10)
		{
			for(j=0;cnt[i].whatsup[j]!='\0';j++)
			{
				if(cnt[i].whatsup[j] == '0')
				{
					count++;
				}
				else if(cnt[i].whatsup[j] >= 'a' && cnt[i].whatsup[j] <= 'z' || cnt[i].whatsup[j] >= 'A' && cnt[i].whatsup[j] <= 'Z')
				{
					return 0;
				}
			}
			if(count == strlen(cnt[i].whatsup))
				return 0;
			else
				return 1;
		}
		
}
//Validating email
int validate_email(char * email)
{
	int j,count=0,count1 = 0;
	
	if(cnt[i].email[0] == '@')
	{
		return 0;
	}
	else
	{
		for(j = 0;cnt[i].email[j]!='\0';j++)
		{
			if(cnt[i].email[j] == '@')
			{
				count++;
			}
			if(cnt[i].email[j] == '.')
			{
				count1++;
			}
			
		}
		
		if(count > 2 && count1 == 0)
		{
			return 0;
		}
		else
		{
			if(!(strlen(cnt[i].email)>=5))
			{
				return 0;
			}
		}
	}
}


