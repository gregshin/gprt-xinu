/* xsh_deadset.c - xsh_deadset */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


/*------------------------------------------------------------
* xsh_deadset - shell command to make sure readylist is ordered
*------------------------------------------------------------
*/

shellcmd xsh_deadset(int nargs, char *args[])
{
    deadset(); // calls the deadset function

    return 0;
}