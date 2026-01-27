#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *d;
    struct dirent *entry;

    /* open current directory */
    d = opendir(".");

    if (d == NULL)
    {
        printf("Directory cannot be opened\n");
        return 1;
    }
    /* read directory entries */
    printf("Directory contents:\n");
    while ((entry = readdir(d)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }
    /* close directory */
    closedir(d);
    return 0;
}

output:-
    ~/os lab$ ls
2026-01-13-file-1.term  2026-01-13-file-2.term  2026-01-27-file-1.term  lab1a  lab1a.c  lab1b.c  lab2  lab2.c
~/os lab$ gcc lab1b.c -o lab1b
~/os lab$ ./lab1b
Directory contents:
.
..
lab2.c
2026-01-27-file-1.term
lab2
2026-01-13-file-1.term
lab1a
lab1b.c
lab1b
lab1a.c
2026-01-13-file-2.term
~/os lab$ 

