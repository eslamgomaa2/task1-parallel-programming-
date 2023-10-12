#include <stdio.h>
#include <string.h>

#define MAX_USERS 100


struct User {
char username[32];
char password[32];
};


struct User registeredUsers[MAX_USERS]; 


int numRegistered = 0;

void registerUser();
void loginUser();

int main() {

int choice;

while(1) {
printf("1. Register new user\n");
printf("2. Login\n");
printf("0. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);

if(choice == 1) {
registerUser();
}
else if(choice == 2) {
loginUser(); 
}
else if(choice == 0) {
break;
}
}

return 0;
}


void registerUser() {


if(numRegistered == MAX_USERS) {
printf("Max users reached!\n");
return;
}

printf("Enter username: ");
scanf("%s", registeredUsers[numRegistered].username);

printf("Enter password: ");
scanf("%s", registeredUsers[numRegistered].password);


numRegistered++;

printf("User registered successfully!\n");
}


void loginUser() {

char username[32], password[32];

printf("Enter username: ");
scanf("%s", username);

printf("Enter password: ");
scanf("%s", password);

for(int i=0; i<numRegistered; i++) {
if(strcmp(registeredUsers[i].username, username) == 0 && 
strcmp(registeredUsers[i].password, password) == 0) {
printf("Login successful!\n");
return;
}
}

printf("Invalid credentials!\n");
}
