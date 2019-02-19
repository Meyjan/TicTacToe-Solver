/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : Board.c
   Topik        : Tugas Besar TBFO
   Tanggal      : 4 Oktober 2018
   Deskripsi    : Bertugas menggambarkan papan tic-tac-toe */

// BODY dari ADT BOARD a.k.a MATRIKS

#include "Board.h"
#include <stdio.h>
#include <string.h>

/* MEMBENTUK BOARD KOSONG Tic-Tac-Toe */
void MakeMATRIKS (BOARD * M)
/* Membentuk sebuah Board TIC TAC TOE "kosong" yang siap diisi berukuran 3 x 3 di "ujung kiri" memori */
/* I.S. tidak ada apa-apa */
/* F.S. Board berbentuk Matriks M berukurn 3x3 terbentuk */
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA
  for (i = 1; i <= 3; i++)
  {
    for (j = 1; j <= 3; j++)
    {
      Elmt (*M,i,j) = '_';
    }
  }
}


/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (BOARD * M, arrSTATE arrS, int state, boolean CPUFirst)
/* Membaca sebuah state dan string yang dimiliki state tersebut */
/* Lalu memasukannya ke dalam board */
{
  indeks i;
  char string[10];
  strcpy (string, String(arrS, state));

  if (CPUFirst)
  {
    for (i = 0; i < strlen (string); i++)
    {
      int mark = string[i] - '0';
      if (i % 2 == 0)
      {
        Elmt (*M, ((mark + 2) / 3), (((mark + 2) % 3) + 1)) = 'O';
      }
      else
      {
        Elmt (*M, ((mark + 2) / 3), (((mark + 2) % 3) + 1)) = 'X';
      }
    }
  }
  else // PLAYERFirst
  {
    for (i = 0; i < strlen (string); i++)
    {
      int mark = string[i] - '0';
      if (i % 2 == 0)
      {
        Elmt (*M, ((mark + 2) / 3), (((mark + 2) % 3) + 1)) = 'X';
      }
      else
      {
        Elmt (*M, ((mark + 2) / 3), (((mark + 2) % 3) + 1)) = 'O';
      }
    }
  }
}

void TulisMATRIKS (BOARD M)
/* Menuliskan matriks yang telah diisi ke dalam layar */
/* Dalam bentuk papan Tic-Tac-Toe
   Papan Tic-Tac-Toe berukuran 3x3 dengan setiapnya diisi O, X, atau _*/
{
  // KAMUS LOKAL
  indeks i, j;

  // ALGORITMA
  printf ("\n");
  for (i = 1; i < 3; i++)
  {
    for (j = 1; j < 3; j++)
    {
      printf (" %c |", Elmt(M,i,j));
    }
    printf (" %c \n", Elmt(M,i,3));
    printf ("-----------\n");
  }
  for (j = 1; j < 3; j++)
  {
    printf (" %c |", Elmt(M,i,j));
  }
  printf (" %c \n\n", Elmt(M,i,3));
}

void DrawNext (BOARD *M, int input)
/* Menggambarkan keadaan matriks sementara sebelum direspon oleh komputer */
/* Yaitu dengan mengganti sebuah elemen jika */
{
  Elmt (*M, ((input + 2) / 3), (((input + 2) % 3) + 1)) = 'X';
  TulisMATRIKS (*M);
}
