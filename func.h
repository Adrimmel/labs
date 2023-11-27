#ifndef func_h
#define func_h

typedef struct {
    char name[20];
    int age;
    int numChildEaten;
} anim;

void save(char* filename);
void load(char* filename);
void search(char* filename, char* searchName);

#endif  // func_h
