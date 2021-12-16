#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAD_NUMBER_ARGS 1
#define TRUE 1
#define FALSE 0

FILE *parseCommandLine(int argc, char **argv, int *encrypt)
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

void printCoordinates(int origin)
{
    int x = 0;
    int y = 0;
    int offset = origin - 32;
    while( offset > 10 )
    {
        x += 10;
        offset -= 10;
    }
    while(offset > 0)
    {
        y += 1;
        offset -= 1;
    }

    if(x+y == 0)
    {
        printf("00");
    }
    else if(x+y < 10)
    {
        printf("0%d",x+y);
    }
    else
    {
        printf("%d",x+y);
    }
}

void printEncrypted(unsigned char *data)
{
    int caster = data[0];
    if( caster >= 32 && caster <= 126)
    {
        printCoordinates(caster);
    }
    else
    {
        printf("%s",data);
    }
}

void encryptText(FILE *input)
{
    unsigned char data[1];
    int numRead = fread(data, 1, 1, input);
    while( numRead != 0)
    {
        printEncrypted(data);
        numRead = fread(data, 1, 1, input);
    }
}

void printOriginal(int x,int y)
{
    char orig = (x * 10) + y + 16;
    char final = orig;
    printf("%c",final);
}

void printDecrypted(unsigned char* data)
{
    int xcaster = data[0];
    int ycaster = data[1];
    printOriginal(xcaster,ycaster);
}

void decryptText(FILE *input)
{
    unsigned char data[1];
    unsigned char convertible[2];
    int numRead = fread(data, 1, 1, input);
    while( numRead != 0)
    {
        convertible[0] = ' ';
        convertible[1] = ' ';
        int intValue = data[0];
        if(intValue >= 48 && intValue <= 57)
        {
            convertible[0] = intValue;
            numRead = fread(data,1,1,input);
            intValue = data[0];
            if(intValue >= 48 && intValue <= 57)
            {
                convertible[1] = intValue;
                printDecrypted(convertible);
            }
            else
            {
                convertible[1] = intValue;
                printf("&%s",convertible);
            }
        }
        else
        {
            //data[0] = '^';
            //data[1] = '$';
            //data[2] = '#';
            printf("%c",data[0]);
        }
        numRead = fread(data, 1, 1, input);
    }
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