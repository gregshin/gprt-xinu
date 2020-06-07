/* xsh_create.c - xsh_create */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


/*------------------------------------------------------------
* xsh_deadset - shell command to make sure readylist is ordered
*------------------------------------------------------------
*/

shellcmd xsh_deadset(int nargs, char *args[])
{
    deadset();

    return 0;
}