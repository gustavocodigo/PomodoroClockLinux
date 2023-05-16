#include <iostream>

#include <chrono>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <climits>
#include <iostream>
#include <locale>
#include <string>
#include <thread>
#include <vector>
#include <filesystem>

// linux
#include <unistd.h>

#include "libs/webview/webview.h"

#include <gtk/gtk.h>
#include <gtk/gtk.h>

// base64
#include <iostream>
#include <string>
#include <algorithm>

#include "notification.hpp"

std::string show_notification_js_binding(std::string args)
{
    std::string title = webview::json_parse(args, "", 0);
    std::string message = webview::json_parse(args, "", 1);
    show_notification(title.c_str(), message.c_str());
    return "{}";
}


std::string show_alert_js_binding(std::string args) {
    std::string message = webview::json_parse(args,"", 0);
  GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", message.c_str());
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
  return "{}";
}






int main()
{
    webview::webview w(true, nullptr);
    w.set_title("Pomodoro clock");
    w.set_size(360, 310, WEBVIEW_HINT_FIXED);
    gtk_window_set_resizable(GTK_WINDOW(w.window()), FALSE);
    // w.set_size(9000, 80000, WEBVIEW_HINT_MAX);
    std::filesystem::path cwd = std::filesystem::current_path() / "../index.html";
    w.navigate(std::string("file://") + cwd.string());
    w.bind("show_notification", show_notification_js_binding);
    w.bind("show_alert_js_binding", show_alert_js_binding);
    w.run();
    return 0;
}
