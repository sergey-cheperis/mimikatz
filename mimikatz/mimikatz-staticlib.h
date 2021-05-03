#pragma once

typedef NTSTATUS mimikatz_entry_point(int argc, const wchar_t* argv[]);

#ifdef __cplusplus
extern "C"
{
#endif

void mimikatz_begin();
void mimikatz_end(
#ifdef __cplusplus
	NTSTATUS status = 0
#else
	NTSTATUS status
#endif
);
const wchar_t* mimikatz_call_direct(mimikatz_entry_point* func, int argc, const wchar_t* argv[]);

#ifdef __cplusplus
}
#endif


#pragma comment(lib, "delayimp")

#pragma comment(lib, "advapi32.hash.lib")
#pragma comment(lib, "bcrypt.lib")
#pragma comment(lib, "cryptdll.lib")
#pragma comment(lib, "dnsapi.lib")
#pragma comment(lib, "hid.lib")
// #pragma comment(lib, "mincore.lib")  // win >= 8 only
#pragma comment(lib, "msasn1.min.lib")
#pragma comment(lib, "msxml2.lib")
#pragma comment(lib, "ncrypt.lib")
#pragma comment(lib, "netapi32.lib")
#pragma comment(lib, "netapi32.min.lib")
#pragma comment(lib, "ntdll.min.lib")
#pragma comment(lib, "rpcrt4.lib")
#pragma comment(lib, "samlib.lib")
#pragma comment(lib, "setupapi.lib")
#pragma comment(lib, "userenv.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "winscard.lib")
#pragma comment(lib, "winsta.lib")
#pragma comment(lib, "wldap32.lib")
#pragma comment(lib, "fltlib.lib")
#pragma comment(lib, "cabinet.lib")
