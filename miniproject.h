#ifndef MINIPROJECT_H_INCLUDED
#define MINIPROJECT_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

char *convertBase(const char *number, int fromBase, int toBase);
void on_convert_clicked(GtkWidget *widget, gpointer data);
#endif // MINIPROJECT_H_INCLUDED
