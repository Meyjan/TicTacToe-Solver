/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : realmain.c
   Topik        : Tubes
   Tanggal      : 30 September 2018
   Deskripsi    : Menjalankan program Tic-Tac-Toe */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int i;

  FILE* pointer = fopen ("compfirst.txt", "r");

  if (pointer == NULL)
  {
    printf ("Can't open / find file!\n");
    return 1;
  }

  char output[255];

  /*for (i = 1; fgets(output, sizeof (output), pointer) != NULL; i++)
  {
    printf ("%02d: %s", i, output);
  }*/

  while (fgets (output, sizeof (output), pointer) != NULL)
  {
    const char str1[20] = "DAFTAR STATE\n";
    const char str2[20] = "TRANSISI STATE\n";
    const char str3[20] = "START STATE\n";
    const char str4[20] = "FINAL STATE\n";

    if (strcmp (output, str1) == 0)
    {
      i = 1;
      printf ("DAFTAR STATE terbaca\n\n");
      while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
      {
        const char* state = strtok (output, ",");
        const char* string = strtok (NULL, ",");

        int input = atoi (state);
        char _index;
        int index;

        char str2[10];
        strcpy (str2, string);
        str2[strcspn(str2, "\n")] = 0;

        printf ("[%02d]state = q%d\n", i, input);
        printf ("[%02d]string = %s\n", i, str2);

        int j;

        for (j = 0; j < strlen (str2); j++)
        {
          _index = str2[j];
          index = _index - '0';
          printf ("idx[%d] = %c\n", (j + 1), _index);
          printf ("idx[%d] = %d\n", (j + 1), index);
        }

        i++;
        printf ("\n");
      }
    }

    if (strcmp (output, str2) == 0)
    {
      i = 1;
      printf ("TRANSISI STATE terbaca\n");
      while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
      {
        const char* state = strtok (output, ",");
        const char* target1 = strtok (NULL, ",");
        const char* target2 = strtok (NULL, ",");
        const char* target3 = strtok (NULL, ",");

        printf ("[%02d]state = q%s\n", i, state);
        printf ("[%02d]alphabet1 = %d\n", i, atoi(target1));
        printf ("[%02d]alphabet2 = %s\n", i, target2);
        printf ("[%02d]alphabet3 = %s\n", i, target3);

        i++;
        printf ("\n");
      }
    }

    if (strcmp (output, str3) == 0)
    {
      printf ("START STATE terbaca\n");
      printf ("Start state : q%s\n", fgets (output, 2, pointer));
    }

    if (strcmp (output, str4) == 0)
    {
      i = 1;
      printf ("FINAL STATE terbaca\n");
      while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
      {
        const char* fstate = strtok (output, ",");
        const char* WoD = strtok (NULL, ",");

        printf ("[%02d]Final state : q%d\n", i, atoi(fstate));
        printf ("[%02d]WinOrDraw : %d\n", i, atoi(WoD));
        i++;
        printf ("\n");
      }
    }
  }
  //printf ("ENDFILE\n");
  fclose (pointer);
  return 0;
}
