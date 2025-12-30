// Name: MUHAMMAD AIDIL FARHAN BIN ZAMRI // MATRIC NUMBER: A25CS0260
// Name: MUHAMMAD HAFIZUDDIN HAKIMI BIN HASMADI  // MATRIC NUMBER: A25CS0273
// 28th December 2025
// Set 2

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void getCarInfo (int &, int &, int &);
void carInfo (int, int, int);
int carPrice(int, int, int);

int main(){
    
    int model, variant, region;
    float downPayment, interestRate;
    int repaymentPeriod;

    cout << "Proton Car Loan Calculator" << endl;

    char choice = 'Y';

    while (choice == 'Y' || choice == 'y'){
        getCarInfo(model, variant, region);

        cout << "\nCar info" << endl;

        carInfo(model, variant, region);

        cout << "Paint Type: Metallic" << endl;
        cout << "Price (MYR): " << carPrice(model, variant, region) << endl;

        cout << "\nDown Payment (MYR): ";
        cin >> downPayment;
        cout << "Interest Rate (%): ";
        cin >> interestRate;
        cout << "Repayment Period (in years): ";
        cin >> repaymentPeriod;

        cout << "\nMONTHLY REPAYMENT (MYR): ";
        float principal = carPrice(model, variant, region) - downPayment;
        float totalInterest = principal * (interestRate / 100) * repaymentPeriod;
        float totalAmount = principal + totalInterest;
        float monthlyRepayment = totalAmount / (repaymentPeriod * 12);
        cout << fixed << setprecision(2) << monthlyRepayment << endl;

        cout << "\nDo you want to enter other data? (Y/N): ";
        cin >> choice;


    }

    cout << "\nThank you :)" << endl;

    return 0;


}


void getCarInfo (int &mdl, int &vrnt, int &rgion){

    cout << "\nModel [1-X50, 2-Exora, 3-Persona]: ";
    cin >> mdl;

    cout << "Variants [1-1.6L Standart CVT, 2-1.6L Premium CVT]: ";
    cin >> vrnt;

    cout << "Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
    cin >> rgion;
}

void carInfo (int mdl, int vrnt, int rgion){
    switch (mdl){    
        case 1:
            cout << "Model: X50" << endl;
            break;
        case 2:
            cout << "Model: Exora" << endl;
            break;
        case 3:
            cout << "Model: Persona" << endl;
            break;
        default:
            cout << "Invalid model selected" << endl;
    }
    switch (vrnt){
        case 1:
            cout << "Variant: 1.6L Standard CVT" << endl;
            break;
        case 2:
            cout << "Variant: 1.6L Premium CVT" << endl;
            break;
        default:
            cout << "Invalid variant selected" << endl;
    }
    switch (rgion){
        case 1:
            cout << "Region: Peninsular Malaysia" << endl;
            break;
        case 2:
            cout << "Region: East Malaysia" << endl;
            break;
        default:
            cout << "Invalid region selected" << endl;
    }
        
    
}
int carPrice(int model, int variant, int region){
    int price = 0;
    if (region == 1){ // Peninsular Malaysia
        if (model == 1){ // X50
            if (variant == 1){ // Standard
                price = 86300;
            } else if (variant == 2){ // Premium
                price = 101800;
            }
        } else if (model == 2){ // Exora
            if (variant == 1){
                price = 62800;
            } else if (variant == 2){
                price = 69800;
            }
        } else if (model == 3){ // Persona
            if (variant == 1){
                price = 47800;
            } else if (variant == 2){
                price = 58300;
            }
        }
    } else if (region == 2){ // East Malaysia
        if (model == 1){ // X50
            if (variant == 1){
                price = 90392;
            } else if (variant == 2){
                price = 106271;
            }
        } else if (model == 2){ // Exora
            if (variant == 1){
                price = 65300;
            } else if (variant == 2){
                price = 72300;
            }
        } else if (model == 3){ // Persona
            if (variant == 1){
                price = 49800;
            } else if (variant == 2){
                price = 60300;
            }
        }
    }
    return price;
}