// File: main.c
// Date: 2024-07-31

#include "framework.h"

application_data app_data;

int main(int argc, char **argv)
{
    
    app_data.gtk_app = gtk_application_new("org.oddyst.text", G_APPLICATION_DEFAULT_FLAGS);
    
    g_signal_connect(app_data.gtk_app, "activate", G_CALLBACK(activate), NULL);
    
    app_data.status = g_application_run(G_APPLICATION(app_data.gtk_app), argc, argv);

    g_object_unref(app_data.gtk_app);

    return 0;
}


static void Scroll()
{
    app_data.scroll = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(app_data.scroll), app_data.text_view);
}

static void SaveFile()
{
    GtkTextBuffer *buffer;
    GtkTextIter start, end;
    gchar *text;
    FILE *file;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_data.text_view));
    gtk_text_buffer_get_bounds(buffer, &start, &end);

    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    
    file = fopen("Text.txt", "w");
    fputs(text, file);
    
    fclose(file);
    g_free(text);


    /*
    GtkTextBuffer *buffer;
    GtkTextIter start, end;
    gchar *text;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_data.text_view));
    gtk_text_buffer_get_bounds(buffer, &start, &end);

    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);


    FILE *file;

    gchar *file_name = "File.txt";

    file = fopen(file_name, "w");

    fputs(text, file);

    fclose(file);

    g_free(text);
    */
}

static void HeaderMenu()
{
    app_data.header_menu = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(app_data.window), app_data.header_menu);
    
    app_data.save_button = gtk_button_new_with_label("Save");
    g_signal_connect(app_data.save_button, "clicked", G_CALLBACK(SaveFile), NULL);
    gtk_header_bar_pack_start(GTK_HEADER_BAR(app_data.header_menu), app_data.save_button);
}

static void TextView()
{
    app_data.text_view = gtk_text_view_new();
    gtk_text_view_set_top_margin(GTK_TEXT_VIEW(app_data.text_view), 10);
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(app_data.text_view), 10);
    gtk_text_view_set_right_margin(GTK_TEXT_VIEW(app_data.text_view), 10);
    gtk_text_view_set_bottom_margin(GTK_TEXT_VIEW(app_data.text_view), 10);
}

static void activate(GtkApplication *app, gpointer user_data)
{
    
    app_data.window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(app_data.window), "Text editor");
    gtk_window_set_default_size(GTK_WINDOW(app_data.window), 1280, 720);
    
    HeaderMenu();
    TextView();
    Scroll();
    
    gtk_window_set_child(GTK_WINDOW(app_data.window), app_data.scroll);

    gtk_window_present(GTK_WINDOW(app_data.window));
}