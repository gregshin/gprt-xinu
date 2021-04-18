/* xsh_chprio.c - xsh_chprio */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


/*------------------------------------------------------------
* xsh_chprio - shell command to change pid priority to 10
*------------------------------------------------------------
*/

shellcmd xsh_chprio(int nargs, char *args[])
{
    pid32   pid;
    pri16   priority;
	char    ch;
    char    *charprio;
    
    priority = 10;

    if (nargs == 1) {
        kprintf("no pid specified\n");
        return 1;
    }
	
    else if ( nargs == 2 ) {
        charprio = args[1];
        ch = *charprio++;
        pid = 0;
        while(ch != NULLCH) {
            if ((ch <'0') || (ch > '9')) {
                kprintf("%s: non-digit in process id\n", args[1]);
                return 1;
            }
            pid = 10*pid + (ch - '0');
            ch = *charprio++;
        }

        if (pid < (pid32)MINKEY) {
            kprintf("%s: invalid pid\n", args[1]);
            return 1;
        }
 
    }
    else {
        kprintf("Too many arguments\n");
        return 1;
    }
    
    chprio(pid, priority);
	
    return 0;

}