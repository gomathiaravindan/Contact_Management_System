#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct contact *cont;
struct contact{
	
	char names[30];
	char phone[30];
	char whatsup[30];
	char email[30];
}cnt[100];
void add_cnt(int);
void delete_cnt(cont, char*,int);
void search_cnt(cont, char*,int);
void view_cnt(cont,int);
int valid_name(cont,int);
int valid_pho(cont,int);
int valid_whs(cont,int);
int valid_email(cont,int);
int i = 0;
int main()
{
	
	char name[40],search[40];
	int x,j=0;
	
	printf("\t\t\tWelcome to Contact Management System\n");
	printf("\t\t\t====================================\n");
	printf("\t\t\t1.Add Contact\n");
	printf("\t\t\t2.View Contact\n");
	printf("\t\t\t3.Delete Contact\n");
	printf("\t\t\t4.Search Contact\n");
	printf("\t\t\t5.Exit\n");
	
	
	while(1)
	{
		
		printf("Enter the choice:");
    	scanf("%d",&x);
	switch(x)
	{
	
		case 1: 
		{
			add_cnt(i);
			i++;
			break;
		}
		case 2:
			{
					view_cnt(cnt,i);
					break;
				
			}
		case 3:
			{
				printf("Enter the name of contact to delete:");
				scanf("%s",name);
				delete_cnt(cnt,name,i);
				break;
			}
		case 4:
			{
				printf("Enter the contact to view:");
				scanf("%s",search);
				search_cnt(cnt,search,i);
				break;
			}
		case 5:
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
void add_cnt(int i)
{
	int n,p,w,e;
	name:
		printf("Enter your contact name:");
		scanf("%s",cnt[i].names);
		
		n=valid_name(cnt,i);
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
			p = valid_pho(cnt,i);
			if(p == 0)
			{
				printf("Please enter a valid phone number!!\n");
				goto phone;
			}
			else
			{
				goto whatsup;
			}
	whatsup:
			printf("Enter your whatsapp number:");
			scanf("%s",cnt[i].whatsup);
			w = valid_whs(cnt,i);
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
			e = valid_email(cnt,i);
			if(e == 0)
			{
				printf("Please enter a valid email-id!!\n");
				goto email;
			}
			
		
			
}
//View contact
void view_cnt(cont cnt,int i)
{
	int j;
	printf("\t\t\tThe List of Contacts\n");
	printf("\t\t\t====================\n");
			for(j=0;j<i;j++)
				{
					if(cnt[j].names != " " && cnt[j].phone != " " && cnt[j].whatsup!=" " && cnt[j].email!=" ")
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
//Delete a contact
void delete_cnt(cont cnt,char *s,int i)
{
	 
	char nullstr[20] = {"\0"};
	int max = i,j;
	
	strcpy(cnt[max].names,"\0");
	
	for (j = 0; j < max; j++) if (strcmp(cnt[j].names,s) == 0) break; 
	
	if (j == max) printf("Record not found!!\n"); // The record not found. 
	
	for ( ; j < max; j++) cnt[j] = cnt[j + 1]; 
	
	max--; 
	
	printf("Contact deleted successfully!!\n");
	 // Successfully deleted record. 
}
//Searching for a contact
void search_cnt(cont cnt,char *str,int i)
{
	int j,flag =0;
	
	for(j=0;j<i;j++)
	{
		if(strcmp(cnt[j].names,str) == 0)
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


/*int validate(cont cnt,int i)
{
	int j;
	for(j = 0;cnt[i].names[j]!='\0';j++)
	{
		if(!((cnt[i].names[j] >= 'a' && cnt[i].names[j]!= 'z') || (cnt[i].names[j] >= 'A' && cnt[i].names[j] <= 'Z') ))
		{
			printf("Enter a valid name!!\n");
			break;
		}
	}
	if(strlen(cnt[i].phone) == 10)
	{
		printf("Please enter a valid mobile number!!\n");
	}
	if(strlen(cnt[i].whatsup) == 0)
	{
		printf("Please enter a valid whatsup number!!\n");
	}
}*/
//Validating name
int valid_name(cont cnt,int i)
{
	int j;
	for(j = 0;cnt[i].names[j]!='\0';j++)
	{
		if(!((cnt[i].names[j] >= 'a' && cnt[i].names[j]!= 'z') || (cnt[i].names[j] >= 'A' && cnt[i].names[j] <= 'Z') ))
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
int valid_pho(cont cnt,int i)
{
		if(strlen(cnt[i].phone) != 10)
	{
		return 0;
	}
	else
		return 1;
	
}
//Validating whatsup_number
int valid_whs(cont cnt,int i)
{
	if(strlen(cnt[i].whatsup) != 10)
	{
		return 0;
	}
	else
		return 1;
}
//Validating email
int valid_email(cont cnt,int i)
{
	int j,ind;
	
	for(j=0;cnt[i].email[j]!='@';j++);
	
	ind = j;
	
	if(strcmp((cnt[i].email) + j , "@gmail.com") == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
