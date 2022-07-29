#include <gtk/gtk.h>

GdkPixbuf *create_pixbuf(const gchar * filename) {
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   
    if (!pixbuf) {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}

void print_msg(GtkWidget *widget, gpointer window) {
    g_print("Button clicked\n");
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *pimage;
    GtkWidget *button;
    GtkWidget *halign;

    gtk_init(&argc, &argv);

    /* Création de la fenêtre */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Bataille navale v0.1");
    gtk_window_set_default_size(GTK_WINDOW(window), 1366, 768);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);    
    
    /* Création du bouton cliquable */
    button = gtk_button_new_with_mnemonic("_Button");
    g_signal_connect(button, "clicked", 
        G_CALLBACK(print_msg), NULL);
  
    halign = gtk_alignment_new(0, 0, 0, 0);
    gtk_container_add(GTK_CONTAINER(halign), button);
    
    /* Création de l'arrière plan */
    pimage=gtk_image_new_from_file("/home/etud/Documents/Bataille-navale/pic_gkt/fond.bmp");
    gtk_container_add(GTK_CONTAINER(halign), pimage);
    gtk_container_add(GTK_CONTAINER(window), halign);

  
    /* Affichage de la fenêtre */
    gtk_widget_show_all(window);
  
    g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_main();

    return 0;
}
