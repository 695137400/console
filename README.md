ConsoleZ
========

![screenshot005](https://github.com/cbucher/console/wiki/screenshot001.png)

This is a modified version of Console 2 for a better experience under Windows Vista/7/8 and a better visual rendering.

This fork supports:

* Splitting Tabs into views (horizontally and vertically)
* Grouping views (so input sent to one goes to all of them)
* Windows Vista aero glass theme
* Windows 7 jumplist
* Windows 7 wallpaper positions and slideshow
* Windows 8 wallpapers on dual screen
* Zooming with Ctrl-Mouse
* Quake style console animation
* Strict monospace font rendering
* Settable opacity of text background color
* Full screen
* and more...

Changelog
=========

    ! changed
    - removed
    + added
    * fixed

Changes in 1.09.0 beta 6 (22 Nov 2013)

    ! Title options are more consistent.
    ! Activate Console (global) hotkey minimizes the application if active.
    ! Quake like: activates the previous application when hiding.
    ! Buffer rows limit increased to 32766.
    + Focus follows mouse.
    + New actions in "File" menu:
      "Close All Tabs BUT This"
      "Close All Tabs to the Left"
      "Close All Tabs to the Right"
    + Right click on tabs: selects the tab and displays a popup menu.
    + New cursor that mimics the Windows console's one.
    + Can specify an initial application window size (in pixels).
    + Can save the application window size (in pixels) on exit.
    + Allow multiple instances (or single instance).
    + Blinking XTerm Cursor.
    + Support of drag and drop in settings.
    + Can hide icons in tabs bar.
    * Fix problem with dead chars sent to multiple consoles.
    * Fix icon extraction with negative index.
    * Fix a visual bug when caption and resize are removed.
    * Transmit the current working directory when application instance is reused.
    * Maximized application was retored at wrong position.

Changes in 1.08.0 (28 Sep 2013)

    ! prettier split bar (aero only).
    + displays intensified colors in bold.
    + displays intensified colors in italic.
    + user can configure an extra width added to the fixed width of the font.
    + shell can be launched with elevated priviledges (run as administrator).
    + supports shell link files (.lnk) in tabs settings.
      Icon, program's path, arguments, working directory and "run as administrator" option
      are extracted from the link.
    * Some cursors was hidden with black color.
    * Fade cursor was blinking when console was inactive.
    * Fix DBCS rendering.
    * Fix DBCS selection.
    * Fix DBCS cursor.
    * Fix hang when starting with multiple startup tabs.
    * Pressing alt key will switch the menu bar visibility only if menu bar is not permanently on.
    * Fix pasting to multiple views when views are grouped.
    * Inputs are no longer sent to views do not belong to the group.
    * Active view cannot be painted (and 100% cpu).

Changes in 1.07.1 (05 Jul 2013)

    * Sometimes the application could not start with multiple tabs.
      The delay between initial tabs was uninitialized.
    * Icons missing in tabs menu popup.

Changes in 1.07.0 (26 May 2013)

    ! Limits the maximized windows size on monitors with taskbar
      so ConsoleZ, with no border, no longer overlaps the taskbar when WIN+UP is pressed
    ! Restart is no longer needed for this appearance setting: "Tabs on bottom"
    ! Settings edition no longer modifies the zoom factor
    + Full screen support
    + Full screen button in taskbar
    + Full screen hot key (default: F11)
    + Full screen settings: can start in full screen and select the full screen monitor
    + Left and right delimiters for word selection can be set
    + View can be closed from the menu
    + New behavior settings:
      "Allow closing the last tab/view"
      "Confirm before closing multiple tabs/views"
    + Color map per tab
    + Color map can be imported from another configuration file
    + 3 context menus can be configured in mouse settings:
      Context menu #1 = full menu
      Context menu #2 = configured tabs
      Context menu #3 = opened tabs
    + Zoom factor in status bar
    + New hotkeys:
      "Zoom 100%"      (default: CTRL+0 NUM KEYPAD)
      "Zoom increment" (default: CTRL++ NUM KEYPAD)
      "Zoom decrement" (default: CTRL+- NUM KEYPAD)
    * Caption was removed when border was unchecked
    * Display of hotkey '&' in menu was truncated
    * Press ALT key, with mouse action, no longer shows/hides the menu

Changes in 1.06.0 (24 Mar 2013)

    ! The cloned tab title is suffixed with (2).
    ! about dialog box improvement
    ! Hotkeys are displayed in the menu
    ! Restart is no longer needed for these appearance settings:
      "Caption"
      "Resizable"
      "Border"
      "Taskbar button"
    + new option "Net Only" to "Run as user"
      the user credentials are used only to access network resources
      the user is displayed in tab title surrounded with braces
    + "Run as user" supports UPN format (user@domain).
    + new buttons in the toolbar:
      "Rename tab"
      "Split Horizontally"
      "Split Vertically"
    + new hotkeys:
      "New Tab 11"            (default: CTRL+F11)
      "New Tab 12"            (default: CTRL+F12)
      "Switch to left view"   (default: ALT+LEFT)
      "Switch to right view"  (default: ALT+RIGHT)
      "Switch to top view"    (default: ALT+UP)
      "Switch to bottom view" (default: ALT+DOWN)
    + Windows key can be used in global hotkeys.
    + The glass frame extended in client area (toolbar and tabs) can be used to
      move the window.
    + The glass frame extended in client area (tabs only) can be used to
      maximize or restore the window by double clicking.
    * If the only one tab was cloned, the "delete" button remained disabled.
    * Under Windows 8, the call to GetTextMetrics function failed with some fonts.
      The return code wasn't checked and char metrics wasn't correctly initialized.
    * wrong tabs scrolling
    * close button drawing
    * background of tab was black with basic Windows theme
    * error handling and return code checking
    * Re-add tray icon if Windows Explorer restarts.
    * When files are dropped on a view, this view gets the focus.
    * Title was not updated when view changed.

Changes in 1.05.0 (2 Feb 2013)

    ! FreeImage 3.15.4
    ! Visual Studio 2012
    ! WTL 8.1.12085
    ! Forces monospace displaying
      by adjusting the size of chars larger than average width font.
    ! Limits vertical scrolling to the furthest buffer location viewed.
    + Windows 8 can use a wallpaper per monitor.
    + Displays a closing confirmation when there is only one tab
      but multiple views.
    + Improves the status bar with:
      console buffer size, console screen size,
      selection size and console PID
    * Dropping a file affects all views in a group.
    * Aero glass margins are resetted when composition change
      (hibernation disables DWM, at wakeup ConsoleZ was fully transparent).
