/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 04 - Dynamic Structures
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : Muhammad Azka Rahadian (13224036)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menyusun rangkaian kargo di stasiun dengan spesifikasi
 *                         insertFirst insertLast deleteNode dan SearchPosByVal
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
typedef node* List;

void insertLast(List *L, int data){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    node *temp=*L;
    //kosong
    if(*L==NULL){
        *L=newNode;
        return;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newNode;
        return;
    }
}

void insertFirst(List *L, int data){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=*L;
    *L = newNode;
}

void deleteNode(List *L, int val){
    if(*L==NULL){
        printf("List kosong\n");
        return;
    }
    node *temp = *L;
    node *prev = NULL;
    //diawal
    if(temp->data == val){
        *L = temp->next;
        free(temp);
        return;
    }
    //cari
    while(temp!=NULL && temp->data != val){
        prev =temp;
        temp =temp->next;
    }
    if(temp==NULL){
        printf("Tidak ditemukan\n");
        return;
    }
    prev->next =temp->next;
    free(temp);
}
void searchPosByVal(List *L, int val){
    node *temp=*L;
    int pos=0;
    while(temp!=NULL){
        if(temp->data==val){
            printf("FOUND %d\n",pos);
            return;
        }
        temp=temp->next;
        pos++;
    }
    printf("NOT FOUND\n");
}
void printList(List L){
    if(L==NULL){
        printf("LIST EMPTY\n");
        return;
    }
    node *temp=L;
    printf("LIST ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main (){
    List L =NULL;
    int q, op, x;
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        scanf("%d", &op);
        scanf("%d", &x);
        if(op==1){
            insertFirst(&L,x);
        }
        if(op==2){
            insertLast(&L,x);
        }
        if(op==3){
            deleteNode(&L,x);
        }
        if(op==4){
            searchPosByVal(&L,x);
        }
    }
    printList(L);
    return 0;
}

/*
REFERENSI :
https://www.geeksforgeeks.org/c/c-program-for-delete-a-linked-list-node-at-a-given-position/
https://www.geeksforgeeks.org/dsa/insert-a-node-at-front-beginning-of-a-linked-list/
https://www.geeksforgeeks.org/dsa/insert-node-at-the-end-of-a-linked-list/
*/
