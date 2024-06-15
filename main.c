/*NAME-Vishal Jadhav
  PROJECT-Inverted search
  DATE-20/03/2024*/
#include "header.h"

int main(int argc,char* argv[])
{
    file_list *head =NULL;
    file_list *uhead =NULL;
    m_node *arr[27]={NULL};
    if(argc>1)
    {
	if(validate(argc,argv,&head)==SUCCESS)
	{
	    int flag=0;										// Flag =0
	    printf("Validation Success\n");
	    int n=1;
	    while(n)
	    {
		printf("\n-------------------------------------------\nSelect your choice among following options:\n-------------------------------------------\n");
		printf("1.Create Database\n2.Display Database\n3.Search\n4.Save Database\n5.Update Database\n6.Exit\n");
		printf("\nEnter the choice :");
		int i;
		scanf("%d",&i);
		switch(i)
		{
		    case 1:

			if(flag==0)
			{
			printf("Creating Database\n");
			create_database(head,arr);
			flag=1;
			printf("Successful : Creation of DATABASE for file \n");
			}
			else
			{
			printf("Data base already updated\n");
			}
			break;
			

		    case 2:
			printf("Display\n");
			display_database(head,arr);
			printf("Displayed Database Successfully\n");
			break;

		    case 3:
			char word[30];
			printf("Searching\n");
			printf("Enter the word you want to search: ");
			scanf("%s",word);
			getchar();
			search_word(word,arr);
			break;

		    case 4:
			printf("Saving\n");
			if(flag == 1)
			{
			    printf("Enter the file name to save database : ");
			    char fname[30];
			    scanf("%s",fname);
			    getchar();
			    if((strstr(fname,".txt")) != NULL)
			    {
				save_database(fname,arr);
				printf(" Database saved successfully\n");
			    }
			    else
			    {
				printf("ERROR : %s is NOT a .txt file\n",fname);
			    }
			}
			else
			{
			    printf("Database is empty please create or update database before saving database\n");
			}
			break;

		    case 5:
			printf("Updating in Process\n");
			if(flag == 0)
			{
			    printf("Enter the file to update the data: ");
			    char str[30];
			    scanf("%s",str);
			    getchar();
			    if ( validate_backupfile(str) == SUCCESS )
			    {
				printf("Validation of backup file successfull\n");
				update_database(str,&uhead,arr);
				printf("Update Successfully\n");
				flag=1;
			    }
			    else printf("validation Successfull\n");
			}
			else
			{
			    printf("Error : Database is already Created\n");
			}
			break;

		    case 6:
			printf("EXIT\n");
			n=0;
			break;

		    default :
			printf("Enter proper choice ,choose between 1 to 6\n");
			break;

		}

	    }
	}
	else
	{
	    printf("Validation Failure\n");
	}
    }
    else
    {
	printf("Pass the comman line argument\n");
    }
    return 0;
}

int validate(int argc,char *argv[],file_list **head)
{
    for(int i=1;i<argc;i++)
    {
	if(strstr(argv[i],".txt"))
	{
	    //File Existing
	    FILE *fp= fopen(argv[i],"r");
	    if(fp==NULL)
	    {
		printf("ERROR : '%s' not exist\n", argv[i]);
		//continue;
	    }
	    else
	    {
		//File Empty
		fseek(fp,0,SEEK_END);
		if(ftell(fp))   //It will return 0 if file is empty 
		{
		    //File  Repeated
		    if(*head == NULL)
		    {
			file_list *new=malloc(sizeof(file_list));
			strcpy(new->filename,argv[i]);
			new->link=NULL;
			*head=new;
			printf("'%s'      :File Linked\n",argv[i]);
		    }
		    else
		    {
			file_list *temp=*head;
			file_list *prev;
			while(temp)        //loop will run till temp reaches NULL
			{
			    if(!strcmp(temp->filename,argv[i]))
			    {
				printf("'%s' is Duplicate\n",argv[i]);
				break;
			    }
			    prev=temp;
			    temp=temp->link;
			}
			if(temp==NULL)
			{
			    file_list *new=malloc(sizeof(file_list));
			    strcpy(new->filename,argv[i]);
			    new->link=NULL;
			    prev->link=new;

			    printf("'%s' :File linked\n",argv[i]);
			}
		    }

		}
		else
		{
		    printf("'%s' File is empty\n", argv[i]);
		}
	    }

	}
	else
	{
	    printf("Check the extension of '%s' it should be only .txt\n",argv[i]);
	    return FAILURE;
	}
    }
    return SUCCESS;
}


int validate_backupfile(char *str)
{
    FILE *fptr;
    if(strstr(str,".txt") != NULL)
    {
	if((fptr = fopen(str,"r")) != NULL)
	{
	    char ch1, ch2;
	    ch1 = fgetc(fptr);
	    fseek(fptr,-2,SEEK_END);
	    ch2 = fgetc(fptr);

	    if (ch1 == '#' && ch2 == '#')
	    {
		return SUCCESS;
	    }
	    else
	    {
		printf("ERROR : File is not in Correct format\n");
		return FAILURE;
	    }
	    fclose(fptr);
	}
	else
	{
	    printf("%s Does not exist\n",str);
	    return FAILURE;
	}
    }
    else
    {
	printf("%s is not a.txt file\n",str);
	return FAILURE;
    }
}



