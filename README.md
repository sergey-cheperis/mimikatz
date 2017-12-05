# mimikatz-staticlib

Mimikatz built as a static library.

## Build

This project is configured for Visual Studio 2017 and may not build with other versions. 

Supported target systems: Windows Vista / 7 / 10, 32-bit and 64-bit.

Unlike original `mimikatz`, it does not include `mimilib` and `mimidrv`. Also, `minesweeper` and `busylights` modules are disabled.

## Usage

```
#include "mimikatz-staticlib/mimikatz/mimikatz-staticlib.h"

mimikatz_begin();
wcout << mimkatz_exec(L"privilege::debug") << L"\n";
wcout << mimkatz_exec(L"sekurlsa::logonPasswords") << L"\n";
wcout << mimkatz_exec(L"coffee") << L"\n";
mimikatz_end();
```

This project is research only, plese do not use for illegal purposes.

## Credits

Mimikatz (c) Benjamin DELPY `gentilkiwi` (benjamin@gentilkiwi.com) / Vincent LE TOUX (vincent.letoux@gmail.com)
http://blog.gentilkiwi.com/mimikatz

CC BY 4.0 licence - https://creativecommons.org/licenses/by/4.0/
