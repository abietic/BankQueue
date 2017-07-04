#include <stdlib.h>
#include <gtk/gtk.h>
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
    GtkWidget *main_window;//
    GtkWidget *button,*button1;
    gtk_init(&argc,&argv);
    main_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window),"Bank of china");
    gtk_window_set_default_size(GTK_WINDOW(main_window),300,100);
    GtkWidget *table=gtk_table_new(2,2,TRUE);
   // button=gtk_button_new_with_label("quit the programe\n");
    gtk_container_add(GTK_CONTAINER(main_window),table);
    GtkWidget *entry=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry),"Is VIP?");
    gtk_editable_set_editable(GTK_EDITABLE(entry),FALSE);
    button=gtk_button_new_with_label("yes");
    button1=gtk_button_new_with_label("no");
    gtk_table_attach_defaults(GTK_TABLE(table),entry,0,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(table),button1,1,2,1,2);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(cb_button),NULL);
    g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(cb_button1),NULL);
    gtk_widget_show(button);
    gtk_widget_show_all(main_window);

    gtk_main();
    return 0;
}
