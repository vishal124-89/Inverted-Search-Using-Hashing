#include "header.h"

int search_word(char *word,m_node **arr)
{
    /* Definition here */
    int index;
    if((isalpha(word[0]) == 0))
	index=26;
    else
	index=tolower(word[0]) - 97;


    m_node *temp = arr[index];
    while( temp != NULL )
    {
	if(strcmp(temp->word,word)==0)
	{
	    printf("\nword \"%s\" is present in %d file/s\n",word,temp->filecount);
	    s_node *sub_temp = temp->sub_link;
	    while( sub_temp != NULL )
	    {
		printf("In file %-10s%-2d time/s\n",sub_temp->filename,sub_temp->word_count);
		sub_temp = sub_temp ->sub_link;
	    }
	    printf("\n");
	    return SUCCESS;

	}
	temp = temp->main_link;
    }
    printf("NO such word Present\n");
    return SUCCESS;
}


