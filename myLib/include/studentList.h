
#define MAX_STR 32
typedef struct {
    char name[MAX_STR];
    char major[MAX_STR];
} StudentType;
typedef struct Node {
    StudentType *data;
    struct Node *next;
} NodeType;
extern void createStudent(char*, char*, StudentType**);
extern void createNode(NodeType**, StudentType*);
extern void printStudent(StudentType*);
extern void freeList(NodeType*);
extern void insertStudent(NodeType**, StudentType*, int);
extern int deleteStudent(NodeType**, char*);
