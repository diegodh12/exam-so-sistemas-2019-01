#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char *path = getenv("PATH");;
        char *dir;
	char s[2] = ":";
        struct dirent *dirTemp;
        DIR *d;
        comando = strtok(argv, " ");
        /* get the first token */
        dir = strtok(path, s);

        /* walk through other tokens */
        while (dir != NULL)
        {
            d = opendir(dir);
            while ((dirTemp = readdir(d)) != NULL)
            {
                if (strcmp(dirTemp->d_name, comando) == 0)
                {
                    printf("%s/%s\n",dir, dirTemp->d_name);
                }
            }
            closedir(d);
            dir = strtok(NULL, s);
        }

    return 0;
}
