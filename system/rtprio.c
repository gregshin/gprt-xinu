#include <xinu.h>

void rtprio(pid32 pid)
{
    intmask 	mask;    	/* interrupt mask		*/
    
    struct procent *procptr;
    struct procent *currptr;

    // disable mask because we don't want this to be interrupted and we don't want the ready list to change in the middle
    mask = disable();

    procptr = &proctab[pid];
    currptr = &proctab[currpid];

    // return error if process is not deadline enabled
    if (procptr->prhasdl == FALSE)
    {
        return SYSERR;
    }

    if (procptr->prdl <= 0)
    {
        chprio(pid, currptr->prprio + 1);
    }
    else
    {
        chprio(pid, currptr->prprio);
    }
    // restore interrupts
    restore(mask);
}