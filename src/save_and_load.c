// File: save_and_load.c
// Date: 2024-08-02

#include "framework.h"

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

    if(file != NULL)
    {
        fputs(text, file);
        /* Closing */
        fclose(file);
    }
    else
    {
        gtk_alert_dialog_show(gtk_alert_dialog_new("Failed to save file."), GTK_WINDOW(app_data.window));
    }

    
    g_free(text);
}

void loadFile()
{
    GtkAlertDialog *upcoming = gtk_alert_dialog_new("Upcoming...");
    gtk_alert_dialog_show(upcoming, GTK_WINDOW(app_data.window));
}