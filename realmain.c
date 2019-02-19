/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : board.c
   Topik        : Tubes
   Tanggal      : 30 September 2018
   Deskripsi    : Bertugas menggambarkan papan tic-tac-toe */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.c"
#include "DFA.c"

int main()
{
  // KAMUS
  char PorC;
  boolean CPUFirst;

  int state;
  int alphabet;
  char string[10];

  arrSTATE daStates;
  arrTRANSISI daTransisis;
  STARTSTATE daStart;
  FINALSTATE daFinal;
  RECORDSTATE daRecStates;
  BOARD M;

  // ALGORITMA

  printf ("--------------------------------------------------------\n");
  printf ("----------------------TIC-TAC-TOE-----------------------\n");
  printf ("--------------------------------------------------------\n\n");

  printf ("Selamat datang di program Tic-Tac-Toe\n");
  printf ("Sebuah game di mana Anda tidak mungkin menang\n\n");

  printf ("Apakah Anda ingin bermain duluan atau belakangan?\n");
  printf ("Masukkan 'P' bila ingin main duluan\n");
  printf ("Masukkan 'C' bila ingin main belakangan\n");

  scanf ("%c", &PorC);

  while (PorC != 'C' && PorC != 'c' && PorC != 'P' && PorC != 'p')
  {
    printf ("Nilai yang anda masukkan tidak valid\n");
    printf ("Masukkan karakter 'C' atau 'P'\n");
    scanf ("%c", &PorC);
  }

  if (PorC == 'C' || PorC == 'c')
  {
    CreateDFAComp (&daStates, &daTransisis, &daStart, &daFinal);
    CPUFirst = true;
  }
  else //PorC = P atau PorC = p
  {
    CreateDFAPlayer (&daStates, &daTransisis, &daStart, &daFinal);
    CPUFirst = false;
  }

  MakeMATRIKS (&M);
  printf ("Membuat playboard\n");
  TulisMATRIKS (M);
  SetRecord (&daRecStates);

  // STAR GAME
  state = daStart;
  SearchString (daStates, state, string);
  printf ("State ke 0 adalah : %s\n", string);
  BacaMATRIKS (&M, daStates, state, CPUFirst);
  TulisMATRIKS (M);
  RecordStates (&daRecStates, daStates, state);

  //printf ("Jika state 0 dimasukkan 3 akan maju ke state : %d", NextState (daTransisis, state, 3));
  if (IsFinal (daFinal, state))
  {
    printf ("Ini final\n");
  }
  else
  {
    printf ("Ini tidak final\n");
  }

  while (!IsFinal (daFinal, state))
  {
    printf ("Masukkan posisi yang akan dimasukkan [0-9] : ");
    scanf ("%d", &alphabet);
    if (IsNext (daTransisis, state, alphabet))
    {
      printf ("Input diterima\n");
      state = NextState (daTransisis, state, alphabet);
      DrawNext (&M, alphabet);
      BacaMATRIKS (&M, daStates, state, CPUFirst);
      TulisMATRIKS (M);
      RecordStates (&daRecStates, daStates, state);
    }
    else
    {
      printf ("Input tidak diterima, masukkan lagi!\n");
    }
  }

  if (checkFinal (daFinal, state) == 1)
  {
    printf ("GAME ENDS. CPU WINS\n");
  }
  else
  {
    printf ("GAME ENDS. TIE\n");
  }

  ShowStates (daRecStates);

  return 0;
}
