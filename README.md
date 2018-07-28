Kernel namespace
----------------

This is a basic example of `unshare()` and `chroot()` system calls to get an idea on how containerization may work behind the hood. 

In this example, before forking a son, the father sets the `CLONE_NEWPID` flags with `unshare(CLONE_NEWPID)` and change its root dir to `jail`. The son PID will be assigned in a new namespace and its current dir will be `\`.

Usage:

        > make main
        > sudo ./main

        My son's pid is 12818
        my pid is 1
        my working dir is /

