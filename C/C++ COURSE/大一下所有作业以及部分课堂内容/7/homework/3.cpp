//problem 7-3
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class Package
{
public:                                                                                                                                                                // constructor initiliazes data members
    Package(const string &, const string &, const string &, const string &, int, const string &, const string &, const string &, const string &, int, double, double); // done
    void setSenderName(const string &);                                                                                                                                // set sender's name
    string getSenderName() const;                                                                                                                                      // return sender's name
    void setSenderAddress(const string &);                                                                                                                             // set sender's address
    string getSenderAddress() const;                                                                                                                                   // return sender's address
    void setSenderCity(const string &);                                                                                                                                // set sender's city
    string getSenderCity() const;                                                                                                                                      // return sender's city
    void setSenderState(const string &);                                                                                                                               // set sender's state
    string getSenderState() const;                                                                                                                                     // return sender's state
    void setSenderZIP(int);                                                                                                                                            // set sender's ZIP code
    int getSenderZIP() const;                                                                                                                                          // return sender's ZIP code
    void setRecipientName(const string &);                                                                                                                             // set recipient's name
    string getRecipientName() const;                                                                                                                                   // return recipient's name
    void setRecipientAddress(const string &);                                                                                                                          // set recipient's address
    string getRecipientAddress() const;                                                                                                                                // return recipient's address
    void setRecipientCity(const string &);                                                                                                                             // set recipient's city
    string getRecipientCity() const;                                                                                                                                   // return recipient's city
    void setRecipientState(const string &);                                                                                                                            // set recipient's state
    string getRecipientState() const;                                                                                                                                  // return recipient's state
    void setRecipientZIP(int);                                                                                                                                         // set recipient's ZIP code
    int getRecipientZIP() const;                                                                                                                                       // return recipient's ZIP code
    void setWeight(double);                                                                                                                                            // validate and store weight
    double getWeight() const;                                                                                                                                          // return weight of package
    void setCostPerOunce(double);                                                                                                                                      // validate and store cost per ounce
    double getCostPerOunce() const;                                                                                                                                    // return cost per ounce
    double calculateCost() const;                                                                                                                                      // calculate shipping cost for package
private:
    // data members to store sender and recipient's address information
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    int senderZIP;
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    int recipientZIP;
    double weight;       // weight of the package
    double costPerOunce; // cost per ounce to ship the package
};                       // end class Package
class TwoDayPackage : public Package
{
public:
    TwoDayPackage(const string &sName, const string &sAddress, const string &sCity, const string &sState, int sZIP, const string &rName, const string &rAddress, const string &rCity, const string &rState, int rZIP, double w, double cost, double extra);
    void setFlatFee(double);      // set flat fee for two-day-delivery service
    double getFlatFee() const;    // return flat fee
    double calculateCost() const; // calculate shipping cost for package
private:
    double flatFee; // flat fee for two-day-delivery service
};                  // end class TwoDayPackage
class OvernightPackage : public Package
{
public:
    OvernightPackage(const string &sName, const string &sAddress, const string &sCity, const string &sState, int sZIP, const string &rName, const string &rAddress, const string &rCity, const string &rState, int rZIP, double w, double cost, double extra);
    void setOvernightFeePerOunce(double);   // set overnight fee
    double getOvernightFeePerOunce() const; // return overnight fee
    double calculateCost() const;           // calculate shipping cost for package
private:
    double overnightFeePerOunce; // fee per ounce for overnight delivery
};                               // end class OvernightPackage
// constructor initiliazes data members
Package::Package(const string &sName, const string &sAddress, const string &sCity, const string &sState, int sZIP, const string &rName, const string &rAddress, const string &rCity, const string &rState, int rZIP, double w, double cost) : senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZIP(sZIP), recipientName(rName), recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), recipientZIP(rZIP)
{
    setWeight(w);          // validate and store weight
    setCostPerOunce(cost); // validate and store cost per ounce
} // end Package constructor
// set sender's name
void Package::setSenderName(const string &name) { senderName = name; }
// end function setSenderName
// return sender's name
string Package::getSenderName() const
{
    return senderName;
} // end function getSenderName
// set sender's address
void Package::setSenderAddress(const string &address)
{
    senderAddress = address;
}
// end function setSenderAddress
// return sender's address
string Package::getSenderAddress() const
{
    return senderAddress;
}
// end function getSenderAddress
// set sender's city
void Package::setSenderCity(const string &city)
{
    senderCity = city;
}
// end function setSenderCity
// return sender's city
string Package::getSenderCity() const
{
    return senderCity;
}
// end function getSenderCity
// set sender's state
void Package::setSenderState(const string &state)
{
    senderState = state;
}
// end function setSenderState
// return sender's state
string Package::getSenderState() const
{
    return senderState;
}
// end function getSenderState
// set sender's ZIP code
void Package::setSenderZIP(int zip)
{
    senderZIP = zip;
}
// end function setSenderZIP
// return sender's ZIP code
int Package::getSenderZIP() const
{
    return senderZIP;
}
// end function getRecipientZIP
// validate and store weight
void Package::setWeight(double w)
{
    weight = (w < 0.0) ? 0.0 : w;
}
// end function setWeight
// return weight of package
double Package::getWeight() const
{
    return weight;
}
// end function getWeight
// validate and store cost per ounce
void Package::setCostPerOunce(double cost)
{
    costPerOunce = (cost < 0.0) ? 0.0 : cost;
}
// end function setCostPerOunce
// return cost per ounce
double Package::getCostPerOunce() const
{
    return costPerOunce;
}
// end function getCostPerOunce
// calculate shipping cost for package
double Package::calculateCost() const
{
    return getWeight() * getCostPerOunce();
}
// end function calculateCost
// StudybarCommentEnd
void Package::setRecipientName(const string &name)
{
    recipientName = name;
}
string Package::getRecipientName() const
{
    return recipientName;
}
void Package::setRecipientAddress(const string &address)
{
    recipientAddress = address;
}
string Package::getRecipientAddress() const
{
    return recipientAddress;
}
void Package::setRecipientCity(const string &city)
{
    recipientCity = city;
}
string Package::getRecipientCity() const
{
    return recipientCity;
}
void Package::setRecipientState(const string &state)
{
    recipientState = state;
}
string Package::getRecipientState() const
{
    return recipientState;
}
void Package::setRecipientZIP(int zip)
{
    recipientZIP = zip;
}
int Package::getRecipientZIP() const
{
    return recipientZIP;
}
TwoDayPackage::TwoDayPackage(const string &sName, const string &sAddress, const string &sCity, const string &sState, int sZIP, const string &rName, const string &rAddress, const string &rCity, const string &rState, int rZIP, double w, double cost, double extra) : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost)
{
    setWeight(w);          // validate and store weight
    setCostPerOunce(cost); // validate and store cost per ounce
    setFlatFee(extra);
}
void TwoDayPackage::setFlatFee(double fla)
{
    flatFee = fla;
}
double TwoDayPackage::getFlatFee() const
{
    return flatFee;
}
double TwoDayPackage::calculateCost() const
{
    return getWeight() * getCostPerOunce() + getFlatFee();
}
OvernightPackage::OvernightPackage(const string &sName, const string &sAddress, const string &sCity, const string &sState, int sZIP, const string &rName, const string &rAddress, const string &rCity, const string &rState, int rZIP, double w, double cost, double extra) : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost)
{
    setWeight(w);          // validate and store weight
    setCostPerOunce(cost); // validate and store cost per ounce
    setOvernightFeePerOunce(extra);
}
void OvernightPackage::setOvernightFeePerOunce(double extra)
{
    overnightFeePerOunce = extra;
}
double OvernightPackage::getOvernightFeePerOunce() const
{
    return overnightFeePerOunce;
}
double OvernightPackage::calculateCost() const
{
    return getWeight() * getCostPerOunce() + getOvernightFeePerOunce();
}
int main()
{
    Package package1("Lou Brown", "1 Main St", "Boston", "MA", 11111, "Mary Smith", "7 Elm St", "NewYork", "NY", 22222, 8.5, 0.5);
    TwoDayPackage package2("Lisa Klein", "5 Broadway", "Somerville", "MA", 33333, "Bob George", "21Pine Rd", "Cambridge", "MA", 44444, 10.4, 0.65, 2.0);
    OvernightPackage package3("Ed Lewis", "2 Oak St", "Boston", "MA", 55555, "Don Kelly", "9 Main St", "Denver", "CO", 66666, 12.25, 0.7, 3.065);
    cout << fixed << setprecision(2);
    // print each package's information and cost
    cout << "Package 1:\n\nSender:\n"
         << package1.getSenderName() << '\n'
         << package1.getSenderAddress() << '\n'
         << package1.getSenderCity() << ", " << package1.getSenderState() << ' ' << package1.getSenderZIP();
    cout << "\n\nRecipient:\n"
         << package1.getRecipientName() << '\n'
         << package1.getRecipientAddress() << '\n'
         << package1.getRecipientCity() << ", " << package1.getRecipientState() << ' ' << package1.getRecipientZIP();
    cout << "\n\nCost: $" << package1.calculateCost() << endl;
    cout << "\nPackage 2:\n\nSender:\n"
         << package2.getSenderName()
         << '\n'
         << package2.getSenderAddress() << '\n'
         << package2.getSenderCity() << ", " << package2.getSenderState() << ' ' << package2.getSenderZIP();
    cout << "\n\nRecipient:\n"
         << package2.getRecipientName() << '\n'
         << package2.getRecipientAddress() << '\n'
         << package2.getRecipientCity() << ", " << package2.getRecipientState() << ' ' << package2.getRecipientZIP();
    cout << "\n\nCost: $" << package2.calculateCost() << endl;
    cout << "\nPackage 3:\n\nSender:\n"
         << package3.getSenderName() << '\n'
         << package3.getSenderAddress() << '\n'
         << package3.getSenderCity() << ", " << package3.getSenderState() << ' ' << package3.getSenderZIP();
    cout << "\n\nRecipient:\n"
         << package3.getRecipientName() << '\n'
         << package3.getRecipientAddress() << '\n'
         << package3.getRecipientCity() << ", " << package3.getRecipientState() << ' ' << package3.getRecipientZIP();
    cout << "\n\nCost: $" << package3.calculateCost() << endl;
    return 0;
} // end main