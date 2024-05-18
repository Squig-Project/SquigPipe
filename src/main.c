#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

DWORD WINAPI ServerThread(LPVOID lpParam) 
{
    HANDLE pipe = CreateNamedPipeA(
        "\\\\.\\pipe\\SquigPipe", 
        PIPE_ACCESS_DUPLEX, PIPE_READMODE_BYTE | PIPE_TYPE_BYTE | PIPE_WAIT, 
        1, 
        4096, 
        4096, 
        0, 
        NULL
    );

    if (pipe == INVALID_HANDLE_VALUE) 
    {
        return -1;
    }

    if (!ConnectNamedPipe(pipe, NULL)) 
    {
        CloseHandle(pipe);
        return -1;
    }

    DWORD bytesRead;
    char buffer[4096];
    if (!ReadFile(pipe, buffer, sizeof(buffer), &bytesRead, NULL)) 
    {
        CloseHandle(pipe);
        return -1;
    }

    CloseHandle(pipe);
    return 0;
}

DWORD WINAPI ClientThread(LPVOID lpParam) 
{
    if (!WaitNamedPipeA("\\\\.\\pipe\\SquigPipe", NMPWAIT_USE_DEFAULT_WAIT)) 
    {
        return -1;
    }

    HANDLE pipe = CreateFileA(
        "\\\\.\\pipe\\SquigPipe", 
        GENERIC_WRITE | GENERIC_READ, 
        0, 
        NULL, 
        OPEN_EXISTING, 
        0, 
        NULL
    );

    char *buffer = (char *)VirtualAlloc(NULL, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (buffer == NULL) 
    {
        return -1;
    }

    if (fgets(buffer, 4096, stdin) == NULL) 
    {
        return -1;
    }

    DWORD bytesWritten;
    if (!WriteFile(pipe, buffer, 4096, &bytesWritten, NULL)) 
    {
        CloseHandle(pipe);
        return -1;
    }

    CloseHandle(pipe);
    return 0;
}

DWORD start(void) 
{
    HANDLE serverThread = CreateThread(NULL, 0, ServerThread, NULL, 0, NULL);
    if (serverThread == NULL) 
    {
        return -1;
    }

    HANDLE clientThread = CreateThread(NULL, 0, ClientThread, NULL, 0, NULL);
    if (clientThread == NULL) 
    {
        CloseHandle(serverThread);
        return -1;
    }

    while (1) 
    {

    }
    
}

int main(void)
{
    
    return 0;
}
