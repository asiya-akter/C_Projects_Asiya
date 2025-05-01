#include <stdio.h>
#include <string.h>

struct Product
{
    char productCode[20];
    char name[100];
    char brand[50];
    //char size[20];
    int stock;
    int buyPrice;
    int sellPrice;
}products[1000];



struct SellItem
{
    char productCode[20];
    int quantity;
    int profitPerItem;
}sellItems[1000];

int totalProduct = 0;
int totalSell = 0;

void addNewProduct();
void addMoreItemToStock();
void viewProductList();
void sellProduct();
void viewSellList();
void viewTotalProfit();

int main()
{
    int choice;
    int flag = 1;

    while(flag)
    {
        printf("Enter a choice\n1. Add a Product.\n2. Add stock to product.\n3. View porudct list.\n4. sell a product.\n5. View sell list.\n6. view profit.\n7. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addNewProduct();
                break;
            case 2:
                addMoreItemToStock();
                break;
            case 3:
                viewProductList();
                break;
            case 4:
                sellProduct();
                break;
            case 5:
                viewSellList();
                break;
            case 6:
                viewTotalProfit();
                break;
            case 7:
                flag = 0;
                break;
        }
    }
    return 0;
}



void addNewProduct()
{
    printf("Enter Product name\n");
    scanf("%s", products[totalProduct].name);

    printf("Enter Product Code\n");
    scanf("%s", products[totalProduct].productCode);

    printf("Enter Product Brand\n");
    scanf("%s", products[totalProduct].brand);

    printf("Enter Product Buy Price\n");
    scanf("%d",&products[totalProduct].buyPrice);

    printf("Enter Product Sell Price\n");
    scanf("%d",&products[totalProduct].sellPrice);
    totalProduct++;
}


void viewProductList()
{
    printf("****************Product List Starts*****************\n");
    for( int index=0; index<totalProduct; index++ ){
        printf("\n");
        printf("Product Name: %s\n", products[index].name);
        printf("Product Code: %s\n", products[index].productCode);
        printf("Product Brand: %s\n", products[index].brand);
        printf("Product Buy Price: %d\n", products[index].buyPrice );
        printf("Product Sell Price: %d\n", products[index].sellPrice );
        printf("Product Stock: %d\n", products[index].stock );
        printf("\n");
    }
    printf("****************Product List Ends*****************\n");
}

void addMoreItemToStock()
{
    char productCode[20];
    int stock;
    int index;
    printf("Enter Product Code\n");
    scanf("%s", productCode);

    for( index=0; index < totalProduct; index++ ){
        if( strcmp(products[index].productCode, productCode)==0){
            printf("Enter item number you want to add in stock\n");
            scanf("%d",&stock);
            products[index].stock+=stock;
            return;
        }
    }

    printf("Wrong product code given \n");
}


void sellProduct()
{
    char productCode[20];
    int quantity;
    int profitPerItem;
    int index;
    printf("Enter Product Code\n");
    scanf("%s", productCode);

    for( index=0; index < totalProduct; index++ ){
        if( strcmp(products[index].productCode, productCode)==0){
            printf("Enter Quanityt You want to sell\n");
            scanf("%d",&quantity);
            if( products[index].stock<quantity ){
                printf("There is not enough item in the stock\n");
            }else{
                products[index].stock -= quantity;
                profitPerItem = products[index].sellPrice - products[index].buyPrice;

                strcpy(sellItems[totalSell].productCode, productCode);
                sellItems[totalSell].quantity = quantity;
                sellItems[totalSell].profitPerItem = profitPerItem;
                totalSell++;
            }
            return;
        }
    }
    printf("Wrong product code given \n");
}


void viewSellList()
{
    printf("****************Sell List Starts*****************\n");
    for( int index=0; index < totalSell; index++ ){
        printf("\n");
        printf("Product code: %s\n", sellItems[index].productCode );
        printf("Quantity: %d\n", sellItems[index].quantity);
        printf("Profit: %d\n", sellItems[index].quantity * sellItems[index].profitPerItem);
        printf("\n");
    }
    printf("****************Sell List Ends*****************\n");
}


void viewTotalProfit()
{
    int totalProfit = 0;
    for( int index=0; index < totalSell; index++ ){
        totalProfit+= sellItems[index].quantity * sellItems[index].profitPerItem;
    }
    printf( "Total Profit is: %d\n\n", totalProfit );
}
