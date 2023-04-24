#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100

// Define the structure for the Customer bank account
struct customer {
    int account_number;
    char name[50];
    float balance;
    char internet_banking[4]; // Yes or No
    int pin_code;
    char account_type[10]; // saving, recurring, deposit
};

// Function to classify customers based on their balance
char* classify_customer(float balance) {
    if (balance > 1000000) {
        return "Golden";
    } else if (balance > 500000) {
        return "Silver";
    } else {
        return "General";
    }
}

int main() {
    int n;
    struct customer customers[MAX_CUSTOMERS];

    // Read account details for N customers
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter details for customer %d:\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &customers[i].account_number);
        printf("Name: ");
        scanf("%s", customers[i].name);
        printf("Balance: ");
        scanf("%f", &customers[i].balance);
        printf("Internet Banking Facility (Yes or No): ");
        scanf("%s", customers[i].internet_banking);
        printf("Pin code: ");
        scanf("%d", &customers[i].pin_code);
        printf("Account Type (saving, recurring, deposit): ");
        scanf("%s", customers[i].account_type);
    }

    // Classify customers based on their balance
    printf("\nCustomer classification:\n");
    for (int i = 0; i < n; i++) {
        char* customer_class = classify_customer(customers[i].balance);
        printf("%s - %s\n", customers[i].name, customer_class);
    }

    // Display the list of customers availing the Internet banking facility
    printf("\nCustomers availing Internet banking facility:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(customers[i].internet_banking, "Yes") == 0) {
            printf("%s\n", customers[i].name);
        }
    }

    // Display the customers belonging to a particular geographical location depending on postal code
    int postal_code;
    printf("\nEnter a postal code to search for customers: ");
    scanf("%d", &postal_code);

    printf("\nCustomers belonging to postal code %d:\n", postal_code);
    for (int i = 0; i < n; i++) {
        if (customers[i].pin_code == postal_code) {
            printf("%s\n", customers[i].name);
        }
    }

    // Display the customer list as per their account type
    char account_type[10];
    printf("\nEnter an account type to search for customers (saving, recurring, deposit): ");
    scanf("%s", account_type);

    printf("\nCustomers with account type %s:\n", account_type);
    for (int i = 0; i < n; i++) {
        if (strcmp(customers[i].account_type, account_type) == 0) {
            printf("%s\n", customers[i].name);
        }
    }

    return 0;
}
