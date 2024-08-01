// File: framework.c
// Date: 2024-08-01

#include "framework.h"

application_data app_data;

void run(int argc, char **argv)
{
    app_data.gtk_app = gtk_application_new("org.oddyst.text", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app_data.gtk_app, "activate", G_CALLBACK(activate), NULL);
    
    app_data.status = g_application_run(G_APPLICATION(app_data.gtk_app), argc, argv);

    g_object_unref(app_data.gtk_app);
}

void activate(GtkApplication *app)
{
    app_data.window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(app_data.window), "Text editor");
    gtk_window_set_default_size(GTK_WINDOW(app_data.window), 1280, 720);
    
    headerMenu();
    textView();

    gtk_window_present(GTK_WINDOW(app_data.window));
}

void saveFile()
{
    /* Starting variables */

    // Buffer for text
    GtkTextBuffer *buffer;
    // Setting up the bounds of starting and ending of the buffer
    GtkTextIter start, end;
    // Text that will be saved by the buffer
    gchar *text;
    // File that will be saved on computer
    FILE *file;

    /* Making the magick */

    // Getting the buffer from the text view
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_data.text_view));
    // Getting the bounds from the buffer to variables
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    // Getting the text from the buffer to text
    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    
    // Opening file with the name Text.txt on the mode write
    file = fopen("Text.txt", "w");
    // Writing the what is in text on file
    fputs(text, file);
    
    /* Closing */
    fclose(file);
    g_free(text);
}


void headerMenu()
{
    app_data.header_menu = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(app_data.window), app_data.header_menu);
    
    app_data.save_button = gtk_button_new_with_label("Save");
    g_signal_connect(app_data.save_button, "clicked", G_CALLBACK(saveFile), NULL);
    gtk_header_bar_pack_start(GTK_HEADER_BAR(app_data.header_menu), app_data.save_button);
}


void textView()
{
    app_data.text_view = gtk_text_view_new();
    gtk_text_view_set_top_margin(GTK_TEXT_VIEW(app_data.text_view), 10);
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(app_data.text_view), 10);
    gtk_text_view_set_right_margin(GTK_TEXT_VIEW(app_data.text_view), 10);
    gtk_text_view_set_bottom_margin(GTK_TEXT_VIEW(app_data.text_view), 10);

    app_data.scroll = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(app_data.scroll), app_data.text_view);
    gtk_window_set_child(GTK_WINDOW(app_data.window), app_data.scroll);
}