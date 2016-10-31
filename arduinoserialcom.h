#include <windows.h>
#include <cstdio>
#include <tchar.h>
using namespace std;

class Ascom
{
private:
    HANDLE hname;
public:
    Ascom();
    Ascom(char *str);
    ~Ascom();
    bool Ccontrol();
    void Write(char *buf);
    void Read(char *inbuf);
};

Ascom operator << (Ascom _COM, char* str);
Ascom operator >> (Ascom _COM, char* str);

//Constructor: defines the port
Ascom::Ascom()
{
    hname=CreateFile("COM6",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,0);
}

//Parametrized Constructor
Ascom::Ascom(char *str) {
	hname = CreateFile(str, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, 0);
}

//Destructor: closes the door
Ascom::~Ascom()
{
    CloseHandle(hname);
}

//Connction controll, returns 0 if the Arduino is not connected, 1 if it is connected and working
bool Ascom::Ccontrol()
{
    if(hname == INVALID_HANDLE_VALUE)
        return 0;
    else
        return 1;
}

//Writes a string of characters
void Ascom::Write(char *buf)
{
    DWORD NumberOfBytesWritten;
    LPOVERLAPPED lpOverlapped = NULL;

    WriteFile(hname,buf,strlen(buf),&NumberOfBytesWritten,lpOverlapped);
}

//Reads the input characters and stores them in an array of characters
void Ascom::Read(char *inbuf)
{
    DWORD dwBytesRead = 0;

    bool result;
    bool exit = true;
    int bufsize=strlen(inbuf);
    int n=0;

    while(exit || n<=bufsize)
    {
        result=ReadFile(hname,inbuf,bufsize,&dwBytesRead,NULL);
        if(result==true)
            exit=false;
        n++;
    }
}


//Overloading operators << & >>

Ascom operator << (Ascom _COM, char* str)
{
    _COM.Write(str);
    return _COM;
}

Ascom operator >> (Ascom _COM, char* str)
{
    _COM.Read(str);
    return _COM;
}
