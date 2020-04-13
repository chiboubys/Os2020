#pragma once

// FAT32 file system driver

#include "fs/fs.h"
#include "k/types.h"

void fatInit();

void fatTerminate();

// The pointer data in FSEntry points to this structure
// Describes a Fat32 directory
typedef struct FatFSEntryData_t
{
    // Where the content is
    u32 cluster;
} FatFSEntryData;

FSEntry *fatFSEntry_new(const char *name, u8 flags, size_t size, FatFSEntryData *data);

void fatFSEntry_del(FSEntry *entry);

void FatFSEntryData_del(FatFSEntryData *data);

size_t fatFSEntry_read(FSEntry *file, void *buffer, size_t count);

FSEntry **fatFSEntry_list(FSEntry *dir);

// Generates the root entry
FSEntry *fatGenRoot();

// Returns the ops structure with
// all methods of fat
FSEntryOps *fatGenFSEntryOps();
