#include <stdio.h>
#include <stdlib.h>

/*typedef struct { // structure deadline

char day[2];
char month[2];
char year[4];

}Deadline;*/

typedef struct{ //structure task

char title[50];
char description[200];
char deadline [20];
int priority;
int status;

}Task;



 void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= 100) {
        printf("Task limit reached.\n");
        return;
    }

    Task newTask;

    printf("Enter task title: ");
    scanf(" %[^\n]", newTask.title); //%[^\n]-- Read string with spaces

    printf("Enter task description: ");
    scanf(" %[^\n]", newTask.description);

    printf("Enter deadline: ");
    scanf(" %[^\n]", newTask.deadline);

    // Set priority
    printf("Enter priority (0 for low, 1 for high): ");
    scanf("%d", &newTask.priority); // Read priority as integer

    // Set status
    newTask.status = 0; // Initially, set status to 0 (incomplete)

    tasks[*taskCount] = newTask; // Add new task to the array
    (*taskCount)++; // increment +1
}

void displayTasks(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount; i++) {
        printf("------------- Task %d ------------\n", i + 1);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Deadline: %s\n", tasks[i].deadline);
        printf("Priority: %s\n", tasks[i].priority ? "High" : "Low");
        printf("Status: %s\n", tasks[i].status ? "Complete" : "Incomplete");
        printf("--------------------------\n");
    }
}

void Modify(Task tasks[], int taskCount) {
    int choice;
    int index;

    printf("Enter the task number you want to modify ! (1 To %d)", taskCount);
    scanf("%d",&index);

    if(index<0 || index > taskCount){

        printf("Invalid Task number !!\n");
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
                scanf("%s", tasks[index].title);
                break;
            case 2:
                printf("New description: ");
                scanf("%d", tasks[index].description);
                break;
            case 3:
                printf("New deadline: ");
                scanf("%s", tasks[index].deadline);
                break;
            case 4:
                printf("New Priority ( 0 for Low | 1 for High): ");
                scanf("%s", tasks[index].priority);
                break;
            case 5:
                printf("New Status ( 0 for Incompleted | 1 for completed) : ");
                scanf("%s", tasks[index].status);
                break;


            case 6:
                printf("Modification completed!!!\n");
                break;
            default:
                printf("Invalid choice, please try again\n");


        }
    } while (choice != 6);
}



int main()
{
     Task tasks[100];
     int taskCount = 0;
     int doo;
     int indice;



     do {
        printf("what do you want to do?:\n");
        printf("1- Add Task \n");
        printf("2- Display Task \n");
        printf("3- Modify Task \n");
        printf("4-Delete Task \n");
        printf("5-Filter Task \n");
        printf("6-Sort Task \n");
        printf("7-Quit \n");
        scanf("%d", &doo);

        switch (doo) {
            case 1:

           addTask(tasks, &taskCount); // Add new task

                break;

            case 2:

            if (taskCount == 0) {
                    printf("No tasks available.\n");
                } else {
                    displayTasks(tasks, taskCount); //display all tasks
                }

                break;

            case 3:
            if (taskCount == 0) {
                    printf("No tasks available.\n");
                } else {
                     Modify(tasks,taskCount);
}
                break;

            case 4:


            break;

            case 5:


            break;

            case 6:


            break;

            case 7:
                printf("Bye!!");
        }
    } while (doo != 7);


    return 0;
}
