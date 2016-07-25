#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vfs.h"

//extern struct Vfs vfs;

int open_vfs(){
	//FILE *fp;
	//char a[MAXLEN];
	//struct Vfs vfs;

	printf("Loading VFS  %s....\n",vfs.header.vfs_info.vfs_name);

	//Open the VFS file
	if( (vfs.vfs_fp=fopen("VFS.txt","wb+"))==NULL){
		printf("Unable to load the filesystem\n");
		exit(1);
	}

	//Load header info into struct
	rewind(vfs.vfs_fp);
	fread(&vfs,sizeof(struct Vfs),1,vfs.vfs_fp);

	//Initialize struct vfs
	vfs.vfs_status=VFS_OPEN;

	printf("VFS Name:%s\n",vfs.header.vfs_info.vfs_name);
	printf("VFS Status:%d VFS_OPEN\n",vfs.vfs_status);
	printf("No of Files:%d\n",vfs.header.vfs_info.num_files);
	return 0;
}