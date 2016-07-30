#vfs_makefile.mk
try: try.o vfs_create.o vfs_load.o vfs_save.o vfs_extract.o vfs_unload.o vfs.o
	gcc -o try try.o vfs_create.o vfs_load.o vfs_save.o vfs_extract.o vfs_unload.o vfs.o

vfs.o:vfs.h
	gcc -c vfs.c

vfs_create.o: vfs.h vfs_create.c
	gcc -c vfs_create.c

vfs_load.o: vfs.h vfs_load.c
	gcc -c vfs_load.c

vfs_save.o: vfs.h vfs_save.c
	gcc -c vfs_save.c

vfs_extract.o: vfs.h vfs_extract.c
	gcc -c vfs_extract.c

vfs_unload.o: vfs.h vfs_unload.c
	gcc -c vfs_unload.c

vfs_try.o:vfs.h try.c
	gcc -c try.c