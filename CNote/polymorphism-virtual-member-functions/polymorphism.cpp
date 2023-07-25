#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Business
{
public:
    void SetName(string busName)
    {
        name = busName;
    }

    void SetAddress(string busAddress)
    {
        address = busAddress;
    }

    virtual string GetDescription() const
    {
        return name + " -- " + address;
    }

protected:
    string name;
    string address;
};

class Restaurant : public Business
{
public:
    void SetRating(int userRating)
    {
        rating = userRating;
    }

    int GetRating() const
    {
        return rating;
    }

    string GetDescription() const override
    {
        return name + " -- " + address +
            "\n  Rating: " + to_string(rating);
    }

private:
    int rating;
};

int main()
{
    unsigned int i;
    vector<Business*> businessList;
    Business* businessPtr;
    Restaurant* restaurantPtr;

    businessPtr = new Business;
    businessPtr->SetName("ACME");
    businessPtr->SetAddress("4 Main St");

    restaurantPtr = new Restaurant;
    restaurantPtr->SetName("Friends Cafe");
    restaurantPtr->SetAddress("500 2nd Ave");
    restaurantPtr->SetRating(5);

    businessList.push_back(businessPtr);
    businessList.push_back(restaurantPtr);

    for (i = 0; i < businessList.size(); ++i)
    {
        cout << businessList.at(i)->GetDescription() << endl;
    }

    return 0;
}
