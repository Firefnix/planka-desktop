#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

void setup_webview(void)
{
    WebKitWebContext *context = webkit_web_context_get_default();
    WebKitCookieManager *cookie_manager =
        webkit_web_context_get_cookie_manager(context);
    webkit_cookie_manager_set_accept_policy(
        cookie_manager,
        WEBKIT_COOKIE_POLICY_ACCEPT_ALWAYS
    );
}
