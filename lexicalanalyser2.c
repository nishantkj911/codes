#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int lc = 0, cc = 0;
char cb = ' ';

struct token
{
	int lc, cc;
	char buf[10];
	int index;
	int type;
};

typedef struct token Token;

enum tokens
{
	AO,
	keyword,
	identifier,
	LT,
	LTE,
	GT,
	GTE,
	EQ,
	NE,
	LO,
	BO,
	SYM,
	LB,
	RB,
	LC,
	RC,
	LS,
	RS,
	SS,
	NUM,
	assignment
};

int isKeyword(char *buf)
{
	char *keywords[] = {"if", "else", "printf", "while", "for", "int", "char", "double", "float", "do", "break", "continue", "return", "scanf"};
	for (int i = 0; i < 14; ++i)
	{
		if (strcmp(buf, keywords[i]) == 0)
			return 1;
	}
/* 
	for (int i = 0; i < 14; i++)
	{
		printf("%s\n", keywords[i]);	
	} */
	return 0;
}

Token *getNextToken(FILE *fa)
{
	int n = 0, flag = 1;
	char buf[10];
	char ca;
	memset(buf, '\0', 10);
	int k = 0;
	Token *token = NULL;
	printf("hello");

	//remove comments

	ca = fgetc(fa);

	while (ca != EOF)
	{
		flag = 1;
		cc++;

		if (ca == '\n')
		{
			lc++;
			cc = 0;
			ca = getc(fa);
		}

		while (ca == ' ' || ca == '\t')
		{
			cc++;
			ca = getc(fa);
		}

		if (ca == '/')
		{
			cb = getc(fa);
			n++;

			if (cb == '/')
			{
				while (cb != '\n')
					cb = getc(fa);
				cb = ' ';
				flag = 0;
			}
			else if (cb == '*')
			{
				ca = getc(fa);
				do
				{
					while (ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				} while (ca != '/');
				cb = ' ';
				flag = 0;
			}
			else if (ca == '=')
			{
				buf[k++] = '/';
				buf[k] = '=';

				token->type = AO;
				cb = ' ';
			}
			else
			{
				buf[k++] = '/';
				token->type = 0;
			}
		}
		//remove preprocessor directives
		else if (ca == '#')
		{
			printf("Dealing with preprocessor directives\n");
			char temp[100];
			fscanf(fa, "%s", temp);
			if (strcmp(temp, "include") == 0 || strcmp(temp, "define") == 0)
			{
				fscanf(fa, "%[^\n]", temp);
			}
			flag = 0;
		}
		// token for brackets

		else if (ca == '(')
		{
			printf("Brackets\n");
			buf[k] = '(';
			token->type = LB;
		}
		else if (ca == ')')
		{
			printf("Brackets\n");
			buf[k] = ')';
			token->type = RB;
		}
		else if (ca == '{')
		{
			buf[k] = '{';
			printf("Brackets\n");
			token->type = LC;
		}
		else if (ca == '}')
		{
			buf[k] = '}';
			printf("Brackets\n");
			token->type = RC;
		}
		else if (ca == '[')
		{
			buf[k] = '[';
			printf("Brackets\n");
			token->type = LS;
		}
		else if (ca == ']')
		{
			printf("Brackets\n");
			buf[k] = ']';
			token->type = RS;
		}

		//token for identifiers and keywords

		else if (isalpha(ca))
		{
			buf[k++] = ca;
			cb = getc(fa);
			while (isalnum(cb))
			{
				n++;
				buf[k++] = cb;
				cb = getc(fa);
			}
			n++;

			int iskey = isKeyword(buf);
			if (iskey)
			{

				token->type = keyword;
			}
			else
				token->type = identifier;
		}

		//token for numbers

		else if (isdigit(ca))
		{
			buf[k++] = ca;
			cb = getc(fa);
			while (isdigit(cb))
			{
				n++;
				buf[k++] = cb;
				cb = getc(fa);
			}
			n++;
			token->type = NUM;
		}

		//remove string literals

		else if (ca = '"')
		{
			ca = getc(fa);
			while (ca != '"')
				ca = getc(fa);
			flag = 0;
		}

		//token for special symbols

		else if (ca == ',' || ca == ';')
		{
			buf[k] = ca;
			token->type = SYM;
		}

		//token for assignment,relational,arithmetic,logical,bitwise operator

		else if (ca == '+' || ca == '-' || ca == '*')
		{
			buf[k++] = ca;
			cb = getc(fa);
			n++;

			if (cb == '=')
			{
				buf[k] = cb;
				cb = ' ';
			}

			token->type = AO;
		}
		else if (ca == '<')
		{
			buf[k] = ca;
			cb = getc(fa);
			n++;
			if (cb != '=')
				token->type = LT;
			else
			{
				token->type = LTE;
				cb = ' ';
			}
		}

		else if (ca == '>')
		{
			buf[k] = ca;
			cb = getc(fa);
			n++;
			if (cb != '=')
				token->type = GT;
			else
			{
				token->type = GTE;
				cb = ' ';
			}
		}
		else if (ca == '=')
		{
			buf[k] = ca;
			cb = getc(fa);
			n++;
			if (cb != '=')
				token->type = assignment;
			else
			{
				token->type = EQ;
				cb = ' ';
			}
		}
		else if (ca == '!')
		{
			buf[k++] = ca;
			cb = getc(fa);
			n++;
			if (cb != '=')
				token->type = BO;
			else
			{
				buf[k] = cb;
				token->type = LO;
				cb = ' ';
			}
		}
		else if (ca == '&')
		{
			buf[k++] = ca;
			cb = getc(fa);
			n++;
			if (cb == '&')
			{
				buf[k] = cb;
				token->type = LO;
				cb = ' ';
			}
			else
			{
				token->type = BO;
			}
		}

		else if (ca == '|')
		{
			buf[k++] = ca;
			cb = getc(fa);
			n++;
			if (cb == '|')
			{
				buf[k] = cb;
				token->type = LO;
				cb = ' ';
			}
			else
			{
				token->type = BO;
			}
		}

		cc += n;
		ca = fgetc(fa);
		if (flag)
			return token;
	}

	return NULL;
}

int main()
{

	FILE *fa = fopen("samp.c", "r");
	printf("bjfjvvf");
	if (fa == NULL)
	{
		printf("File doesn't exist\n");
		exit(0);
	}

	Token *token = NULL;

	while (1)
	{
		token = getNextToken(fa);
		if (token == NULL)
			break;
		printf("\n%s,lc:%d,cc:%d", token->buf, token->lc, token->cc);
	}
}