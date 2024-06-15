#include "header.h"

int save_database(char *fname,m_node **arr)
{
    FILE *fptr=fopen(fname,"w");
    if(fptr == NULL )
    {
	printf("Could not open %s\n",fname);
	return FAILURE;
    }
    for( int i=0; i<27; i++ )
    {
	if (arr[i] != NULL )
	{
	    m_node *temp = arr[i];
	    while( temp != NULL )
	    {
		fprintf(fptr,"#%d;",i);
		s_node *sub_temp = temp->sub_link;
		fprintf(fptr,"%s;%d;",temp->word,temp->filecount);

		while(sub_temp!= NULL )
		{
		    fprintf(fptr,"%s;%d;",sub_temp->filename,sub_temp->word_count);
		    sub_temp = sub_temp->sub_link;
		}
		fprintf(fptr,"#\n");
		temp=temp->main_link;
	    }
	}
    }
    fclose(fptr);
}




