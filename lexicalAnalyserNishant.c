#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*

So this works perfectly well. The output is obtained in a separated file 
because it is too much work to comment all the debug printfs.

But that is the final output and you can verify it, it's correct.

You don't need to write the comment and preprocessor directives part. Ma'am said it.

With love, Nishu
*/

int lc = 1, cc = 0, prevCC = 0; // prevCC used in retracting for the case if the extra read char is '\n'
char cb = ' ';

struct token
{
	int lc, cc;
	char *buf;
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

void updateLineNos(char c)
{
	if (c == '\n')
	{
		lc++;
		prevCC = cc;
		cc = 0;
	}
	else
	{
		cc++;
	}
}

void retract(FILE *f1, char c)
{
	fseek(f1, -1, SEEK_CUR);
	if (c == '\n')
	{
		cc = prevCC;
		lc--;
	}
}

int isKeyword(char *buf)
{
	char *keywords[] = {"if", "else", "while", "for", "int", "char", "double", "float", "do", "break", "continue", "return"};
	for (int i = 0; i < 12; ++i)
	{
		// printf("%s\n", keywords[i]);
		if (strcmp(buf, keywords[i]) == 0)
			return 1;
	}

	/* for (int i = 0; i < 11; i++)
	{
		printf("%s\n", keywords[i]);
	} */
	return 0;
}

Token *getNextToken(FILE *fa)
{
	int n = 0, flag = 1;
	char *buf = calloc(BUFSIZ, sizeof(char));
	char ca;
	memset(buf, '\0', BUFSIZ);
	int k = 0;
	Token *token = malloc(sizeof(Token));
	// printf("hello\n");

	//remove comments

	do
	{
		ca = fgetc(fa);
		updateLineNos(ca);
		k = 0;
		flag = 1;
		printf("Start of while, read: '%c'\n", ca);

		if (ca == '\n')
		{
			// printf("dealing with new line\n");
			ca = getc(fa);
			updateLineNos(ca);
		}

		while (ca == ' ' || ca == '\t')
		{

			ca = getc(fa);
			updateLineNos(ca);
		}

		if (ca == '/')
		{
			// printf("Dealing with comments or /=\n");
			cb = getc(fa);
			updateLineNos(cb);
			n++;

			if (cb == '/')
			{
				printf("single line\n");
				while (cb != '\n')
				{
					cb = getc(fa);
					updateLineNos(cb);
				}
				// cb = ' ';
				flag = 0;
			}
			else if (cb == '*')
			{
				printf("multiline\n");
				ca = getc(fa);
				updateLineNos(ca);
				do
				{
					while (ca != '*')
					{
						ca = getc(fa);
						updateLineNos(ca);
					}
					ca = getc(fa);
					updateLineNos(ca);
				} while (ca != '/');
				// cb = ' ';
				flag = 0;
			}
			else if (cb == '=')
			{
				buf[k++] = '/';
				buf[k++] = '=';
				token->type = 0;
				buf[k++] = '\0';
				token->buf = calloc(strlen(buf), sizeof(char));
				strcpy(token->buf, buf);
				token->lc = lc;
				token->cc = cc - 2;

				return token;
				// cb = ' ';
			}
			else
			{
				buf[k++] = '/';
				token->type = 0;
				buf[k++] = '\0';
				token->buf = calloc(strlen(buf), sizeof(char));
				strcpy(token->buf, buf);
				token->lc = lc;
				token->cc = cc - 1;

				return token;
			}
			continue;
		}
		//remove preprocessor directives
		if (ca == EOF)
			return NULL;
		else if (ca == '#')
		{
			printf("Preprocessor directives\n");
			char temp[100];
			fscanf(fa, "%s", temp);
			if (strcmp(temp, "include") == 0 || strcmp(temp, "define") == 0)
			{
				fscanf(fa, "%[^\n]%*c", temp);
				lc++;
			}
			flag = 0;
		}

		// token for brackets

		else if (ca == '(')
		{
			printf("Bracket\n");
			buf[k++] = '(';
			token->type = 12;
		}
		else if (ca == ')')
		{
			printf("Bracket\n");
			buf[k++] = ')';
			token->type = 13;
		}
		else if (ca == '{')
		{
			buf[k++] = '{';
			printf("Bracket\n");
			token->type = 14;
		}
		else if (ca == '}')
		{
			printf("Bracket\n");
			buf[k++] = '}';
			token->type = 15;
		}
		else if (ca == '[')
		{
			printf("Bracket\n");
			buf[k++] = '[';
			token->type = 16;
		}
		else if (ca == ']')
		{
			printf("Bracket\n");
			buf[k++] = ']';
			token->type = 17;
		}

		//token for identifiers and keywords

		else if (isalpha(ca) || ca == '_')
		{
			printf("Dealing with identifiers and keywords. Read %c\n", ca);
			buf[k++] = ca;
			ca = getc(fa);
			updateLineNos(ca);
			while (isalnum(ca) || ca == '_')
			{
				n++;
				buf[k++] = ca;
				ca = getc(fa);
				updateLineNos(ca);
			}
			retract(fa, ca);
			n++;

			int iskey = isKeyword(buf);
			// printf("Here\n");
			if (iskey)
			{
				printf("keyword\n");
				token->type = 1;
			}
			else
			{
				printf("Identifier\n");
				token->type = 2;
			}
		}

		//token for numbers

		else if (isdigit(ca))
		{
			// printf("dealing with nos\n");
			buf[k++] = ca;
			cb = getc(fa);
			updateLineNos(cb);
			while (isdigit(cb))
			{
				n++;
				buf[k++] = cb;
				cb = getc(fa);
				updateLineNos(cb);
			}
			retract(fa, ca);
			n++;
			token->type = 19;
		}

		//token for special symbols

		else if (ca == ',' || ca == ';')
		{
			// printf("dealing with special symbols\n");
			buf[k++] = ca;
			token->type = 18;
		}

		//token for assignment,relational,arithmetic,logical,bitwise operator

		else if (ca == '+' || ca == '-' || ca == '*')
		{
			printf("assignment, relational, arithmetic, logical and bitwise operators\n");
			buf[k++] = ca;
			cb = getc(fa);
			updateLineNos(ca);
			n++;

			if (cb == '=')
			{
				buf[k++] = cb;
				// cb = ' ';
			}
			else
			{
				retract(fa, cb);
			}

			token->type = 0;
		}
		else if (ca == '<')
		{
			buf[k++] = ca;
			cb = getc(fa);
			n++;
			if (cb != '=')
			{
				token->type = 3;
				retract(fa, cb);
			}
			else
			{
				n++;
				token->type = 4;
				buf[k++] = cb;
				// cb = ' ';
			}
		}

		else if (ca == '>')
		{
			buf[k++] = ca;
			cb = getc(fa);
			updateLineNos(cb);
			n++;
			if (cb != '=')
			{
				token->type = 5;
				retract(fa, cb);
			}
			else
			{
				n++;
				token->type = 6;
				buf[k++] = cb;
				// cb = ' ';
			}
		}
		else if (ca == '=')
		{
			buf[k++] = ca;
			cb = getc(fa);
			updateLineNos(cb);
			n++;
			if (cb != '=')
			{
				token->type = 20;
				retract(fa, cb);
			}
			else
			{
				n++;
				token->type = 7;
				buf[k++] = cb;
				// cb = ' ';
			}
		}
		else if (ca == '!')
		{
			buf[k++] = ca;
			cb = getc(fa);
			updateLineNos(cb);
			n++;
			if (cb != '=')
			{
				token->type = 9;
				retract(fa, cb);
			}
			else
			{
				n++;
				buf[k++] = cb;
				token->type = 8;
				// cb = ' ';
			}
		}
		else if (ca == '&')
		{
			buf[k++] = ca;
			cb = getc(fa);
			updateLineNos(cb);
			n++;
			if (cb == '&')
			{
				n++;
				buf[k++] = cb;
				token->type = 9;
				// cb = ' ';
			}
			else
			{
				token->type = 10;
				retract(fa, cb);
			}
		}

		else if (ca == '|')
		{
			buf[k++] = ca;
			cb = getc(fa);
			updateLineNos(cb);
			n++;
			if (cb == '|')
			{
				n++;
				buf[k++] = cb;
				token->type = 9;
				// cb = ' ';
			}
			else
			{
				token->type = 10;
				retract(fa, cb);
			}
		}
		//remove string literals

		else if (ca == '\"')
		{
			// printf("dealing with literals\n");
			do
			{
				buf[k++] = ca;
				ca = getc(fa);
				updateLineNos(ca);
			} while (ca != '\"');
			buf[k++] = ca;
			flag = 0; // comment this to send literals also to the final code.
			// fseek(fa, -1, SEEK_CUR);
		}
		else
		{
			printf("Unidentified character '%c'\n", ca);
			retract(fa, ca);
			flag = 0;
		}

		// printf("Reached out of maze\n");
		buf[k++] = '\0';
		printf("The final verdict is '%s'\n", buf);
		token->buf = calloc(strlen(buf), sizeof(char));
		token->lc = lc;
		token->cc = cc - n;
		strcpy(token->buf, buf);
		// ca = fgetc(fa);
		if (flag)
			return token;
	} while (ca != EOF);

	return NULL;
}

int main()
{
	// printf("bjfjvvf\n");
	FILE *fa = fopen("samp.c", "r");
	FILE *file2 = fopen("output.txt", "w");
	if (fa == NULL || file2 == NULL)
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
		fprintf(file2, "<'%s'\tlc: %d\tcc: %d>\n", token->buf, token->lc, token->cc);
	}
}