#include <stdio.h>
#include <stdlib.h>

typedef struct { // structure deadline
    char day[3];
    char month[3];
    char year[5];
} Deadline;

typedef struct { // structure task
    char title[50];
    char description[200];
    Deadline deadline;
    int priority;
    int status;
} Task;

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= 100) {
        printf("Task limit reached.\n");
        return;
    }

    Task newTask;

    printf("Enter task title: ");
    scanf(" %[^\n]", newTask.title);

    printf("Enter task description: ");
    scanf(" %[^\n]", newTask.description);

    printf("Enter deadline (Day): ");
    scanf(" %[^\n]", newTask.deadline.day);

    printf("Enter deadline (Month): ");
    scanf(" %[^\n]", newTask.deadline.month);

    printf("Enter deadline (Year): ");
    scanf(" %[^\n]", newTask.deadline.year);

    printf("Enter priority (0 for low, 1 for high): ");
    scanf("%d", &newTask.priority);

    newTask.status = 0;

    tasks[*taskCount] = newTask;
    (*taskCount)++;
}

void displayTasks(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount; i++) {
        printf("------------- Task %d ------------\n", i + 1);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Deadline: %s/%s/%s\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
        printf("Priority: %s\n", tasks[i].priority ? "High" : " Low");
        printf("Status: %s\n", tasks[i].status ? "Complete" : " Incomplete");
        printf("--------------------------\n");
    }
}

void Modify(Task tasks[], int taskCount) {
    int choice;
    int index;

    printf("Enter the task number you want to modify (1 to %d): ", taskCount);
    scanf("%d", &index);

    index--;
    if (index < 0 || index >= taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    do {
        printf("What do you want to modify?\n");
        printf("1- Title\n");
        printf("2- Description\n");
        printf("3- Deadline\n");
        printf("4- Priority\n");
        printf("5- Status\n");
        printf("6- Complete the modification\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("New title: ");
                scanf(" %[^\n]", tasks[index].title);
                break;
            case 2:
                printf("New description: ");
                scanf(" %[^\n]", tasks[index].description);
                break;
            case 3:
                printf("New deadline (Day): ");
                scanf("%s", tasks[index].deadline.day);
                printf("New deadline (Month): ");
                scanf("%s", tasks[index].deadline.month);
                printf("New deadline (Year): ");
                scanf("%s", tasks[index].deadline.year);
                break;
            case 4:
                printf("New Priority (0 for Low | 1 for High): ");
                scanf("%d", &tasks[index].priority);
                break;
            case 5:
                printf("New Status (0 for Incomplete | 1 for Complete): ");
                scanf("%d", &tasks[index].status);
                break;
            case 6:
                printf("Modification completed!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    Task tasks[100];
    int taskCount = 0;
    int doo;

    do {
        printf("What do you want to do?\n");
        printf("1- Add Task\n");
        printf("2- Display Task\n");
        printf("3- Modify Task\n");
        printf("4- Delete Task\n");
        printf("5- Filter Task\n");
        printf("6- Sort Task\n");
        printf("7- Quit\n");
        scanf("%d", &doo);

        switch (doo) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                if (taskCount == 0) {
                    printf("No tasks available.\n");
                } else {
                    displayTasks(tasks, taskCount);
                }
                break;
            case 3:
                if (taskCount == 0) {
                    printf("No tasks available.\n");
                } else {
                    Modify(tasks, taskCount);
                }
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (doo != 7);

    return 0;
}
