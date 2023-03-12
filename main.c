#include "header.h"
#include "set.h"
#include "select.h"
#include "utils.h"

int
main ()
{
  char *fileName = malloc (sizeof (char) * 100);
  struct student *head = NULL,*headError = NULL;
  
  fileOps (fileName, &head, &headError);
  displayMenu(fileName, &head, &headError);
 
  freeList (&head);
  freeList (&headError);
  return 0;
}
