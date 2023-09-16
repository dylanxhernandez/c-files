/*
  
  The objective of this program is to test C with the gtk dev tools

  These tools can be installed using the following commands:
  - debian/ubuntu: `sudo apt-get install libgtk-3-dev`
  - rhel/fedora: `sudo dnf install gtk3-devel`

  This application simply runs a blank window to test the display

  To compile, run the following:
  - gcc `pkg-config --cflags gtk+-3.0` -o <name-of-executable> blankgui.c `pkg-config --libs gtk+-3.0`

*/
#include <gtk/gtk.h> 

int main (int argc, char **argv) { 
  gtk_init (&argc, &argv); 
 
  GtkWidget *w = gtk_window_new (GTK_WINDOW_TOPLEVEL); 
  gtk_window_set_title (GTK_WINDOW (w), "A Blank Application"); 
  gtk_window_set_default_size (GTK_WINDOW (w), 400, 400); 
 
  g_signal_connect (w, "destroy", G_CALLBACK (gtk_main_quit), NULL); 
 
  gtk_widget_show (w); 
  gtk_main (); 

  return 0; 
} 
