/**
 * @file mmap_file.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>

#define MMAP_FILE_NAME "a.txt"
#define MMAP_FILE_SIZE 10

void err_exit(const char *err_msg)
{
    printf("error:%s\n", err_msg);
    exit(1);
}

/* 信号处理器，待补全 */
void signal_handler(int signum)
{
    if (signum == SIGSEGV)
        printf("\nSIGSEGV handler!!!\n");
    else if ()
        printf("\nSIGBUS handler!!!\n");
    exit(1);
}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("usage:%s text\n", argv[0]);
        exit(1);
    }
    
    char *addr;
    int file_fd, text_len;
    long int sys_pagesize;
    
    /* 设置信号处理器 */
    if (signal(SIGSEGV, signal_handler) == SIG_ERR)
        err_exit("signal()");
    if (signal(SIGBUS, signal_handler) == SIG_ERR)
        err_exit("signal()");
    
    if ((file_fd = open(MMAP_FILE_NAME, O_RDWR)) == -1)
        err_exit("open()");
    
    /* 系统分页大小 */
    sys_pagesize = sysconf(_SC_PAGESIZE);
    printf("sys_pagesize:%ld\n", sys_pagesize);
    
    /* 内存只读，待补全 */
    //addr = (char *)mmap();
    
    /* 映射大于文件长度，且大于该文件分页大小，待补全 */
    //addr = (char *)mmap();
    
    /* 正常分配,待补全 */
    addr = (char *)mmap();
    if (addr == MAP_FAILED)
        err_exit("mmap()");
    
    /* 原始数据 */
    printf("old text:%s\n", addr);
    
    /* 越界访问 */
    //addr += sys_pagesize + 1;
    //printf("out of range:%s\n", addr);
    
    /* 拷贝新数据 */
    text_len = strlen(argv[1]);
    memcpy(addr, argv[1], text_len);
    
    /* 同步映射区数据 */
    //if (msync(addr, text_len, MS_SYNC) == -1)
    //    err_exit("msync()");
    
    /* 打印新数据 */
    printf("new text:%s\n", addr);
    
    /* 解除映射区域 */
    if (munmap(addr, MMAP_FILE_SIZE) == -1)
        err_exit("munmap()");
    
    return 0;
}