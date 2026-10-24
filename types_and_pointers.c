
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    /* Частина 1: Розміри типів даних */
    printf("=== ROZMIRU TYPIV DANYH ===\n");
    printf("char:        %zu bytes\n", sizeof(char));
    printf("short:       %zu bytes\n", sizeof(short));
    printf("int:         %zu bytes\n", sizeof(int));
    printf("long:        %zu bytes\n", sizeof(long));
    printf("long long:   %zu bytes\n", sizeof(long long));
    printf("float:       %zu bytes\n", sizeof(float));
    printf("double:      %zu bytes\n", sizeof(double));
    printf("size_t:      %zu bytes\n", sizeof(size_t));
    printf("int32_t:     %zu bytes\n", sizeof(int32_t));
    printf("uint64_t:    %zu bytes\n", sizeof(uint64_t));
    printf("void*:       %zu bytes\n", sizeof(void *));

    printf("\n=== DIAPAZONY ZNACHEN ===\n");
    printf("CHAR: min = %d, max = %d\n", CHAR_MIN, CHAR_MAX);
    printf("INT:  min = %d, max = %d\n", INT_MIN, INT_MAX);
    printf("LLONG: min = %lld, max = %lld\n", LLONG_MIN, LLONG_MAX);

    printf("\n=== VKAZIVNYKY ===\n");
    int a = 15;
    int *p = &a;

    printf("Znachennya a: %d\n", a);
    printf("Adresa a (&a): %p\n", (void*)&a);
    printf("Znachennya p: %p\n", (void*)p);
    printf("Rozimenuvannya *p: %d\n", *p);

    *p = 777;
    printf("Zminene a cherez *p: %d\n", a);

    printf("\n=== ARYFMETYKA VKAZIVNYKIV ===\n");
    int mas[5] = {5, 10, 15, 20, 25};
    int *ptr_mas = mas;

    for(int i = 0; i < 5; i++) {
        printf("mas[%d] = %d | adres: %p | *(ptr_mas + %d) = %d\n", 
               i, mas[i], (void*)(ptr_mas + i), i, *(ptr_mas + i));
    }

    // Різниця вказівників
    int *p1 = &mas[0];
    int *p2 = &mas[4];
    printf("Riznytsia (p2 - p1): %ld elementiv, bativ: %ld\n", 
           (p2 - p1), (char*)p2 - (char*)p1);

    return 0;
}
