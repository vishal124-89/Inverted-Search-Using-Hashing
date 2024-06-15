#include<string.h>
#include<ctype.h>
#include "header.h"

void create_database(file_list *head,m_node **arr)
{
	/* Definition here */
	while(head != NULL )
	{
		FILE *fptr = fopen(head->filename,"r");
		if ( fptr == NULL )
		{
			printf("Could not open %s\n",head->filename);
		}
		char word[30];
		while(fscanf(fptr,"%s",word) != EOF)
		{
			int index;

			if(isalpha(word[0]) == 0)
				index = 26;
			else
				index = tolower(word[0]) - 97;


			if(arr[index] == NULL )
			{
				//printf("1\n");
				m_node *main = malloc(sizeof(m_node));                //creating of m_node
				strcpy(main->word,word);
				main->filecount = 1;
				main->main_link = NULL;

				s_node *sub = malloc(sizeof(s_node));                     //creating of s_node
				strcpy(sub->filename,head->filename);
				sub->word_count = 1;
				sub->sub_link = NULL;


				main->sub_link=sub;                                                     //linking of sub to the main node
				arr[index]=main;                                                     //linking of m_node to the index
			}
			else
			{

				m_node *temp = arr[index];
				m_node *prev = arr[index];
				if(check_word_present(&temp,&prev,word) == SUCCESS)
				{
					s_node *sub_temp = temp->sub_link;
					s_node *sub_prev = temp->sub_link;
					if(check_filename_same(&sub_temp,&sub_prev,head->filename)==SUCCESS)//FILE name matching increment count
					{

						sub_temp->word_count += 1;
					
					}
					else
					{
						s_node *sub = malloc(sizeof(s_node));
						strcpy(sub->filename,head->filename);
						sub->word_count = 1;
						sub->sub_link=NULL;
						sub_prev->sub_link=sub;
						temp->filecount += 1;
					}
				}
				else
				{
					m_node *main = malloc(sizeof(m_node));
					strcpy(main->word,word);
					main->filecount = 1;
					main->main_link = NULL;

					s_node *sub = malloc(sizeof(s_node));
					strcpy(sub->filename,head->filename);
					sub->word_count = 1;
					sub->sub_link = NULL;

					main->sub_link=sub;
					prev->main_link = main;
				}
			}
		}
		fclose(fptr);

		head = head->link;
	}
}



int check_filename_same(s_node **temp,s_node **prev,char *filename)
{
	while( *temp != NULL )
	{
		if ( strcmp((*temp)->filename,filename) == 0)
			return SUCCESS;
		*prev = *temp;
		(*temp)=(*temp)->sub_link;
	}
	return FAILURE;
}


int check_word_present(m_node **temp,m_node **prev, char *word)
{
	while((*temp) != NULL )
	{
		if(strcmp((*temp)->word,word) == 0)
			return SUCCESS;
		*prev = *temp;
		*temp = (*temp)->main_link;
	}
	return FAILURE;
}



