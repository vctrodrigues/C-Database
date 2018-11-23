#include "view.h"
void print_menu() {
    printf(ANSI_COLOR_RED"\n");
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
    printf(ANSI_COLOR_YELLOW"\n");
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
    printf(ANSI_COLOR_RESET);
    printf("\n===============================");
    printf("\nDigite seu comando> ");
}

void print_separator() {
    printf("\n===============================\n");
}