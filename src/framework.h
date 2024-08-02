// File: framework.h
// Date: 2024-07-31

#ifndef FRAMEWORK
#define FRAMEWORK

#include <gtk/gtk.h>

typedef struct
{
    /* APP */

    GtkApplication *gtk_app;
    int status;

    /* WIDGETS */

    GtkWidget *window;
    GtkWidget *header_menu;
    GtkWidget *save_button;
    GtkWidget *load_button;
    GtkWidget *text_view;
    GtkWidget *scroll;
}application_data;

void run();
void activate();
void saveFile();
void loadFile();
void headerMenu();
void textView();

#endif //FRAMEWORK

