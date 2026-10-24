

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char pib[50];
    int age;
    float gpa;
} Student;

// Функція порівняння для qsort 
int cmp(const void *a, const void *b) {
    Student *s1 = (Student*)a;
    Student *s2 = (Student*)b;
    
    if (s2->gpa > s1->gpa) return 1;
    if (s2->gpa < s1->gpa) return -1;
    return 0;
}

int main(void) {
    Student list[MAX];
    int n = 0;

    // Заповнюємо вручну тестовими даними
    strcpy(list[n].pib, "Ivanenko Petро"); list[n].age = 19; list[n].gpa = 4.5; n++;
    strcpy(list[n].pib, "Shevchenko Taras"); list[n].age = 20; list[n].gpa = 4.9; n++;
    strcpy(list[n].pib, "Koval Maria"); list[n].age = 18; list[n].gpa = 4.2; n++;
    strcpy(list[n].pib, "Tkachenko Vasyl"); list[n].age = 21; list[n].gpa = 3.8; n++;
    strcpy(list[n].pib, "Melnyk Olena"); list[n].age = 19; list[n].gpa = 4.7; n++;

    printf("=== SPYSOK STUDENTIV ===\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s, vik: %d, GPA: %.2f\n", i+1, list[i].pib, list[i].age, list[i].gpa);
    }

    // Середній бал групи
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += list[i].gpa;
    }
    printf("\nSeredniy bal grupy: %.2f\n", sum / n);

    // Сортуємо
    qsort(list, n, sizeof(Student), cmp);

    printf("\n=== PISLYA SORTUVANNYA ZA GPA ===\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s — %.2f\n", i+1, list[i].pib, list[i].gpa);
    }

    // Пошук за ім'ям
    char query[50];
    printf("\nVvedit imya dlya poshuku: ");
    getchar(); // очистка буфера
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0; // видалити \n

    int found = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp(list[i].pib, query) == 0) {
            printf("Znaydeno: %s, GPA: %.2f\n", list[i].pib, list[i].gpa);
            found = 1;
            break;
        }
    }
    if(!found) printf("Studenta ne znaydeno.\n");

    return 0;
}
