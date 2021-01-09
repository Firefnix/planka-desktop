#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

#include <widgets/widgets.h>

void webview_load(const gchar *uri)
{
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(get_widgets()->webview), uri);
}

void on_webkit_webview_load_changed(
    WebKitWebView *web_view,
    WebKitLoadEvent load_event,
    gpointer data
)
{
    switch (load_event) {
        case WEBKIT_LOAD_STARTED:
            break;
        case WEBKIT_LOAD_REDIRECTED:
            break;
        case WEBKIT_LOAD_COMMITTED:
            break;
        case WEBKIT_LOAD_FINISHED:
            break;
        default:
            g_assert_not_reached();
    }
}

void add_webview_callback_symbols(void)
{
    // No callbacks yet
}
