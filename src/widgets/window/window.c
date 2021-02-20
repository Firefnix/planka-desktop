#include <gtk/gtk.h>
#include <app/app.h>
#include <widgets/widgets.h>

static gboolean key_event_closes_window(const GdkEventKey *event);

GtkWidget *get_window(void)
{
	static GtkWidget *window = NULL;
	if (!window) {
		window = get_widget("window_main");
		if (should_show_top_bar() == FALSE) {
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

Propagation on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
	if (event->type == GDK_KEY_PRESS) {
		if (key_event_closes_window(event)) {
			on_window_main_destroy();
			return STOP_PROPAGATION;
		}
	}
	return PROPAGATE;
}

/// Return true if the [event] should cause the window to close, else false.
static gboolean key_event_closes_window(const GdkEventKey *event)
{
	if (event->state & GDK_CONTROL_MASK) {
		if (event->keyval == GDK_KEY_q || event->keyval == GDK_KEY_w) {
			return true;
		}
	}
	return false;
}

/// Add the callbacks symbols for the window.
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
