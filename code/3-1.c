#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[100];
    int score;
};

struct Node {
    struct Student data;
    struct Node *next;
};

struct StudentList {
    struct Node *head;
};

struct StudentList sl = {NULL};

void add(char name[100], int score){
    struct Student newStu;
    strcpy(newStu.name, name);
    newStu.score = score;

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newStu;
    newNode -> next = NULL;

    if(sl.head == NULL){
        sl.head = newNode;
        return;
    }

    struct Node *curr = sl.head;
    while(curr -> next != NULL)
        curr = curr -> next;
    curr -> next = newNode;
}

void delete(char name[100]){
     struct Node *curr = sl.head;
     struct Node *prev = NULL;
     while(curr != NULL){
        struct Student del;
        strcpy(del.name, curr -> data.name);
        if(strcmp(del.name, name) == 0){
            if(prev == NULL)
                sl.head = curr -> next;
            else
                prev -> next = curr -> next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr -> next;
     }
}

void print(){
    struct Node *curr = sl.head;
    while(curr != NULL){
        printf("%s %d\n", curr -> data.name, curr -> data.score);
        curr = curr -> next;
    }
}

void quit(){
    struct Node *curr = sl.head;
    struct Node *tmp;
    while(curr != NULL){
        tmp = curr -> next;
        free(curr);
        curr = tmp;
    }
    sl.head = NULL;
}

int main(){
    char command[20];
    char name[100];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } 
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        } 
        else if (strcmp(command, "print") == 0) {
            print();
        } 
        else {
            quit(); 
            break;
        } 
    }

    return 0;
}