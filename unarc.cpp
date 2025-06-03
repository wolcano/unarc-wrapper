#include <windows.h>
#include <iostream>

using namespace std;

typedef unsigned int(__stdcall *f_cb)(const char*,int,int,const char*);

typedef unsigned int(__stdcall *f_wcb)(f_cb,int,char**);

typedef int(__cdecl *f_unarc)(f_cb,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*,const char*);

unsigned int __stdcall cb(const char* a,int b, int c, const char* d) {
	cout << (char*)a << " " << b << " " << c << (char*)d << endl;
	return 0;
}

unsigned int __stdcall wcb(f_cb cb,int argc, char** argv) {
	cout << "cb " << hex << cb << " param count " << argc << endl;
	
	for(int i=0;i<argc;i++){
		cout << (char*)argv[i] << endl;
		}
	
	const char *n="";
	cb(n,0,0,n);
	
	return 0;
}

int main(int argc, char** argv) {

	HINSTANCE h = LoadLibrary("unarc.dll");
	if (!h) {
		DWORD err = GetLastError();
		printf("LoadLibrary failed with error: %d\n", err);
		cout << "unarc.dll not found" << endl;
		return 0;
	}

	f_unarc unarc = (f_unarc)GetProcAddress(h, "FreeArcExtract");
	if (!unarc) {
		cout << "FreeArcExtract not found" << endl;
		return 0;
	}

	if( argc <7) {
		cout << "usage a.exe a b c d e f" << endl;
		return 0;
	}

	char const *a1=argv[1];
	char const *a2=argv[2];
	char const *a3=argv[3];
	char const *a4=argv[4];
	char const *a5=argv[5];
	char const *a6=argv[6];
	const char *n="";
	unarc(&cb,a1,a2,a3,a4,a5,a6,n,n,n,n);

	return 0;
}
