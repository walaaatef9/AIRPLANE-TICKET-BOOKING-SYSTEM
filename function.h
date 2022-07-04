#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define NEW_CLIENT 1
#define SEARSH 2
#define DELETE_CLIENT 3
#define EDIT_CLIENT 4
#define CLIENT_LIST 5
#define BOOKING 6

// create a structure to store Client data.
typedef struct client{
	unsigned int id;
	char name[50];
	char phone[15];
	char address[100];
	char DateofBirth[15];
	char flightClass[10] ;
	int seat;
}Client;

typedef struct node{
 Client data;
 struct node* next;

}Node;

typedef struct mylist{
  Node *pHead;
  //ListNode *pTail;
  unsigned int ListSize;
}List;
//Prototype of  functions
void booking(List* ,int );
void sortList(List* );
void scanStruct(Client* );
void creatList(List*);
void welcomeMessage();
void main_menu();
void insert(List*,Client*);
void sortList();
void Delete(List* , int );
void update(List* , int );
void search(List*,int );
void display(List* );
//void sortList(List* );
#endif // FUNCTION_H_INCLUDED
