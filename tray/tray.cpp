#include "stdafx.h"

using namespace std;
 
void usage();
 
int _tmain(int argc, _TCHAR* argv[])
{
    int result = 0;
    char returnString[MAX_PATH] = { 0 };
    MCIERROR mcierror = 0;
 
    if (argc == 2)
    {
        basic_string<TCHAR> command = argv[1];
        if (command == TEXT("open"))
        {
            mcierror = mciSendStringA(
                ("set cdaudio door open"), returnString,
                _countof(returnString), NULL);
        }
        else if (command == TEXT("close"))
        {
            mcierror = mciSendStringA(
                ("set cdaudio door closed"), returnString,
                _countof(returnString), NULL);
        }
        else
        {
            usage();
            result = 1;
        }
        if (mcierror != 0)
        {
            cerr << "Unable to execute command - ";
            char errorString[MAX_PATH] = { 0 };
            mciGetErrorStringA(mcierror, errorString, _countof(errorString));
            cerr << errorString;
            result = 2;
        }
    }
    else
    {
        usage();
        result = 1;
    }
    return result;
}
 
void usage()
{
    cout << "Usage: tray <command>\n\n";
    cout << "Commands:\n";
    cout << " open  - Opens CD drive tray\n";
    cout << " close - Closes CD drive tray\n";
}
