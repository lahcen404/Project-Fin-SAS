#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structure deadline
typedef struct { 
    char day[3];
    char month[3];
    char year[5];
} Deadline;

// structure task
typedef struct { 
    char title[50];
    char description[200];
    Deadline deadline;
    int priority;
    int status;
} Task;

// Function to check if the date is valid 
 int isValidDate(int day, int month, int year) {
    return (month >= 1 && month <= 12) && (day >= 1 && day <= 31) && (year >= 2024); // Valid MONTH DAY YEAR
}


int addTask(Task tasks[], int taskCount) {
    if (taskCount >= 100) {
        printf("\n    Task limit reached.\n");
        return taskCount;
    }

    Task newTask;

    printf("     Enter task title: ");
    scanf(" %[^\n]", newTask.title);

    printf("     Enter task description: ");
    scanf(" %[^\n]", newTask.description);

    printf("     Enter deadline (Day): ");
    scanf(" %[^\n]", newTask.deadline.day);

    printf("     Enter deadline (Month): ");
    scanf(" %[^\n]", newTask.deadline.month);


    printf("     Enter deadline (Year): ");
    scanf(" %[^\n]", newTask.deadline.year);

    

    printf("     Enter priority (0 for low, 1 for high): ");
    scanf("%d", &newTask.priority);

    newTask.status = 0;

    tasks[taskCount] = newTask;
    taskCount++;
    return taskCount;
}

void displayTasks(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount; i++) {
        printf("    ------------- Task %d ------------\n", i + 1);
        printf("     Title: %s\n", tasks[i].title);
        printf("     Description: %s\n", tasks[i].description);
        printf("     Deadline: %s/%s/%s\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
        printf("     Priority: %s\n", tasks[i].priority ? "High" : " Low");
        printf("     Status: %s\n", tasks[i].status ? "Complete" : " Incomplete");
        printf("    -----------------------------------\n");
    }
}

void ModifyTasks(Task tasks[], int taskCount) {
    int choice;
    int index;
    int isFutureDate = 0;

    printf("\n    Enter the task number you want to modify (1 to %d): ", taskCount);
    scanf("%d", &index);

    index--;
    if (index < 0 || index >= taskCount) {
        printf("\n    Invalid task number!\n");
        return;
    }

    do {
        printf("\n--------What do you want to modify?--------\n");
        printf("\n    1- Title\n");
        printf("    2- Description\n");
        printf("    3- Deadline\n");
        printf("    4- Priority\n");
        printf("    5- Status\n");
        printf("    6- Complete the modification\n");
        printf("    Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("    New title: ");
                scanf(" %[^\n]", tasks[index].title);
                break;
            case 2:
                printf("    New description: ");
                scanf(" %[^\n]", tasks[index].description);
                break;
            case 3:
                printf("    New deadline (Day): ");
                scanf("%s", tasks[index].deadline.day);
                printf("    New deadline (Month): ");
                scanf("%s", tasks[index].deadline.month);
                printf("    New deadline (Year): ");
                scanf("%s", tasks[index].deadline.year);

                 

                break;
            case 4:
                printf("    New Priority (0 for Low | 1 for High): ");
                scanf("%d", &tasks[index].priority);
                break;
            case 5:
                printf("    New Status (0 for Incomplete | 1 for Complete): ");
                scanf("%d", &tasks[index].status);
                break;
            case 6:
                printf("\n    Modification completed!\n");
                break;
            default:
                printf("\n    Invalid choice, please try again.\n");
        }
    } while (choice != 6);
}

int DeleteTasks(Task tasks[], int index, int taskCount) {
    for (int i = index; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    return taskCount;
}

void filterByPriority(Task tasks[], int taskCount, int WPriority) {
    int found = 0;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].priority == WPriority) {
            found = 1;
            printf("    ------------- Task %d ------------\n", i + 1);
            printf("     Title: %s\n", tasks[i].title);
            printf("     Description: %s\n", tasks[i].description);
            printf("     Deadline: %s/%s/%s\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
            printf("     Priority: %s\n", tasks[i].priority ? "High" : "Low");
            printf("     Status: %s\n", tasks[i].status ? "Complete" : "Incomplete");
            printf("    -----------------------------------\n");
        }
    }

    if (!found) {
        printf("\n    No tasks found with the specified priority.\n");
    }
}

void filterByStatus(Task tasks[], int taskCount, int WStatus) {
    int found = 0;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].status == WStatus) {
            found = 1;
            printf("    ------------- Task %d ------------\n", i + 1);
            printf("     Title: %s\n", tasks[i].title);
            printf("     Description: %s\n", tasks[i].description);
            printf("     Deadline: %s/%s/%s\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
            printf("     Priority: %s\n", tasks[i].priority ? "High" : "Low");
            printf("     Status: %s\n", tasks[i].status ? "Complete" : "Incomplete");
            printf("    -----------------------------------\n");
        }
    }

    if (!found) {
        printf("\n    No tasks found with the specified status.\n");
    }
}

void saveTasksToFile(Task tasks[], int taskCount) {
    FILE *file = fopen("tasks.txt", "w"); 


    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "Title: %s\n", tasks[i].title);
        fprintf(file, "Description: %s\n", tasks[i].description);
        fprintf(file, "Deadline: %s/%s/%s\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
        fprintf(file, "Priority: %s\n", tasks[i].priority ? "High" : "Low");
        fprintf(file, "Status: %s\n", tasks[i].status ? "Complete" : "Incomplete");
        fprintf(file, "-----------------------------------\n");
    }

    fclose(file); 
    printf("Tasks saved Successfully !!\n");
}

int main() {
    printf("\n  ----------- _ OneHand _ -----------  \n ");
    Task tasks[100];
    int taskCount = 0;
    int doo;
    int priority;
    int status;
    int typeFilter;

    do {
        printf("\n         What do you want to do?\n");
        printf("\n    1- Add Task\n");
        printf("    2- Display Task\n");
        printf("    3- Modify Task\n");
        printf("    4- Delete Task\n");
        printf("    5- Filter Task\n");
        printf("    6- Save Tasks in File.txt \n");
        printf("    7- Quit\n");
        scanf("%d", &doo);

        switch (doo) {
            case 1:
                taskCount = addTask(tasks, taskCount);
                saveTasksToFile(tasks, taskCount);
                break;
            case 2:
                if (taskCount == 0) {
                    printf("    No tasks available.\n");
                } else {
                    displayTasks(tasks, taskCount);
                }
                break;
            case 3:
                if (taskCount == 0) {
                    printf("\n    No tasks available.\n");
                } else {
                    ModifyTasks(tasks, taskCount);
                    saveTasksToFile(tasks, taskCount);
                }
                break;
            case 4:
                if (taskCount == 0) {
                    printf("\n    No tasks available.\n");
                } else {
                    int index;
                    printf("\n    Enter index of task you want to delete (1 To %d) : ", taskCount);
                    scanf("%d", &index);
                    if (index >= 1 && index <= taskCount) {
                        taskCount = DeleteTasks(tasks, index - 1, taskCount);
                        saveTasksToFile(tasks, taskCount);
                        printf("    Task Deleted Successfully !! \n");
                    } else {
                        printf("    Invalid index.\n");
                    }
                }
                break;
            case 5:
                if (taskCount == 0) {
                    printf("\n    No tasks available.\n");
                } else {
                    printf("\n -  Filter by : \n");
                    printf("\n 1-  Priority \n");
                    printf(" 2-  Status \n");
                    scanf("%d", &typeFilter);

                    if (typeFilter == 1) {
                        printf("\n    Enter priority to filter by (0 for Low, 1 for High): ");
                        scanf("%d", &priority);
                        if (priority < 0 || priority > 1) {
                            printf("\n    Invalid priority.\n");
                        } else {
                            filterByPriority(tasks, taskCount, priority);
                        }
                    } else if (typeFilter == 2) {
                        printf("\n    Enter status to filter by (0 for Incomplete, 1 for Complete): ");
                        scanf("%d", &status);
                        if (status < 0 || status > 1) {
                            printf("\n    Invalid status.\n");
                        } else {
                            filterByStatus(tasks, taskCount, status);
                        }
                    } else {
                        printf("    Invalid choice.\n");
                    }
                }
                break;

                 case 6:
                saveTasksToFile(tasks, taskCount);
                printf("Tasks saved to file.\n");
                break;
                
            case 7:
                printf("\n    Good Bye!!!\n");
                break;
            default:
                printf("    Invalid choice. Please try again.\n");
        }
    } while (doo != 7);

    return 0;
}
