# Polybius-Square-Cipher-C
Implementation of Polybius Square Cipher in C.

# Usage
## Compiling
Compile the program using gcc. I've named the compiled program named polybiussquare.

    gcc -g polybiussquare.c -o polybiussquare

## Encrypting
To encrypt a file use echo or cat and redirect to ./polybiussquare as below.

    echo "my text" | ./polybiussquare

I recommend outputting to another file using > as below.

    echo "my text" | ./polybiussquare > myoutput.txt

You can just run the program using just ./polybiussquare and type away and it will encrypt line by line, but that gets hard to store, so using cat and echo is best.

# Files in Repository
README.md: What you're reading right now.

commands.txt: I don't like remembering what commands I need for compiling a C program, so I've included it for now.

polybiussquare.c: This is where the magic will happen. It will be the program that runs and does the encrypting, decrypting, everything.

# TODO's
Decrypting characters. 

Along the way I'll need to figure out how I want to create and run unit tests, if I want to have separate .c and .h files.
