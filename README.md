                                                    OBJECTIVE
                                                    
To write a function that returns a line read from a file descriptor (reading a file and reading from standard input). 
The function should return the line that was read. 
The returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.

Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.

If there is nothing else to read or if an error occurred, it should return NULL.
