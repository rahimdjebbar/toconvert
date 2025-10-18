#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "miniproject.h"

int main(int argc, char *argv[])
//argc and argv are used to receive information during program execution; argc is the number of pieces of information and argv is the information in a dynamic array
{
    GtkWidget *window, *grid;
    GtkWidget *entry_number, *entry_fromBase, *entry_toBase, *btn_convert, *lbl_result; // Array of pointers

    gtk_init(&argc, &argv); // Prepare for program execution and give access to information

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "⇌𝐁𝐚𝐬𝐞 𝐂𝐨𝐧𝐯𝐞𝐫𝐭𝐞𝐫⇌");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 260);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // Stop the process properly

    // Create a grid to organize widgets
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Entry for the number
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Number ➩"), 0, 0, 1, 1);
    entry_number = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry_number, 1, 0, 1, 1);

    // Entry for the source base
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new(" Source Base ➩"), 0, 1, 1, 1);
    entry_fromBase = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry_fromBase, 1, 1, 1, 1);

    // Entry for the target base
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Target Base (10/2/8/16) ➩"), 0, 2, 1, 1);
    entry_toBase = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry_toBase, 1, 2, 1, 1);

    // Button to start the conversion
    btn_convert = gtk_button_new_with_label("┕━━━━↻━━┑ 𝙲𝚘𝚗𝚟𝚎𝚛𝚝 ┍━━↺━━━━┙");
    gtk_grid_attach(GTK_GRID(grid), btn_convert, 0, 3, 2, 1);

    // Label to display the result
    lbl_result = gtk_label_new("⚜️=====𝕽𝖊𝖘𝖚𝖑𝖙=====⚜️");
    gtk_grid_attach(GTK_GRID(grid), lbl_result, 0, 10, 2, 1);

    // Connect the button to its callback function
    GtkWidget *widgets[4] = {entry_number, entry_fromBase, entry_toBase, lbl_result};// array
    g_signal_connect(btn_convert, "clicked", G_CALLBACK(on_convert_clicked), widgets);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("📣 You can convert a number from any \n       base you want to base 10/2/8/16 !"), 0, 6, 5, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("🧑🏻‍💻 𝐵𝑎𝑑𝑖𝑠 𝐵𝑜𝑢𝑑𝑗𝑎𝑜𝑢𝑖 \n🧑🏻‍💻 𝑅𝑎ℎ𝑖𝑚 𝐾𝑎𝑑𝑑𝑜𝑢𝑟 𝐷𝑗𝑒𝑏𝑏𝑎𝑟"), 0, 15, 1, 2);

    // Display all widgets
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
