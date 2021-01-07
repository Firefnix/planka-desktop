#include <app/app.h>
#include <widgets/widgets.h>

/// Return a [struct AppWidgets *] containing all the widgets of the app
struct AppWidgets *get_widgets(void)
{
    static struct AppWidgets *widgets = NULL;
    if (!widgets) {
        widgets = g_slice_new(struct AppWidgets);
        widgets->window = get_window();
        widgets->webview = get_widget("webkit_webview");
    }
    return widgets;
}

/// Free the widgets and the builder
void free_widgets(void)
{
    struct AppWidgets *widgets = get_widgets();
    g_slice_free(struct AppWidgets, widgets);
    widgets = NULL;
    free_builder();
}

/// Connect the signals of the widgets to the event callbacks
void connect_signals(void)
{
    gtk_builder_connect_signals(get_builder(), get_widgets());
}
