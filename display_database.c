#include "header.h"

void display_database(file_list *head, m_node **arr)
{

    printf("%-10s%-18s%-15s%-15s%-15s\n","[INDEX]","WORD","FILECOUNT","FILENAME","WORDCOUNT");
    for ( int i=0; i<27; i++ )
    {
	if ( arr[i] != NULL )
	{
	    int index=i;
	    m_node *temp = arr[i];
	    while( temp != NULL )
	    {
		printf(" %-10d %-18s %-15d",index,temp->word,temp->filecount);
		s_node *sub_temp = temp->sub_link;
		while(sub_temp != NULL )
		{
		    printf("%-15s %-15d",sub_temp->filename,sub_temp->word_count);
		    sub_temp = sub_temp->sub_link;
		}
		temp=temp->main_link;
		printf("\n");
	    }
	}
    }
}
