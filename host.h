#ifndef HOST_H
#define HOST_H
#include <string.h>


/*
 *Reference: http://albert-oma.blogspot.tw/2012/04/semihosting.html
 */
enum HOST_SYSCALL{
	SYS_OPEN=0x01,
	SYS_CLOSE,
	SYS_WRITEC,
	SYS_WRITE0,
	SYS_WRITE,
	SYS_READ,
	SYS_READC,
	SYS_ISERROR,
	SYS_ISTTY,
	SYS_SEEK,
	SYS_FLEN=0xC,
	SYS_TMPNAM,
	SYS_REMOVE,
	SYS_RENAME,
	SYS_CLOCK,
	SYS_TIME,
	SYS_SYSTEM,
	SYS_ERRNO,
	SYS_GET_CMDLINE=0x15,
	SYS_HEAPINFO,
	SYS_ELAPSED=0x30,
	SYS_TICKFREQ
};

enum SYS_OPEN_MODE{
	SYS_OPEN_R = 0,
	SYS_OPEN_RB,
	SYS_OPEN_RU,
	SYS_OPEN_RUB,
	SYS_OPEN_W,
	SYS_OPEN_WB,
	SYS_OPEN_WU,
	SYS_OPEN_WUB,
	SYS_OPEN_A,
	SYS_OPEN_AB,
	SYS_OPEN_AU,
	SYS_OPEN_AUB
};

typedef union param_t{
	int pdInt;
	void *pdPtr;
	char *pdChrPtr;
} param;


int host_call(enum HOST_SYSCALL, void *argv) __attribute__((naked));

int host_system(char *cmd);

#endif 
