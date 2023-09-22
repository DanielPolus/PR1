#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Student {
    char name[10];
    char surname[15];
    int age;
    char sex;
    char department[30];
    int course;
};

typedef struct node {
    Student stud;
    struct node* next;
} node_t;


int main()
{

    int choice;
    node_t* head = NULL;
    node_t* current = NULL;
    head = (node_t*) malloc(sizeof(node_t));
    head->next = NULL;

    if (head == NULL) {
        return 1;
    }

    Student stud;
    char* pos;

    while (1) {
        printf("\nChoose Action:\n1 - Add student\n2 - Show list\n3 - Exit\n");

        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            current = head;

            while (current->next != NULL) {
                current = current->next;
            }

            printf("Write name: ");
            getchar();
            fgets(current->stud.name, 10, stdin);
            if ((pos = strchr(current->stud.name, '\n')) != NULL) {
                *pos = '\0';
            }

            printf("Write surname: ");
            fgets(current->stud.surname, 15, stdin);
            if ((pos = strchr(current->stud.surname, '\n')) != NULL) {
                *pos = '\0';
            }

            printf("Write age: ");
            scanf_s("%d", &current->stud.age);

            getchar();
            printf("Write sex: ");
            scanf_s("%c", &current->stud.sex);
            getchar();

            printf("Write department: ");
            fgets(current->stud.department, 20, stdin);
            if ((pos = strchr(current->stud.department, '\n')) != NULL) {
                *pos = '\0';
            }

            printf("Write course: ");
            scanf_s("%d", &current->stud.course);
            
            current->next = (node_t*)malloc(sizeof(node_t));
            current->next->next = NULL;

            printf("\nname: %s | surname: %s | age: %d | sex: %c | department: %s | course:%d\n",
                current->stud.name, current->stud.surname, current->stud.age, current->stud.sex, current->stud.department, current->stud.course);
            
            break;
        case 2:
            current = head;
            while (current->next != NULL) {
                printf("\nname: %s | surname: %s | age: %d | sex: %c | department: %s | course:%d",
                    current->stud.name, current->stud.surname, current->stud.age, current->stud.sex, current->stud.department, current->stud.course);
                
                current = current->next;
            }
            printf("\n");
            break;
        case 3:
            while (head->next != NULL) {
                current = head;
                while (current->next != NULL) {
                    free(current->next);
                    current->next = NULL;
                }
            }
            free(head);
            return 0;
        default: 
            printf("Invalid input\n");
            break;
        }
    }

    return 0;
}
