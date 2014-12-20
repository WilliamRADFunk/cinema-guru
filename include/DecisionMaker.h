#ifndef DECISIONMAKER_H_INCLUDED
#define DECISIONMAKER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "Cinema.h"
#include "Theater.h"
#include "Movie.h"
#include "Calendar.h"
#include "RandomEvent.h"
#include "RandomEventHandler.h"
#include "Global.h"

class DecisionMaker
{
private:

    Cinema* TheCinema;
    RandomEventHandler* TheREHandler;

    const std::string Snacks[6] =            {"Popcorn", "Soda", "HotDogs", "Cappuccinos", "Pretzels", "Nachos"};
    const std::string StaffPerformance[5] =  {"Dismal", "Below Average", "Mediocre", "Above Average", "Flawless"};
    const std::string Promotions[6] =        {"None", "Tickets Half-Off on Tuesdays", "Free Snack w/ Ticket",
                                              "Flood Local Papers w/ Advertisements", "Mass-Mailed Coupon Booklets", "TV Commercial"};

    char Decision, DecisionBuy, DecisionBuyUpgrade, DecisionStaff,
         DecisionBuyMovieLicense, DecisionMovieSelection, DecisionRandomEvent;

    int Decision_TheaterNum, HowManySeatsToBuy, ChangeStaff,
        MovieLicenseSelected, NewLicenseOffered, NumTicketsPurchased,
        TheatersWithoutMoviesPlaying, RandomEventIndex;

    float RandomAttendanceQuotient;

public:
    DecisionMaker(Cinema*);
    ~DecisionMaker();

    void choiceTree_Main();
    void choiceTree_01();
    void choiceTree_01_01(int);
    void choiceTree_01_03(int);
    void choiceTree_01_04(int);
    void choiceTree_01_05(int);
    void choiceTree_01_06(int);
    void choiceTree_02();
    void choiceTree_03(float);
    void choiceTree_04(int);
    void choiceNumOfSeats(int, int);
    void choiceUpgradeLevels(int, float, float, float);
    void choiceUpgradeChosenEquipment(float, Equipment);
    std::string calculateStaffLevel(int, int);
    std::string calculatePromotionLevel(int);
    void choiceHireStaff(int, int);
    void choiceFireStaff(int, int);
    void currentMovie(int, std::string);

    char getYesOrNo();
    char getQuitConfirmation();
    char getSelectionMain();
    char getSelection_01();
    int getSelection_01_02();
    char getSelection_01_05(int);
    bool getSelection_01_06(int, int);
    char getSelection_02();
    int getSelection_TheaterNum(int);
    int getSelectionSeatPurchase();
    char getSelectionUpgradePurchase();
    int getNumOfEmployeesToHire(int, int);
    int getNumOfEmployeesToFire(int, int);
    float getNewTicketPrice();
    int getSelectedLicense();
    char getRandomEventChoice();
    float getStaffFactor(int, int);
    float getTPriceFactor(float);
    float getSeasonFactor(Season, Season, Season);
    float getPromoFactor(int);

    bool checksPurchaseOfSeats(int, int, int);
    bool checkPurchaseOfMovieLicense(int, int);
    bool checkPurchaseOfSnacks(int, int);
    bool checkPurchaseOfUpgrade(int, float, Equipment);

    void activateDecisionTree();
};

#endif // DECISIONMAKER_H_INCLUDED
