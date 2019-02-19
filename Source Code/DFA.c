/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : DFA.c
   Topik        : Tugas Besar TBFO
   Tanggal      : 4 Oktober 2018
   Deskripsi    : Mengimplementasikan yang ada di DFA.h */

// BODY dari ADT DFA
#include "DFA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FILE EKSTERNAL SECTION
void CreateDFA (arrSTATE *_State, STARTSTATE *SS, char* filename)
// Membuat tipe data yang menampung semua informasi mengenai state-state yang ada
// arrSTATE akan menampung state yang ada, stringnya, transisi, dan final state
// STARTSTATE berisi state awal saat memulai game
{
  // KAMUS LOKAL
  int i;
  int index;
  char output[255];
  FILE* pointer;

  // ALGORITMA

  // Membuka file
  pointer = fopen (filename, "r");

  if (pointer == NULL)
  {
    printf ("File yang dimaksudkan tidak ada\n");
  }
  else
  {
    while (fgets(output, sizeof (output), pointer) != NULL)
    {
      // LIST NAMA STATE YANG ADA
      const char str1[20] = "DAFTAR STATE\n";
      const char str2[20] = "TRANSISI STATE\n";
      const char str3[20] = "START STATE\n";
      const char str4[20] = "FINAL STATE\n";

      // DAFTAR STATE
      if (strcmp (output, str1) == 0)
      {
        //printf ("Daftar State terbaca\n");
        Neff (*_State) = 0;

        while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
        {
          const char* state = strtok (output, ",");
          const char* string = strtok (NULL, ",");

          index = atoi (state);

          Neff (*_State)++;
          strcpy (String (*_State, index), string);
        }
        Neff(*_State) = index;
      }

      // TRANSISI STATE
      if (strcmp (output, str2) == 0)
      {
        while (strcmp (fgets (output, sizeof (output), pointer), "\n") != 0)
        {
          const char* state = strtok (output, ",");
          index = atoi(state);

          for (i = 1; i <= 9; i++)
          {
            const char* target = strtok (NULL, ",");
            Transition (*_State, index, i) = atoi (target);
          }
        }
      }

      // START STATE
      if (strcmp (output, str3) == 0)
      {
        char str3[10];
        strcpy (str3, output);
        str3[strcspn(str3, "\n")] = 0;
        *SS = atoi (str3);
      }

      // FINAL STATE
      if (strcmp (output, str4) == 0)
      {
        int check;

        do
        {
          fgets (output, sizeof (output), pointer);
          const char* fstate = strtok (output, ",");
          const char* WoD = strtok (NULL, ",");

          char str3[10];
          strcpy (str3, WoD);
          str3[strcspn(str3, "\n")] = 0;

          check = atoi (fstate);
          WD (*_State, check) = atoi (str3);

          i++;
        }
        while (check < index);
      }
    }
    fclose (pointer);
  }
}


// DFA CHECKING SECTION
int checkFinal (arrSTATE _State, int state)
// Mengembalikan 0 jika state yang sedang ada bukan final state
// Mengembalikan 1 jika state yang sedang ada merupakan final state dan menang
// Mengembalikan 2 jika state yang sedang ada merupakan final state dan seri
{
  return (WD (_State, state));
}

boolean IsNext (arrSTATE _State, int state, int alfa)
// Mengembalikan true jika terdapat state lain yang bisa diganti setelah alfabet
{
  return (Transition (_State, state, alfa) != -1);
}

boolean IsFinal (arrSTATE _State, int state)
// Mengembalikan true jika state yang dimaksudkan merupakan final state
{
  return (WD (_State, state) != 0);
}


// SEARCHING STATE DAN TRANSITION STATE
void SearchString (arrSTATE _States, int state, char *string)
// Mengembalikan string yang dimaksud dari sebuah state
{
  strcpy (string, String(_States, state));
}

int NextState (arrSTATE _States, int state, int alfa)
// Prasyarat : Merupakan alfabet yang memiliki state berikutnya
// Mengembalikan state berikutnya dari state yang dimasuki alfabet
{
  return (Transition (_States, state, alfa));
}
