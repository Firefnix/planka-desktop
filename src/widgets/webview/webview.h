#include <webkit2/webkit2.h>

void webview_load(const gchar *uri);

void on_webkit_webview_load_changed(
    WebKitWebView *web_view,
    WebKitLoadEvent load_event,
    gpointer data
);
