#include <gtk/gtk.h>

static void on_video_file_selected(GtkFileChooser *file_chooser, GtkWindow *window) {
  // Get the selected video file.
  GFile *file = gtk_file_chooser_get_file(file_chooser);

  // Create a new video widget.
  GtkVideo *video = gtk_video_new_for_file(file);

  // Add the video widget to the window.
  gtk_container_add(GTK_CONTAINER(window), video);

  // Play the video.
  gtk_video_play(video);
}

int main(int argc, char *argv[]) {
  // Initialize GTK.
  gtk_init(&argc, &argv);

  // Create a new window.
  GtkWindow *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // Set the title of the window.
  gtk_window_set_title(window, "Video Feed");

  // Create a file chooser.
  GtkFileChooser *file_chooser = gtk_file_chooser_new("Select a video file", window, GTK_FILE_CHOOSER_ACTION_OPEN);

  // Add the file chooser to the window.
  gtk_container_add(GTK_CONTAINER(window), file_chooser);

  // Set the on-select callback for the file chooser.
  g_signal_connect(file_chooser, "selection-changed", G_CALLBACK(on_video_file_selected), window);

  // Show the window.
  gtk_widget_show_all(window);

  // Run the GTK main loop.
  gtk_main();

  return 0;
}

