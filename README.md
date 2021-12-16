# Polybius-Square-Cipher-C
Implementation of Polybius Square Cipher in C.

Maps ascii characters 32-126 to a 10x10 square. When used to encrypt a text, it will output coordinates of all characters that can be mapped as their coordinates in the square, or the character itself if it is not mapped. It can be used to decrypt text which has been encrypted using the same method. 

I used the ascii table because it was convenient. My encryption and decryption are not the prettiest as I use lots of casting back and forth between integers and characters, but it works and I like it.

I would like to implement a 5x5x5, or maybe a 4x4x4 "Polybius Cube" at some point.

# Usage
## Compiling
Compile the program using gcc. I've named the compiled program polybiussquare.

    gcc -g polybiussquare.c -o polybiussquare

## Encrypting
To encrypt a file use echo or cat and redirect to ./polybiussquare as below.

    echo "my text" | ./polybiussquare

I recommend outputting to another file using > as below.

    echo "my text" | ./polybiussquare > myoutput.txt

You can just run the program using just ./polybiussquare and type away and it will encrypt line by line, but that gets hard to store, so using cat and echo is best.

## Decrypting
To decrypt a file use echo or cat and redirect to ./polybiussquare -d as below.

    cat myfile.txt | ./polybiussquare -d

I recommend outputting to another file using > as below.

    cat myfile.txt | ./polybiussquare -d > outputfile.txt

As with encryption you can run the program using just ./polybiussquare -d and type away, but that output gets really messy, so using cat and echo is best.

# Files in Repository
README.md: What you're reading right now.

commands.txt: I don't like remembering what commands I need for compiling a C program, so I've included it for now.

polybiussquare.c: This is where the magic will happen. It will be the program that runs and does the encrypting, decrypting, everything.

test.sh: bash file to test the program. Passes the test in my Ubuntu setup. I don't plan on testing in other setups, but if it doesn't let me know and I'd be happy to work out the problems.

# TODO's

Add visuals to show the Polybius Square I'm using.

Implement a 5x5x5 square.