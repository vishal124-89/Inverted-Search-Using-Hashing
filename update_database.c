#include "header.h"
int update_database(char *str,file_list **head,m_node **arr)
{
    FILE *fptr =fopen(str,"r");
    char arr1[300];
    char *token;

    while((fscanf(fptr,"%s",arr1)) != EOF )
    {
	token= strtok(arr1,"#;");
	int index= atoi(token);
	m_node *main=malloc(sizeof(m_node));
	main->main_link=NULL;
	token=strtok(NULL,"#;");
	strcpy(main->word,token);

	token=strtok(NULL,"#;");
	int count=atoi(token);
	main->filecount=count;

	s_node *sub_temp;
	for(int i=0;i<count; i++ )
	{
	    s_node *sub=malloc(sizeof(s_node));
	    token=strtok(NULL,"#;");
	    strcpy(sub->filename,token);
	    insert_at_first(&head,token);
	    token=strtok(NULL,"#;");
	    int num=atoi(token);
	    sub->word_count=num;

	    if (i==0)
	    {
		main->sub_link=sub;
		sub_temp=sub;
	    }
	    else
	    {
		sub_temp->sub_link=sub;
		sub_temp=sub;
	    }
	}
	m_node *temp=arr[index];
	if ( temp == NULL )
	{
	    arr[index]=main;
	}
	else
	{
	    while(temp->main_link != NULL )
	    {
		temp=temp->main_link;
	    }
	    temp->main_link=main;
	}
    }
}
int insert_at_first(file_list ***head,char *str)
{
    file_list *new=malloc(sizeof(file_list));
    strcpy(new->filename,str);
    new->link = NULL;
    if ( **head == NULL )
    {
	**head =new;
	return SUCCESS;
    }
    new->link=**head;
    **head=new;
    return SUCCESS;
}


