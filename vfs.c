#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vfs.h"

int cmp_vfsfile(const void * a, const void * b)
{
   return strcmp((*(struct Vfs_File_Info*)a).fname,(*(struct Vfs_File_Info*)b).fname);
}
