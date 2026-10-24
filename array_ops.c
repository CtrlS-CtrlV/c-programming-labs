
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функція для обміну елементів
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Сортування бульбашкою 
void sort_array(int *arr, size_t n) {
    for(size_t i = 0; i < n - 1; i++) {
        for(size_t j = 0; j < n - i - 1; j++) {
            if(*(arr + j) > *(arr + j + 1)) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

// Лінійний пошук через арифметику вказівників
int* my_search(int *arr, size_t n, int key) {
    for(size_t i = 0; i < n; i++) {
        if(*(arr + i) == key) {
            return (arr + i);
        }
    }
    return NULL;
}

void show_arr(int *arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main(void) {
    size_t n;
    printf("Vvedit rozmir masyvu: ");
    if(scanf("%zu", &n) != 1 || n == 0) {
        printf("Pomylka vvodu!\n");
        return 1;
    }

    // Виділення пам'яті
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Pomylkaallocated memory!\n");
        return 1;
    }

    // Заповнення рандомом
    srand(time(NULL));
    for(size_t i = 0; i < n; i++) {
        *(arr + i) = rand() % 100;
    }

    printf("Masiv do sortuvannya:\n");
    show_arr(arr, n);

    sort_array(arr, n);

    printf("Masiv pislya sortuvannya:\n");
    show_arr(arr, n);

    // Пошук
    int target;
    printf("Shukaty chyslo: ");
    if(scanf("%d", &target) == 1) {
        int *res = my_search(arr, n, target);
        if(res != NULL) {
            printf("Znaydeno! Indeks: %ld, adresa: %p\n", res - arr, (void*)res);
        } else {
            printf("Ne znaydeno.\n");
        }
    }

    free(arr);
    return 0;
}
