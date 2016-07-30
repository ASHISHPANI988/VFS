
#ifndef VFS_H
#define VFS_H

#define MAXLEN 31
#define MAXFILES 5

#define VFS_OPEN 0
#define VFS_CLOSE 1

struct Vfs_File_Info{
	char fname[MAXLEN];
	int offset;
	int size;
};

struct Vfs_Info{
	char vfs_name[MAXLEN];
	int num_files;   //file counter
	int size;
};

struct Vfs_Header_Info{
	struct Vfs_Info vfs_info;
	struct Vfs_File_Info vfs_files[MAXFILES];
};

struct Vfs{
	struct Vfs_Header_Info header;
	FILE *vfs_fp;
	int vfs_status;
};

struct Vfs vfs;

int create_vfs();
int open_vfs();
int close_vfs();
int save_vfs(char*);
int extract_vfs(char*);

int cmp_vfsfile(const void * a, const void * b);

#endif  /* VFS_H  */