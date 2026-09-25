#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>

int main(void)
{
    int arr[]={12,4,5,6};
    int a=12,b=16;
    int f1;  
    f1=open("C:\\Users\\lochieh\\Desktop\\dev c++\\c\\C HW\\ch12\\hw12_12.bin",O_WRONLY|O_CREAT|O_BINARY,S_IREAD); /* 開啟檔案 */
    
    if(f1!=-1)     /* 檔案開啟成功 */
    {
    	write(f1,arr,sizeof(arr)); /* 將arr陣列寫入f1 */
    	write(f1,&a,sizeof(a));    /* 將a寫入f1 */
    	write(f1,&b,sizeof(b));    /* 將b寫入f1 */
    	close(f1);                 /* 關閉檔案 */
    	printf("檔案開啟成功\n");
    	
	}
	else
	{
		printf("檔案開啟失敗!!\n");
	}
   
    system("pause");
	return 0;
}
