/****************************************************************/
/*      Name    :   Bike Operations                             */
/*      Author  :   Subbaramaiah Chevuru                        */
/*                                                              */
/****************************************************************/

//==============================================================//
//                  REVISION LOG                                //
//==============================================================//
//                                                              //
//  2025-12-09  -   Initial Draft of the Program.               //
//                                                              //
//                                                              //
//==============================================================//

//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>

//FILE Definitions
#define FILENAME "bike.dat"

//Struct Record for the service history
typedef struct ServiceHistory{
    char service_type[16];
    char last_service_date[16];
    char description[128];
    struct ServiceHistory *next;
}ServiceHistory;

//Struct Record for the Bike Details
typedef struct BikeDetails{
    char bike_number[16];
    char name[50];
    char address[100];
    char mobile[16];
    char date_of_purchase[16];
    ServiceHistory *service_history;
    struct BikeDetails *next;
}BikeDetails;

//Global Variables
BikeDetails *bike_data=NULL;
char *serviceType[7] = {"NEW", "IN-RUNNING","SERVICE_BOOKED", "WAITING","SERVICE_INPROGRESS","WAITING_FOR_USER", "DELIVERED"};

/* Clear all bike data from memory */
void clear_bike_data()
{
    BikeDetails *temp;

    while (bike_data != NULL)
    {
        ServiceHistory *sh = bike_data->service_history;
        while (sh != NULL)
        {
            ServiceHistory *nextSh = sh->next;
            free(sh);
            sh = nextSh;
        }

        temp = bike_data;
        bike_data = bike_data->next;
        free(temp);
    }
}

/* Add new bike to database */
BikeDetails* create_db(BikeDetails *db)
{
    if(db==NULL)
        return bike_data;

    db->next = bike_data;
    bike_data = db;
    
    return bike_data;
}

/* Return local time struct */
struct tm* print_time()
{
    time_t now;
    struct tm *t;

    setenv("TZ", "Asia/Kolkata", 1);
    tzset();

    time(&now);
    t = localtime(&now);

    return t;
}

/* Helper Function to select service type */
const char* select_service_type() {
    int stype, c;
    printf("\nAvailable Service Types:\n");
    for(int s = 0; s < 7; s++)
        printf("%d. %s\n", s+1, serviceType[s]);

    printf("Choose Service Type (1-7): ");
    if(scanf("%d", &stype) != 1) {
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\nInvalid input!\n");
        return NULL;
    }
    while ((c = getchar()) != '\n' && c != EOF);

    if (stype < 1 || stype > 7) {
        printf("\nInvalid Service Type Selected!\n");
        return NULL;
    }

    return serviceType[stype-1];
}

/* Helper Function to Rewrite the Data base */
void rewrite_full_db()
{
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) {
        printf("Error rewriting DB.\n");
        return;
    }

    BikeDetails *b = bike_data;

    while (b) {
        fprintf(fp, "============================= Bike Details ==============================\n");
        fprintf(fp, "Customer Name      : %s\n", b->name);
        fprintf(fp, "Bike Number        : %s\n", b->bike_number);
        fprintf(fp, "Address            : %s\n", b->address);
        fprintf(fp, "Mobile Number      : +91-%s\n", b->mobile);
        fprintf(fp, "Date of Purchase   : %s\n", b->date_of_purchase);
        fprintf(fp, "Service Details\n------------------\n");

        ServiceHistory *sh = b->service_history;
        while (sh)
        {
            fprintf(fp, "Service Type       : %s\n", sh->service_type);
            fprintf(fp, "Last Service Date  : %s\n", sh->last_service_date);
            fprintf(fp, "Description        : %s\n", sh->description);
            fprintf(fp, "-----------------------------------------------------------------------\n");
            sh = sh->next;
        }

        fprintf(fp, "=========================================================================\n");
        b = b->next;
    }

    fclose(fp);
}

/* Helper Function to Save the bike details to file */
void save_to_file(BikeDetails *bike)
{
    if (!bike) return;

    struct tm *t = print_time();
    char file_name[64];
    snprintf(file_name, sizeof(file_name), "%s.dat", bike->bike_number);

    // Rewrite full DB file (clean)
    rewrite_full_db();

    // Append only the latest service to bike-specific file
    FILE *bn = fopen(file_name, "a");
    if (!bn)
    {
        printf("\nUnable to open bike-specific file.\n");
        return;
    }

    ServiceHistory *sh = bike->service_history;

    fprintf(bn, "============================= Bike Details ==============================\n");
    fprintf(bn, "Date: %02d-%02d-%04d %02d:%02d:%02d\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec);

    fprintf(bn, "Customer Name      : %s\n", bike->name);
    fprintf(bn, "Bike Number        : %s\n", bike->bike_number);
    fprintf(bn, "Address            : %s\n", bike->address);
    fprintf(bn, "Mobile Number      : +91-%s\n", bike->mobile);
    fprintf(bn, "Date of Purchase   : %s\n", bike->date_of_purchase);
    fprintf(bn, "Service Details\n------------------\n");

    while (sh)
    {
        fprintf(bn, "Service Type       : %s\n", sh->service_type);
        fprintf(bn, "Last Service Date  : %s\n", sh->last_service_date);
        fprintf(bn, "Description        : %s\n", sh->description);
        fprintf(bn, "-----------------------------------------------------------------------\n");
        sh = sh->next;
    }

    fprintf(bn, "=========================================================================\n");
    fclose(bn);

    printf("\nDetails Saved successfully.....!!!!\n");
}

/* Helper function to Find the Bike Number */
BikeDetails* find_bike_by_number(char *number)
{
    BikeDetails *temp = bike_data;

    while (temp != NULL)
    {
        if (strcmp(temp->bike_number, number) == 0)
            return temp;

        temp = temp->next;
    }

    return NULL;    // not found
}

/* Helper Function for Sorting the Service History according to the Dates */
void sort_service_history(ServiceHistory **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    int swapped;
    ServiceHistory *p, *last = NULL;

    do {
        swapped = 0;
        p = *head;

        while (p->next != last)
        {
            // Convert dates to comparable numbers
            int d1=0, m1=0, y1=0, d2=0, m2=0, y2=0;

            if (strcmp(p->last_service_date, "N/A") != 0)
                sscanf(p->last_service_date, "%d-%d-%d", &d1, &m1, &y1);

            if (strcmp(p->next->last_service_date, "N/A") != 0)
                sscanf(p->next->last_service_date, "%d-%d-%d", &d2, &m2, &y2);

            // Compare dates
            int newer =
                (y2 > y1) ||
                (y2 == y1 && m2 > m1) ||
                (y2 == y1 && m2 == m1 && d2 > d1);

            if (newer)
            {
                // Swap data only
                ServiceHistory temp = *p;
                strcpy(p->service_type, p->next->service_type);
                strcpy(p->last_service_date, p->next->last_service_date);
                strcpy(p->description, p->next->description);

                strcpy(p->next->service_type, temp.service_type);
                strcpy(p->next->last_service_date, temp.last_service_date);
                strcpy(p->next->description, temp.description);

                swapped = 1;
            }

            p = p->next;
        }

        last = p;

    } while (swapped);
}

/* Helper function to Load bike details from file */
void load_from_file()
{
    clear_bike_data();  

    FILE *fp = fopen(FILENAME, "r");
    if (!fp)
    {
        printf("\nDB file not found. Starting fresh.\n");
        return;
    }

    char line[256];
    BikeDetails tempBike;
    ServiceHistory *tempSHHead = NULL, *tempSHLast = NULL;
    int readingBike = 0;

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "============================= Bike Details"))
        {
            memset(&tempBike, 0, sizeof(BikeDetails));
            tempSHHead = tempSHLast = NULL;
            readingBike = 1;
        }
        else if (readingBike && strstr(line, "Bike Number"))
            sscanf(line, " Bike Number        : %15[^\n]", tempBike.bike_number);
        else if (readingBike && strstr(line, "Customer Name"))
            sscanf(line, " Customer Name      : %49[^\n]", tempBike.name);
        else if (readingBike && strstr(line, "Address"))
            sscanf(line, " Address            : %99[^\n]", tempBike.address);
        else if (readingBike && strstr(line, "Mobile Number"))
            sscanf(line, " Mobile Number      : +91-%15[^\n]", tempBike.mobile);
        else if (readingBike && strstr(line, "Date of Purchase"))
            sscanf(line, " Date of Purchase   : %15[^\n]", tempBike.date_of_purchase);

        else if (readingBike && strstr(line, "Service Type"))
        {
            ServiceHistory *sh = malloc(sizeof(ServiceHistory));
            memset(sh, 0, sizeof(ServiceHistory));
            sh->next = NULL;
            sscanf(line, " Service Type       : %15[^\n]", sh->service_type);

            if (!tempSHHead)
                tempSHHead = sh;
            else
                tempSHLast->next = sh;

            tempSHLast = sh;
        }
        else if (readingBike && strstr(line, "Last Service Date"))
            sscanf(line, " Last Service Date  : %15[^\n]", tempSHLast->last_service_date);
        else if (readingBike && strstr(line, "Description"))
            sscanf(line, " Description        : %127[^\n]", tempSHLast->description);

        else if (readingBike && strstr(line, "========================================================================="))
        {
            BikeDetails *exists = find_bike_by_number(tempBike.bike_number);

            if (exists == NULL)
            {
                // Create new bike entry
                BikeDetails *newBike = malloc(sizeof(BikeDetails));
                memcpy(newBike, &tempBike, sizeof(BikeDetails));
                newBike->service_history = tempSHHead;
                newBike->next = bike_data;
                bike_data = newBike;
            }
            else
            {
                // Merge new service history block to existing bike
                if (exists->service_history == NULL)
                {
                    exists->service_history = tempSHHead;
                }
                else
                {
                    ServiceHistory *p = exists->service_history;
                    while (p->next)
                        p = p->next;
                    p->next = tempSHHead;
                }
            }

            readingBike = 0;
        }
    }

    fclose(fp);

    BikeDetails *bike = bike_data;
    while (bike)
    {
        sort_service_history(&bike->service_history);
        bike = bike->next;
    }

    printf("\nData loaded from the DB successfully...!!!\n");
}

/* Helper function to Vehicle validation  */
int is_vehicle_valid(const char *bike_number) {
    if (strlen(bike_number) != 10) {
        printf("\nInvalid Bike Number: Must be 10 characters (e.g., TN01AB1234).\n");
        return 0;
    }

    if (!isalpha(bike_number[0]) || !isalpha(bike_number[1])) {
        printf("\nInvalid Bike Number: First two characters must be letters.\n");
        return 0;
    }

    if (!isdigit(bike_number[2]) || !isdigit(bike_number[3])) {
        printf("\nInvalid Bike Number: Characters 3 and 4 must be digits.\n");
        return 0;
    }

    if (!isalpha(bike_number[4]) || !isalpha(bike_number[5])) {
        printf("\nInvalid Bike Number: Characters 5 and 6 must be letters.\n");
        return 0;
    }

    for (int i = 6; i < 10; i++) {
        if (!isdigit(bike_number[i])) {
            printf("\nInvalid Bike Number: Last four characters must be digits.\n");
            return 0;
        }
    }

    printf("\nBike Number is valid.\n");
    return 1;
}

/* New Registration Helper function */
void new_registration()
{
    printf("\nWelcome to New Registration:\n");
    BikeDetails *new=NULL;
    ServiceHistory *serv_hist=NULL;
    int c;

    new = (BikeDetails*)malloc(sizeof(BikeDetails));
    if(!new){
        printf("\nMemory Not allocated.\n");
        return;
    }

    printf("\nEnter BikeNumber:\n");
    scanf("%s", new->bike_number);
    is_vehicle_valid(new->bike_number);

    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nName of Customer:\n");
    scanf(" %48[^\n]", new->name);
    printf("\nAddress :\n");
    scanf(" %99[^\n]", new->address);
    printf("\nMobile No.:\n");
    scanf(" %s", new->mobile);
    printf("\nDate of Purchase:\n");
    scanf("%s", new->date_of_purchase);
    while ((c = getchar()) != '\n' && c != EOF);

    serv_hist = (ServiceHistory*)malloc(sizeof(ServiceHistory));
    if(!serv_hist){
        printf("\nMemory not allocated for service history.\n");
        free(new);
        return;
    }
    memset(serv_hist, 0, sizeof(ServiceHistory));

    const char* selected_type = select_service_type();
    if(selected_type == NULL) {
        free(new); free(serv_hist); return;
    }
    strcpy(serv_hist->service_type, selected_type);

    if(strcmp(serv_hist->service_type, "NEW") != 0)
    {
        printf("\nLast Service Date:\n");
        scanf("%15s", serv_hist->last_service_date);
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\nProblem Description:\n");
        scanf("%127[^\n]", serv_hist->description);
    }
    else
    {
        strcpy(serv_hist->last_service_date, "N/A");
        strcpy(serv_hist->description, "NEW VEHICLE.......No Issues");
    }

    new->service_history = serv_hist;
    new->next = NULL;
    create_db(new);
    save_to_file(new);
    printf("\n\e[0;92mNew Registration Successful...\e[0m\n");
}

/* Helper function to Get Bike Details */
void get_bike_details()
{
    int count =0;
    load_from_file();
    printf("\nThe Bike Details are :\n");
    if(bike_data == NULL)
    {
        printf("\nNo bike Details found....!!!\n");
        return;
    }
    BikeDetails *bike= bike_data;
    while(bike !=NULL)
    {
        printf("\n================= Bike Details ================\n");
        printf(" Bike Number       : \e[0;92m%s\e[0m\n", bike->bike_number);
        printf(" Customer Name     : \e[0;94m%s\e[0m\n", bike->name);
        printf(" Address           : \e[0;95m%s\e[0m\n", bike->address);
        printf(" Mobile Number     : \e[0;97m+91-%s\e[0m\n", bike->mobile);
        printf(" Date of Purchase  : \e[0;93m%s\e[0m\n", bike->date_of_purchase);
        printf(" Service Type      : \e[0;96m%s\e[0m\n", bike->service_history->service_type);
        printf(" Last Service Date : \e[0;91m%s\e[0m\n", bike->service_history->last_service_date);
        printf(" Problem Description : \e[0;92m%s\e[0m\n", bike->service_history->description);
        printf("================================================\n");
        bike = bike->next;
        count++;
    }
    printf("\n Total %d number of bikes are printed....!!!\n", count);
}

/* Helper function to Update the Bike Details */
void update_bike_details()
{
    if(bike_data == NULL)
    {
        printf("\nNo Bike Data available to update....\n");
        return;
    }

    char search_num[12], temp[128];
    int choice=0, c;
    printf("\nEnter Bike Number to Update:\n");
    scanf("%11s", search_num);

    BikeDetails *bike_upd = bike_data;

    while(bike_upd != NULL)
    {
        if(strcmp(bike_upd->bike_number, search_num) == 0)
        {
            printf("\n\e[0;93mBike Found! Current Details:\e[0m\n");
            printf("=========================================\n");
            printf("Bike Number        : \e[0;92m%s\e[0m\n", bike_upd->bike_number);
            printf("1. Name            : \e[0;94m%s\e[0m\n", bike_upd->name);
            printf("2. Address         : \e[0;95m%s\e[0m\n", bike_upd->address);
            printf("3. Mobile          : \e[0;97m%s\e[0m\n", bike_upd->mobile);
            printf("4. Date of Purchase: \e[0;93m%s\e[0m\n", bike_upd->date_of_purchase);
            printf("5. Service Type    : \e[0;96m%s\e[0m\n", bike_upd->service_history->service_type);
            printf("6. Last Service Date : \e[0;91m%s\e[0m\n", bike_upd->service_history->last_service_date);
            printf("7. Problem Description : \e[0;92m%s\e[0m\n", bike_upd->service_history->description);
            printf("=========================================\n");

            while(1)
            {
                printf("\n===== \e[0;36mUpdate Menu\e[0m =====\n");
                printf("1. Update Name\n");
                printf("2. Update Address\n");
                printf("3. Update Mobile\n");
                printf("4. Update Date of Purchase\n");
                printf("5. Update Service Type\n");
                printf("6. Update Last Service Date\n");
                printf("7. Update Description \n");
                printf("8. Save & Exit\n");
                printf("Choose an option: ");

                if (scanf("%d", &choice) != 1) {
                    printf("\n\e[0;91mInvalid input.\e[0m\n");
                    while(getchar()!='\n');
                    continue;
                }
                while ((c = getchar()) != '\n' && c != EOF);

                switch (choice)
                {
                    case 1:
                        printf("Enter new Name: ");
                        fgets(temp, sizeof(temp), stdin);
                        sscanf(temp, "%49[^\n]", bike_upd->name);
                        break;

                    case 2:
                        printf("Enter new Address: ");
                        fgets(temp, sizeof(temp), stdin);
                        sscanf(temp, "%99[^\n]", bike_upd->address);
                        break;

                    case 3:
                        printf("Enter new Mobile: ");
                        fgets(temp, sizeof(temp), stdin);
                        sscanf(temp, "%15[^\n]", bike_upd->mobile);
                        break;

                    case 4:
                        printf("Enter new Date of Purchase: ");
                        fgets(temp, sizeof(temp), stdin);
                        sscanf(temp, "%15[^\n]", bike_upd->date_of_purchase);
                        break;

                    case 5:
                        {
                            const char* selected_type = select_service_type();
                            if(selected_type != NULL) {
                                strcpy(bike_upd->service_history->service_type, selected_type);
                                printf("\n\e[0;92mService Type updated to %s\e[0m\n", selected_type);
                            } else {
                                printf("\n\e[0;91mService Type not updated.\e[0m\n");
                            }
                            break;
                        }

                    case 6:
                        printf("Enter new Last Service Date: ");
                        fgets(temp, sizeof(temp), stdin);
                        sscanf(temp, "%15[^\n]", bike_upd->service_history->last_service_date);
                        break;

                    case 7:
                        printf("Enter the Correct Description: ");
                        fgets(temp, sizeof(temp), stdin);
                        sscanf(temp, "%127[^\n]", bike_upd->service_history->description);
                        break;

                    case 8:
                        printf("\nSaving updated details to file...\n");
                        save_to_file(bike_upd);
                        printf("\n\e[0;92mUpdate successful!\e[0m\n");
                        return;

                    default:
                        printf("\n\e[0;91mInvalid option. Try again.\e[0m\n");
                }
            }
        }
        bike_upd = bike_upd->next;
    }

    printf("\n\e[0;91mBike Number '%s' not found!\e[0m\n", search_num);
}

//Helper function to get the Service History.
void get_service_history()
{
    load_from_file();

    if(bike_data == NULL)
    {
        printf("\n\e[0;91mNo Bike Data Found!\e[0m\n");
        return;
    }

    BikeDetails *bike = bike_data;

    while(bike != NULL)
    {
        printf("\n================= Service History for %s =================\n", bike->bike_number);

        sort_service_history(&(bike->service_history));
        
        ServiceHistory *sh = bike->service_history;
        
        while(sh != NULL)
        {
            printf("Service Type       : \e[0;96m%s\e[0m\n", sh->service_type);
            printf("Last Service Date  : \e[0;91m%s\e[0m\n", sh->last_service_date);
            printf("Description        : \e[0;92m%s\e[0m\n", sh->description);
            printf("----------------------------------------------------------\n");
            sh = sh->next;
        }
        bike = bike->next;
    }
}

/* Helper function to Book a Service */
void book_service()
{
    if (bike_data == NULL)
    {
        printf("\n\e[0;91mNo Bike Data Available. Please load or register a bike.\e[0m\n");
        return;
    }

    char search_num[16];
    int c;

    printf("\nEnter Bike Number to Book Service:\n");
    scanf("%15s", search_num);

    BikeDetails *bike = bike_data;

    while (bike != NULL)
    {
        if (strcmp(bike->bike_number, search_num) == 0)
        {
            printf("\n\e[0;93mBike Found! Booking Service for %s\e[0m\n", search_num);

            ServiceHistory *newService = (ServiceHistory *)malloc(sizeof(ServiceHistory));
            if (!newService)
            {
                printf("\n\e[0;91mMemory Allocation Failed for Service History!\e[0m\n");
                return;
            }
            memset(newService, 0, sizeof(ServiceHistory));
            newService->next = NULL;

            const char* selected_type = select_service_type();
            if(selected_type == NULL) {
                free(newService);
                return;
            }
            strcpy(newService->service_type, selected_type);

            printf("\nEnter Service Date (DD-MM-YYYY): ");
            scanf("%15s", newService->last_service_date);
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\nEnter Problem Description:\n");
            scanf(" %127[^\n]", newService->description);

            ServiceHistory *sh = bike->service_history;
            while (sh->next != NULL)
                sh = sh->next;
            sh->next = newService;

            printf("\n\e[0;92mService Booked Successfully!\e[0m\n");
            save_to_file(bike);
            return;
        }

        bike = bike->next;
    }

    printf("\n\e[0;91mBike Number '%s' Not Found!\e[0m\n", search_num);
}

/* Helper function to Print menu*/
void print_menu()
{
    const char *welcome_msg = "WELCOME TO BIKE MOTORS. ";
    printf("\n*********************************");
    printf("\n*  \e[32m%s\t\e[37m*", welcome_msg);
    printf("\n*********************************");
    printf("\n^  1. New Registration. \t^");
    printf("\n^  2. Get Bike Details. \t^");
    printf("\n^  3. Update Bike Details. \t^");
    printf("\n^  4. Service History. \t\t^");
    printf("\n^  5. Book a Service.  \t\t^");
    printf("\n^  6. Quit.            \t\t^");
    printf("\n*********************************");
}

/* Main function */
int main()
{
    int sel;
    while(1)
    {
        print_menu();
        printf("\nEnter the number for Selection(1 or 2 or 3 or 4 or 5 and 6)\n");
        if(scanf(" %d", &sel) !=1) {
            printf("\n\e[0;91mInvalid Input.\e[0m\n");
            while(getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch(sel)
        {
            case 1: new_registration(); break;
            case 2: get_bike_details(); break;
            case 3: update_bike_details(); break;
            case 4: get_service_history(); break;
            case 5: book_service(); break;
            case 6: printf("\n\e[0;93mQuiting the Application...\e[0m\n"); exit(0);
            default: printf("\n\e[0;91mInvalid Selection. Thank You for Visiting.....\e[0m\n");
        }
    }
}

