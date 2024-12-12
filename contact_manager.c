#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stddef.h>
#define tab printf("\t\t")

struct list
{
    int id;
    char name[50];
    char last_name[50];
    char phone[15];
    char email[50];
    char address[100];
}newcontact, currentcontact;
 

void create_contact();
void list_contact();
void search_contact();
void edit_contact();
void delete_contact();

//function to clear buffer
int clearinputbuffer(){
    int c;
    while((c= getchar())!='\n' && c!=EOF);
    return c; //return the character that stooped the loop
};

int main(){
    int choice;
    int exit_loop = 0;
    while(!exit_loop){//if exit_loop = 1, the while loop will be broken
        system("cls");//clear the console
        printf("\t\t==================================================\n");
        printf("\t\t--------------------Main Menu---------------------\n");
        printf("\t\t==================================================\n");
        printf("\t\t1. New Contact\n");
        printf("\t\t2. List Contacts\n");
        printf("\t\t3. Search Contact\n");
        printf("\t\t4. Edit Contact\n");
        printf("\t\t5. Delete Contact\n");
        printf("\t\t6. Exit\n");
        printf("\t\t==================================================\n");
        printf("\t\tEnter Choice: ");
        scanf("%d",&choice);
        clearinputbuffer();//clear input buffer
        printf("\t\t==================================================\n");
        
        
        switch(choice){
                case 1:
                    create_contact();
                    break;
                case 2:
                    list_contact();
                    break;
                case 3:
                    search_contact();
                    break;
                case 4:
                    edit_contact();
                    break;
                case 5:
                    delete_contact();
                    break;
                case 6:
                    printf("\033[2J\033[H");//clear the console
                    printf("Terminated!");
                    getchar();
                    exit_loop=1;
                    break;
                default:
                    printf("Invalid option\n");
                    break;
        }
        
    }    
    return 0;
}

void create_contact(){
    system("cls");//clear the console
    FILE *fp;
    fp = fopen("Contacts.csv","a+");//open file in append mode
    if(fp == NULL){
        printf("\nError Opening File!");//check if there was an error opening the 
        getch();//Exit the Function if file cannot be opened
    }
    printf("\t\t==================================================\n");
    printf("\t\t-------------------NEW CONTACT--------------------\n");
    printf("\t\t==================================================\n");
    printf("\t\tMust include Firstname and Lastname\n");
    printf("\t\t--------------------------------------------------\n");
    printf("\t\tEnter FirstName: ");
    fgets(newcontact.name,sizeof(newcontact.name),stdin);
    newcontact.name[strcspn(newcontact.name,"\n")]=0;

    printf("\n\t\tEnter LastName: ");
    fgets(newcontact.last_name,sizeof(newcontact.last_name),stdin);
    newcontact.last_name[strcspn(newcontact.last_name,"\n")]=0;

    printf("\n\t\tEnter Phone Number: ");
    fgets(newcontact.phone,sizeof(newcontact.phone),stdin);
    newcontact.phone[strcspn(newcontact.phone,"\n")]=0;

    printf("\n\t\tEnter Email: ");
    fgets(newcontact.email, sizeof(newcontact.email),stdin);
    newcontact.email[strcspn(newcontact.email,"\n")]=0;

    printf("\n\t\tEnter Address: ");
    fgets(newcontact.address, sizeof(newcontact.address),stdin);
    newcontact.address[strcspn(newcontact.address,"\n")]=0;

    fprintf(fp,"%s,%s,%s,%s,%s\n",newcontact.name,newcontact.last_name,newcontact.phone,newcontact.email,newcontact.address);
    fclose(fp);
    printf("\t\t==================================================\n");
    printf("\t\t----------Contact Created Successfully!-----------\n");
    printf("\t\t==================================================\n");
    printf("\t\tPlease Enter any Key to continue..................");
    getch();  
}

void list_contact(){
    system("cls");//clear the console
    FILE *fp;
    fp = fopen("Contacts.csv","r");//open file in read mode
    if(fp==NULL){
        printf("Error Opening File!");//check if there was an error opening the file
        getch();//Exit the Function if file cannot be opened
    }
    int count = 0;//Track the number of contacts
    printf("\t\t==================================================\n");
    printf("\t\t------------------VIEW CONTACT--------------------\n");
    printf("\t\t==================================================\n");
    //Read each content from the csv file an print using a while loop
    while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",currentcontact.name,currentcontact.last_name, currentcontact.phone,currentcontact.email,currentcontact.address)!=EOF){
        printf("\t\tFirstName: %s\n",currentcontact.name);
        printf("\t\tLastName: %s\n",currentcontact.last_name);
        printf("\t\tPhone Number: %s\n",currentcontact.phone);
        printf("\t\tEmail: %s\n",currentcontact.email);
        printf("\t\tAddress: %s\n\n",currentcontact.address);
        count++;

    }
    if(count == 0){
        printf("\t\tNo Contacts Found\n");
    }
    printf("\t\t==================================================\n");
    printf("\t\tNumber of Contacts: %d\n",count);
    printf("\t\t==================================================\n");
    fclose(fp);
    printf("\t\tPlease press any Key to continue..................");
    getch();


}


void search_contact(){
    system("cls");//clear the console
    char searchName[50];//Declaring the Search Name Variable
    char line[100];//a new array to represent each line the file
    int found = 0;//how many contacts with the same name has been found
    FILE *fp;
    fp = fopen("Contacts.csv","r");//open file in read mode
    if(fp==NULL){
        printf("Error Opening File!");//check if there was an error opening the file
        getch();//Exit the Function if file cannot be opened
    }
    printf("\t\t=======================================================\n");
    printf("\t\t--------------------SEARCH CONTACT---------------------\n");
    printf("\t\t=======================================================\n");
    printf("\t\tEnter Name: ");
    fgets(searchName, sizeof(searchName),stdin);
    searchName[strcspn(searchName,"\n")]=0;

    while(fgets(line,sizeof(line),fp)){//reads the file and stores it in the line array, the loop will keep running as long as fgets successfully reads a line from the file
        //Assuming each Contact is on a separate line
        if(strstr(line,searchName)!=NULL){
           //remove the trailin comma and newline character
           size_t len = strlen(line);
           if(len>0 && line[len-1]=='\n'){
            line[len-1]='\0';
           }

           if(len>0 && line[len-2]==','){
            line[len-2]='\0';
           }

           for(int i=0; line[i]!='\0';i++){
            if(line[i]==','){
                line[i]=' ';//replace the comma with a space
            }
           }
           
            printf("\t\t=======================================================\n");
            printf("\n\t\tContact found:%d \n\t\t%s\n",++found,line);
            found++;
            
        }
    }
    if(!found){
        printf("\n\t\tContact Not Found!\n");
    }

    fclose(fp);
    printf("\n\t\t=======================================================\n");
    printf("\t\tPlease press any Key to continue..................");
    getch();
}

void edit_contact(){
    system("cls");//clear the console
    int choice;
    char searchName[100], firstName[50], lastName[50], originalfirstname[50], originallastname[50], originalemail[50], originalphone[50],originaladdress[50];
    int found = 0; // flag if contact was found
    FILE *fp , *newfp;
    fp = fopen("Contacts.csv","r");
    newfp =fopen("temp.csv","w");
    if(fp == NULL || newfp == NULL){
        printf("Error opening file");
        getch();
    }
    
    printf("\t\t==================================================\n");
    printf("\t\t------------------EDIT CONTACT--------------------\n");
    printf("\t\t==================================================\n");
    printf("\t\tSearch contact by full name: ");
    fgets(searchName,sizeof(searchName),stdin);
    searchName[strcspn(searchName,"\n")]=0;//remove newline character

    sscanf(searchName, "%49s %49s", firstName, lastName);//spilt search name into first and last name
    while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",currentcontact.name,currentcontact.last_name, currentcontact.phone,currentcontact.email,currentcontact.address)!=EOF){
        if(strcmp(firstName,currentcontact.name)==0 && strcmp(lastName,currentcontact.last_name)==0){
            found = 1;

            //storing original values
            strcpy(originalfirstname,currentcontact.name);
            strcpy(originallastname,currentcontact.last_name);
            strcpy(originaladdress,currentcontact.address);
            strcpy(originalemail,currentcontact.email);
            strcpy(originalphone,currentcontact.phone);

            printf("\t\tContact found!\n");
            printf("\t\tCurent Phone: %s\n",currentcontact.phone);
            printf("\t\tCurent Email: %s\n",currentcontact.email);
            printf("\t\tCurrent Address: %s\n",currentcontact.address);
            printf("\n\t\t==================================================\n");
            printf("\t\tPlease press any Key to continue..................");
            getch();

            while(1){
                system("cls");
                printf("\t\t==================================================\n");
                printf("\t\t-------------------EDIT MENU----------------------\n");
                printf("\t\t==================================================\n");
                printf("\t\t1.Edit Firstname and Lastname\n");
                printf("\t\t2.Edit Email\n");
                printf("\t\t3.Edit Phone Number\n");
                printf("\t\t4.Edit Address\n");
                printf("\t\t5.Exit\n");
                printf("\t\t==================================================\n");
                printf("\t\tEnter Choice: ");
                scanf(" %d",&choice);
                clearinputbuffer();
                switch (choice){
                    case 1:
                        system("cls");
                        printf("\t\tEnter firstname(leave blank to keep unchanged): ");
                        fgets(currentcontact.name,sizeof(currentcontact.name),stdin);//get input from the command-line
                        if(strlen(currentcontact.name)>1){
                            currentcontact.name[strcspn(currentcontact.name,"\n")]=0;//remove the new line at the end of the string
                        }
                        else{
                            strcpy(currentcontact.name,originalfirstname);
                        }

                        printf("\t\tEnter lastname(leave blank to keep unchanged): ");
                        fgets(currentcontact.last_name,sizeof(currentcontact.last_name),stdin);//get input from the command-line
                        if(strlen(currentcontact.last_name)>1){
                            currentcontact.last_name[strcspn(currentcontact.last_name,"\n")]=0;//remove the new line at the end of the string
                        }
                        else{
                            strcpy(currentcontact.last_name,originallastname);
                        }
                        printf("\n\t\t==================================================\n");
                        printf("\t\tPlease press any Key to continue..................");
                        getch();
                        break;
                    case 2:
                        system("cls");
                        printf("\t\tEnter Email(leave blank to keep unchanged): ");
                        fgets(currentcontact.email,sizeof(currentcontact.email),stdin);//get input from the command-line
                        if(strlen(currentcontact.email)>1){
                            currentcontact.email[strcspn(currentcontact.email,"\n")]=0;//remove the new line at the end of the string
                        }
                        else{
                            strcpy(currentcontact.email,originalemail);
                        }
                        printf("\n\t\t==================================================\n");
                        printf("\t\tPlease press any Key to continue..................");
                        getch();
                        break;
                    case 3:
                        system("cls");
                        printf("\t\tEnter Phone Number(leave blank to keep unchanged): ");
                        fgets(currentcontact.phone,sizeof(currentcontact.phone),stdin);//get input from the command-line
                        if(strlen(currentcontact.phone)>1){
                            currentcontact.phone[strcspn(currentcontact.phone,"\n")]=0;//remove the new line at the end of the string
                        }
                        else{
                            strcpy(currentcontact.phone,originalphone);
                        }
                        printf("\n\t\t==================================================\n");
                        printf("\t\tPlease press any Key to continue..................");
                        getch();
                        break;
                    case 4:
                        system("cls");
                        printf("\t\tEnter Address(leave blank to keep unchanged): ");
                        fgets(currentcontact.address,sizeof(currentcontact.address),stdin);//get input from the command-line
                        if(strlen(currentcontact.address)>1){
                            currentcontact.address[strcspn(currentcontact.address,"\n")]=0;//remove the new line at the end of the string
                        }
                        else{
                            strcpy(currentcontact.address,originaladdress);
                        }
                        printf("\n\t\t==================================================\n");
                        printf("\t\tPlease press any Key to continue..................");
                        getch();
                        break;
                    case 5:
                        goto write_contact;
                        break;    
                    default:
                        printf("\t\tInvalid choice!!");
                        break;
                }
            }
            
        }
        write_contact:
        fprintf(newfp,"%s,%s,%s,%s,%s\n",currentcontact.name,currentcontact.last_name,currentcontact.phone,currentcontact.email,currentcontact.address);
        
    }

    if(found!=1){
        printf("\t\tContact not found!!\n");
    }

    
    fclose(fp);
    fclose(newfp);
    remove("Contacts.csv");//remove the original file
    rename("temp.csv","Contacts.csv");//rename the temp file
    printf("\n\t\t==================================================\n");
    printf("\t\tPlease press any Key to continue..................");
    getch();
}



void delete_contact(){
    system("cls");//clear the console
    char choice;
    char searchName[100], firstName[50], lastName[50], originalfirstname[50], originallastname[50], originalemail[50], originalphone[50],originaladdress[50];
    int found = 0; // flag if contact was found
    FILE *fp , *newfp;
    fp = fopen("Contacts.csv","r");
    newfp =fopen("temp.csv","w");
    if(fp == NULL || newfp == NULL){
        printf("Error opening file");
        getch();
    }
    
    printf("\t\t==================================================\n");
    printf("\t\t-----------------DELETE CONTACT-------------------\n");
    printf("\t\t==================================================\n");
    printf("\t\tSearch contact by full name: ");
    fgets(searchName,sizeof(searchName),stdin);
    searchName[strcspn(searchName,"\n")]=0;//remove newline character

    sscanf(searchName, "%49s %49s", firstName, lastName);//spilt search name into first and last name
    while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",currentcontact.name,currentcontact.last_name, currentcontact.phone,currentcontact.email,currentcontact.address)!=EOF){
        if(strcmp(firstName,currentcontact.name)==0 && strcmp(lastName,currentcontact.last_name)==0){
            found = 1;

            //storing original values
            strcpy(originalfirstname,currentcontact.name);
            strcpy(originallastname,currentcontact.last_name);
            strcpy(originaladdress,currentcontact.address);
            strcpy(originalemail,currentcontact.email);
            strcpy(originalphone,currentcontact.phone);

            printf("\t\tContact found!\n");
            printf("\t\tCurent Phone: %s\n",currentcontact.phone);
            printf("\t\tCurent Email: %s\n",currentcontact.email);
            printf("\t\tCurrent Address: %s\n",currentcontact.address);
            printf("\n\t\t==================================================\n");
            printf("\t\tPlease press any Key to continue..................\n");
            getch();
            printf("\t\tDo you want to delete this contact(Y/N): ");
            scanf(" %c",&choice);
            clearinputbuffer();//clear input buffer

            if(choice == 'Y' || choice == 'y'){
                printf("\n\t\t==================================================\n");
                printf("\t\tDeleting contact......\n");
                printf("\n\t\t==================================================\n");
                printf("\t\tContact deleted successfully!");
                continue;  
            }
            else if(choice == 'N'|| choice == 'n'){
                strcpy(currentcontact.name,originalfirstname);
                strcpy(currentcontact.last_name,originallastname);
                strcpy(currentcontact.email,originalemail);
                strcpy(currentcontact.address,originaladdress);
                strcpy(currentcontact.phone,originalphone);
            }
        }

        fprintf(newfp,"%s,%s,%s,%s,%s\n",currentcontact.name,currentcontact.last_name,currentcontact.phone,currentcontact.email,currentcontact.address);
        
    }

    if(found!=1){
        printf("\t\tContact not found!!\n");

    }
    

    
    fclose(fp);
    fclose(newfp);
    remove("Contacts.csv");//remove the original file
    rename("temp.csv","Contacts.csv");//rename the temp file
    printf("\n\t\t==================================================\n");
    printf("\t\tPlease press any Key to continue..................");
    getch();

}


