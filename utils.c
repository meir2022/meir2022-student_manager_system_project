#include "utils.h"

char * scanLineDinamically (FILE * type)
{
  char *fullstr = NULL;
  char substr[11] = { 0 };
  size_t sumlen = 0, curlen = 0;

  do
    {
      fgets (substr, 11, type);
      curlen = (int) strlen (substr);

      char *str = realloc (fullstr, sumlen + curlen + 1);	// resize the full string and paste the new substring in
      if (!str)
	return NULL;
      fullstr = str;
      strcpy (fullstr + sumlen, substr);
      sumlen += curlen;
    }
  while (curlen == 10 && substr[9] != '\n');	// if the current length less than 10, i know its the end of input

  return fullstr;
}

void
toLowerStr (char *str)
{
  while (*str)
    {
      *str = tolower (*str);
      str++;
    }
}

void
removeSpaces (char *str)
{
  char *newStr = (char *) malloc (sizeof (char) * strlen (str));
  for (int i = 0, j = 0; i < strlen (str); i++)
    {
      if (str[i] == ' ')
	continue;
      else
	newStr[j++] = str[i];
    }
  for (int i = 0; i < strlen (newStr); i++)
    {
      str[i] = newStr[i];
    }
  str[strlen (newStr)] = '\0';
  free (newStr);
}

int
isalphaStr (char *str)
{				// loop on string to validate only alphabet characters inside
  while (*str)
    {
      if (!isalpha (*str))
	return 0;
      str++;
    }
  return 1;
}

int
isDigitStr (char *str)
{				// loop on string to validate only alphabet characters inside
  while (*str)
    {
      if (!isdigit (*str))
	return 0;
      str++;
    }
  return 1;
}

void
printList (struct student *head)
{				// this function print the whole file average sum
  while (head)
    {
      printNode (head);
      head = head->next;
    }
}

void
printNode (struct student *head)
{
  for (int i = 0; i < 116; i++)
    printf ("%c", 95);

  printf ("\n  %-15s %-15s %-15s%9.f\t%9.f\t  %9.f\t   %10.2f ", head->fname,
	  head->lname, head->ID,
	  head->c_language == -10 ? sqrt (-1.0) : head->c_language,
	  head->computer_network ==
	  -10 ? sqrt (-1.0) : head->computer_network,
	  head->cs_fundementals == -10 ? sqrt (-1.0) : head->cs_fundementals,
	  head->average);
  if (head->error)
    printf ("\t   %s", head->error);
  puts ("");
}

void
freeList (struct student **head)
{
  while (*head)
    {
      struct student *tmp = *head;
      *head = (*head)->next;
      freeNode (tmp);
    }
  *head = NULL;
}

void
freeNode (struct student *tmp)
{
  free (tmp->fname);
  free (tmp->lname);
  free (tmp->ID);
  free (tmp->course);
  free (tmp->error);
}
