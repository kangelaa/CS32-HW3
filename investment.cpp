//
//  investment.cpp
//  HW3
//
//  Created by Angela Kan on 2/9/21.
//

//CLASS DECLARATIONS

class Investment
{
    public:
        Investment(string name, int purchasePrice);
        virtual ~Investment();
        string name() const;
        virtual bool fungible() const;
        virtual string description() const = 0;
        int purchasePrice() const;
    private:
        string m_name;
        int m_purchasePrice;
};

class Painting : public Investment
{
    public:
        Painting(string name, int purchasePrice);
        virtual ~Painting();
        virtual string description() const;
    private:
};

class Stock : public Investment
{
    public:
        Stock(string name, int purchasePrice, string symbol);
        virtual ~Stock();
        virtual bool fungible() const;
        virtual string description() const;
    private:
        string m_symbol;
};

class House : public Investment
{
    public:
        House(string name, int purchasePrice);
        virtual ~House();
        virtual string description() const;
    private:
};

//FUNCTION IMPLEMENTATIONS (INVESTMENT)

Investment::Investment(string name, int purchasePrice)
: m_name(name), m_purchasePrice(purchasePrice)
{}

Investment::~Investment()
{}

string Investment::name() const {
    return m_name;
}

bool Investment::fungible() const {
    return false;
}

int Investment::purchasePrice() const {
    return m_purchasePrice;
}

//FUNCTION IMPLEMENTATIONS (PAINTING)

Painting::Painting(string name, int purchasePrice)
: Investment(name, purchasePrice)
{}

Painting::~Painting(){
    cout << "Destroying " << name() << ", a painting" << endl;
}

string Painting::description() const {
    return "painting";
}

//FUNCTION IMPLEMENTATIONS (STOCK)

Stock::Stock(string name, int purchasePrice, string symbol)
: Investment(name, purchasePrice), m_symbol(symbol)
{}

Stock::~Stock(){
    cout << "Destroying " << Investment::name() << ", a stock holding" << endl;
}

bool Stock::fungible() const {
    return true;
}

string Stock::description() const {
    return "stock trading as " + m_symbol;
}

//FUNCTION IMPLEMENTATIONS (HOUSE)

House::House(string name, int purchasePrice)
: Investment(name, purchasePrice)
{}

House::~House(){
    cout << "Destroying the house " << Investment::name() << endl;
}

string House::description() const {
    return "house";
}

