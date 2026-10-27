  #include <iostream>
#include <string>
using namespace std;

struct Product
{
    string name;
    double buyingPrice;
    double sellingPrice;
    int quantity;
};

Product products[100];
int productCount = 0;

void addProduct()
{
    cout << "\n--- ADD PRODUCT ---\n";

    cout << "Enter product name: ";
    cin >> products[productCount].name;

    cout << "Enter buying price: ";
    cin >> products[productCount].buyingPrice;

    cout << "Enter selling price: ";
    cin >> products[productCount].sellingPrice;

    cout << "Enter quantity: ";
    cin >> products[productCount].quantity;

    productCount++;

    cout << "Product added successfully!\n";
}

void viewProducts()
{
    cout << "\n--- PRODUCTS ---\n";

    for (int i = 0; i < productCount; i++)
    {
        cout << "\nProduct: " << products[i].name;
        cout << "\nBuying Price: GHc " << products[i].buyingPrice;
        cout << "\nSelling Price: GHc " << products[i].sellingPrice;
        cout << "\nQuantity: " << products[i].quantity;
        cout << "\n----------------------\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "       SHOP SALES SYSTEM\n";
        cout << "================================\n";
        cout << "1. Add Product\n";
        cout << "2. Record Sale\n";
        cout << "3. View Products\n";
        cout << "4. View Sales\n";
        cout << "5. Exit\n";
        cout << "================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addProduct();
        }
        else if (choice == 3)
        {
            viewProducts();
        }
        else if (choice == 5)
        {
            cout << "Goodbye!\n";
        }
        else
        {
            cout << "This option is not ready yet.\n";
        }

    } while (choice != 5);

    return 0;
}
