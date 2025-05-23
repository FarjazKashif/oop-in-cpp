#include <iostream>
using namespace std;

/*
A stock trading platform tracks different company stocks with current prices and total available
shares. Users can buy and sell stocks, and the system should update the company’s stock price
dynamically based on demand. Create a Stock class with private attributes for company name, stock
price, and available shares. Implement setters and getters to handle transactions securely, updating
stock prices based on market demand. Use a static data member to track overall stock market value.
The program should allow users to trade stocks and reflect market changes dynamically.
*/

class Stock
{
private:
    string companyName;
    float stockPrice;
    int availableShares;
    static float marketValue;

public:
    Stock(string name, float price, int shares)
    {
        this->companyName = name;
        this->stockPrice = price;
        this->availableShares = shares;
    }

    void market_Value()
    {
        marketValue = stockPrice * availableShares;
    }

    static float getMarketValue() {
        return marketValue;
    }

    void displayStock()
    {
        cout << "📈 " << companyName
             << " | Price: $" << stockPrice
             << " | Shares: " << availableShares << endl;
    }

    void setPrice(float p) { this->stockPrice = p; }

    void buyShares(int quantity)
    {
        if (quantity > availableShares)
        {
            cout << "Not enough shares available to buy." << endl;
            return; // Stop
        }

        availableShares -= quantity;

        if (quantity > 10)
            stockPrice *= 1.01; // Increment of 1%

        market_Value();
        cout << "✅ Bought: " << quantity << " shares of " << companyName << endl;
    }

    void sellShares(int quantity)
    {
        availableShares += quantity;

        if (quantity > 10)
            stockPrice *= 0.99; // Decrement of 1%

        market_Value();
        cout << "✅ Sold: " << quantity << " shares of " << companyName << endl;
    }
};

float Stock::marketValue = 0.0;

int main()
{
    Stock apple("Apple", 150.0, 100),
    tesla("Tesla", 200.0, 80);

    
    apple.displayStock();
    tesla.displayStock();
    cout << "🌍 Total Market Value: $" << Stock::getMarketValue() << "\n\n";
    
    // Buy Shares
    apple.buyShares(15);
    tesla.buyShares(10);

    cout << "\n📊 After transactions:\n";
    apple.displayStock();
    tesla.displayStock();
    cout << "🌍 Total Market Value: $" << Stock::getMarketValue() << "\n";
    
    return 0;
}
