# :clipboard: Pipex | 42 SP
- Actual Status: finished.
- Result      : Approved with 100 points ✅

  :us: Pipex is the sixty project at 42.
This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program. The aim of the project is reproduce the behavior of pipe.

  	:brazil: Pipex é o sexto projeta da 42.
  Este projeto permitirá que você descubra em detalhes um mecanismo UNIX que você já
  conhece usando-o em seu programa. O objetivo do projeto é reproduzir o comportamento do pipe.
#
  #### We need to implement the following rules:

• Your program will be executed as follows:  

  	./pipex file1 cmd1 cmd2 file2  

• It must take 4 arguments:  
  file1 and file2 are file names.  
  cmd1 and cmd2 are shell commands with their parameters  
  
• You have to turn in a Makefile which will compile your source files. It must not
relink.  

• You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).  

• Your program mustn’t have memory leaks.  

• If you have any doubt, handle the errors like the shell command:  

  	< file1 cmd1 | cmd2 > file2  


## 📝 Files

| Name | Description |
| :------: | :---------: |
| ``pipex.h`` | The header with functions libraries and prototypes. |
| ``pipex.c`` | Contains 3 functions to handle with fork and commands. |
| ``main.c`` | Contains the main and the function to initialize de struct. |
| ``utils.c`` | Contains the fuctions to handle with file and get the path. |
| ``error.c`` | Contains the functions who deal with errors. |
| ``Makefile`` | The automatizated compilator. |

## 🛠️ Usage

Then you can run this commands below 
``` shell
$> make
$> ./pipex infile cmd1 cmd2 outfile
```

• infile: a file to get data  
• cmd1 and cmd2: shell commands, if the commands have flags, you need to use like this "cmd -flag"  
• outfile: a file to output the result
