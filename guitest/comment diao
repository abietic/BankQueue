#include <stdlib.h>
#include <gtk/gtk.h>
void cb_button(GtkWidget* widget,gpointer data)
{
    int num=1;
   //gtk_main_q
  // printf("1\n");
}
void cb_button1(GtkWidget* widget,gpointer data)
{
   int num=2;
}
void cb_button2(GtkWidget* widget,gpointer data)
{
   int num=3;
}
void cb_button3(GtkWidget* widget,gpointer data)
{
   int num=4;
}
void cb_button4(GtkWidget* widget,gpointer data)
{
   int num=5;
}
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
void comment()
{
   //GtkWidget *image=gtk_image_new_from_file("4.jpg");
    GtkWidget *main_window;//
    GtkWidget *button,*button1,*button2,*button3,*button4;
  //  gtk_init(&argc,&argv);
    main_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window),"Bank of china");
    gtk_window_set_default_size(GTK_WINDOW(main_window),300,100);
    change_background(main_window,300,100,"3.jpg");
    GtkWidget *table=gtk_table_new(4,7,TRUE);
   // button=gtk_button_new_with_label("quit the programe\n");
    gtk_container_add(GTK_CONTAINER(main_window),table);
    GtkWidget *entry=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry),"  Please input your comment:");
    set_widget_font_size(entry,15,FALSE);
    gtk_editable_set_editable(GTK_EDITABLE(entry),FALSE);
    button=gtk_button_new_with_label("1");
    button1=gtk_button_new_with_label("2");
    button2=gtk_button_new_with_label("3");
    button3=gtk_button_new_with_label("4");
    button4=gtk_button_new_with_label("5");
    gtk_table_attach_defaults(GTK_TABLE(table),entry,0,7,0,1);
    gtk_table_attach_defaults(GTK_TABLE(table),button,1,2,2,3);
    gtk_table_attach_defaults(GTK_TABLE(table),button1,2,3,2,3);
    gtk_table_attach_defaults(GTK_TABLE(table),button2,3,4,2,3);
    gtk_table_attach_defaults(GTK_TABLE(table),button3,4,5,2,3);
    gtk_table_attach_defaults(GTK_TABLE(table),button4,5,6,2,3);
  // gtk_button_set_image(GTK_BUTTON(button),image);
    //gtk_container_add(GTK_CONTAINER(button),image);
 //  g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_button_clicked),NULL);
   g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(cb_button),NULL);
    g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(cb_button1),NULL);
    g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(cb_button2),NULL);
    g_signal_connect(G_OBJECT(button3),"clicked",G_CALLBACK(cb_button3),NULL);
    g_signal_connect(G_OBJECT(button4),"clicked",G_CALLBACK(cb_button4),NULL);
   // gtk_widget_show(button);
 gtk_widget_show_all(main_window);
//gtk_widget_destroy (main_window);
    gtk_main();

    return ;
}
void cb_button5(GtkWidget* widget,gpointer data)
{int num=1;
    comment();

     // gtk_widget_destroy (dialog);
}
void cb_button6(GtkWidget* widget,gpointer data)
{int num=2;
   comment();

}
void cb_button7(GtkWidget* widget,gpointer data)
{int num=3;
   comment();
}
void cb_button8(GtkWidget* widget,gpointer data)
{int num=4;
   comment();
}
void cb_button9(GtkWidget* widget,gpointer data)
{int num=5;
   comment();
}
void cb_button10(GtkWidget* widget,gpointer data)
{
    int num=6;
    comment();
}
void cb_button11(GtkWidget* widget,gpointer data)
{
    int num=7;
   comment();
}
void cb_button12(GtkWidget* widget,gpointer data)
{
    int num=8;
   comment();
}
void cb_button13(GtkWidget* widget,gpointer data)
{
    int num=9;
   comment();
}
void cb_button14(GtkWidget* widget,gpointer data)
{
    int num=10;
   comment();
}
void cb_button15(GtkWidget* widget,gpointer data)
{
    int num=11;
    comment();
}
void cb_button16(GtkWidget* widget,gpointer data)
{
    int num=12;
   comment();
}
void cb_button17(GtkWidget* widget,gpointer data)
{
    int num=13;
   comment();
}
void cb_button18(GtkWidget* widget,gpointer data)
{
    int num=14;
   comment();
}
void cb_button19(GtkWidget* widget,gpointer data)
{
    int num=15;
   comment();
}
void cb_button20(GtkWidget* widget,gpointer data)
{
    int num=16;
   comment();
}
int main(int argc,char *argv[])
{
   //GtkWidget *image=gtk_image_new_from_file("4.jpg");
    GtkWidget *main_window;//
    GtkWidget *button,*button1,*button2,*button3,*button4,*button5,*button6,*button7,*button8,
    *button9,*button10,*button11,*button12,*button13,*button14,*button15;
    gtk_init(&argc,&argv);
    main_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window),"Bank of china");
    gtk_window_set_default_size(GTK_WINDOW(main_window),300,100);
    change_background(main_window,300,100,"3.jpg");
    GtkWidget *table=gtk_table_new(5,4,TRUE);
   // button=gtk_button_new_with_label("quit the programe\n");
    gtk_container_add(GTK_CONTAINER(main_window),table);
    GtkWidget *entry=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry),"  Please input your comment:");
    set_widget_font_size(entry,15,FALSE);
    gtk_editable_set_editable(GTK_EDITABLE(entry),FALSE);
    button=gtk_button_new_with_label("1");
    button1=gtk_button_new_with_label("2");
    button2=gtk_button_new_with_label("3");
    button3=gtk_button_new_with_label("4");
    button4=gtk_button_new_with_label("5");
    button5=gtk_button_new_with_label("6");
    button6=gtk_button_new_with_label("7");
    button7=gtk_button_new_with_label("8");
    button8=gtk_button_new_with_label("9");
    button9=gtk_button_new_with_label("10");
    button10=gtk_button_new_with_label("11");
    button11=gtk_button_new_with_label("12");
    button12=gtk_button_new_with_label("13");
    button13=gtk_button_new_with_label("14");
    button14=gtk_button_new_with_label("15");
    button15=gtk_button_new_with_label("16");

 //char a[5];
   // for(int i=0;i<16;i++)
   // {

   // sprintf(a,"%d",i+1);
      //button[i]=gtk_buttons_new_with_lab(a);}
    gtk_table_attach_defaults(GTK_TABLE(table),entry,0,4,0,1);
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(table),button1,1,2,1,2);
    gtk_table_attach_defaults(GTK_TABLE(table),button2,2,3,1,2);
    gtk_table_attach_defaults(GTK_TABLE(table),button3,3,4,1,2);
    gtk_table_attach_defaults(GTK_TABLE(table),button4,0,1,2,3);
    gtk_table_attach_defaults(GTK_TABLE(table),button5,1,2,2,3);
    gtk_table_attach_defaults(GTK_TABLE(table),button6,2,3,2,3);
    gtk_table_attach_defaults(GTK_TABLE(table),button7,3,4,2,3);
    gtk_table_attach_defaults(GTK_TABLE(table),button8,0,1,3,4);
    gtk_table_attach_defaults(GTK_TABLE(table),button9,1,2,3,4);
    gtk_table_attach_defaults(GTK_TABLE(table),button10,2,3,3,4);
    gtk_table_attach_defaults(GTK_TABLE(table),button11,3,4,3,4);
    gtk_table_attach_defaults(GTK_TABLE(table),button12,0,1,4,5);
    gtk_table_attach_defaults(GTK_TABLE(table),button13,1,2,4,5);
    gtk_table_attach_defaults(GTK_TABLE(table),button14,2,3,4,5);
    gtk_table_attach_defaults(GTK_TABLE(table),button15,3,4,4,5);
  // gtk_button_set_image(GTK_BUTTON(button),image);
    //gtk_container_add(GTK_CONTAINER(button),image);

    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(cb_button5),NULL);
    g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(cb_button6),NULL);
    g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(cb_button7),NULL);
    g_signal_connect(G_OBJECT(button3),"clicked",G_CALLBACK(cb_button8),NULL);
    g_signal_connect(G_OBJECT(button4),"clicked",G_CALLBACK(cb_button9),NULL);
    g_signal_connect(G_OBJECT(button5),"clicked",G_CALLBACK(cb_button10),NULL);
    g_signal_connect(G_OBJECT(button6),"clicked",G_CALLBACK(cb_button11),NULL);
    g_signal_connect(G_OBJECT(button7),"clicked",G_CALLBACK(cb_button12),NULL);
    g_signal_connect(G_OBJECT(button8),"clicked",G_CALLBACK(cb_button13),NULL);
    g_signal_connect(G_OBJECT(button9),"clicked",G_CALLBACK(cb_button14),NULL);
    g_signal_connect(G_OBJECT(button10),"clicked",G_CALLBACK(cb_button15),NULL);
    g_signal_connect(G_OBJECT(button11),"clicked",G_CALLBACK(cb_button16),NULL);
    g_signal_connect(G_OBJECT(button12),"clicked",G_CALLBACK(cb_button17),NULL);
    g_signal_connect(G_OBJECT(button13),"clicked",G_CALLBACK(cb_button18),NULL);
    g_signal_connect(G_OBJECT(button14),"clicked",G_CALLBACK(cb_button19),NULL);
    g_signal_connect(G_OBJECT(button15),"clicked",G_CALLBACK(cb_button20),NULL);
   // gtk_widget_show(button);
    gtk_widget_show_all(main_window);

    gtk_main();
    return 0;
}
