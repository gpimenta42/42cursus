                                                    OBJECTIVE
                                                    
To write a function that returns a line read from a file descriptor (reading a file and reading from standard input). 
The function should return the line that was read. 
The returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.

Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.

If there is nothing else to read or if an error occurred, it should return NULL.


- To compile the code use as follows (a buffer size of 42 is used as an ex): cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 < files >.c

Forbidden:
- lseek() is forbidden.
- Global variables are forbidden.

Bonus part: 
- Develop get_next_line() using only one static variable.
- get_next_line() can manage multiple file descriptors at the same time.
