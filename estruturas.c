#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/* Defining comparator function as per the requirement*/
int myCompare(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

/* Function to sort the array*/
void sort(char* arr[], int n)
{
    qsort(arr, n, sizeof(const char*), myCompare);
}


int binarySearch(char** arr, char* x,int n)
   {
      int l = 0 ;
       int r = n - 1;
       int m ; int res=-1;
       while (l <= r)
       {
           m = l + (r - l) / 2;


       if (strcmp(x,arr[m])==0)
         res = 0;


           /* Check if x is present at mid*/
           if (res == 0)
               return m;

           /* If x greater, ignore left half*/
           if (strcmp(x,arr[m])>0)
               l = m + 1;

           /* If x is smaller, ignore right half*/
           else
               r = m - 1;
       }

       return res;
   }


/*
#define LEFT 1
#define BAL 0
#define RIGHT -1


typedef struct avl {
  int bal;
  char* key;
  struct avl *left, *right;
} *AVLTree;


int lookup(AVLTree a, int k){
  int found=1;

}


int lookup (BST a , int k , int ∗i ){
int found = 1 ;
while ( a!=NULL && a−>key != k )
if ( a−>key > k ) a = a−>left ;
else a = a−>right ;
if ( a!=NULL) ∗i=a−>info ;
else found =0;
return fount;
}


AVLTree updateAVLRec (AVLTree a, char* k, int*g, int *u);


int updateAVL (AVLTree *a, char* k){
  int g, u;
  *a=updateAVLRec(*a, k, &g, &u);
  return u;
}

AVLTree rotateRight (AVLTree a){
AVLTree b = a->left;
a->left= b->right;
b->right=a;
return b;
}


AVLTree rotateLeft (AVLTree b){
AVLTree a = b->right;
b->right= a->left;
a->left=b;
return a;
}


AVLTree fixRight (AVLTree a) {
  AVLTree b,c;
  b=a->right;
  if (b->bal == RIGHT) {
    a->bal=b->bal=BAL;
    a=rotateLeft(a);
  } else {
    c=b->left;
    switch (c->bal) {
      case LEFT: a->bal=BAL;
      b->bal=RIGHT;
      break;
      case RIGHT: a->bal =LEFT;
      b->bal =BAL;
      break;
      case BAL: a->bal =b->bal=BAL;
    }
    c->bal =BAL;
    a->right = rotateRight(b);
    a=rotateLeft(a);
  }
  return a;
}



AVLTree fixLeft (AVLTree a) {
  AVLTree b,c;
  b=a->left;
  if (b->bal == LEFT) {
    a->bal=b->bal=BAL;
    a=rotateRight(a);
  } else {
    c=b->right;
    switch (c->bal) {
      case LEFT: a->bal=RIGHT;
      b->bal=BAL;
      break;
      case RIGHT: a->bal =BAL;
      b->bal =LEFT;
      break;
      case BAL: a->bal =b->bal=BAL;
    }
    c->bal =BAL;
    a->left = rotateLeft(b);
    a=rotateRight(a);
  }
  return a;
}


AVLTree updateAVLRec (AVLTree a, char* k, int*g, int *u){
if (a==NULL) {
  a=malloc (sizeof (struct avl));
  a->key=k; a->bal=BAL;
  a->left =a->right=NULL;
  *g=1; *u=1;
} else if (a->key ==k){
  *g=0; *u=1;
} else if(a->key > k) {
  a->left = updateAVLRec(a->left, k, g, u);
  if(*g ==1)
  switch (a->bal) {
    case LEFT: a= fixLeft(a); *g=0; break;
    case BAL: a->bal =LEFT; break;
    case RIGHT: a->bal =BAL; *g=0; break;
  }
}else {
  a->right= updateAVLRec(a->right, k, g, u);
  if(*g==1)
  switch (a->bal) {
    case RIGHT: a= fixRight(a); *g=0; break;
    case BAL: a->bal =RIGHT; break;
    case LEFT: a->bal =BAL; *g=0; break;
  }
}
return a;
}
*/
