#include "set.h"
#include "utils.h"

void
setNewData (char *inputLine, struct student **head, struct student **headB,
	    char *fileName)
{
  struct student *newStruct = checkValidSet (inputLine);
  while (!newStruct || newStruct->error)
    {
      puts
	("\nwrong insert , try again !\nfor example : \" set first name = avi , last name = iaakobi , ID = 123456789 , course = c language , grade = 100 \" ");
      puts ("to go back , press 'enter'.");
      inputLine = scanLineDinamically (stdin);
      if (*inputLine == '\n')
	break;
      newStruct = checkValidSet (inputLine);
      validateNewStruct (&newStruct, head, headB);
    }
  if (*inputLine != '\n')
    writeTofile (newStruct, fileName);	// if line checked write it into the file
}

struct student *
checkValidSet (char *inputLine)
{				//this function destruct line to validate object and check existance 
  char *tempInputLine = strdup (inputLine);
  if (!tempInputLine)
    return NULL;
  toLowerStr (tempInputLine);
  char *setFirstName, *fnameValue, *lastName, *lnameValue, *ID, *IDValue,
    *course, *courseName, *grade, *gradeValue;
  setFirstName = strtok (tempInputLine, "=");
  if (strcmp (setFirstName, "set first name "))
    return NULL;
  fnameValue = strtok (NULL, ",");
  lastName = strtok (NULL, "=");
  if (strcmp (lastName, " last name "))
    return NULL;
  lnameValue = strtok (NULL, ",");
  ID = strtok (NULL, "=");
  if (strcmp (ID, " id "))
    return NULL;
  IDValue = strtok (NULL, ",");
  if (strlen (IDValue) != 10 || !isDigitStr (IDValue + 1))
    return NULL;
  course = strtok (NULL, "=");
  if (strcmp (course, " course "))
    return NULL;
  courseName = strtok (NULL, ",");
  if (strcmp (courseName, " c language")
      && strcmp (courseName, " cs fundementals")
      && strcmp (courseName, " computer network"))
    return 0;
  grade = strtok (NULL, "=");
  if (strcmp (grade, " grade "))
    return NULL;
  gradeValue = strtok (NULL, " ");
  inputLine =
    malloc (strlen (fnameValue) + strlen (lnameValue) + strlen (IDValue) +
	    strlen (courseName) + strlen (gradeValue) + 5);
  sprintf (inputLine, "%s, %s, %s, %s, %s", fnameValue, lnameValue, IDValue,
	   courseName, gradeValue);
  struct student *newStruct = createStruct (inputLine);
  free (tempInputLine);
  printf (">>%s\n", inputLine);
  return newStruct;
}
