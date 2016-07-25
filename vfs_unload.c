#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vfs.h"

int close_vfs(){

	//Setting the pointer to beggining
	fseek(vfs.vfs_fp,0,SEEK_SET);

	//Save header into file
	fwrite(&vfs,sizeof(struct Vfs),1,vfs.vfs_fp);

	//Close the file
	fclose(vfs.vfs_fp);

	//Update struct Vfs
	vfs.vfs_status=VFS_CLOSE;
	vfs.vfs_fp=NULL;

	return 0;
}