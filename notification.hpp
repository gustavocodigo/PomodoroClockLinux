#ifdef _WIN32 // Windows
#include <windows.h>
#elif __linux__ // Linux
#include <libnotify/notify.h>
#endif

void show_notification(const char* title, const char* message) {
#ifdef _WIN32
    // Windows Notification
    HWND hwnd = GetDesktopWindow();
    MessageBox(hwnd, message, title, MB_OK | MB_ICONINFORMATION);
#elif __linux__
    // Linux Notification
    notify_init("My Application");
    NotifyNotification* notif = notify_notification_new(title, message, NULL);
    notify_notification_set_timeout(notif, 5000); // 5 seconds
    notify_notification_show(notif, NULL);
    g_object_unref(notif);
#endif
}
