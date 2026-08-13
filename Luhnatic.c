#include <stdio.h>

int main (int argv, char *argc[]) {
    if (argv < 2) {
        printf("USAGE:\n\
                ./Luhnatic validate <16 digit num>\n\
                ./Luhnatic generate <length>\n\
                ./Luhnatic explain <16 digit num>\n");
    }

    printf("%s\n", argc[0]);

    return 0;
}
