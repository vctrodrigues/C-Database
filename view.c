#include "view.h"
void print_menu() {
    printf(ANSI_COLOR_YELLOW"\n");
    printf("┌───┐   ┌─┐┌─┐     ┌──┐┌───┐\n");
    printf("│┌─┐│   │┌┘│┌┘     │┌┐│└┐┌┐│\n");
    printf("││ └┼──┬┘└┬┘└┬──┬──┤└┘└┐││││\n");
    printf("││ ┌┤┌┐├┐┌┴┐┌┤ ─┤ ─┤┌─┐│││││\n");
    printf("│└─┘│└┘│││ │││ ─┤ ─┤└─┘├┘└┘│\n");
    printf("└───┴──┘└┘ └┘└──┴──┴───┴───┘\n");
    printf("CoffeeBD Co.\nv1.0.0-stable\n");
    printf(ANSI_COLOR_RESET "\n");
    printf("\nCOMANDOS:");
    printf(ANSI_COLOR_CYAN);
    printf("\n> create_table");
    printf("\n> list_table");
    printf("\n> insert_data");
    printf("\n> list_data");
    printf("\n> remove_data");
    printf("\n> delete_table");
    printf("\n> search_data");
    printf("\n> change_data");
    printf("\n> help");
    printf("\n> clear");
    printf("\n> exit");
    printf(ANSI_COLOR_RESET);
    printf("\n");
    printf("\nCoffeeBD> ");
}

void print_menu_header() {
    printf(ANSI_COLOR_YELLOW"\n");
    printf("CoffeeBD Co.\nv1.0.0-stable\n");
}

void print_separator() {
    printf("\n");
}

void print_search_options() {
    printf("\nOPÇÕES");
    printf(ANSI_COLOR_CYAN);
    printf("\n1> valores maiores");
    printf("\n2> valores maiores ou iguais");
    printf("\n3> valores iguais");
    printf("\n4> valores menores");
    printf("\n5> valores menores ou iguais");
    printf("\n6> valores próximos (string)");
    printf(ANSI_COLOR_RESET);
    printf("\nDigite a opção> ");
}

void print_err(char message[256]) {
    printf(ANSI_COLOR_RED);
    printf("err> %s\n", message);
    printf(ANSI_COLOR_RESET);
}

void print_notification(char message[256]) {
    printf(ANSI_COLOR_GREEN);
    printf("info> %s\n", message);
    printf(ANSI_COLOR_RESET);
}

void print_receive_command(char message[256]) {
    printf(ANSI_COLOR_RESET "CoffeeBD> ");
}

void print_commands() {
    printf("COMANDOS:");
    printf(ANSI_COLOR_CYAN);
    printf("\n> create_table");
    printf("\n> list_table");
    printf("\n> insert_data");
    printf("\n> list_data");
    printf("\n> remove_data");
    printf("\n> delete_table");
    printf("\n> search_data");
    printf("\n> change_data");
    printf("\n> help");
    printf("\n> clear");
    printf("\n> exit\n");
    printf(ANSI_COLOR_RESET);
}