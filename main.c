#include <stdio.h> 
#include <stdlib.h> 

// Deklarasi struct tnode yang memiliki data bertipe integer
// struct tnode adalah single linked list
struct tnode {
    int data; // Data bertipe integer
    struct tnode *next; // Pointer ke node berikutnya
};

// Prosedur untuk menyisipkan "bil" di akhir single linked-list
void insertLast(int bil, struct tnode **head, struct tnode **tail) {
    struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode)); // Alokasi memori untuk node baru
    if (newNode == NULL) { // Jika alokasi memori gagal
        printf("Alokasi memori gagal"); // Tampilkan pesan error
        exit(1); // Keluar dari program
    } else {
        newNode->data = bil; // Set data node baru
        newNode->next = NULL; // Set next node baru ke NULL
        if (*head == NULL) { // Jika linked list kosong
            *head = *tail = newNode; // Set head dan tail ke node baru
        } else {
            (*tail)->next = newNode; // Set next dari tail ke node baru
            *tail = newNode; // Set tail ke node baru
        }
    }
}

// Prosedur untuk menyisipkan "bil" di awal single linked-list
void insertFirst(int bil, struct tnode **head, struct tnode **tail) {
    struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode)); // Alokasi memori untuk node baru
    if (newNode == NULL) { // Jika alokasi memori gagal
        printf("Alokasi memori gagal"); // Tampilkan pesan error
        exit(1); // Keluar dari program
    } else {
        newNode->data = bil; // Set data node baru
        newNode->next = *head; // Set next node baru ke head saat ini
        if (*head == NULL) { // Jika linked list kosong
            *head = *tail = newNode; // Set head dan tail ke node baru
        } 
        *head = newNode; // Set head ke node baru
    }
}

// Prosedur untuk menampilkan nilai single linked-list dari awal ke akhir
void printLinkedList(struct tnode *head) {
    struct tnode *temp = head; // Pointer sementara untuk traversal
    while (temp != NULL) { // Selama belum mencapai akhir linked list
        printf("%d ", temp->data); // Tampilkan data node saat ini
        temp = temp->next; // Pindah ke node berikutnya
        if (temp != NULL) { // Jika belum mencapai akhir
            printf(" -> "); // Tampilkan panah
        }
    }
    printf("\n"); // Baris baru setelah selesai menampilkan linked list
}

int main() {
    struct tnode *head, *tail; // Deklarasi pointer head dan tail
    head = NULL; // Inisialisasi head ke NULL
    tail = NULL; // Inisialisasi tail ke NULL

    insertFirst(10, &head, &tail); // Sisipkan 10 di awal linked list
    insertFirst(20, &head, &tail); // Sisipkan 20 di awal linked list
    insertFirst(30, &head, &tail); // Sisipkan 30 di awal linked list

    insertLast(40, &head, &tail); // Sisipkan 40 di akhir linked list
    insertLast(50, &head, &tail); // Sisipkan 50 di akhir linked list
    insertLast(60, &head, &tail); // Sisipkan 60 di akhir linked list

    printLinkedList(head); // Tampilkan linked list
    return 0; // Kembalikan 0 untuk menandakan program selesai dengan sukses
}
