
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main(void) {
    FILE *f = fopen("students.txt", "r");
    if(f == NULL) {
        printf("Ne vdilosya vidkryty file dlya chytannya!\n");
        return 1;
    }

    Student students[100];
    int count = 0;
    char buffer[256];

    // Читаємо файл по рядках
    while(fgets(buffer, sizeof(buffer), f) != NULL) {
        // Видаляємо перенесення рядка
        buffer[strcspn(buffer, "\n")] = 0;
        
        char *token = strtok(buffer, ";");
        if(token != NULL) {
            strcpy(students[count].name, token);
            
            token = strtok(NULL, ";");
            if(token != NULL) students[count].age = atoi(token);
            
            token = strtok(NULL, ";");
            if(token != NULL) students[count].gpa = atof(token);
            
            count++;
        }
    }
    fclose(f);

    printf(" Zpysovano studentiv z faylu: %d\n", count);

    // Рахуємо min, max, avg
    float min = students[0].gpa;
    float max = students[0].gpa;
    float sum = 0;

    for(int i = 0; i < count; i++) {
        if(students[i].gpa < min) min = students[i].gpa;
        if(students[i].gpa > max) max = students[i].gpa;
        sum += students[i].gpa;
    }
    float avg = sum / count;

    // Пишемо звіт у новий файл
    FILE *out = fopen("report.txt", "w");
    if(out == NULL) {
        printf("Pomylka zapysu report.txt!\n");
        return 1;
    }

    fprintf(out, "--- ZVIT USPISHNOSTI ---\n");
    fprintf(out, " Vsiho studentiv: %d\n\n", count);
    
    for(int i = 0; i < count; i++) {
        fprintf(out, "%d. %s | Vik: %d | GPA: %.2f\n", 
                i+1, students[i].name, students[i].age, students[i].gpa);
    }
    
    fprintf(out, "\nStatystyka:\n");
    fprintf(out, "Min GPA: %.2f\n", min);
    fprintf(out, "Max GPA: %.2f\n", max);
    fprintf(out, "Seredniy GPA: %.2f\n", avg);
    
    fclose(out);
    printf("Zvit uspihno sformulovano u fayli report.txt\n");

    return 0;
}
