# WinAPI
list is not ranked

* [GlobalMemoryStatus](https://docs.microsoft.com/zh-cn/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex)

 **P/Invoke**
```
  [DllImport("kernel32.dll", SetLastError = true)]
  [return: MarshalAs(UnmanagedType.Bool)]
  private static extern bool GlobalMemoryStatus(ref MemoryStatus lpBuffer);
```
