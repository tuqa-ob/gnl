*This activity has been created as part of
the 42 curriculum by tobaidat*

## Description
In this project I create the function `get_next_line()` that read one single line of any text file and return it , using any BUFFER_SIZE you choose , if you will not enter a specific BUFFER_SIZE I choose 42 by default.
- note : the function works as expected both when reading a file and when reading
from the standard input.


## Instructions
- to run the code :
1. include "get_next_line.h" in your main.c
2. call the function `get_next_line(<inter your file descriptor here>)` in your main.c
3. You will compile your code as follows (n is the buffer_size you choose):
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c 
```
or if you want to read from the standard input ,when you call the function write `get_next_line(0)` after that compile as:
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```
4. run:
```bash
./a.out
```

## Resources
- man page .
- AI to know how the function works and what I need to create it ,also I learned how can I use static variable .

