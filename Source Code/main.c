/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : main.c
   Topik        : Tugas Besar TBFO
   Tanggal      : 4 Oktober 2018
   Deskripsi    : Menjalankan game Tic-Tac-Toe */

/* Program ini mensimulasikan sebuah game bernama Tic-Tac-Toe

   Dengan menggunakan DFA.c, maka dimasukkan input berisi daftar state, transisi
   start state dan final state

   Dengan menggunakan Board.c, maka state-state yang ada dapat dijadikan matriks
   yang menggambarkan Board Tic-Tac-Toe*/

#include "Board.h"
#include "DFA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // KAMUS PROGRAM

  // Tipe data primitif
  char PorC;
  char string[10];
  char input;

  boolean CPUFirst;

  int i;
  int Neff;
  int listStates[10];
  int state;
  int alphabet;

  // Tipe-tipe dari DFA.h
  arrSTATE _state;
  STARTSTATE _start;
  BOARD _board;

  // ALGORITMA

  // Opening
  printf ("-------------------------------------------------------------------------------\n");
  printf ("----------------------------------TIC-TAC-TOE----------------------------------\n");
  printf ("-------------------------------------------------------------------------------\n\n");

  printf ("Selamat Datang di Game Tic-Tac-Toe!\n");
  printf ("Sebuah game yang diprogram agar Anda tidak menang\n\n");

  // Player atau CPU first
  printf ("Apakah Anda ingin bermain duluan atau belakangan?\n");
  printf ("Masukkan 'P' bila ingin main duluan\n");
  printf ("Masukkan 'C' bila ingin main belakangan\n");
  scanf ("%c", &PorC);

  while (PorC != 'C' && PorC != 'c' && PorC != 'P' && PorC != 'p')
  {
    printf ("\n");
    printf ("Nilai yang anda masukkan tidak valid\n");
    printf ("Masukkan karakter 'C' atau 'P'\n");
    scanf ("%c", &PorC);
  }

  printf ("\n");
  if (PorC == 'C' || PorC == 'c')
  {
    CreateDFA (&_state, &_start, "compfirst.txt");
    CPUFirst = true;
  }
  else //PorC = P atau PorC = p
  {
    CreateDFA (&_state, &_start, "playerfirst.txt");
    CPUFirst = false;
  }

  // INISIASI GAME
  MakeMATRIKS (&_board);
  printf ("\nMembuat playboard. Harap bersabar\n");

  state = _start;
  SearchString (_state, state, string);
  BacaMATRIKS (&_board, _state, state, CPUFirst);
  TulisMATRIKS (_board);

  Neff = 1;
  listStates [Neff] = state;

  printf ("\n");
  if (!CPUFirst)
  {
    printf ("Masukkan angka 5 agar game dapat dimulai\n");
  }
  printf ("\n");

  // GAME MULAI
  while (!IsFinal (_state, state))
  {
    printf ("Giliran ke - %d\n", Neff);
    printf ("Masukkan posisi yang mau dimasukkan [1-9]\n");
    printf ("Keterangan : Posisi tersebut bukanlah posisi yang sudah ada\n");
    printf ("Input = ");

    // Asumsi user selalu memasukkan angka
    scanf ("%d", &alphabet);
    printf ("\n");

    // Cek input apakah antara 1-9
    if (alphabet < 1 || alphabet > 9)
    {
      printf ("Input yang dimasukkan bukanlah input yang sah");
    }
    // Cek kevalidan input
    else if (IsNext (_state, state, alphabet))
    {
      // NEXT STATE
      printf ("Input diterima\n");
      state = NextState (_state, state, alphabet);

      // GAMBAR KE LAYAR
      DrawNext (&_board, alphabet);
      printf ("\n-----------\n");
      printf ("-----------\n\n");
      BacaMATRIKS (&_board, _state, state, CPUFirst);
      TulisMATRIKS (_board);

      // UPLOAD ARRAY
      Neff = Neff + 1;
      listStates[Neff] = state;
    }
    else
    {
      printf ("Input tidak diterima, masukkan lagi!\n\n");
    }
    printf ("\n");
  }

  // EKSEKUSI ENDGAME

  // CEK MENANG ATAU KALAH
  if (checkFinal (_state, state) == 1) // WIN STATE
  {
    printf ("GAME ENDS. CPU WINS\n");
  }
  else if (checkFinal (_state, state) == 2) // TIE STATE
  {
    printf ("GAME ENDS. IT'S A DRAW\n");
  }
  else
  {
    printf ("GAME ENDS. PROGRAM LOSE\n");
  }

  // LIST STATE
  printf ("\nINI LIST STATE YANG TELAH DILALUI\n\n");

  for (i = 1; i <= Neff; i++)
  {
    SearchString (_state, listStates[i], string);
    printf ("State [%d] = q%d\n", i, listStates [i]);
    printf ("String [%d] = %s\n\n", i, string);
  }
  printf ("Tekan apapun, lalu ENTER to exit\n");
  scanf ("\n");

  return 0;
}
