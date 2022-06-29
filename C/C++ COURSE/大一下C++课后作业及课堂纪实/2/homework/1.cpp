#include <iostream>
#include <string>
using namespace std;
class invoice
{
private:
    int PricePerItem, Quantity;
    string PartNumber, PartDescription;

public:
    invoice(string s, string b, int j, int k)
    {
        PartNumber = s;
        PartDescription = b;
        PricePerItem = k;
        Quantity = j;
    }
    void setPricePerItem(int x)
    {
        if (x < 0)
        {
            cout << " PricePerItemcannot be negative. PricePerItem set to 0" << endl;
            x = 0;
        }
        PricePerItem = x;
    }
    void setQuantity(int y)
    {
        if (y < 0)
        {
            cout << "quantity cannot be negative. quantity set to 0" << endl;
            y = 0;
        }
        Quantity = y;
    }
    void setPartNumber(string z)
    {
        PartNumber = z;
    }
    void setPartDescription(string m)
    {
        PartDescription = m;
    }
    int getPricePerItem()
    {
        return PricePerItem;
    }
    int getQuantity()
    {
        return Quantity;
    }
    string getPartNumber()
    {
        return PartNumber;
    }
    string getPartDescription()
    {
        return PartDescription;
    }
    int getInvoiceAmount()
    {
        return PricePerItem * Quantity;
    }
};
int main()
{
    // create an Invoice object
    invoice invoice("12345", "Hammer", 100, 5);
    // display the invoice data members and calculate the amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    // modify the invoice data members
    invoice.setPartNumber("123456");
    invoice.setPartDescription("Saw");
    invoice.setQuantity(-5);
    // negative quantity, so quantity set to 0
    invoice.setPricePerItem(10);
    cout << "\nInvoice data members modified.\n";
    // display the modified invoice data members and calculate new amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    return 0; // indicate successful termination} // end main
}