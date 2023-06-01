[![gpimenta's 42 ft_printf Score](https://badge42.vercel.app/api/v2/cldx0plxj00060fl5yi95cgh9/project/2857975)](https://github.com/JaeSeoKim/badge42)

Recode of the printf() function from libc.
The prototype of ft_printf() is:

int ft_printf(const char *, ...);

Here are the requirements: Don’t implement the buffer management of the original printf(). | Your function will be compared against the original printf(). | You must use the command ar to create your library. Using the libtool command is forbidden. | Your libftprintf.a has to be created at the root of your repository.


It handles the following conversions:

- %c Prints a single character.

- %s Prints a string (as defined by the common C convention).

- %p The void * pointer argument has to be printed in hexadecimal format.

- %d Prints a decimal (base 10) number.

- %i Prints an integer in base 10.

- %u Prints an unsigned decimal (base 10) number.

- %x Prints a number in hexadecimal (base 16) lowercase format.

- %X Prints a number in hexadecimal (base 16) uppercase format.

- %% Prints a percent sign.
