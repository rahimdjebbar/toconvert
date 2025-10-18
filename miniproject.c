#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "miniproject.h"


// Function to convert a number from one base to another
char *convertBase(const char *number, int fromBase, int toBase) { // "*" BACH LE PROGRAM YCHFA 3LA LA FONCTION W ma yasrawch des problemes , la fonction return a pointer
    char *endptr;
    long decimal = strtol(number, &endptr, fromBase);
    static char result[65]; //static means that result retains its value between function calls

    if (*endptr != '\0') {//pointer yastoki digit li matgzistich f la base "from base"
        snprintf(result, sizeof(result), "Invalid number for base %d.", fromBase);//snpritf=fgets+printf
        return result;//result rahi mastokia fih return ta3 printf
    }

    if (toBase == 2) {
        int i = 0;
        for (int bit = sizeof(long) * 8 - 1; bit >= 0; bit--) {
            result[i++] = ((decimal >> bit) & 1) + '0'; //Shift and mask method
        }
        result[i] = '\0';
    } else if (toBase == 8) {
        snprintf(result, sizeof(result), "%lo", decimal);
    } else if (toBase == 10) {
        snprintf(result, sizeof(result), "%ld", decimal);
    } else if (toBase == 16) {
        snprintf(result, sizeof(result), "%lX", decimal);
    } else {
        snprintf(result, sizeof(result), "Unsupported target base.");
    }

    return result;
}




// Callback for the "Convert" button
void on_convert_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget **widgets = (GtkWidget **)data;// acceced to gtk array pointer

    const char *number = gtk_entry_get_text(GTK_ENTRY(widgets[0])); // Get the input
    const char *fromBaseStr = gtk_entry_get_text(GTK_ENTRY(widgets[1]));
    const char *toBaseStr = gtk_entry_get_text(GTK_ENTRY(widgets[2]));

    int fromBase = atoi(fromBaseStr);
    int toBase = atoi(toBaseStr);

    char *result = convertBase(number, fromBase, toBase);
    gtk_label_set_text(GTK_LABEL(widgets[3]), result);
}
