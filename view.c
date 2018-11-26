#include "view.h"
void print_menu() {
    printf(ANSI_COLOR_CYAN"\n");
    printf("           ▒▒▒▒▒▒▒▒\n");
    printf("         ▒▒▒      ▒▒▒\n");
    printf("        ▒▒   ▒▒▒▒  ▒░▒\n");
    printf("       ▒▒   ▒▒  ▒▒  ▒░▒\n");
    printf("      ▒▒░▒      ▒▒  ▒░▒\n");
    printf("       ▒▒░▒    ▒▒  ▒░▒\n");
    printf("         ▒▒▒▒▒▒▒   ▒▒\n");
    printf("                 ▒▒▒\n");
    printf("     ▒▒▒▒        ▒▒\n");
    printf("   ▒▒▒░░▒▒▒     ▒▒  ▓▓▓▓▓▓▓▓\n");
    printf("  ▒▒     ▒▒▒    ▒▒▓▓▓▓▓░░░░░▓▓  ▓▓▓▓\n");
    printf(" ▒   ▒▒    ▒▒ ▓▓▒░░░░░░░░░█▓▒▓▓▓▓░░▓▓▓\n");
    printf("▒▒  ▒ ▒▒   ▓▒▒░░▒░░░░░████▓▓▒▒▓░░░░░░▓▓\n");
    printf("░▒▒   ▒  ▓▓▓░▒░░░░░░█████▓▓▒▒▒▒▓▓▓▓▓░░▓▓\n");
    printf("  ▒▒▒▒  ▓▓░░░░░░███████▓▓▓▒▒▒▒▒▓   ▓▓░▓▓\n");
    printf("      ▓▓░░░░░░███████▓▓▓▒▒▒▒▒▒▒▓   ▓░░▓▓\n");
    printf("     ▓▓░░░░░███████▓▓▓▒▒▒▒▒▒▒▒▒▓▓▓▓░░▓▓\n");
    printf("    ▓▓░░░░██████▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▓░░░░▓▓\n");
    printf("    ▓▓▓░████▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓\n");
    printf("     ▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓\n");
    printf("     ▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓\n");
    printf("      ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓\n");
    printf("       ▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓\n");
    printf("         ▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓\n");
    printf("           ▓▓▓▓▓▓▒▒▒▒▒▓▓▓▓\n");
    printf("               ▓▓▓▓▓▓▓▓\n");
    printf("\n");
    printf("   ██████████████████████████████████\n");
    printf("   █                                █\n");
    printf("   █  ┌───┐   ┌─┐┌─┐     ┌──┐┌───┐  █\n");
    printf("   █  │┌─┐│   │┌┘│┌┘     │┌┐│└┐┌┐│  █\n");
    printf("   █  ││ └┼──┬┘└┬┘└┬──┬──┤└┘└┐││││  █\n");
    printf("   █  ││ ┌┤┌┐├┐┌┴┐┌┤ ─┤ ─┤┌─┐│││││  █\n");
    printf("   █  │└─┘│└┘│││ │││ ─┤ ─┤└─┘├┘└┘│  █\n");
    printf("   █  └───┴──┘└┘ └┘└──┴──┴───┴───┘  █\n");
    printf("   █                                █\n");
    printf("   ██████████████████████████████████\n");
    printf(ANSI_COLOR_RESET"\n");
    printf("\n-> Bem-vindo ao SGBD:");
    printf("\n===============================");
    printf("\n---------- COMANDOS: ----------");
    printf(ANSI_COLOR_GREEN);
    printf("\n> create_table");
    printf(ANSI_COLOR_CYAN);
    printf("\n> list_table");
    printf(ANSI_COLOR_YELLOW);
    printf("\n> insert_data");
    printf(ANSI_COLOR_MAGENTA);
    printf("\n> list_data");
    printf(ANSI_COLOR_RED);
    printf("\n> remove_data");
    printf(ANSI_COLOR_BLUE);
    printf("\n> delete_table");
    printf(ANSI_COLOR_GREEN);
    printf("\n> search_data");
    printf(ANSI_COLOR_CYAN);
    printf("\n> change_data");
    printf(ANSI_COLOR_RESET);
    printf("\n===============================");
    printf("\nDigite seu comando> ");
}

void print_separator() {
    printf("===============================\n");
}

void print_search_options() {
    printf("\n===============================");
    printf("\n---------- COMANDOS: ----------");
    printf(ANSI_COLOR_GREEN);
    printf("\n1> valores maiores");
    printf(ANSI_COLOR_CYAN);
    printf("\n2> valores maiores ou iguais");
    printf(ANSI_COLOR_YELLOW);
    printf("\n3> valores iguais");
    printf(ANSI_COLOR_MAGENTA);
    printf("\n4> valores menores");
    printf(ANSI_COLOR_RED);
    printf("\n5> valores menores ou iguais");
    printf(ANSI_COLOR_BLUE);
    printf("\n6> valores próximos (string)");
    printf(ANSI_COLOR_RESET);
    printf("\n===============================");
    printf("\nDigite a opção> ");
}

void print_err(char message[256]) {
    printf(ANSI_COLOR_RED);
    printf("err> %s\n", message);
    printf(ANSI_COLOR_RESET);
}

void print_notification(char message[256]) {
    printf(ANSI_COLOR_GREEN);
    printf("msg> %s\n", message);
    printf(ANSI_COLOR_RESET);
}

void print_receive_command(char message[256]) {
    printf("Digite a opção> ");
}