/* Gnome Search Tool 
 * (C) 1998 the Free Software Foundation
 *
 * Author:   George Lebl
 */

#include <gtk/gtk.h>

#include "gsearchtool.h"
#include "outdlg.h"

static GtkWidget *outdlg=NULL;
static GtkWidget *outlist;
static int list_width=0;

static void
outdlg_clicked(GtkWidget * widget, int button, gpointer data)
{
	if(button == 0)
		gtk_clist_clear(GTK_CLIST(outlist));
	else
		gtk_widget_destroy(outdlg);
	list_width=0;
}

static int
outdlg_closedlg(GtkWidget * widget, gpointer data)
{
	list_width=0;
	outdlg=NULL;
	return FALSE;
}

int
outdlg_makedlg(char name[], int clear)
{
	GtkWidget *widget;

	/*we already have a dialog!!!*/
	if(outdlg!=NULL) {
		if(clear) {
			list_width=0;
			gtk_clist_clear(GTK_CLIST(outlist));
		}
		return FALSE;
	}
	list_width=0;

	outdlg=gnome_dialog_new(name,
				"Clear",
				GNOME_STOCK_BUTTON_CLOSE,
				NULL);
	gtk_signal_connect(GTK_OBJECT(outdlg), "destroy",
			   GTK_SIGNAL_FUNC(outdlg_closedlg), NULL);

	gtk_signal_connect(GTK_OBJECT(outdlg), "clicked",
			   GTK_SIGNAL_FUNC(outdlg_clicked), NULL);

	/*widget=gtk_label_new("Files Found:");
	gtk_box_pack_start(GTK_BOX(GNOME_DIALOG(outdlg)->vbox),widget,
			   FALSE,FALSE,5);*/

	outlist = gtk_clist_new(1);
	gtk_widget_set_usize(outlist,200,350);
	gtk_box_pack_start(GTK_BOX(GNOME_DIALOG(outdlg)->vbox),outlist,
			   TRUE,TRUE,0);

	return TRUE;
}

void
outdlg_additem(char item[])
{
	gtk_clist_append(GTK_CLIST(outlist),&item);
	if(list_width < 
	   gdk_string_width(GTK_WIDGET(outlist)->style->font,item))
		list_width = gdk_string_width(GTK_WIDGET(outlist)->style->font,
					      item);
	gtk_clist_set_column_width(GTK_CLIST(outlist),0,list_width);
}

void
outdlg_freeze(void)
{
	gtk_clist_freeze(GTK_CLIST(outlist));
}

void
outdlg_thaw(void)
{
	gtk_clist_thaw(GTK_CLIST(outlist));
}

void
outdlg_showdlg(void)
{
	gtk_widget_show_all(outdlg);
}

