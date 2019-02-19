/* NIM / Nama   : 13517131 / Jan Meyer Saragih
   Nama file    : DFA.h
   Topik        : Tubes
   Tanggal      : 30 September 2018
   Deskripsi    : Bertugas menyimpan DFA yang dibaca dari file dan menjalankan game */

// HEADER dari ADT DFA
#ifndef DFA_H
#define DFA_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom Tic-Tac-Toe */
#define InvState -999

typedef char STR[10];

// Tipe STATE mengandung state yang ada dan string pengisian Tic-Tac-Toe
typedef struct {
  int state1;
  char string[10];
} STATE;

typedef struct{
  STATE daSTATE[120];
  int Neff1;
} arrSTATE;

// Tipe TRANSISI berisi state dan 9 state tujuan berdasarkan 9 input yang masuk
typedef struct {
  int state2;
  int transition[10];
} TRANSISI;

typedef struct{
  TRANSISI daTRANSISI[120];
  int Neff2;
} arrTRANSISI;

// Tipe StartState berisi integer state yang memulai game
typedef int STARTSTATE;

// Tipe FinalState berisi array integer yang merupakan state-state akhir
typedef struct{
  int winORdraw[100];
  int FinState[100];
  int Neff3;
} FINALSTATE;

typedef struct{
  STATE Record[10];
  int Neff4;
} RECORDSTATE;


// SELEKTOR
#define State1(M,i) (M).daSTATE[(i)].state1
#define String(M,i) (M).daSTATE[(i)].string
#define Neff1(M) (M).Neff1

#define State2(M,i) (M).daTRANSISI[(i)].state2
#define Transition(M,i,j) (M).daTRANSISI[(i)].transition[(j)]
#define Neff2(M) (M).Neff2

#define WD(M,i) (M).winORdraw[(i)]
#define FS(M,i) (M).FinState[(i)]
#define Neff3(M) (M).Neff3

#define RecState(M,i) (M).Record[(i)].state1
#define RecString(M,i) (M).Record[(i)].string
#define Neff4(M) (M).Neff4

// FILE EKSTERNAL SECTTION
void CreateDFAComp (arrSTATE *_State, arrTRANSISI *_Transisi, STARTSTATE *SS, FINALSTATE *FS);
// Membuat DFA jika komputer berjalan duluan

void CreateDFAPlayer (arrSTATE *_State, arrTRANSISI *_Transisi, STARTSTATE *SS, FINALSTATE *FS);
// Membuat DFA jika player berjalan duluan


// DFA CHECKING SECTION
int cariStart (STARTSTATE SS);
// Mencari state yang digunakan untuk memulai game;

int checkFinal (FINALSTATE FS, int state);
// Mengembalikan 1 jika state yang sedang ada merupakan final state dan menang
// Mengembalikan 2 jika state yang sedang ada merupakan final state dan seri
// Mengembalikan 0 jika state bukan merupakan finalstate


// SEARCHING STATE DAN TRANSITION STATE
void SearchString (arrSTATE _States, int state, char *string);
// Mengembalikan string yang dimaksud dari sebuah state

int NextState (arrTRANSISI _Transisi, int state, int alfa);
// Mengembalikan state berikutnya dari state yang dimasuki alfabet

boolean IsNext (arrTRANSISI _Transisi, int state, int alfa);
// Mengembalikan true jika terdapat state lain yang bisa diganti setelah alfabet

boolean IsFinal (FINALSTATE fin, int state);
// Mengembalikan true jika fin merupakan final state

// RECORDING STATES
void SetRecord (RECORDSTATE *RS);
// Megeset Neff4 menjadi 0 karena tidak ada state yang direcord

void RecordStates (RECORDSTATE *RS, arrSTATE _States, int state);
// Menyimpan state-state yang sedang dijalankan oleh program

void ShowStates (RECORDSTATE RS);
// Menampilkan semua state yang disimpan dalam RECORDSTATE

#endif
