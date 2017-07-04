#include <stdlib.h>
#include <gtk/gtk.h>
void change_background(GtkWidget*widget,int w,int h,const gchar *path)
{
    gtk_widget_set_app_paintable(widget,TRUE);
    gtk_widget_realize(widget);
    gtk_widget_queue_draw(widget);
    GdkPixbuf *src =gdk_pixbuf_new_from_file(path,NULL);
    GdkPixbuf *dst =gdk_pixbuf_scale_simple(src,w,h,GDK_INTERP_BILINEAR);
    GdkPixmap *pixmap=NULL;
    gdk_pixbuf_render_pixmap_and_mask(dst,&pixmap,NULL,128);
    gdk_window_set_back_pixmap(widget->window,pixmap,FALSE);
    g_object_unref(src);
    g_object_unref(dst);
    g_object_unref(pixmap);
    return ;
}
 static void set_widget_font_size(GtkWidget *widget,int size,gboolean is_button)
{
    GtkWidget *labelChild;
    PangoFontDescription *font;
    gint fontSize=size;

    font=pango_font_description_from_string("Helvetica");
    pango_font_description_set_size(font,fontSize *PANGO_SCALE);

    if(is_button)
    {
        labelChild=gtk_bin_get_child(GTK_BIN(widget));
    }
    else
    {
        labelChild=widget;
    }
    gtk_widget_modify_font(GTK_WIDGET(labelChild),font);
    pango_font_description_free(font);
}
void cb_button(GtkWidget* widget,gpointer data)
{
  int num1,num2;
  char *str1,*str2,*str3,*str4,str5[100],*str6,str7[100],*str8,*str9,str10[100];
  //str1=(char*)malloc(100*sizeof(char));
    // str2=(char*)malloc(100*sizeof(char));
      // str3=(char*)malloc(100*sizeof(char));
//  gtk_init(&argc,&argv);
  GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window),180,100);
  change_background(window,180,100,"2.jpg");
  GtkWidget *vbox=gtk_vbox_new(TRUE,5);
  gtk_container_add(GTK_CONTAINER(window),vbox);

  GtkWidget *label_one=gtk_label_new("label one");
  gtk_container_add(GTK_CONTAINER(vbox),label_one);
  str1=gtk_label_get_label(GTK_LABEL(label_one));
  /*give the num fuzhi

  */
  num1=89;//siample
  //scanf("%s",str1);
  sprintf(str1 , "%d" , num1);
  str9="A";
  strcpy(str10,str9);
  strcat(str10,str1);
  set_widget_font_size(label_one,50,FALSE);
  gtk_label_set_text(GTK_LABEL(label_one),str10);

  GtkWidget *label_two=gtk_label_new("label two");
  gtk_container_add(GTK_CONTAINER(vbox),label_two);
  str2=gtk_label_get_label(GTK_LABEL(label_two));
  num2=13;
  //scanf("%s",str2);
   sprintf(str2, "%d" , num2);
   str4="waiting people:>";
   strcpy(str5,str4);
   strcat(str5,str2);
   //printf("%s",str2);
  gtk_label_set_text(GTK_LABEL(label_two),str5);

  GtkWidget *label_three=gtk_label_new("label_three");
  gtk_container_add(GTK_CONTAINER(vbox),label_three);
  str3=gtk_label_get_label(GTK_LABEL(label_three));
  //scanf("%s",str3);
  sprintf(str3,"%d",num2*3);
  str6="waiting time:>";
  str8="minute";
  strcpy(str7,str6);
  strcat(str7,str3);
  strcat(str7,str8);
  gtk_label_set_text(GTK_LABEL(label_three),str7);

  gtk_widget_show_all (window);
  gtk_main ();
 // return 0;
}

   // printf("you have click the yes\n");
    //gtk_main_quit;

void cb_button1(GtkWidget* widget,gpointer data)
{
    int num1,num2;
  char *str1,*str2,*str3,*str4,str5[100],*str6,str7[100],*str8,*str9,str10[100];
  //str1=(char*)malloc(100*sizeof(char));
    // str2=(char*)malloc(100*sizeof(char));
      // str3=(char*)malloc(100*sizeof(char));
//  gtk_init(&argc,&argv);
  GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window),180,100);
  change_background(window,180,100,"1.jpg");
GtkWidget *vbox=gtk_vbox_new(TRUE,5);
  //gtk_window_set_default_size(GTK_WINDOW(window),180,100);
  gtk_container_add(GTK_CONTAINER(window),vbox);

  GtkWidget *label_one=gtk_label_new("label one");
  gtk_container_add(GTK_CONTAINER(vbox),label_one);
  str1=gtk_label_get_label(GTK_LABEL(label_one));
  /*give the num fuzhi

  */
  num1=89;//siample
  //scanf("%s",str1);
  sprintf(str1 , "%d" , num1);
  str9="B";
  strcpy(str10,str9);
  strcat(str10,str1);
  set_widget_font_size(label_one,50,FALSE);
  gtk_label_set_text(GTK_LABEL(label_one),str10);

  GtkWidget *label_two=gtk_label_new("label two");
  gtk_container_add(GTK_CONTAINER(vbox),label_two);
  str2=gtk_label_get_label(GTK_LABEL(label_two));
  num2=13;
  //scanf("%s",str2);
   sprintf(str2, "%d" , num2);
   str4="waiting people:>";
   strcpy(str5,str4);
   strcat(str5,str2);
   //printf("%s",str2);
  gtk_label_set_text(GTK_LABEL(label_two),str5);

  GtkWidget *label_three=gtk_label_new("label_three");
  gtk_container_add(GTK_CONTAINER(vbox),label_three);
  str3=gtk_label_get_label(GTK_LABEL(label_three));
  //scanf("%s",str3);
  sprintf(str3,"%d",num2*3);
  str6="waiting time:>";
  str8="minute";
  strcpy(str7,str6);
  strcat(str7,str3);
  strcat(str7,str8);
  gtk_label_set_text(GTK_LABEL(label_three),str7);

  gtk_widget_show_all (window);
  gtk_main ();
    //printf("you have click the no\n");
}
int main(int argc,char *argv[])
{
   //GtkWidget *image=gtk_image_new_from_file("4.jpg");
    GtkWidget *main_window;//
    GtkWidget *button,*button1;
    gtk_init(&argc,&argv);
    main_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window),"Bank of china");
    gtk_window_set_default_size(GTK_WINDOW(main_window),300,100);
    change_background(main_window,300,100,"3.jpg");
    GtkWidget *table=gtk_table_new(10,10,TRUE);
   // button=gtk_button_new_with_label("quit the programe\n");
    gtk_container_add(GTK_CONTAINER(main_window),table);
    GtkWidget *entry=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry),"      welcome to here");
    set_widget_font_size(entry,20,FALSE);
    gtk_editable_set_editable(GTK_EDITABLE(entry),FALSE);
    button=gtk_button_new_with_label("vip entry");
    button1=gtk_button_new_with_label("ordinary entry");
    gtk_table_attach_defaults(GTK_TABLE(table),entry,0,10,0,4);
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,3,7,10);
    gtk_table_attach_defaults(GTK_TABLE(table),button1,7,10,7,10);
  // gtk_button_set_image(GTK_BUTTON(button),image);
    //gtk_container_add(GTK_CONTAINER(button),image);

    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(cb_button),NULL);
    g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(cb_button1),NULL);
    gtk_widget_show(button);
    gtk_widget_show_all(main_window);

    gtk_main();
    return 0;
}
