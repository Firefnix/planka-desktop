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

void on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
	if (event->type == GDK_KEY_PRESS) {
		if (event->state & GDK_CONTROL_MASK && event->state & GDK_KEY_w) {
			on_window_main_destroy();
		}
	}
}

void add_window_callback_symbols(void)
{
	gtk_builder_add_callback_symbol(
		get_builder(),
		"on_window_main_destroy",
		G_CALLBACK(on_window_main_destroy)
	);
	gtk_builder_add_callback_symbol(
		get_builder(),
		"on_key_press",
		G_CALLBACK(on_key_press)
	);
}
