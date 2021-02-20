#include <gtk/gtk.h>
#include "app/data/data.h"
#include "args.h"

static GOptionEntry *get_args_entries(void);

/// Parse the program's arguments
void parse_args(gint argc, gchar **argv) {
    GOptionContext *context = g_option_context_new("");
    g_option_context_add_main_entries(context, get_args_entries(), NULL);
    g_option_context_add_group(context, gtk_get_option_group(TRUE));
    if (!g_option_context_parse(context, &argc, &argv, NULL)) {
        g_print ("option parsing failed\n");
        exit(1);
    }
}

static gboolean hide_bar = FALSE;

/// Getter for the static variable [hide_bar]
gboolean should_show_top_bar(void) {
    return !hide_bar;
}

/// Return a list of [GOptionEntry] defining the arguments of the program
static GOptionEntry *get_args_entries(void) {
    static GOptionEntry entries[] = {
        {
            "hide-bar",
            'b',
            G_OPTION_FLAG_NONE,
            G_OPTION_ARG_NONE,
            &hide_bar,
            "Hide the top bar",
            NULL
        }
    };
    return entries;
}
