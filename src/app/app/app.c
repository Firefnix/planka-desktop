#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

#include "widgets/widgets.h"
#include "app/data/data.h"

static void load_webkit_types(void)
{
	webkit_web_view_get_type();
	webkit_settings_get_type();
}

void setup(const gchar *uri)
{
	load_webkit_types();
    struct AppWidgets *widgets = get_widgets();

	webview_load(uri);

	gtk_widget_grab_focus(widgets->webview);

	maximize_window();
	gtk_widget_show_all(widgets->window);
}
