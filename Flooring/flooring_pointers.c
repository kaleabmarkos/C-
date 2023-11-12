// Description:
// This program will create a customer's bill for a company that sells and installs flooring material.
// The program makes use of pointers.
//
//*******************************************************************************************************

//preprocessor directives
#include <stdio.h>

#define LABOR_RATE 0.35
#define TAX_RATE   8.50

//function prototypes
void introduction(void);

int get_int(void);
double get_double(void);

void print_measurements(int length, int width, int area);
void print_charges(double cost_sq_ft, double material_cost, double labor_cost,
                   double goods_and_labor, int pct_discount, double discount_amt,
                   double subtotal, double tax, double total);
void calc_price_with_install(int len, int wid, double cost_sq_ft, int* ptr_area, double* ptr_material_cost, double* ptr_labor_cost, double* ptr_good_labor_cost);
void calc_subtotal( double goods_labor_cost, int disc_pct, double* ptr_discount_amt, double* ptr_subtotal);
void calc_total(double subtotal, double* ptr_tax_amt, double* ptr_total );

int main (void)
{
    // Declare variables
    int length = 0,          // These variables could all be doubles, but the are set to
        width = 0,           // to be integers so we can work with multiple data types.
        pct_discount = 0,    // By making the Percent an integer we cannot have 5.5% discount.
        area = 0;            // If length & width are both integers, the area will also be.
    double cost_sq_ft = 0,   // Cost per square foot of the flooring material
        material_cost = 0,   // Total cost of material (area * cost per sq ft)
        labor_cost = 0,      // Cost to install - Charged based on area of material purchased
        goods_and_labor = 0, // Cost of materials plus cost to install.
        discount_amt = 0,    // Discount amount to be ducted from bill (goods_and_labor * pct_discount)
        subtotal = 0,        // Total before taxes
        tax = 0,             // Amount of tax to pay
        total = 0;           // Total cost due from customer

    // Display Greeting
    introduction();

    // Get data
    get_all_data(&length, &width, &pct_discount, &cost_sq_ft);

    // Process/calculations
    calc_price_with_install(length, width, cost_sq_ft, &area, &material_cost, &labor_cost, &goods_and_labor);
    calc_subtotal(goods_and_labor, pct_discount, &discount_amt, &subtotal);
    calc_total(subtotal, &tax, &total);

    // Display output
    print_measurements(length, width, area);
    print_charges(cost_sq_ft, material_cost, labor_cost, goods_and_labor, pct_discount,
                  discount_amt, subtotal, tax, total);

    return 0;
}   //End main

//***************************************************************************
// Function:        introduction
// Data Passed In:  none
// Data Returned:   none
// Description:     Displays a greeting to the user.
//***************************************************************************
void introduction(void)
{
    printf("******************************************************************\n");
    printf("\nThis program creates a customer's bill for the purchase and\n");
    printf("installation of flooring material.\n\n\n");
    printf("******************************************************************\n");

    return;
}   //End introduction

//***************************************************************************
// Function:        get_all_data
// Data Passed In:
// Data Returned:
// Description:     get length, width, percent discount, and flooring price from
//                  the user and return them to main
//***************************************************************************
void get_all_data(int * ptr_length, int * ptr_width, int* ptr_pct, double * ptr_cost)
{
    printf("\nLength of room (feet)?         ");
    *ptr_length = get_int();                    //calls the get_int function to get an integer value
    printf("Width of room (feet)?          ");
    *ptr_width  = get_int();                     //calls the get_int function to get an integer value
    printf("Customer discount (percent)?   ");
    *ptr_pct = get_int();          //calls the get_int function to get an integer value
    printf("Cost per square foot (xxx.xx)? ");
    *ptr_cost  = get_double();           //calls the get_double function to get a double value

    return;
}   //End get_all_data


//***************************************************************************
// Function:        get_int
// Data Passed In:
// Data Returned:
// Description:     get one integer value from the user
//***************************************************************************
int get_int(void)
{
    //Declare variables
    int num = 0;
    scanf("%d", &num);
    return num;
}   //End get_int

//***************************************************************************
// Function:        get_double
// Data Passed In:
// Data Returned:
// Description:     get one double value from the user
//***************************************************************************
double get_double(void)
{
    //Declare variables
    double num = 0;

    scanf("%lf", &num);

    return num;
}   //End get_double

//***************************************************************************
// Function:        ca1c_price_with_install
// Data Passed In:
// Data Returned:
// Description:     calculates area, material cost, labor cost, & installed price
//***************************************************************************
void calc_price_with_install(int len, int wid, double cost_sq_ft, int* ptr_area, double* ptr_material_cost, double* ptr_labor_cost, double* ptr_goods_and_labor)
{

   *ptr_area = len* wid;
   *ptr_material_cost = cost_sq_ft * *ptr_area;
   *ptr_labor_cost =  LABOR_RATE * *ptr_area;
   *ptr_goods_and_labor = *ptr_material_cost + *ptr_labor_cost;


    return;
}   //End ca1c_price_with_install

//***************************************************************************
// Function:        ca1c_subtotal
// Data Passed In:
// Data Returned:
// Description:     calculates discount amount and subtotal
//***************************************************************************
void calc_subtotal( double goods_labor_cost, int disc_pct, double* ptr_discount_amt, double* ptr_subtotal)
{
    *ptr_discount_amt = goods_labor_cost * disc_pct/100.0;
    *ptr_subtotal = goods_labor_cost - *ptr_discount_amt;

    return;
}   //End ca1c_subtotal

//***************************************************************************
// Function:        ca1c_total
// Data Passed In:
// Data Returned:
// Description:     calculates tax and total cost
//***************************************************************************
void calc_total(double subtotal, double* ptr_tax_amt, double* ptr_total )
{
   *ptr_tax_amt = subtotal * TAX_RATE;
   *ptr_total = subtotal + *ptr_tax_amt;

    return;
}   //End ca1c_total

//***************************************************************************
// Function:        print_measurements
// Data Passed In:  three integers
// Data Returned:   none
// Description:     Displays the measurements
//***************************************************************************
void print_measurements(int length, int width, int area)
{
    printf("\n\t\t\tMEASUREMENT\n");
    printf("\n\tLength\t\t\t\t%3d ft", length);
    printf("\n\tWidth\t\t\t\t%3d ft", width);
    printf("\n\tArea\t\t\t\t%3d square ft", area);

    return;
}   //End print_measurements

//***************************************************************************
// Function:        print_charges
// Data Passed In:  8 doubles and one integer
// Data Returned:   none
// Description:     displays the charges section
//***************************************************************************
void print_charges(double cost_sq_ft, double material_cost, double labor_cost,
                   double goods_and_labor, int pct_discount, double discount_amt,
                   double subtotal, double tax, double total)
{
    printf("\n\n\t\t\t  CHARGES");
    printf("\n\n\tDESCRIPTION  COST/SQ.FT.      CHARGE\n");
    printf("\t-----------  -----------  ------------\n");
    printf("\tMaterial       %6.2f\t     $%8.2f\n", cost_sq_ft, material_cost);
    printf("\tLabor\t\t %4.2f\t      %8.2f\n", LABOR_RATE, labor_cost);
    printf("\t\t\t\t  ------------\n");
    printf("\tMaterial + Labor\t     $%8.2f\n", goods_and_labor);
    printf("\tDiscount\t   %2d%%\t      %8.2f\n", pct_discount, discount_amt);
    printf("\t\t\t\t  ------------\n");
    printf("\tSUBTOTAL\t\t     $%8.2f\n", subtotal);
    printf("\tTAX\t\t\t      %8.2f\n", tax);
    printf("\tTOTAL\t\t\t     $%8.2f\n", total);

    return;
}   //End print_charges
//============================END_PROGRAM====================================
