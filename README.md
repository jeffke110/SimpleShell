# SimpleShell
Simple Shell Project
Overview

This project implements a simple Unix-like shell in C. The shell allows users to execute commands, such as ls, pwd, or custom commands, by creating child processes and using system functions like fork(), execvp(), and waitpid() to manage process creation and execution. The shell supports basic input parsing, output handling, and error management.
Features

    Execute system commands like ls, pwd, and more.
    Supports running programs with arguments.
    Basic support for background processes (by appending &).
    Command-line input and output handling.
    Error handling for failed commands or processes.

Getting Started

To get started with the project, follow the steps below:
Prerequisites

    C Compiler (e.g., GCC)
    Make (for building the project)
    A Unix-like operating system (Linux, macOS, etc.) to run the shell

