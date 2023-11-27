#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void save(char*filename) {
    int n;
    printf("n=");
    scanf("%d", &n);
    if (n < 0) {
        printf("What's wrong with you???\n");
        return;
    }
    anim*arr = (anim*)calloc(n, sizeof(anim));
    for (int i = 0; i < n; i++) {
        printf("name=");
        scanf("%s", arr[i].name);
        printf("age=");
        scanf("%d", &arr[i].age);
        printf("number of children eaten=");
        scanf("%d", &arr[i].numChildEaten);
        
        if (arr[i].age < 0 || arr[i].numChildEaten < 0) {
            printf("What's wrong with you??? Well. Let's start with 2+2 \n");
            free(arr);
            return;
        }
        
    }

    FILE* file = fopen(filename, "wb");
    if(file == NULL) {
        printf("Failed to open the file. Go through the window!\n");
        free(arr);
        return;
    }

    fwrite(arr, sizeof(anim), n, file);
    fclose(file);
    free(arr);
    printf("Info saved successfully.\n");
}

void load(char* filename) {
    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Failed to open the file. Go through the window!\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    int n = fileSize / sizeof(anim);
    fseek(file, 0, SEEK_SET);

    anim* arr = (anim*)malloc(n * sizeof(anim));
    fread(arr, sizeof(anim), n, file);
    fclose(file);

    for (int i = 0; i < n; i++) {
        printf("-------------------\n");
        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Number of children eaten: %d\n", arr[i].numChildEaten);
        printf("-------------------\n");
    }
    free(arr);
}

void search(char* filename, char* searchName) {
    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Failed to open the file. sad\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    int n = fileSize / sizeof(anim);
    fseek(file, 0, SEEK_SET);

    anim* arr = (anim*)malloc(n * sizeof(anim));
    fread(arr, sizeof(anim), n, file);
    fclose(file);

    printf("Search Results:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, searchName) == 0) {
            printf("-------------------\n");
            printf("Name: %s\n", arr[i].name);
            printf("Age: %d\n", arr[i].age);
            printf("Number of children eaten: %d\n", arr[i].numChildEaten);
            printf("-------------------\n");
        }
    }
    free(arr);
}
