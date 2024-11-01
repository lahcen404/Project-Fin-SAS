
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