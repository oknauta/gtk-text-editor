// File: framework.h
// Date: 2024-07-31

#ifndef FRAMEWORK
#define FRAMEWORK

#include <gtk/gtk.h>

typedef struct
{
    GtkApplication *gtk_app;
    int status;
    GtkWidget *window;
    GtkWidget *text_view;
    GtkWidget *header_menu;
    GtkWidget *item;
    GtkWidget *scroll;
    GtkWidget *save_button;
}application_data;

static void Scroll();
static void SaveFile();
static void HeaderMenu();
static void activate(GtkApplication *app, gpointer user_data);

#endif // FRAMEWORK