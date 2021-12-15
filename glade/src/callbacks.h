#include <gtk/gtk.h>

int argc;
char *argv[];

void chang_background(GtkWidget *widget,int w,int h,const gchar *path);


void
on_n_button_insc_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_button_auth_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_menu_afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_menu_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_com_jours_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_m_miseajour_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_f_insc_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_f_login_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_image11_button_press_event          (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_n_pec_insc_button_press_event       (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_n_pec_auth_button_press_event       (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_reteurn_auth_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_reteurn_insc_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_menu_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_logout_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_aff_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_n_m_supprimer_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_supp_valider_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_supp_lundi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_supp_mardi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_supp_mercredi_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_supp_jeudi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_supp_vendredi_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_supp_samedi_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_supp_dimanche_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_menu_actualiser_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_m_ajouter_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_meilleur_menu_aff_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_sem1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_sem2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_sem3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_sem4_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modif_remplire_case_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_modifier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_logout_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_sup_menu_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_reteurn_auth_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_reteurn_insc_activate               (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_menu_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_modifier_choix_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_reteurn_insc_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_meilleur_menu_aff_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_modifier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_entry_pw_insc_insert_text         (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_aff_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_rechercher_menu_button_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_tout_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_return_meilleur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_meilleur_m_menu_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_w_meilleur_activate_default       (GtkWindow       *window,
                                        gpointer         user_data);

void
on_n_w_meilleur_activate_default       (GtkWindow       *window,
                                        gpointer         user_data);

void
on_n_aff_m_menu_activate_current_link  (GtkLabel        *label,
                                        gpointer         user_data);

void
on_n_aff_supp_clicked                  (GtkButton       *button,
                                        gpointer         user_data);



void
on_n_aff_clear_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_box_rechercher_menu_j_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_supp_sem_changed                  (GtkComboBox     *combobox,
                                        gpointer         user_data);

gboolean
on_chois_theme_activate_cursor_item    (GtkIconView     *iconview,
                                        gpointer         user_data);

void
on_n_theme_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_iconview1_activate_cursor_item      (GtkIconView     *iconview,
                                        gpointer         user_data);

void
on_n_iconview1_item_activated          (GtkIconView     *iconview,
                                        GtkTreePath     *path,
                                        gpointer         user_data);

void
on_m_background1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_theme_1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_theme_2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_theme_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_n_theme_4_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_n_theme_3_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
