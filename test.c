#include "types.h"
#include "user.h"

int testExitAndWait(void);
int testWaitPid(void);

// Part d
int main(int argc, char *argv[])
{
    if (atoi(argv[1]) == 1)
    {
        testExitAndWait();
    }
    else if (atoi(argv[1]) == 2)
    {
        testWaitPid();
    }
    exit(0);
    return 0;
}

// Test exit(int status) and wait(int* status)
int testExitAndWait(void)
{
    printf(1, "\nTesting parts a & b starts. Testing exit(int status) and wait(int* status)\n");
    for (int i = 0; i < 5; i++)
    {
        int pid = fork();
        if (pid == 0)
        { // child executed this code
            printf(1, "\nThis is the child with PID# %d and I will exit with status %d\n", getpid(), i);
            exit(i);
        }

        // parent executes this code
        int exitStatus;
        int childPid = wait(&exitStatus);
        printf(1, "\nThis is the parent: child with PID# %d has exited with status %d\n", childPid, exitStatus);
    }
    printf(1, "\nTesting parts a & b ends.\n");
    return 0;
}

// Test waitpid(int pid, int* status, int options)
int testWaitPid(void)
{
    printf(1, "\nTesting Part c starts. Testing waitpid(int pid, int* status, int options)\n");
    int pids[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 5; i++)
    {   // fork 5 procs, children will exit with different exit status(0 to 4).
        pids[i] = fork();
        if (pids[i] == 0)
        { // child executed this code
            printf(1, "\nThis is the child with PID# %d and I will exit with status %d\n", getpid(), i);
            exit(i);
        }
        sleep(10);
    }

    // parent executed this code
    for (int i = 0; i < 5; i++)
    {   // parents wait for a certain child with pids[i] to exit, then print child pid and exit status.
        printf(1, "\nThis is the parent: Now waiting for child with PID# %d\n", pids[i]);
        int exitStatus;
        int childPid = waitpid(pids[i], &exitStatus, 0);
        printf(1, "\nThis is the parent: Child# %d has exited with status %d\n", childPid, exitStatus);
        sleep(10);
    }
    printf(1, "\nTesting Part c ends.\n");
    return 0;
}