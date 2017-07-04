#include<malloc.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
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
int main (int argc, char *argv[])
{
    int num1,num2;
  char *str1,*str2,*str3,*str4,str5[100],*str6,str7[100],*str8;
  //str1=(char*)malloc(100*sizeof(char));
    // str2=(char*)malloc(100*sizeof(char));
      // str3=(char*)malloc(100*sizeof(char));
  gtk_init(&argc,&argv);
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
  set_widget_font_size(label_one,50,FALSE);
  gtk_label_set_text(GTK_LABEL(label_one),str1);

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
  return 0;
}
