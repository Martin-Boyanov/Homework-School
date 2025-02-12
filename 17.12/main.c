#include <stdio.h>
#include "processes.h"

int main(void)
{
    while (1) {
        printf("\n===== Task Manager =====\n");
        printf("1. Start a process\n");
        printf("2. List of all processes\n");
        printf("3. Stop a process\n");
        printf("4. Exit\n");
        printf("Choose option: ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice!\n");
            int cc;
            while ((cc = getchar()) != '\n' && cc != EOF) {}
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (choice == 1) {
            char name[MAX_PROCESS_NAME];
            printf("Name of the process(no spaces): ");
            if (scanf("%30s", name) == 1) {
                unsigned int pid = createnewprocess(name);
                if (pid == 0) {
                    printf("Unsuccessful creation of process! "
                           "Limit is reached or too much IDs.\n");
                } else {
                    printf("Made a new process with ID: %u\n", pid);
                }
            } else {
                printf("Invalid name!\n");
            }

            while ((c = getchar()) != '\n' && c != EOF) {}

        } else if (choice == 2) {
            printf("\nProcesses:\n");
            listprocesses();
        } else if (choice == 3) {
            unsigned int pid;
            printf("ID of the wanted process: ");
            if (scanf("%u", &pid) != 1) {
                printf("Invalid ID!\n");
            } else {
                stopprocess(pid);
            }
            while ((c = getchar()) != '\n' && c != EOF) {}

        } else if (choice == 4) {
            printf("Exit.\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}