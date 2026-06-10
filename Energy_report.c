#include <stdio.h>
#include <math.h>
//Global scope
#define USD_RATE 3700.0
#define GBP_RATE 4400.0
#define EUR_RATE 4500.0
#define UNIT_PRICE 900.0
#define FILE_NAME "energy_report.txt"

// FUNCTION PROTOTYPE
void saveReportToFile(float apparent, float powerfactor, float amount, char*currencyName);

int main(){
    float real_power, reactive_power, apparent_power, powerfactor;
    float units, total_UGX, final_amount;
    int choice;
    char*currencyName;

    printf("--- Industrial Energy Management System ---\n");

    // 1.Power Factor Input & Calculation
    printf("Enter Real Power (P) in kW: ");
    scanf("%f", &real_power);
    printf("Enter Reactive Power (Q) IN kVAR: ");
    scanf("%f", &reactive_power);

    apparent_power = sqrt(pow(real_power, 2) + pow(reactive_power, 2));
    powerfactor = (apparent_power != 0) ? (real_power / apparent_power) : 0;

    //2. Consumption and Base Bill
    printf("\nEnter total electricity consumed (kWh): ");
    scanf("%f", &units);
    total_UGX = units * UNIT_PRICE;

    //3. Currency Selection
    printf("\nSelect payment currency:\n");
    printf("1.UGX (Ugandan Shillings)\n2. USD ($)\n3. GBP (£)\n4. EUR (€)\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch(choice){
        case 2: final_amount = total_UGX / USD_RATE; currencyName = "USD"; break;
        case 3: final_amount = total_UGX / GBP_RATE; currencyName = "GBP"; break;
        case 4: final_amount = total_UGX / EUR_RATE; currencyName = "EUR"; break;
        default: final_amount = total_UGX; currencyName = "UGX"; break;
    }

    //4. Final Output Report (NOW VISIBLE ON SCREEN)
    printf("\n======================================\n");
    printf("       INDUSTRIAL ENERGY REPORT  \n");
    printf("========================================\n");
    printf("EFFICIENCY DATA:\n");
    printf("Apparent Power: %.2f kVA\n", apparent_power);
    printf("Power Factor: %.3f\n", powerfactor);

    if (powerfactor < 0.90f) {
        printf("STATUS: LOW POWER FACTOR - Penalty may apply.\n");
    } else {
        printf("STATUS: Efficient Operation.\n");
    }

    printf("---------------------------\n");
    printf("BILLING SUMMARY:\n");
    printf("Please pay: %s %.2f\n", currencyName, final_amount);
    printf("==========================\n");
    // 5. chapter 11 save the data to a file
    saveReportToFile(apparent_power, powerfactor, final_amount, currencyName);
    return 0;
}
//chapter 11 : FILE OPERATIONS
void saveReportToFile( float power , float powerfactor, float amount , char*currencyName){
    FILE* filePtr = fopen(FILE_NAME, "w");
    if(filePtr == NULL){
        printf("Error : Could not save to file.\n");
        return ;
    }
    fprintf(filePtr, "INDUSTRY ENERGY REPORT \n");
    fprintf(filePtr, "Apparent power: %.2f KVA\n", power);
    fprintf(filePtr, "Power Factor: %.3f\n", powerfactor);
    fprintf(filePtr, "Final bill: %s %.2f\n", currencyName, amount);
    fclose(filePtr);
    printf("\n[System: Report also saved to %s]\n", FILE_NAME);
}


