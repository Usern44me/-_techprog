#include <stdio.h>
#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
 

struct node_s
{
	struct node_s *next;
	char slovo [10] ; 
};

typedef struct node_s node_t;

struct list_s
{
	node_t *head;
	int size;
};

typedef struct list_s list_t;

void init(list_t *l)
{
	l->head = NULL;
	l->size = 0;
}
void push(list_t *l, char *val)
{
	node_t *tmp = (node_t*)malloc(sizeof(node_t));
	int k = l -> size;
	node_t *cur = l -> head;
	node_t *cur2 = l-> head;
	int count = 0;
	int a = 0;
	if (k == 0)
	{
	for(int i = 0; i < 10; i ++)
	{
		tmp->slovo[i] = val[i];
	}
		tmp->next = l->head;
		l->head = tmp;
		l->size++;
	}
	else 
	{
		if( strcmp (l->head ->slovo , val) > 0)
		{
			tmp -> next = l -> head;
			l -> head = tmp;
			for(int i = 0; i < 10; i ++)
			{
			tmp -> slovo[i] = val[i];
			}
			l -> size++;
		}
		else
		{
			while(strcmp (cur -> slovo , val) < 0)
			{
				
				cur = cur -> next;
				count++;
				if(count >= l->size)
				{
					
					a++;
					goto stop;
				}

			}
			count--;
			while(count != 0)
			{
				cur2 = cur2 ->next;
				count--;
			}
			cur2 -> next = tmp;
			tmp -> next = cur;
			for(int i = 0; i < 10; i ++)
			{
			tmp -> slovo[i] = val[i];
			}
			l -> size++;
		}
		stop:;
		if(a != 0)
		{
			
			count--;
			while(count != 0)
			{
				cur2 = cur2 ->next;
				count--;
			}
			cur2->next = tmp;
			tmp -> next = NULL;
			for(int i = 0; i < 10; i ++)
			{
			tmp->slovo[i] = val[i];
			}
			l -> size++;	
		}
	}
}

void Rev(list_t *l, int len)
{
	int k = l->size;
	node_t *cur = l->head;
	int count = 0;
	while (count != len)
	{
		count++;
		cur = cur->next;
	}
	printf("%s\n", cur->slovo);
	Rev(l, len-1);
}

int main()
{
	const int len = 15, strings = 10;
	const char ch = '\n';
	char mass[len][strings];
	list_t* laba6;
	laba6 = (list_t*)malloc(sizeof(list_t));
	init(laba6);
	ifstream fs("file.txt", ios::in | ios::binary); 
 	for(int r = 0; r<strings; r++)
	{
		fs.getline(mass[r], len-1,ch);
		push(laba6, mass[r]);
	}
	Rev(laba6, strings - 1);
	delete mass;
	fs.close();
	return 0;
}


