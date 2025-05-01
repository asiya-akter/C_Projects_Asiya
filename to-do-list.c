#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

// Function to display the menu options
void showMenu() {
    printf("\n********** To-Do List **********\n");
    printf("1. Add a Task\n");
    printf("2. Remove a Task\n");
    printf("3. View All Tasks\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

// Function to add a new task
void addTask(char tasks[MAX_TASKS][MAX_LENGTH], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full! You can't add more tasks.\n");
    } else {
        printf("Enter the task description: ");
        getchar();
        fgets(tasks[*taskCount], MAX_LENGTH, stdin);  // Get the task description
        tasks[*taskCount][strcspn(tasks[*taskCount], "\n")] = '\0';
        (*taskCount)++;
        printf("Task added successfully!\n");
    }
}

// Function to remove an existing task
void removeTask(char tasks[MAX_TASKS][MAX_LENGTH], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks available to remove.\n");
    } else {
        int taskNum;
        printf("Enter the task number to remove (1 to %d): ", *taskCount);
        scanf("%d", &taskNum);

        if (taskNum < 1 || taskNum > *taskCount) {
            printf("Invalid task number.\n");
        } else {

            for (int i = taskNum - 1; i < *taskCount - 1; i++) {
                strcpy(tasks[i], tasks[i + 1]);
            }
            (*taskCount)--;
            printf("Task removed successfully!\n");
        }
    }
}


void viewTasks(char tasks[MAX_TASKS][MAX_LENGTH], int taskCount) {
    if (taskCount == 0) {
        printf("Your To-Do List is empty.\n");
    } else {
        printf("\nYour To-Do List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }
}

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int taskCount = 0;
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                removeTask(tasks, &taskCount);
                break;
            case 3:
                viewTasks(tasks, taskCount);
                break;
            case 4:
                printf("Exiting To-Do List. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}
