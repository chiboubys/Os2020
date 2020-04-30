#pragma once

// All syscalls (user)

#include "types.h"

// --- Id --- //
// !!! These definitions should be the same as syscalls.inc's definitions
// Syscalls ids
// See doc/syscalls.md for specs
#define SYS_FATAL       0x02
#define SYS_ENTER       0x03
#define SYS_TERMINATE   0x04

#define SYS_OPEN        0x10
#define SYS_READ        0x11
#define SYS_WRITE       0x12
#define SYS_CLOSE       0x13
#define SYS_PIPE        0x14


// --- System --- //
// Fatal error
extern void fatal(const char *msg);

// Calls the entry of an application
extern int enter(int (*entry)(int argc, char **argv), int argc, char **argv);

// Terminates the current program
extern int terminate();

// --- IO --- //
// Opens a file
// * Modes are described in k/io.h
// * Returns -1 on error
extern fd_t open(const char *path, u8 mode);

// Reads count bytes of the file associated to fd in buffer
// * Returns how many bytes read
extern ssize_t read(fd_t fd, void *buffer, size_t count);

// Writes count bytes of buffer in the file associated to fd
// * Returns how many bytes written
extern ssize_t write(fd_t fd, void *buffer, size_t count);

// Closes a file
extern void close(fd_t fd);

// Creates a pipe
// * Returns its file descriptor
extern fd_t pipe();
