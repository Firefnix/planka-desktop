#include <gtk/gtk.h>

struct AppWidgets {
    GtkWidget *window;
	GtkWidget *webview;
};

struct AppWidgets *get_widgets(void);
void free_widgets(void);
void connect_signals(void);
