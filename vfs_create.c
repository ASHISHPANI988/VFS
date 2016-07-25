#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vfs.h"



int create_vfs(){
	char a[MAXLEN];

	//Create the VFS file
	if( (vfs.vfs_fp=fopen("VFS.txt","wb+"))==NULL){
		printf("FileSystem can't be created\n");
		exit(1);
	}

	//Initialize Header
	printf("Enter FileSystem name:");
	scanf("%s",a);
	strcpy(vfs.header.vfs_info.vfs_name,a);

	vfs.header.vfs_info.num_files=0;
	vfs.header.vfs_info.size=0;
	vfs.vfs_status=VFS_CLOSE;
	//vfs.vfs_fp=NULL;

	//Save header at the beginning of the file
	rewind(vfs.vfs_fp);
	fwrite(&vfs,sizeof(struct Vfs),1,vfs.vfs_fp);

	//Close the vfs file
	fclose(vfs.vfs_fp);

	return 0;
}