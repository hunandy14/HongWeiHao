/*****************************************************************
Name :
Date : 2017/05/07
By   : CharlotteHonG
Final: 2017/05/07

http://blog.csdn.net/aoshilang2249/article/details/44958907
https://www.ptt.cc/bbs/C_and_CPP/M.1496806078.A.36B.html
*****************************************************************/
#include <windows.h>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
//--------------------------------------------------------------
//                      CPU序列號
//--------------------------------------------------------------
BOOL GetCpuByCmd(char *lpszCpu, int len/*=128*/){
    const long MAX_COMMAND_SIZE = 10000; // 命令行輸出緩衝大小
    LPSTR szFetCmd = "wmic cpu get processorid"; // 獲取CPU序列號命令行
    const string strEnSearch = "ProcessorId"; // CPU序列號的前導信息

    BOOL   bret       = FALSE;
    HANDLE hReadPipe  = NULL; //讀取管道
    HANDLE hWritePipe = NULL; //寫入管道
    PROCESS_INFORMATION pi;   //進程信息
    STARTUPINFO         si;   //控制命令行窗口信息
    SECURITY_ATTRIBUTES sa;   //安全屬性

    char            szBuffer[MAX_COMMAND_SIZE+1] = {0}; // 放置命令行結果的輸出緩衝區
    string          strBuffer;
    unsigned long   count = 0;
    long            ipos  = 0;

    memset(&pi, 0, sizeof(pi));
    memset(&si, 0, sizeof(si));
    memset(&sa, 0, sizeof(sa));

    pi.hProcess = NULL;
    pi.hThread  = NULL;
    si.cb = sizeof(STARTUPINFO);
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    //1.0 創建管道
    bret = CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);
    if (!bret) goto END;

    //2.0 設置命令行窗口的信息爲指定的讀寫管道
    GetStartupInfo(&si);
    si.hStdError   = hWritePipe;
    si.hStdOutput  = hWritePipe;
    si.wShowWindow = SW_HIDE; //隱藏命令行窗口
    si.dwFlags     = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

    //3.0 創建獲取命令行的進程
    bret = CreateProcess(NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    if (!bret) goto END;

    //4.0 讀取返回的數據
    WaitForSingleObject(pi.hProcess, 500/*INFINITE*/);
    bret = ReadFile(hReadPipe, szBuffer, MAX_COMMAND_SIZE, &count, 0);
    if (!bret) goto END;

    //5.0 查找CPU序列號
    bret = FALSE;
    strBuffer = szBuffer;
    ipos = strBuffer.find(strEnSearch);

    if (ipos < 0){   // 沒有找到
        goto END;
    } else {
        strBuffer = strBuffer.substr(ipos + strEnSearch.length());
    }

    memset(szBuffer, 0x00, sizeof(szBuffer));
    strcpy_s(szBuffer, strBuffer.c_str());

    //去掉中間的空格 \r \n
    for (unsigned i=0, j=0; i < strlen(szBuffer); i++){
        if (szBuffer[i] != ' ' && szBuffer[i] != '\n' && szBuffer[i] != '\r'){
            lpszCpu[j++] = szBuffer[i];
        }
    }

    bret = TRUE;

END:
    //關閉所有的句柄
    CloseHandle(hWritePipe);
    CloseHandle(hReadPipe);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return(bret);
}

int main(int argc, char const *argv[]) {
    char str[128] = {};
    GetCpuByCmd(str, 128);
    cout << "str=" << str << endl;
    return 0;
}