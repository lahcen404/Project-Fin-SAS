#include <stdio.h>
#include <stdlib.h>

// structure deadline
typedef struct { 
    int day;
    int month;
    int year;
} Deadline;

// structure task
typedef struct { 
    char title[50];
    char description[200];
    Deadline deadline;
    int priority;
    int status;
} Task;
// Function add task
int addTask(Task tasks[], int taskCount) {
    if (taskCount >= 100) {   // Check if task limit is reached
        printf("\n    Task limit reached.\n");
        return taskCount;   // Return current task count
    }

    Task newTask;   // Create a new task variable

    printf("     Enter task title: ");
    scanf(" %[^\n]", &newTask.title);

    printf("     Enter task description: ");
    scanf(" %[^\n]", &newTask.description);

    // Input valid day
    do {
        printf("     Enter deadline (Day): ");
        scanf("%d", &newTask.deadline.day);

        if (newTask.deadline.day < 1 || newTask.deadline.day > 31) {
            printf("     Invalid day. Enter a valid day (1-31).\n");
        }
    } while (newTask.deadline.day < 1 || newTask.deadline.day > 31);

    // Input valid month
    do {
        printf("     Enter deadline (Month): ");
        scanf("%d", &newTask.deadline.month);

        if (newTask.deadline.month < 1 || newTask.deadline.month > 12) {
            printf("     Invalid month. Enter a valid month (1-12).\n");
        }
    } while (newTask.deadline.month < 1 || newTask.deadline.month > 12);

    // Input valid year
    do {
        printf("     Enter deadline (Year): ");
        scanf("%d", &newTask.deadline.year);

        if (newTask.deadline.year < 2024) {
            printf("     Invalid year. Enter a year bigger from 2024 \n");
        }
    } while (newTask.deadline.year < 2024);

    printf("     Enter priority (0 for low, 1 for high): ");
    scanf("%d", &newTask.priority);

    newTask.status = 0; // Initialize status to 0 = incomplete

    tasks[taskCount] = newTask;  // Add the new task to the tasks array
    taskCount++; //Increment
    return taskCount;  // Return updated task count
}
// function Display task
void displayTasks(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount; i++) {
        printf("    ------------- Task %d ------------\n", i + 1);
        printf("     Title: %s\n", tasks[i].title);
        printf("     Description: %s\n", tasks[i].description);
        printf("     Deadline: %02d/%02d/%d\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
        printf("     Priority: %s\n", tasks[i].priority ? "High" : "Low");
        printf("     Status: %s\n", tasks[i].status ? "Complete" : "Incomplete");
        printf("    -----------------------------------\n");
    }
}

// Function Modify task
void ModifyTasks(Task tasks[], int taskCount) {
    int choice;
    int index;

    printf("\n    Enter the task number you want to modify (1 to %d): ", taskCount);
    scanf("%d", &index);

    index--; // Convert to 0 based index
    if (index < 0 || index >= taskCount) { // Check if index is valid
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

// Switch case to handle modification options

        switch (choice) {
            case 1:
                printf("    New title: ");
                scanf(" %[^\n]", &tasks[index].title);
                break;
            case 2:
                printf("    New description: ");
                scanf(" %[^\n]", &tasks[index].description);
                break;
            case 3:
                do {
        printf("     New deadline (Day): ");
        scanf("%d", &tasks[index].deadline.day);

            //Check valid Day
        if (tasks[index].deadline.day < 1 || tasks[index].deadline.day > 31) {
            printf("     Invalid day. Enter a valid day (1-31)\n");
        }
    } while (tasks[index].deadline.day < 1 || tasks[index].deadline.day > 31);

    
    do {
        printf("     New deadline (Month): ");
        scanf("%d", &tasks[index].deadline.month);
            //Check valid Month
        if (tasks[index].deadline.month < 1 || tasks[index].deadline.month > 12) {
            printf("     Invalid month. Enter a valid month (1-12)\n");
        }
    } while (tasks[index].deadline.month < 1 || tasks[index].deadline.month > 12);

    
    do {
        printf("     New deadline (Year): ");
        scanf("%d", &tasks[index].deadline.year);
            //Check valid Year
        if (tasks[index].deadline.year < 2024) {
            printf("     Invalid year. Enter a year bigger from 2024 \n");
        }
    } while (tasks[index].deadline.year < 2024); //Repeated loop as long as the years less than 2024
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

// Function Delete task
int DeleteTasks(Task tasks[], int index, int taskCount) {
    for (int i = index; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    return taskCount;
}

// Function Filter by priority 
void filterByPriority(Task tasks[], int taskCount, int WPriority) {
    int found = 0;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].priority == WPriority) {
            found = 1;
            printf("    ------------- Task %d ------------\n", i + 1);
            printf("     Title: %s\n", tasks[i].title);
            printf("     Description: %s\n", tasks[i].description);
            printf("     Deadline: %02d/%02d/%d\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
            printf("     Priority: %s\n", tasks[i].priority ? "High" : "Low");
            printf("     Status: %s\n", tasks[i].status ? "Complete" : "Incomplete");
            printf("    -----------------------------------\n");
        }
    }

    if (!found) {
        printf("\n    No tasks found with the specified priority.\n");
    }
}

// Function Filter by status 
void filterByStatus(Task tasks[], int taskCount, int WStatus) {
    int found = 0;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].status == WStatus) {
            found = 1;
            printf("    ------------- Task %d ------------\n", i + 1);
            printf("     Title: %s\n", tasks[i].title);
            printf("     Description: %s\n", tasks[i].description);
            printf("     Deadline: %02d/%02d/%d\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
            printf("     Priority: %s\n", tasks[i].priority ? "High" : "Low");
            printf("     Status: %s\n", tasks[i].status ? "Complete" : "Incomplete");
            printf("    -----------------------------------\n");
        }
    }

    if (!found) {
        printf("\n    No tasks found with the specified status.\n");
    }
}

// Function Save Tasks to file.txt
void saveTasksToFile(Task tasks[], int taskCount) {
    FILE *file = fopen("Tasks.txt", "w"); 

    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "---------------Task %d-------------\n",i+1);
        fprintf(file, "Title: %s\n", tasks[i].title);
        fprintf(file, "Description: %s\n", tasks[i].description);
        fprintf(file, "Deadline: %02d/%02d/%d\n", tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year);
        fprintf(file, "Priority: %s\n", tasks[i].priority ? "High" : "Low");
        fprintf(file, "Status: %s\n", tasks[i].status ? "Complete" : "Incomplete");
        fprintf(file, "-----------------------------------\n");
    }

    fclose(file); 
    printf("Tasks saved Successfully !!\n");
}

void SortByAscendingDate(Task tasks[], int taskCount)
{
    for (int i = 0; i < taskCount; i++)           //sorting tasks (ascending)
    {
        int indexMin = i; // 0
        for (int j = i + 1; j < taskCount; j++) // 2
        {
            if (tasks[indexMin].deadline.year > tasks[j].deadline.year ||
                tasks[indexMin].deadline.year == tasks[j].deadline.year && 
                tasks[indexMin].deadline.month > tasks[j].deadline.month ||
                tasks[indexMin].deadline.month == tasks[j].deadline.month && 
                tasks[indexMin].deadline.day > tasks[j].deadline.day)
            {
                indexMin = j;
            } 
            Task temp = tasks[indexMin];
            tasks[indexMin] = tasks[i];
            tasks[i] = temp;
        }
    }

    printf("Tasks ordered by ascending date\n");
    printf("--------------------------------------------\n");
}


void SortByDescendingDate(Task tasks[], int taskCount)
{
    for (int i = 0; i < taskCount; i++)           //sorting tasks (Descending)
    {
        int indexMin = i; 
        for (int j = i + 1; j < taskCount; j++) 
        {
            if (tasks[indexMin].deadline.year < tasks[j].deadline.year ||
                tasks[indexMin].deadline.year == tasks[j].deadline.year && 
                tasks[indexMin].deadline.month < tasks[j].deadline.month ||
                tasks[indexMin].deadline.month == tasks[j].deadline.month && 
                tasks[indexMin].deadline.day < tasks[j].deadline.day)
            {
                indexMin = j;
            } 
            Task temp = tasks[indexMin];
            tasks[indexMin] = tasks[i];
            tasks[i] = temp;
        }
    }

    printf("Tasks ordered by ascending date\n");
    printf("--------------------------------------------\n");
}

int main() {
    printf("\n  -----------------------------------  \n ");
    printf("\n  ----------- * OneHand * -----------  \n ");
    printf("\n  -----------------------------------  \n ");
    Task tasks[100];
    int taskCount = 0;
    int doo;
    int priority;
    int status;
    int typeFilter;

    do {
        //Menu

        printf("\n         What do you want to do?\n");
        printf("\n    1- Add Task\n");
        printf("    2- Display Task\n");
        printf("    3- Modify Task\n");
        printf("    4- Delete Task\n");
        printf("    5- Filter Task\n");
        printf("    6- Save Tasks in File.txt \n");
        printf("    7- Sort By Ascending Deadline \n");
        printf("    8- Sort By Descending Deadline \n");
        printf("    9- Quit\n");
        scanf("%d", &doo);

        switch (doo) {
            case 1:
                taskCount = addTask(tasks, taskCount); //Call AddTask Function

                break;
            case 2:
                if (taskCount == 0) {
                    printf("    No tasks available.\n");
                } else {
                    displayTasks(tasks, taskCount); //Call DisplayTask Function

                }
                break;
            case 3:
                if (taskCount == 0) {
                    printf("    No tasks available.\n"); 
                } else {
                    ModifyTasks(tasks, taskCount); //Call ModifyTask Function
                    
                }
                break;
            case 4:
                if (taskCount == 0) {
                    printf("    No tasks available.\n");
                } else {
                    int index;
                    printf("    Entre 0 to cancel deleting \n");
                    printf("\n    Enter the task number to delete (1 to %d): ", taskCount);
                    scanf("%d", &index);
                    index--;
                    if (index < 0 || index >= taskCount) {
                        printf("\n    Invalid task number!\n");
                    } else {
                        taskCount = DeleteTasks(tasks, index, taskCount); //Call DeleteTask Function
                        
                        printf("    Task deleted successfully.\n");
                    }
                }
                break;
            case 5:
                if (taskCount == 0) {
                    printf("    No tasks available.\n");
                } else {
                    printf("\n    1- Filter by priority\n");
                    printf("    2- Filter by status\n");
                    printf("    Enter your choice: ");
                    scanf("%d", &typeFilter);

                    if (typeFilter == 1) {
                        printf("\n    Enter priority level (0 for Low | 1 for High): ");
                        scanf("%d", &priority);
                        filterByPriority(tasks, taskCount, priority); //Call FilterByPriority function
                    } else if (typeFilter == 2) {
                        printf("\n    Enter status level (0 for Incomplete | 1 for Complete): ");
                        scanf("%d", &status);
                        filterByStatus(tasks, taskCount, status); //Call FilterByStatus function
                    } else {
                        printf("    Invalid filter type.\n");
                    }
                }
                break;
            case 6:
            if (taskCount == 0) {
                    printf("    No tasks available.\n");
                } else {
                saveTasksToFile(tasks, taskCount);  //Call Save tasks to file function
                }
                break;

            case 7:
                if (taskCount == 0) {
                    printf("    No tasks available.\n");
                } else {
                SortByAscendingDate(tasks, taskCount);
                displayTasks(tasks, taskCount);
                }

            break;   

            case 8:
                if (taskCount == 0) {
                    printf("    No tasks available.\n");
                } else {
                SortByDescendingDate(tasks, taskCount);
                 displayTasks(tasks, taskCount);

                }
                break;
            case 9:
                printf("\n    Good Bye!!! \n");
                break;
            default:
                printf("\n    Invalid choice, please try again.\n");
        }
    } while (doo != 9);

    return 0;
}
