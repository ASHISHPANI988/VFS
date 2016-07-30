#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vfs.h"


int extract_vfs(char *name){
	//Pre-condition: VFS is loaded
	char ch;
	struct Vfs_File_Info *ii;
	if(vfs.vfs_status==VFS_CLOSE){
		return -1;
	}

	printf("Reaching extract\n");
	FILE *fp;
	int i=0,offset,count=0,flag=0,size=0;

	
	//Iterate on vfs_files array
	/*
	flag=0;
	while(i<vfs.header.vfs_info.num_files){
		if(strcmp(vfs.header.vfs_files[i].fname,name)==0){
			flag=1;
			break;
		}
		++i;
	}
	*/
	ii= bsearch (name,vfs.header.vfs_files,vfs.header.vfs_info.num_files, sizeof(struct Vfs_File_Info), cmp_vfsfile);

	//	printf("Finding Index :%d\n",*ii);
	/*
	if(flag==0){
		printf("File Not Found");
		exit(1);
	}
	*/

	//Create empty external file
	if( (fp=fopen("temp.txt","wb+"))==NULL){
		printf("Unable to open the file %s\n",name);
	}

	//Locate the offset
	//offset=vfs.header.vfs_files[*ii].offset;
	offset=(*ii).offset;
	fseek(vfs.vfs_fp,offset,SEEK_SET);

	//Calculate bytes to read
	//size=vfs.header.vfs_files[*ii].size;
	size=(*ii).size;
	//Read bytes to read and Save bytes into external file
	while(count<=size){
			fread(&ch,sizeof(char),1,vfs.vfs_fp);
			printf("%c",ch);
			fwrite(&ch,sizeof(char),1,fp);
			++count;
	}
	
	//Close external file
	fclose(fp);
	rewind(vfs.vfs_fp);

	return 0;
}