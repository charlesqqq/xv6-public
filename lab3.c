#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int priority = atoi(argv[1]);
    printf(1, "Process# %d starts, set priority to %d.\n", getpid(), priority);
    setPriority(priority);
    int limit = 50000;
    for (int i = 0; i < limit; i++)
    {
        for (int j = 0; j < limit; j++)
        {
            asm("nop");
        }
    }
    printf(1, "Process# %d finished, initial priority was %d.\n", getpid(), priority);
    printPerformance();
    exit(0);
    return 0;
}
