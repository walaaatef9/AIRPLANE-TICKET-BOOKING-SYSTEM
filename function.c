#include "function.h"

void Reserve(List* Pl,int id){

    Node* temp = Pl->pHead;
	while(temp!=NULL){

		if(temp->data.id == id){
			printf("bokking tiket for client with id %d  !!!\n", id);
                int c,p;
                int i;
                int j;
                int s[10]={};
                for (j=0; j<10; j++)
            {
        printf("   Class\n\n   [1] Business Class\n   [2] Economic class\n\n [3] exit");
        printf("   Choose: ");
        scanf("%i",&c);
        //system("cls");
        switch(c)
        {
        case 1:
            printf("   Business class\n\n");
            printf("   Seats available\n     |1|2|3|4|5|\n\n");
            do
            {
                printf("   Pick a seat: ");
                scanf("%i",&p);
                s[j]=p;
                //system("cls");
                for (i=0; i<j; i++)
                {
                    if (s[j]==s[i])
                    {
                        printf("\n\n   Seat taken.\n\n");
                        break;
                    }
                }
            }while (i!=j);

            if(s[j] <= 5)
                {
                    printf("\n");
                    printf("   Class: Business class\n");
                    printf("   Seat no : %i\n",s[j]);
                    temp->data.seat = s[j];
                    strcpy(temp->data.flightClass ,"Business");
                    printf("\n");
                }
                else
                printf("\nWrong number!  No seat for you!\n\n");
            break;
        case 2:
            printf("   Economical class\n\n");
            printf("   Seats available\n    |6|7|8|9|10|\n\n");
            do
            {
                printf("   Pick a seat: ");
                scanf("%i",&p);
                s[j]=p;
                //system("cls");
                for (i=0; i<j; i++)
                {
                    if (s[j]==s[i])
                    {
                        printf("\n\n   Seat taken.\n\n");
                        break;
                    }
                }
            }
            while (i!=j);
                if(s[j] >= 6)
                {
                    printf("\n");
                    printf("   Class: Economical class\n");
                    printf("   Seat no : %i\n",s[j]);
                    temp->data.seat = s[j];
                    strcpy(temp->data.flightClass ,"Economical");

                    printf("\n");
                }
                else
                printf("\nWrong number!  No seat for you!\n\n");
            break;
        case 3:
                return ;
        default:
                break;
        }//end switch case
    }//end counting people*/

		}
		temp = temp->next;
	}

}
void creatList(List *pl){
        pl->pHead = NULL;
        pl->ListSize =0;
}
void scanStruct(Client* s){
                    printf("Enter id: ");
                    scanf("%d", &s->id);
                    fflush(stdin);

                    printf("Enter name: ");
                    fgets(s->name,50,stdin);
                    fflush(stdin);

                    printf("Enter Date of Birth: ");
                    fgets(s->DateofBirth,15,stdin);
                    fflush(stdin);

                    printf("Enter phone number: ");
                    fgets(s->phone,15,stdin);
                    fflush(stdin);

                    printf("Enter address: ");
                    fgets(s->address,100,stdin);
                    fflush(stdin);
}
void main_menu()
{       /* Function to print welcome Message.*/
        welcomeMessage();
        List l;
        Client c;
        Client* e;
        e = &c;
        creatList(&l);
        int choice;
        int id;

        printf("\n\t\t\t1.to insert new client details\n"
               "\n\t\t\t2.to search for client details\n"
               "\n\t\t\t3.to delete client details\n"
               "\n\t\t\t4.to edit client details\n"
               "\n\t\t\t5.to display all clients details\n"
               "\n\t\t\t6.to book flight for client \n"

               );
        do
        {
            printf("\n\t\t\tEnter Choice:\t");
            scanf("%d", &choice);
            fflush(stdin);

            switch (choice)
            {
                case NEW_CLIENT:
                    scanStruct(e);
                    fflush(stdin);
                    insert(&l, e);
                    break;
                case BOOKING:
                    printf("Enter id number to book: ");
                    scanf("%d", &id);
                    fflush(stdin);
                    Reserve(&l, id);
                    break;
                case SEARSH:
                    printf("Enter id number to search: ");
                    scanf("%d", &id);
                    fflush(stdin);
                    search(&l, id);
                    break;
                case DELETE_CLIENT:
                    printf("Enter id number to delete: ");
                    scanf("%d", &id);
                    fflush(stdin);
                    Delete(&l,id);
                    break;
                case EDIT_CLIENT:
                    printf("Enter id number to update: ");
                    scanf("%d", &id);
                    fflush(stdin);
                    update(&l,id);
                    break;
                case CLIENT_LIST:
                    sortList(&l);
                    display(&l);
                    break;
            }

        } while (choice != 0);
}

void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                     TO                    =");
    printf("\n\t\t\t        =               Airline Ticket              =");
    printf("\n\t\t\t        =               Booking  SYSTEM             =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
//The insert Function, that will add a new node to the linked list.
//The insert function accepts cleint details as an argument
void insert(List* Pl,Client* e)
{
    Node* pn;
    pn = (Node *) malloc(sizeof(Node));
    if(pn == NULL){
     printf("Heap is full \n");
     return;
    }
	pn->data.id = e->id;
	strcpy(pn->data.name, e->name);
	strcpy(pn->data.phone, e->phone);
	strcpy(pn->data.address, e->address);
	strcpy(pn->data.DateofBirth, e->DateofBirth);
	pn->next = NULL;

	if(Pl->pHead == NULL){
		// if head is NULL set student as the new head
		// set student as the new head
		Pl->pHead = pn;
	}
	else{
		// if list is not empty
		// insert student in beginning of head
		pn->next = Pl->pHead;
		Pl->pHead = pn;
	}
}
// The search function searches the record based on the id number
// The function traverses all the nodes of the linked list to find the required record.
void search(List* Pl,int id)
{
    Node* temp = Pl->pHead;
	while(temp!=NULL){
		if(temp->data.id == id){
			printf("Id: %d\n", temp->data.id);
			printf("Date of Birth: %s\n", temp->data.DateofBirth);
			printf("Name: %s\n", temp->data.name);
			printf("Phone: %s\n", temp->data.phone);
			printf("Address: %s\n", temp->data.address);
			return;
		}
		temp = temp->next;
	}
	printf("Client with ID %d is not found !!!\n", id);
}
//The update function first searches for the node with the required roll number.
// If the node is found,
//the program asks the user to enter new updated values.
void update(List* Pl, int id)
{
    Node* temp = Pl->pHead;
	while(temp!=NULL){

		if(temp->data.id == id){
			printf("Record with id %d Found !!!\n", id);
			printf("Enter new name: ");
			scanf("%s", temp->data.name);
			printf("Enter new Age: ");
			scanf("%s", temp->data.DateofBirth);
			printf("Enter new phone number: ");
			scanf("%s", temp->data.phone);
			printf("Enter new Address: ");
			scanf("%s",temp->data.address);
			printf("Updating Successful!!!\n");
			return;
		}
		temp = temp->next;

	}
	printf("Client with id %d is not found !!!\n", id);
}
/*
* Delete works similar to search.
* We search for the record by it’s id.
* If the record is found,
* we delete it from the linked list.
*/
void Delete(List* Pl, int id)
{

    Node* temp1 = Pl->pHead;
    Node* temp2 = Pl->pHead;
	while(temp1!=NULL){
		if(temp1->data.id == id){
			printf("Record with id %d Found !!!\n", id);
			if(temp1 == temp2){
				/*
                 * this condition will run if
				 * the record that we need to delete is the first node
				 * of the linked list
				 */
				 Pl->pHead = temp1->next;
				 free(temp1);
			}
			else{
				/*
				 * temp1 is the node we need to delete
				 * temp2 is the node previous to temp1 */

				temp2->next = temp1->next;
				free(temp1);
			}

			printf("Record Successfully Deleted !!!\n");
			return;

		}
		temp2 = temp1;
		temp1 = temp1->next;

	}
	printf("Client with id %d is not found !!!\n", id);

}
/*
* Display function traverse the linked list and print all the details of each node of
* the linked list.
*/
void display(List* Pl)
{
    Node* temp = Pl->pHead;
    while(temp!=NULL){
		printf("\tId: %d\n", temp->data.id);
		printf("\tDate of Birth: %s\n", temp->data.DateofBirth);
		printf("\tName: %s\n", temp->data.name);
		printf("\tPhone: %s\n", temp->data.phone);
		printf("\tAddress: %s\n", temp->data.address);
		printf("seatno: %d\n", temp->data.seat);
		printf("Class: %s\n", temp->data.flightClass);

		temp = temp->next;
	}

}

void swap(Client *A, Client *B){
    Client temp = *A;
    *A = *B;
    *B = temp;
}
void sortList(List* Pl) {
        //Node current will point to head
        Node* current = Pl->pHead;
        Node*index = NULL;
        if(Pl->pHead == NULL) {
            return;
        }
        else {
        while(current != NULL) {
                //Node index will point to node next to current
                index = current->next;
        while(index != NULL) {
                    //If current node's data is greater than index's node data, swap the data between them
                    if(strcmp(current->data.name, index->data.name) > 0 ) {
                            Client*  A = &current->data;
                            Client* B = &index->data;

                        swap(A, B);
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
