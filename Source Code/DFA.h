/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : DFA.h
   Topik        : Tugas Besar TBFO
   Tanggal      : 4 Oktober 2018
   Deskripsi    : Bertugas menyimpan DFA yang dibaca dari file dan menjalankan game */

// HEADER dari ADT DFA
#ifndef DFA_H
#define DFA_H

#include "boolean.h"

// Tipe STATE mengandung state, string, list transisi , dan state final pengisian Tic-Tac-Toe
typedef struct {
  char string[10];
  int transition [10];
  int winORdraw;
} STATES;

// Array dari STATE yang menyimpan setiap state yang dibaca dari sebuah file eksternal
typedef struct{
  STATES daSTATE[120];
  int Neff;
} arrSTATE;

// Tipe StartState berisi integer state yang memulai game
typedef int STARTSTATE;

// SELEKTOR
#define String(M,i) (M).daSTATE[(i)].string
#define Transition(M,i,j) (M).daSTATE[(i)].transition[(j)]
#define WD(M,i) (M).daSTATE[(i)].winORdraw
#define Neff(M) (M).Neff

// FILE EKSTERNAL SECTION
void CreateDFA (arrSTATE *_State, STARTSTATE *SS, char* filename);
// Membuat tipe data yang menampung semua informasi mengenai state-state yang ada
// arrSTATE akan menampung state yang ada, stringnya, transisi, dan final state
// STARTSTATE berisi state awal saat memulai game


// DFA CHECKING SECTION
int checkFinal (arrSTATE _State, int state);
// Prekondisi : State yang dimasukkan termasuk Final State
// Mengembalikan 0 jika state belum berada di final state
// Mengembalikan 1 jika state yang sedang ada merupakan final state dan menang
// Mengembalikan 2 jika state yang sedang ada merupakan final state dan seri

boolean IsNext (arrSTATE _State, int state, int alfa);
// Mengembalikan true jika terdapat state lain yang bisa diganti setelah alfabet

boolean IsFinal (arrSTATE _State, int state);
// Mengembalikan true jika state yang dimaksudkan merupakan final state


// SEARCHING STATE DAN TRANSITION STATE
void SearchString (arrSTATE _States, int state, char *string);
// Mengembalikan string yang dimaksud dari sebuah state

int NextState (arrSTATE _States, int state, int alfa);
// Prasyarat : Merupakan alfabet yang memiliki state berikutnya
// Mengembalikan state berikutnya dari state yang dimasuki alfabet

#endif
