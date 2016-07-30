#include <stdio.h>
#include "vfs.h"

int main()
{
	int status,load;
	status=create_vfs();

	if(status==0){
		printf("\n Filesystem %s created\n",vfs.header.vfs_info.vfs_name);
	}
	else{
		printf("\nCreation of Filesystem failed\n ");
	}

	if(open_vfs()==0){
		printf("\nVFS opened successfully\n");
	}
	else{
		printf("\nOpening of Filesystem failed\n ");
	}
///////////////////////////////////////////////////////////////////////////
	if(save_vfs("a.txt")==0){
		printf("\na.txt File saved successfully\n");
	}
	else{
		printf("\nSaving of file in Filesystem failed\n ");
	}
	if(save_vfs("ab.txt")==0){
		printf("\nab.txt File saved successfully\n");
	}
	else{
		printf("\nSaving of file in Filesystem failed\n ");
	}
	if(save_vfs("abc.txt")==0){
		printf("\nabc.txt File saved successfully\n");
	}
	else{
		printf("\nSaving of file in Filesystem failed\n ");
	}
////////////////////////////////////////////////////////////////////////////
	if(extract_vfs("ab.txt")==0){
		printf("\nFile extracted successfully\n");
	}
	else{
		printf("\nExtracted of file in Filesystem failed\n ");
	}

	if(close_vfs()==0){
		printf("\nVFS closed successfully\n");
	}
	return 0;
}