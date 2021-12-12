#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAD_NUMBER_ARGS 1
#define TRUE 1
#define FALSE 0

FILE * parseCommandLine(int argc, char **argv, int *encrypt)
{
    if( argc > 2 )
    {
        printf("Usage: %s [-d|--decrypt]\n", argv[0]);
        exit(BAD_NUMBER_ARGS);
    }

    if( argc == 2 && (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--decrypt") == 0 ))
    {
        *encrypt = FALSE;
    }
    else
    {
        *encrypt = TRUE;
    }
    return stdin;
}

void encryptText(FILE *input)
{
    printf("TODO: encryptText\n");
}

void decryptText(FILE *input)
{
    printf("TODO: decryptText\n");
}

int main(int argc, char * argv[])
{
    int encrypt;
    FILE *input = parseCommandLine(argc,argv,&encrypt);
    if( encrypt == TRUE)
    {
        encryptText(input);
    }
    else
    {
        decryptText(input);
    }

    return 0;
}