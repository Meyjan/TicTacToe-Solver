/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : DFA.c
   Topik        : Tubes
   Tanggal      : 30 September 2018
   Deskripsi    : Mengimplementasikan yang ada di DFA.h */

// BODY dari ADT DFA
#include "DFA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FILE EKSTERNAL SECTTION
void CreateDFAComp (arrSTATE *_State, arrTRANSISI *_Transisi, STARTSTATE *SS, FINALSTATE *FS)
// Membuat DFA jika komputer berjalan duluan
{
  // KAMUS LOKAL
  int i;

  // ALGORITMA
  FILE* pointer = fopen ("compfirst.txt", "r");

  if (pointer == NULL)
  {
    printf ("Can't open / find file!\n");
  }

  else
  {
    char output[255];

    while (fgets (output, sizeof (output), pointer) != NULL)
    {
      const char str1[20] = "DAFTAR STATE\n";
      const char str2[20] = "TRANSISI STATE\n";
      const char str3[20] = "START STATE\n";
      const char str4[20] = "FINAL STATE\n";
      const char str5[20] = "ENDFILE\n";

      if (strcmp (output, str1) == 0)
      {
        //printf ("DAFTAR STATE terbaca\n");
        Neff1 (*_State) = 0;

        while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
        {
          const char* state = strtok (output, ",");
          const char* string = strtok (NULL, ",");

          int index = atoi (state);

          char str2[10];
          strcpy (str2, string);
          str2[strcspn(str2, "\n")] = 0;

          Neff1 (*_State)++;
          State1(*_State, index) = index;
          strcpy (String (*_State, index), str2);
        }
      }

      if (strcmp (output, str2) == 0)
      {

        //printf ("TRANSITION STATE terbaca\n");
        Neff2(*_Transisi) = 0;
        while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
        {
          const char* state = strtok (output, ",");
          const char* target1 = strtok (NULL, ",");
          const char* target2 = strtok (NULL, ",");
          const char* target3 = strtok (NULL, ",");
          const char* target4 = strtok (NULL, ",");
          const char* target5 = strtok (NULL, ",");
          const char* target6 = strtok (NULL, ",");
          const char* target7 = strtok (NULL, ",");
          const char* target8 = strtok (NULL, ",");
          const char* target9 = strtok (NULL, ",");

          int index = atoi (state);
          State2 (*_Transisi, index) = index;
          Transition (*_Transisi, index, 1) = atoi (target1);
          Transition (*_Transisi, index, 2) = atoi (target2);
          Transition (*_Transisi, index, 3) = atoi (target3);
          Transition (*_Transisi, index, 4) = atoi (target4);
          Transition (*_Transisi, index, 5) = atoi (target5);
          Transition (*_Transisi, index, 6) = atoi (target6);
          Transition (*_Transisi, index, 7) = atoi (target7);
          Transition (*_Transisi, index, 8) = atoi (target8);
          Transition (*_Transisi, index, 9) = atoi (target9);
          Neff2 (*_Transisi)++;
        }
      }

      if (strcmp (output, str3) == 0)
      {
        //printf ("START STATE terbaca\n");

        char str2[10];
        strcpy (str2, output);
        str2[strcspn(str2, "\n")] = 0;

        *SS = atoi (str2);
      }

      if (strcmp (output, str2) == 0)
      {

        //printf ("TRANSITION STATE terbaca\n");
        Neff2(*_Transisi) = 0;
        while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
        {
          const char* state = strtok (output, ",");
          const char* target1 = strtok (NULL, ",");
          const char* target2 = strtok (NULL, ",");
          const char* target3 = strtok (NULL, ",");
          const char* target4 = strtok (NULL, ",");
          const char* target5 = strtok (NULL, ",");
          const char* target6 = strtok (NULL, ",");
          const char* target7 = strtok (NULL, ",");
          const char* target8 = strtok (NULL, ",");
          const char* target9 = strtok (NULL, ",");

          int index = atoi (state);
          State2 (*_Transisi, index) = index;
          Transition (*_Transisi, index, 1) = atoi (target1);
          Transition (*_Transisi, index, 2) = atoi (target2);
          Transition (*_Transisi, index, 3) = atoi (target3);
          Transition (*_Transisi, index, 4) = atoi (target4);
          Transition (*_Transisi, index, 5) = atoi (target5);
          Transition (*_Transisi, index, 6) = atoi (target6);
          Transition (*_Transisi, index, 7) = atoi (target7);
          Transition (*_Transisi, index, 8) = atoi (target8);
          Transition (*_Transisi, index, 9) = atoi (target9);
          Neff2 (*_Transisi)++;
        }
      }

      if (strcmp (output, str3) == 0)
      {
        //printf ("START STATE terbaca\n");

        char str2[10];
        strcpy (str2, output);
        str2[strcspn(str2, "\n")] = 0;

        *SS = atoi (str2);
      }

      if (strcmp (output, str4) == 0)
      {
        int target;
        i = 1;
        //printf ("FINAL STATE terbaca\n");

        do
        {
          fgets (output, sizeof (output), pointer);
          const char* fstate = strtok (output, ",");
          const char* WoD = strtok (NULL, ",");

          char str2[10];
          strcpy (str2, WoD);
          str2[strcspn(str2, "\n")] = 0;

          WD (*FS,i) = atoi (str2);
          FS (*FS,i) = atoi (fstate);
          //printf ("check[%d]\t[%d]\n", atoi (fstate), atoi(str2));
          i++;
          target = atoi(fstate);
        }
        while (target < 96);
        Neff3(*FS) = i - 1;
        printf ("%d", Neff3(*FS));
      }
      /*if (strcmp (output, str4) == 0)
      {
        i = 1;
        printf ("FINAL STATE terbaca\n");
        while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
        {
          const char* fstate = strtok (output, ",");
          const char* WoD = strtok (NULL, ",");

          char str2[10];
          strcpy (str2, WoD);
          str2[strcspn(str2, "\n")] = 0;

          WD (*FS,i) = atoi (str2);
          FS (*FS,i) = atoi (fstate);

          i++;
        }
        Neff3(*FS) = i - 1;
      }*/
    }
    fclose (pointer);
    printf ("checkLoad\n");
  }
}

void CreateDFAPlayer (arrSTATE *_State, arrTRANSISI *_Transisi, STARTSTATE *SS, FINALSTATE *FS)
// Membuat DFA jika player berjalan duluan
{
  // KAMUS LOKAL
  int i;

  // ALGORITMA
  FILE* pointer = fopen ("playerfirst.txt", "r");

  if (pointer == NULL)
  {
    printf ("Can't open / find file!\n");
  }

  else
  {
    char output[255];
    int _state;

    while (fgets (output, sizeof (output), pointer) != NULL)
    {
      const char str1[20] = "DAFTAR STATE\n";
      const char str2[20] = "TRANSISI STATE\n";
      const char str3[20] = "START STATE\n";
      const char str4[20] = "FINAL STATE\n";
      const char str5[20] = "ENDFILE\n";

      if (strcmp (output, str1) == 0)
      {
        //printf ("DAFTAR STATE terbaca\n");
        Neff1 (*_State) = 0;

        while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
        {
          const char* state = strtok (output, ",");
          const char* string = strtok (NULL, ",");

          int index = atoi (state);

          char str2[10];
          strcpy (str2, string);
          str2[strcspn(str2, "\n")] = 0;

          Neff1 (*_State)++;
          State1(*_State, index) = index;
          strcpy (String (*_State, index), str2);
        }
      }

      if (strcmp (output, str2) == 0)
      {

        //printf ("TRANSITION STATE terbaca\n");
        Neff2(*_Transisi) = 0;
        while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
        {
          const char* state = strtok (output, ",");
          const char* target1 = strtok (NULL, ",");
          const char* target2 = strtok (NULL, ",");
          const char* target3 = strtok (NULL, ",");
          const char* target4 = strtok (NULL, ",");
          const char* target5 = strtok (NULL, ",");
          const char* target6 = strtok (NULL, ",");
          const char* target7 = strtok (NULL, ",");
          const char* target8 = strtok (NULL, ",");
          const char* target9 = strtok (NULL, ",");

          int index = atoi (state);
          State2 (*_Transisi, index) = index;
          Transition (*_Transisi, index, 1) = atoi (target1);
          Transition (*_Transisi, index, 2) = atoi (target2);
          Transition (*_Transisi, index, 3) = atoi (target3);
          Transition (*_Transisi, index, 4) = atoi (target4);
          Transition (*_Transisi, index, 5) = atoi (target5);
          Transition (*_Transisi, index, 6) = atoi (target6);
          Transition (*_Transisi, index, 7) = atoi (target7);
          Transition (*_Transisi, index, 8) = atoi (target8);
          Transition (*_Transisi, index, 9) = atoi (target9);
          Neff2 (*_Transisi)++;
        }
      }

      if (strcmp (output, str3) == 0)
      {
      //  printf ("START STATE terbaca\n");

        char str2[10];
        strcpy (str2, output);
        str2[strcspn(str2, "\n")] = 0;

        *SS = atoi (str2);
      }

      if (strcmp (output, str4) == 0)
      {
        int target;
        i = 1;
        //printf ("FINAL STATE terbaca\n");

        do
        {
          fgets (output, sizeof (output), pointer);
          const char* fstate = strtok (output, ",");
          const char* WoD = strtok (NULL, ",");

          char str2[10];
          strcpy (str2, WoD);
          str2[strcspn(str2, "\n")] = 0;

          WD (*FS,i) = atoi (str2);
          FS (*FS,i) = atoi (fstate);
          //printf ("check[%d]\t[%d]\n", atoi (fstate), atoi(str2));
          i++;
          target = atoi(fstate);
        }
        while (target < 115);
        Neff3(*FS) = i - 1;
        printf ("%d", Neff3(*FS));
      }
        /*while (//strcmp (fgets (output, sizeof (output), pointer), "\n") != 0 ||
        strcmp (fgets (output, sizeof (output), pointer), str5) != 0)
        {
          const char* fstate = strtok (output, ",");
          const char* WoD = strtok (NULL, ",");

          char str2[10];
          strcpy (str2, WoD);
          str2[strcspn(str2, "\n")] = 0;

          WD (*FS,i) = atoi (str2);
          FS (*FS,i) = atoi (fstate);
          printf ("check[%d]\t[%d]\n", atoi (fstate), atoi(str2));
          i++;
        }
        printf ("check1\n");
        Neff3(*FS) = i - 1;
      }*/
    }
    fclose (pointer);
    printf ("checkLoad\n");
  }
}


// DFA CHECKING SECTION
int cariStart (STARTSTATE SS)
// Mencari state yang digunakan untuk memulai game;
{
  return (SS);
}

int checkFinal (FINALSTATE FS, int state)
// Mengembalikan 1 jika state yang sedang ada merupakan final state dan menang
// Mengembalikan 2 jika state yang sedang ada merupakan final state dan seri
// Mengembalikan 0 jika state bukan merupakan finalstate
{
  return (WD (FS,state));
}

// SEARCHING STATE DAN TRANSITION STATE
void SearchString (arrSTATE _States, int state, char *string)
// Mengembalikan string yang dimaksud dari sebuah state
{
  strcpy (string, String (_States, state));
}

int NextState (arrTRANSISI _Transisi, int state, int alfa)
// Mengembalikan state berikutnya dari state yang dimasuki alfabet
// Jika STATE berikutnya tidak ada, mengembalikan -1
{
  return (Transition (_Transisi, state, alfa));
}

boolean IsNext (arrTRANSISI _Transisi, int state, int alfa)
// Mengembalikan true jika terdapat state lain yang bisa diganti setelah alfabet
{
  return (Transition (_Transisi, state, alfa) != -1);
}


boolean IsFinal (FINALSTATE fin, int state)
// Mengembalikan true jika fin merupakan final state
{
  // KAMUS LOKAL
  int i;

  // ALGORITMA
  i = 1;
  while (i < Neff3 (fin) && FS (fin, i) != state)
  {
    i++;
  }
  return (FS(fin, i) == state);
}

void SetRecord (RECORDSTATE *RS)
// Megeset Neff4 menjadi 0 karena tidak ada state yang direcord
{
  Neff4 (*RS) = 0;
}

void RecordStates (RECORDSTATE *RS, arrSTATE _States, int state)
// Menyimpan state-state yang sedang dijalankan oleh program
{
  // KAMUS LOKAL
  char string[10];

  // ALGORITMA
  SearchString (_States, state, string);
  Neff4 (*RS)++;
  RecState (*RS, Neff4(*RS)) = state;
  printf ("%d", state);
  printf ("%d\n", RecState (*RS, Neff4(*RS)));
  strcpy (RecString (*RS, Neff4(*RS)),string);
}

void ShowStates (RECORDSTATE RS)
// Menampilkan semua state yang disimpan dalam RECORDSTATE
{
  // KAMUS LOKAL
  int i;

  // ALGORITMA
  printf ("INILAH LIST STATENYA\n");
  for (i = 1; i <= Neff4(RS); i++)
  {
    printf ("State [%d] = %d\n", i, RecState (RS, Neff4(RS)));
    printf ("String [%s] = %s\n", i, RecString (RS, Neff4(RS)));
  }

}
