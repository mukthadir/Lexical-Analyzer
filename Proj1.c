#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

struct node {
	int line;
	char tokentype[15];
	char token1[MAX_TOKEN_LENGTH];
	struct node *next;
};

void add(struct node **, int, char [], char []);
void reverse(struct node *);

int main()
{
	struct node *n;
	n = NULL;
	int type;
	int test;
	char tokentype[15];

	while(!feof(stdin))
	{
		type = getToken();
		
		while(type != EOF)
		{
			test = type;
			switch(test)
			{
				case 1: strcpy(tokentype,"IF");
					break;
				case 2: strcpy(tokentype,"WHILE");
					break;
				case 3: strcpy(tokentype,"DO");
					break;
				case 4: strcpy(tokentype,"THEN");
					break;
				case 5: strcpy(tokentype,"PRINT");
					break;
				case 6: strcpy(tokentype,"PLUS");
					break;
				case 7: strcpy(tokentype,"MINUS");
					break;
				case 8: strcpy(tokentype,"DIV");
					break;
				case 9: strcpy(tokentype,"MULT");
					break;
				case 10: strcpy(tokentype,"EQUAL");
					break;
				case 11: strcpy(tokentype,"COLON");
					break;
				case 12: strcpy(tokentype,"COMMA");
					break;
				case 13: strcpy(tokentype,"SEMICOLON");
					break;
				case 14: strcpy(tokentype,"LBRAC");
					break;
				case 15: strcpy(tokentype,"RBRAC");
					break;
				case 16: strcpy(tokentype,"LPAREN");
					break;
				case 17: strcpy(tokentype,"RPAREN");
					break;
				case 18: strcpy(tokentype,"NOTEQUAL");
					break;
				case 19: strcpy(tokentype,"GREATER");
					break;
				case 20: strcpy(tokentype,"LESS");
					break;
				case 21: strcpy(tokentype,"LTEQ");
					break;
				case 22: strcpy(tokentype,"GTEQ");
					break;
				case 23: strcpy(tokentype,"DOT");
					break;
				case 24: strcpy(tokentype,"NUM");
					break;
				case 25: strcpy(tokentype,"ID");
					break;
				case 26: strcpy(tokentype,"ERROR");
					break;
				}

//			if(type == NUM)
//			{
				add(&n, line, tokentype, token);
//			}
			
//			if(type == ID)
//			{ 
//				if(strcmp(token, "cse340") == 0 || strcmp(token, "programming") == 0 || strcmp(token, "language") == 0)
//				{
//					add(&n, line, tokentype, token);
//				}
//			}
		type = getToken();
		}
	}
	
	reverse(n);

	return 0;
}

void add(struct node **q, int d1, char d2[], char d3[])
{
	struct node *temp, *last;
	
	if(*q == NULL)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->line = d1;
		strcpy(temp->tokentype,d2);
		strcpy(temp->token1,d3);
		temp->next = NULL;
		*q = temp;
	}
	else
	{
		last = *q;
		
		while(last->next != NULL)
		{
			last=last->next;
		}
		
		temp = (struct node *)malloc(sizeof(struct node));
		temp->line = d1;
		strcpy(temp->tokentype,d2);
		strcpy(temp->token1,d3);
		temp->next = NULL;
		last->next = temp;
	}
}

void reverse(struct node *n)
{
	if(n==NULL)
	return;

	reverse(n->next);

	printf("%d\t %s\t %s\n", n->line, n->tokentype, n->token1);
}

















