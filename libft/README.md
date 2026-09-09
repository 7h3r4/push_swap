*This project has been created as part of the 42 curriculum by abukh.*
# Description
This project reimplements a set of functions from libc, glibc and implements other useful throughout the 42 Core Curriculum functions, all compiled into static library named libft.\
Libft contains handful of functions to make it easier to work with memory, strings, integers and characters.\
The library also implements a linked list with following definition:
```
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```
# Instructions
To compile a static library from source:
```
git clone
cd libft/ && make
```
To use libft.a in your projects:

1. link flag
```
cc main.c -I/path/to/libft -L/path/to/libft -lft -o program_name
```
2. direct
```
cc main.c -I/path/to/libft /path/to/libft.a -o program_name
```
# Resources
- All of libc functions were implemented based on [man7.org](https://man7.org/linux/man-pages/index.html)
- Glibc functions were mostly implemented based on [man.freebsd.org](https://man.freebsd.org/cgi/man.cgi)
- [README markdown syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
- This video helped me understand how linked lists work [YouTube (russian)](https://www.youtube.com/watch?v=XmuZ_U_GLYY)
- Claude Opus 5.0 (High Effort) was used to test the functionality of **ft_memmove** as well as to generate all 43 source files name for makefile since i am not allowed to use wildcards.