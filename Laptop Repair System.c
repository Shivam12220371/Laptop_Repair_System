#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100

typedef struct {
    char username[50];
    char password[50];
    char device_model[50];
} User;

int main() {
	int i;
    User users[MAX_USERS];
    int num_users = 0;

    FILE *file = fopen("users.txt", "r");
    if (file) {
        char line[200];
        while (fgets(line, sizeof(line), file)) {
            char *token = strtok(line, ",");
            strcpy(users[num_users].username, token);
            token = strtok(NULL, ",");
            strcpy(users[num_users].password, token);
            token = strtok(NULL, ",");
            strcpy(users[num_users].device_model, token);
            num_users++;
        }
        fclose(file);
    }

    printf("Welcome to our device repair service.\n\n");
    printf("Do you want to sign in or create a new user?\n\n");
    printf("Enter 's' for sign in and 'n' for new user:  ");
    

    char choice;
    scanf("%c", &choice);
    printf("\n----------------------------------------------------");

    if (choice == 's') {
        char username[50];
        printf("\n  Enter your username: ");
        scanf("%s", username);

        int found_user = 0;
        for (i = 0; i < num_users; i++) {
            if (strcmp(username, users[i].username) == 0) {
                found_user = 1;
                printf("Welcome back, %s.\n\n", username);
                printf("Your device model is %s.\n\n", users[i].device_model);
                printf("Order has been carried out. Please collect your device.\n\n");
                break;
            }
        }

        if (!found_user) {
            printf("No such user was found in the database.\n\n");
        }
    } else if (choice == 'n') {
        char username[50];
        printf("\n  Enter a username: ");
        scanf("%s", username);

        int found_user = 0;
        for (i = 0; i < num_users; i++) {
            if (strcmp(username, users[i].username) == 0) {
                found_user = 1;
                printf("A user with that username already exists.\n");
                break;
            }
        }

        if (!found_user) {
            char password[50];
            char device_model[50];
            printf("  Enter a password: ");
            scanf("%s", password);
            printf("  Enter the device model: ");
            scanf("%s", device_model);

            User user;
            strcpy(user.username, username);
            strcpy(user.password, password);
            strcpy(user.device_model, device_model);
            users[num_users] = user;
            num_users++;

            file = fopen("users.txt", "a");
            if (file) {
                fprintf(file, "%s,%s,%s\n", username, password, device_model);
                fclose(file);
            } else {
                printf("Error saving user to file.\n");
            }
        }
    }

    if (choice == 'n') {
        printf("What is the problem with your device?\n\n");
        printf("1. Screen, keyboard or touch not working.\n");
        printf("2. System very slow, or virus infected.\n");
        printf("3. Windows and softwares giving problems.\n");
        printf("4. Problems in configuration/installing of new or additional components (external camera, keyboards, mouse, etc.).\n");
        printf("5. Need spare parts (chargers, wired applications, etc.).\n\n");
        printf("\n\nEnter the corresponding number: ");
		int problem;
		scanf("%d", &problem);
		int cost;
		switch(problem) {
		case 1:
		printf("You need hardware replacement.\n\n");
		printf("Contact our internal hardware expert Miss Ritika.\n");
		printf("Contact info:\nPhone no - 23450002\nEmail - ritika@gmail.com\n");
		cost = 1000;
		break;
		case 2:
		printf("Your system is very slow, or virus infected.\n\n");
		printf("Contact our internal software expert Mr.Shivam Bhardwaj.\n");
		printf("Contact info:\nPhone no - 1234562\nEmail - bhardwaj@gmail.com\n");
		cost = 2000;
		break;
		case 3:
		printf("You are having problems with Windows and softwares.\n\n");
		printf("Contact our internal software expert Mr. Vishwa.\n");
		printf("Contact info:\nPhone no - 1234563\nEmail - vardhana@gmail.com\n");
		cost = 500;
		break;
		case 4:
		printf("You are having problems in configuration/installing new or additional components.\n\n");
		printf("Contact our internal hardware expert Mr. kuldeep.\n");
		printf("Contact info:\nPhone no - 1234564\nEmail - vishwas@gmail.com\n");
		cost = 100;
		break;
		case 5:
		printf("You need spare parts (chargers, wired applications, etc.).\n\n");
		printf("Contact our internal hardware expert Mr. singh.\n");
		printf("Contact info:\nPhone no - 123456***5\nEmail - singh@gmail.com\n");
		cost = 350;
		break;
		default:
		printf("Invalid choice.\n");
		cost = 0;
		}
		    if (cost > 0) {
        printf("\nHave you talked to our expert and got their opinion? (y/n)\n");
        char opinion_choice;
        scanf(" %c", &opinion_choice);
        if (opinion_choice == 'y') {
            printf("Please pay Rs.%d - only to UPI ID shivambhardwaj522001@oksbi.\n\n", cost);
            printf("Have you completed the payment? (y/n)\n");
            char payment_choice;
            scanf(" %c", &payment_choice);
            if (payment_choice == 'y') {
                printf("Your device will be taken to our shop by the delivery boy.\n");
                for (i = 0; i < 15; i++) {
                    printf(".\n");
                }
                printf("Your device has reached our shop and the repair will start shortly.\n");
                for (i = 0; i < 15; i++) {
                    printf("Repairing...\n");
                }
                printf("Your device has been repaired.\n\n");
                printf("Thank you for using our services.\n");
            } else {
                printf("Please complete the payment.\n");
            }
        } else {
            printf("Please talk to our experts before continuing.\n");
        }
    }
} else {
    printf("No such user was found in the database.\n");
}

fclose(file);
return 0;
}
