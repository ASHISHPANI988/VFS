#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vfs.h"

int save_vfs(char *name){
	//Pre-condition: VFS is loaded
	if(vfs.vfs_status==VFS_CLOSE){
		return -1;
	}

	FILE *fp;
	int offset,vfs_offset,size,count=0;
	char ch;

	//Open file to be saved
	if( (fp=fopen(name,"rb+"))==NULL){
		printf("Unable to open the file %s\n",name);
		exit(0);
	}
	else{
		//Calculate offset where file needs to be stored
		fseek(fp,0,SEEK_END);
		size=ftell(fp);
		rewind(fp);

		fseek(vfs.vfs_fp,0,SEEK_END);
		vfs_offset=ftell(vfs.vfs_fp);

		//Initialize vfs_file_info
		vfs.header.vfs_files[vfs.header.vfs_info.num_files].offset=vfs_offset;  //offset of file in VFS
		strcpy(vfs.header.vfs_files[vfs.header.vfs_info.num_files].fname,name);
		vfs.header.vfs_files[vfs.header.vfs_info.num_files].size=size;

		vfs.header.vfs_info.num_files+=1;

		//Write external file contents at offset location
		while(count!=size){
			fread(&ch,sizeof(char),1,fp);
			//printf("%c",ch);
			fwrite(&ch,sizeof(char),1,vfs.vfs_fp);
			++count;
		}

		fclose(fp);
		rewind(vfs.vfs_fp);

		//sort the vfs_files
		qsort(vfs.header.vfs_files,vfs.header.vfs_info.num_files, sizeof(struct Vfs_File_Info), cmp_vfsfile);
	}
	return 0;
}