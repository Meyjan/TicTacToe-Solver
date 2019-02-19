/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : Board.h
   Topik        : Tugas Besar TBFO
   Tanggal      : 4 Oktober 2018
   Deskripsi    : Bertugas menggambarkan papan tic-tac-toe */

// HEADER dari ADT BOARD a.k.a MATRIKS
#ifndef BOARD_H
#define BOARD_H

#include "boolean.h"
#include "DFA.h"
#include <string.h>

typedef int indeks; /* indeks baris dan kolom dalam Tic-Tac-Toe */
typedef char ElType; /* elemen untuk menampilkan Tic-Tac-Toe */
typedef struct{
  ElType Ele[4][4];
} BOARD;
/* Matriks yang ditampilkan untuk mewakili Tic-Tac-Toe */

// SELEKTOR
#define Elmt(M,i,j) (M).Ele[(i)][(j)]


/* MEMBENTUK BOARD KOSONG Tic-Tac-Toe */
void MakeMATRIKS (BOARD * M);
/* Membentuk sebuah Board TIC TAC TOE "kosong" yang siap diisi berukuran 3 x 3 di "ujung kiri" memori */
/* I.S. tidak ada apa-apa */
/* F.S. Board berbentuk Matriks M berukurn 3x3 terbentuk */


/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (BOARD * M, arrSTATE arrS, int state, boolean CPUFirst);
/* Membaca sebuah state dan string yang dimiliki state tersebut */
/* Lalu memasukannya ke dalam board */

void TulisMATRIKS (BOARD M);
/* Menuliskan matriks yang telah diisi ke dalam layar */
/* Dalam bentuk papan Tic-Tac-Toe
   Papan Tic-Tac-Toe berukuran 3x3 dengan setiapnya diisi O, X, atau _*/

void DrawNext (BOARD *M, int input);
/* Menggambarkan keadaan matriks sementara sebelum direspon oleh komputer */
/* Yaitu dengan mengganti sebuah elemen jika elemen tersebut valid dimasukkan*/

#endif
