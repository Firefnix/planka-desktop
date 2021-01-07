#include <gtk/gtk.h>
#include <app/app.h>
#include <widgets/widgets.h>

GtkWidget *get_window(void)
{
	static GtkWidget *window = NULL;
	if (!window) {
		window = get_widget("window_main");
		if (should_show_top_bar()) {
			gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
		}
	}
	return window;
}

void maximize_window(void)
{
	gtk_window_maximize(GTK_WINDOW(get_widgets()->window));
}

void on_window_main_destroy(void)
{
	gtk_main_quit();
}
