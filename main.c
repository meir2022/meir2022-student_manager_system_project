#include "header.h"
#include "set.h"
#include "select.h"
#include "utils.h"

int
main ()
{
  char *fileName = malloc (sizeof (char) * 100);
  struct student *head = NULL;
  struct student *headError = NULL;
  fileOps (fileName, &head, &headError);
  char *inputLine = NULL, *op = NULL;
  int quit = 0;
  while (!quit)
    {
      puts
	("\n\nto add a new data please enter \"set\" in this format, for example : \" set first name = avi , last name = iaakobi , ID = 123456789 , course = c language , grade = 100 \"");
      puts
	("to select data please enter \"select\" in this format, for example : \"first name = david\" OR \"grade > 80\" etc. ");
      puts ("to print enter \"print\" . enter \"quit\" to exit : ");
      inputLine = scanLineDinamically (stdin);
      if (strstr (inputLine, "print\n"))
	printList (head);
      if (strstr (inputLine, "set"))
	setNewData (inputLine, &head, &headError, fileName);	// destruct and validate input than insert to students list
      else if (strstr (inputLine, "select"))
	selectData (head, inputLine);
      else if (strstr (inputLine, "quit\n"))
	quit = 1;
    }
  puts ("\n bye bye!");
  freeList (&head);
  freeList (&headError);
  return 0;
}
