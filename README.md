# HW6
## Gordon Zhang
## SBU ID: 117574236

## This program only recognize the -s, -l, -w, and -r, commands, any other commands will be ignored 

# -s command
## Take the argument after the command and store it as a string to search for
### The program only allows one "*" in -s if -w is enabled
#### Otherwise, the program will return WILDCARD_INVALID

# -l command
## Given two argument seperated by commas, parse them if possible, then search from the range of the first number to the second number inclusively
### Expect both positive int for the argument, so if a negative int is passed in the program might break

# -r command
## Once find occurance of the string -s stores, replaces it with the argument passes to -r

# -w command
## Take the string stores by -s, search and replace the whole word by the argument of -r command, while keeping the punctuation
## *string means find the words with suffix string
## string* means find the words with prefix string



