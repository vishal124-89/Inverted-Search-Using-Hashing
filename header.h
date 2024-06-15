#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef enum
{
	SUCCESS,
	FAILURE
} Status;

typedef struct m_node
{
	char word[30];
	int filecount;
	struct s_node *sub_link;
	struct m_node *main_link;
}m_node;

typedef struct s_node
{
	int word_count;
	char filename[30];
	struct s_node *sub_link;
}s_node;

typedef struct file_list
{
	char filename[30];
	struct file_list *link;
}file_list;

//Create
int validate(int argc,char *argv[],file_list **head);
void create_database(file_list *head,m_node **arr);
int check_filename_same(s_node **temp,s_node **prev,char *filename);
//Display
int check_word_present(m_node **temp,m_node **prev, char *word);
void display_database(file_list *head,m_node **arr);
//Search
int search_word(char *word,m_node **arr);
int save_database(char* fname,m_node **arr);
//Update
int validate_backupfile(char *);
int update_database(char *,file_list **,m_node **arr);
int insert_at_first(file_list ***head,char *str);

#endif


