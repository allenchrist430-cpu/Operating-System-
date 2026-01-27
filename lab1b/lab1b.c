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
