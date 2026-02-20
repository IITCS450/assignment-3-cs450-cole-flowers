#include "types.h"
#include "stat.h"
#include "user.h"

#define ITERATIONS 50000000

void do_work() {
    volatile int i, j; 
    for (i = 0; i < 20000; i++) {
        for (j = 0; j < 20000; j++) {
        }
    }
}

int main(int argc, char *argv[]) {
    int tickets[] = {10, 20, 30};
    int i;
    int pid;

    printf(1, "Starting lottery experiment...\n");

    for (i = 0; i < 3; i++) {
        pid = fork();
        if (pid < 0) {
            printf(1, "Fork failed\n");
            exit();
        } else if (pid == 0) {
            if (settickets(tickets[i]) < 0) {
                printf(1, "settickets failed for child %d\n", i);
                exit();
            }
            
            int start = uptime();
            do_work();
            int end = uptime();
            
            printf(1, "Child %d (Tickets: %d) finished in %d ticks\n", i, tickets[i], end - start);
            exit();
        }
    }

    for (i = 0; i < 3; i++) {
        wait();
    }

    printf(1, "Experiment complete.\n");
    exit();
}