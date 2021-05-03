#include "mimikatz.h"
#include "mimikatz-staticlib.h"

#if defined(_MIMIKATZ_STATICLIB)

static BOOL prepare_output_buffer()
{
	if (outputBuffer)
		memset(outputBuffer, 0, outputBufferElements * sizeof(wchar_t));
	else
	{
		outputBufferElements = 0xffff;
		outputBuffer = (wchar_t*)LocalAlloc(LPTR, outputBufferElements * sizeof(wchar_t));
	}
	outputBufferElementsPosition = 0;
	return outputBuffer != NULL;
}

const wchar_t* mimikatz_call_direct(mimikatz_entry_point* func, int argc, const wchar_t* argv[])
{
	if (prepare_output_buffer())
		func(argc, argv);
	return outputBuffer;
}

static void init_or_clean(BOOL init)
{
	if (init)
	{
		RtlGetNtVersionNumbers(&MIMIKATZ_NT_MAJOR_VERSION, &MIMIKATZ_NT_MINOR_VERSION, &MIMIKATZ_NT_BUILD_NUMBER);
		MIMIKATZ_NT_BUILD_NUMBER &= 0x00007fff;
		HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
		if (FAILED(hr))
			PRINT_ERROR(L"CoInitializeEx: %08x\n", hr);
		kull_m_asn1_init();
	}
	else
	{
		kull_m_asn1_term();
		CoUninitialize();
		kull_m_output_file(NULL);
	}
}

void mimikatz_begin()
{
	init_or_clean(TRUE);
}

void mimikatz_end(NTSTATUS status)
{
	init_or_clean(FALSE);

	if (outputBuffer)
	{
		LocalFree(outputBuffer);
		outputBuffer = NULL;
	}
}

#endif
