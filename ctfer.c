#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

void nmap_ip();
void nmap_url();
void choose();

void print_ctfer_ascii() {


    printf(" *     ____ ____ ____ ____ ____ \n");
    printf(" *    ||C |||T |||F |||e |||r ||\n");
    printf(" *    ||__|||__|||__|||__|||__||\n");
    printf(" *    |/__\\|/__\\|/__\\|/__\\|/__\\|\n");
    printf(" *                              \n");
    printf(" *                              \n");
    printf(" *                              \n");
}

void nmap_url() {
    char link[256];
    printf("\nIntroduce the URL: ");
    scanf("%255s", link);  

    char hostname[256];
    int i = 0;
    while (link[i] != '/' && link[i] != '\0') {
        hostname[i] = link[i];
        i++;
    }
    hostname[i] = '\0'; 

    struct hostent *he;
    struct in_addr **addr_list;
    if ((he = gethostbyname(hostname)) == NULL) {
        printf("Could not resolve hostname.\n");
        return;
    }

    addr_list = (struct in_addr **) he->h_addr_list;
    printf("The IP address of your URL is: %s\n", inet_ntoa(*addr_list[0]));

    char port[20], nm_args[100];
    printf("Introduce your port range (p-p): ");
    scanf("%19s", port);  
    printf("Introduce your favorite nmap command: ");
    scanf(" %[^\n]", nm_args);  // Read the entire line

    char command[256];
    snprintf(command, sizeof(command), "nmap %s %s -p %s", nm_args, inet_ntoa(*addr_list[0]), port);
    printf("Running: %s\n", command);
    system(command);
}

void nmap_ip() {
    char ip[50], port[20], nm_args[100];
    printf("\nIntroduce the IP address: ");
    scanf("%49s", ip);  

    printf("Introduce your port range (p-p): ");
    scanf("%19s", port);  
    printf("Introduce your favorite nmap command: ");
    scanf(" %[^\n]", nm_args);

    char command[256];
    snprintf(command, sizeof(command), "nmap %s %s -p %s", nm_args, ip, port);
    printf("Running: %s\n", command);
    system(command);
}

void choose() {
    char choice;
    printf("\nWhat do you want to nmap?\nURL: (1)\nIP address: (2)\n(q)uit\nSelect: ");
    scanf(" %c", &choice);

    if (choice == '1') {
        nmap_url();
    } else if (choice == '2') {
        nmap_ip();
    } else if (choice == 'q') {
        exit(0);
    } else {
        printf("Choose between 1, 2, or (q)uit. Try again!\n");
        choose();
    }
}

int main() {
    print_ctfer_ascii();
    choose();
    return 0;
}

