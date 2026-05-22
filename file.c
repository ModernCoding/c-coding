#include <stdio.h>


int main () {

  // FILE *pFile = fopen ("/home/ccc-444/Desktop/output.txt", "w");
  FILE *pFile = fopen ("output.txt", "w");

  char text [] = "BOOTY BOOTY BOOTY\nROCKIN' EVERYWHERE!";

  if (pFile == NULL) {
    printf ("Error opening file!\n");
    return 1;
  }

  fprintf (pFile, "%s", text);
  printf ("File was written successfully!\n");

  fclose (pFile);


  FILE *pFile2 = fopen ("output.txt", "r");

  char buffer [ 1024 ] = { 0 };

  if (pFile2 == NULL) {
    printf ("Error opening file!\n");
    return 1;
  }

  while (fgets (buffer, sizeof (buffer), pFile2) != NULL) {
    printf ("%s", buffer);
  }

  fclose (pFile2);
  
  return 0;

}