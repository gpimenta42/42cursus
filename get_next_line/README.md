[![gpimenta's 42 ft_printf Score](https://badge42.vercel.app/api/v2/cldx0plxj00060fl5yi95cgh9/project/2857975)](https://github.com/JaeSeoKim/badge42)

### Objective 

To write a function that returns a line read from a file descriptor (reading a file and reading from standard input). 

The function should return the line that was read. 

The returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.

Repeated calls (e.g., using a loop) to get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.

If there is nothing else to read or if an error occurred, it should return NULL.

Forbidden:
- lseek() is forbidden.
- Global variables are forbidden.

Bonus part: 
- Develop get_next_line() using only one static variable.
- get_next_line() can manage multiple file descriptors at the same time.

### How to compile

To compile the code use as follows (a buffer size of 42 is used as an ex): cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 < files >.c
