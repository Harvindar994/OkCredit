#include<custom.h>

struct users
{
    char username[30];
    char password[30];
};

// Global Users Variables
const char MAIN_PATH[] = "OkCredit";
const char USERS_RECORD_FILE[] = "Users.txt";
struct users LOGED_USER;

// Code Written BY Shailja___________________________________________________________________




// Code Written By Harvindar Singh___________________________________________________________


void create_path(char *path, char *add_path, char *result)
{
    strcpy(result, path);
    strcat(result, "/");
    strcat(result, add_path);
}

int gernate_key_char(char *key,int lenth)
{
    int i,temp,number;
    for(i=0;i<lenth;i++)
    {
        temp=rand()%10;
        key[i]=int_to_char_int(temp);
    }
    key[i]='\0';
    return 1;
}

// User Management Function's.

int add_user(struct users new_user)
{
    char users_file[267];
    FILE *USERS_FILE;
    create_path(MAIN_PATH, USERS_RECORD_FILE, users_file);
    USERS_FILE = fopen(users_file, "ab");
    if(USERS_FILE != NULL)
    {
        fwrite(&new_user, sizeof(struct users), 1, USERS_FILE);
        fclose(USERS_FILE);
        return 1;
    }
    return 404;
}

int auth_user(char *username, char *password)
{
    FILE *USERS_FILE;
    struct users login;
    char users_file_path[267];
    create_path(MAIN_PATH, USERS_RECORD_FILE, users_file_path);
    USERS_FILE = fopen(users_file_path, "rb");
    if(USERS_FILE != NULL)
    {
        while(fread(&login, sizeof(struct users), 1, USERS_FILE)>0)
        {
            printf("WENT INSIDE OF FUNCTION");
            printf("RESULT : %d",strcmp(login.username, username));
            if(strcmp(username, login.username)==0 && strcmp(password, login.password)==0)
            {
                fclose(USERS_FILE);
                LOGED_USER = login;
                return 1;
            }
        }
        fclose(USERS_FILE);
        return 0;
    }
    return 404;
}

void main()
{
    int a;
    printf("Testing");
    struct users new_user;
    strcpy(new_user.username, "harvindar");
    strcpy(new_user.password, "078singh");
    //a= add_user(new_user);
    a = auth_user(new_user.username, new_user.password);
    printf("STATUS : %d",a);
    getch();
}
