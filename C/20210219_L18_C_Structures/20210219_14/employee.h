struct experience{
    int years;
    int months;
};

struct employee{
    int id;
    char *name;
    char *middleName;
    char *lastName;
    char *job;
    struct experience experience;
    int pay;
    struct employee *manager;
};

struct experience makeExperience(int years, int months);
struct employee makeEmployee(int id, char *name, char *middleName,
char *lastName, char *job, struct experience experience, int pay);
void fillEmployeeArray(struct employee arr[], int size);
void printEmployees(struct employee arr[], int size);