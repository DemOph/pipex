/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:09:18 by chael-ha          #+#    #+#             */
/*   Updated: 2021/07/12 21:58:57 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>

// int main(int argc, char *argv[])
// {
//     // causes creation of a new process.  The new process (child process) is an exact copy of the calling
//     //process (parent process) except for the following:
//     //wait for the child to ter;inate its process otherwise ppid would die and ull be assigned another ppid
//     //if u dont wait for the child process to terminate, and even if u kill the his new parent it wouldnt free the memory == mem leak, let the fucking child finish its things!
//      int id = fork();
//     // if (id != 0)
//     //     fork();
//     printf("hello world!%d\n", getpid());
//     return 0;
//     //the pipe() system function is used to open file descriptors, which are used to communicate between different Linux processes
// }

//The dup() system call creates a copy of a file descriptor.
//int dup(int oldfd);
//oldfd: old file descriptor whose copy is to be created.
//The dup2() system call is similar to dup() but the basic difference between them is that instead of using 
//the lowest-numbered unused file descriptor, it uses the descriptor number specified by the user.

//pipe is a connection between two processes
//inter-process communication
// int pipe(int fds[2]);

// Parameters :
// fd[0] will be the fd(file descriptor) for the 
// read end of pipe.
// fd[1] will be the fd for the write end of pipe.
// Returns : 0 on Success.
// -1 on error.

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
 
// int main(int c, char **v, char **env) {
//     int i;

//     i = 0;
//     while (env[i])
//     {
//         printf("%s\n", env[i++]);
//     }
// //   int pipefds[2];
 
// //   if(pipe(pipefds) == -1) {
// //     perror("pipe");
// //     exit(EXIT_FAILURE);
// //   }
 
// //   printf("Read File Descriptor Value: %d\n", pipefds[0]);
// //   printf("Write File Descriptor Value: %d\n", pipefds[1]);
 
//   return EXIT_SUCCESS;
// }

// #include<stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
  
// int main()
// {
//     // open() returns a file descriptor file_desc to a 
//     // the file "dup.txt" here"
  
//     int file_desc = open("dup.txt", O_WRONLY | O_APPEND);
      
//     if(file_desc < 0)
//         printf("Error opening the file\n");
      
//     // dup() will create the copy of file_desc as the copy_desc
//     // then both can be used interchangeably.
  
//     int copy_desc = dup(file_desc);
          
//     // write() will write the given string into the file
//     // referred by the file descriptors
  
//     write(copy_desc,"This will be output to the file named dup.txt\n", 46);
          
//     write(file_desc,"This will also be output to the file named dup.txt\n", 51);
      
//     return 0;
// }

// #include <unistd.h>
// int pipe(int pipefd[2]);
//pipe() creates a pipe, a unidirectional data channel that can be used for interprocess 
//communication. The array pipefd is used to return two file descriptors referring to
// the ends of the pipe. pipefd[0] refers to the read end of the pipe. pipefd[1] refers
// to the write end of the pipe. Data written to the write end of the pipe is buffered by 
//the kernel until it is read from the read end of the pipe


// Parent and child sharing a pipe

// When we use fork in any process, file descriptors remain open across child process and also
//  parent process. If we call fork after creating a pipe, then the parent and child can 
//  communicate via the pipe.

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #define MSGSIZE 16
// char* msg1 = "hello, world #1";
// char* msg2 = "hello, world #2";
// char* msg3 = "hello, world #3";
  
// int main()
// {
//     char inbuf[MSGSIZE];
//     int p[2], i;
  
//     if (pipe(p) < 0)
//         exit(1);
  
//     /* continued */
//     /* write pipe */
  
//     write(p[1], msg1, MSGSIZE);
//     write(p[1], msg2, MSGSIZE);
//     write(p[1], msg3, MSGSIZE);
  
//     for (i = 0; i < 3; i++) {
//         /* read pipe */
//         read(p[0], inbuf, MSGSIZE);
//         printf("%s\n", inbuf);
//     }
//     return 0;
// }

// if a child process and a parent process shared the same global variable change in one 
// process does not affected two other processes because 
// data/state of two processes are different. And also parent and child run simultaneously so 
// two outputs are possible == we exec same problem not using same data/state.

// C program to illustrate
// pipe system call in C
// shared by Parent and Child


//The program counter (PC) holds the address of the next instruction to be executed, 
//while the instruction register (IR) holds the encoded instruction. Upon fetching the instruction, 
//the program counter is incremented by one "address value" (to the location of the next instruction)

//for a child process ; same cpu registers, same pc, same opened files

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
 
// #define MSGSIZE 16
// char* msg1 = "hello, world #1";
// char* msg2 = "hello, world #2";
// char* msg3 = "hello, world #3";
  
// int main(int c, char **argv, char **env)
// {
//     char inbuf[MSGSIZE];
//     int p[2], pid, nbytes;
  
//     if (pipe(p) < 0)
//         exit(1);
  
//     /* continued */
//     if ((pid = fork()) > 0) {
//         printf("%d\n", pid);
//         write(p[1], msg1, MSGSIZE);
//         write(p[1], msg2, MSGSIZE);
//         write(p[1], msg3, MSGSIZE);
//         // Adding this line will
//         // not hang the program
//         // close(p[1]);
//         //wait(NULL);
//     }
  
//     else {
//         // Adding this line will
//         // not hang the program
//         // close(p[1]);
//         while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
//               printf("%s\n", inbuf);
//         if (nbytes != 0)
//             exit(2);
//         printf("Finished reading\n");
//     }
//     return 0;
// }

#include "../pipex.h"

char    **search_for_path(char **envp)
{
    int i;
    char **path_splited;

    i = 0;
    while (*envp && ft_strncmp(*envp, "PATH=", 5))
        (*envp)++;
    if (ft_strncmp(*envp, "PATH=", 5) == 0)
    {
        path_splited = ft_split(*envp+5, ':');
        return (path_splited);
    }
    return (NULL);
}

// char    *ft_strdel(char *s, int del_size)
// {
//     char *dst;
//     int cpy_size;
//     int  i;

//     cpy_size = ft_strlen(s) - del_size - 1;
//     i = 0;

//     while (s[i] && i < cpy_size)
//     {
//             dst[i] = s[i];
//             i++;
//     }
//     dst[i] = '\0';
//     return (dst);
// }
char    **store_flags_return_cmd(char *arg)
{
    char **argg;

    argg = ft_split(arg, ' ');
    return (argg);
}

void   iscmd_builtin_sh(char **argv, char **envp)
{
    char *path_dir_orig;
    char *path_dir;
    char **path_splitted;
    char **cmd1;
    int *pid;
    int i;
    int j;
    
    path_splitted = search_for_path(envp);
    cmd1 = store_flags_return_cmd(argv[2]);
    pid = malloc(sizeof(int) * 2);

    i = -1;
    while (++i < 2)
    {
        j = 0;
        while (path_splitted[j])
        {
            // printf("in\n");
            path_dir_orig = ft_strjoin((path_splitted[j]), "/");
            // printf("out\n");
            path_dir = ft_strjoin(path_dir_orig, cmd1[i]);
            // path_dir = ft_strjoin((path_splitted[j])++, cmd1[i]);
            // while (access(path_dir, F_OK) == -1 && path_splitted[j])
            if (!access(path_dir, F_OK))
            {
                pid[i] = fork();
                printf("mera\n");
                if (pid[i] == 0)
                {
                    if (execve(path_dir, cmd1, envp) == -1)
                        perror("execve m3t malha !");
                    exit(0);
                }
                waitpid(pid[i], 0, 0);
                break ;
            }
            j++;
            // (path_splitted[j])++;
        }
        if (!*path_splitted)
        {
            perror("no such file or directory");
            exit(EXIT_FAILURE);
        }
    }
}


void    parse(int argc, char **argv, char **envp)
{
    int i;
    int fd1;
    int fd2;

    i = 0;
    
    if (argc != 5)
        exit(EXIT_FAILURE);
    else
    {
        fd1 = open(argv[1], O_RDONLY);
        if (fd1 < 0)
            write(2, "no such file or directoryy\n", 26);
        fd2 = open(argv[4], O_RDWR);
        if (fd2 < 0)
        {
            ft_putstr_fd("error opening or creating the filee", 2);
             exit(EXIT_FAILURE);
        }
    }
    iscmd_builtin_sh(argv, envp);
}
    
int main(int argc, char **argv, char **envp)
{
    parse(argc, argv, envp);
    return 0;
}
    // char p[2];
    // int pid;
    // if (pipe(p) < 0)
    //     exit(1);
    // pid = fork();
	// if (pid == -1)
	// {
	// 	ft_putstr_fd("Fork failed\n", 2);
	// 	return (0);
	// }
	// if (pid == 0)
	// char* argve[] = {"ls", "-la", NULL};
	// execve("/bin/ls", argve, envp);
	// return (0);
