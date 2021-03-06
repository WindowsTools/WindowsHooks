# WinAPI
### list is not ranked

* [GlobalMemoryStatus](https://docs.microsoft.com/zh-cn/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex)

*Retrieves information about the system's current usage of both physical and virtual memory.*

 **P/Invoke**
```
[DllImport("kernel32.dll", SetLastError = true)]
[return: MarshalAs(UnmanagedType.Bool)]
private static extern bool GlobalMemoryStatus(ref MemoryStatus lpBuffer);
```
* [FindWindow](https://docs.microsoft.com/en-us/previous-versions/aa929233(v=msdn.10))

*This function retrieves the handle to the top-level window whose class name and window name match the specified strings. This function does not search child windows.*

 **P/Invoke**
```
[DllImport("User32.dll", EntryPoint = "FindWindow")]
public static extern IntPtr FindWindow(string lpClassName, string lpWindowName);
```
* [FindWindowEx](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-findwindowexa)

*Retrieves a handle to a window whose class name and window name match the specified strings. The function searches child windows, beginning with the one following the specified child window. This function does not perform a case-sensitive search.*

 **P/Invoke**
```
[DllImport("User32.dll", EntryPoint = "FindWindowEx")]
public static extern IntPtr FindWindowEx(IntPtr hwndParent, IntPtr hwndChildAfter, string lpClassName, string lpWindowName);
```
* [SendMessage](https://docs.microsoft.com/en-us/previous-versions/aa931932(v=msdn.10))

*This function sends the specified message to a window or windows*

 **P/Invoke**
```
[DllImport("user32.dll", EntryPoint = "SendMessageA")]
public static extern int SendMessage(IntPtr hwnd, int wMsg, int wParam, int lParam);
```
* [ShowWindow](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-showwindow)
*Sets the specified window's show state.*

**P/Invoke**
```
[DllImport("user32.dll", EntryPoint = "ShowWindow")]
public static extern int SendMessage(IntPtr hwnd, int nCmdShow);
```
* [GetUserName](https://docs.microsoft.com/zh-cn/windows/desktop/api/winbase/nf-winbase-getusernamea)
*Retrieves the name of the user associated with the current thread.*

*P/Invoke*
```
[DllImport("Advapi32.dll", EntryPoint = "GetUserName")]
public static extern int GetUserName(StringBuilder lpBuffer, int pcbBuffer);
```

* [ReleaseCapture](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-releasecapture)
*Releases the mouse capture from a window in the current thread and restores normal mouse input processing. A window that has captured the mouse receives all mouse input, regardless of the position of the cursor, except when a mouse button is clicked while the cursor hot spot is in the window of another thread.*
