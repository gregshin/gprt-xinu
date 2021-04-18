#include <xinu.h>

void deadset(void)
{
    pid32 readypid;
    struct procent *prptr;
    struct procent *currptr;
    intmask mask;

    // variable to see if deadline mode is needed
    bool8 dlneeded = FALSE;

    mask = disable();

    // start at the head of the ready list
	readypid = firstid(readylist);
    currptr = &proctab[currpid];


    // walk the ready list
	while(readypid != queuetail(readylist))
	{
		prptr = &proctab[readypid];

        // if there is a process with a deadline, set global flag to TRUE
        if (prptr->prhasdl == TRUE && dlneeded == FALSE)
        {
            dlneeded == TRUE;
        }

        // if the process has a deadline, and the priority is less than the currpid priority
        if(prptr->prhasdl == TRUE && prptr->prprio < currptr->prprio)
        {
            // then set the process priority to currpid's priority
            prptr->prprio = currptr->prprio;

            // then remove from ready queue and insert
            insert(getitem(readypid), readylist, prptr->prprio);
        }

        readypid = queuetab[readypid].qnext;
	}

    // after walking the list, check if deadline mode is still needed
    if (dlneeded == FALSE)
    {
        deadon == FALSE;
    }
    restore(mask);
}