/* =========================== AIRPORT BOOKING SYSTEM =========================== */
//
//	CREATORS
//	MAIN DEV: mardanniel
//	Drexmir Mentiza
//	Potchollo Cabos
//	Kenneth Bautista
//
/* ================================== LIBRARIES ================================= */

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

/* =================================== CLASSES ================================== */

static int flightRecords = 0;
const int flightYear = 2019;

struct AirportBookingSystemLL
{
	int passengerAge, passengerDestinationDay, passengerReturningDay, passengerDestinationYear, passengerReturningYear, departingFlightPrice, returningFlightPrice;
	string passengerName, passengerIdentificationNumber, passengerDestination, passengerOrigin, passengerDestinationMonth, passengerReturningMonth, airlineProvider1, airlineProvider2;
	struct AirportBookingSystemLL *next;
}*root;

class AirportBookingSystem
{
	public:

		void userData(string pIN, int pAge, string pN, string pDM, int pDd, string pD, string pO, string pRM, int pRD, int pDY, int pRY, string aP1, string aP2, int dFP, int rFP);
		
		void bookFlight();
		
		void findFlightSchedule(int flightO, int flightD, int flightDM, int flightDDt, int flightRM, int flightRDt, int flightDY, int flightRY);
		
		void illustrateDate(int flightMonth, int flightDay);
		
		void proceedGuestDetails(string flightO, string flightD, int flightDM, int flightDDt, int flightRM, int flightRDt, int flightDY, int flightRY, string aP1, string aP2, int dFP, int rFP);
		
		int airlinePricing(int flightO, int flightD);
		
		void modifyReservation();
		
		void deleteFlight();
		
		void checkBookedFlightInfo();
		
		void checkFlightAvailability(int flightO, int flightD);
		
		void displayAll();	//	FOR TESTING PURPOSES
		
		bool isMonthAndDateValid(int flightDM, int flightDDt, int flightRM, int flightRDt);
		
		string getRandomID();
		
		AirportBookingSystem()
		{
			SetConsoleTitle("AIRPORT BOOKING SYSTEM");
			root = NULL;
		}		
};
		
/* ================================= PROGRAM BODY ================================= */	
		
int main()
{
	system("color 5f");
	AirportBookingSystem ABS;
	while(1)
	{
		system("cls");		
		userChoiceAgain:					
		int userChoice;	
		cout<<"\n\n\n\t\t\t\t\t======================================"
			<<"\n\t\t\t\t\tWELCOME TO OUR AIRPORT BOOKING SYSTEM!\n\t\t\t\t\t======================================"
			<<"\n\n\t\t\t\t\t\tINDICATE YOUR CHOICE:\n\n"
			<<"\t\t\t\t\t\t[1] ADD FLIGHT\n\n"
			<<"\t\t\t\t\t\t[2] DELETE FLIGHT\n\n"
			<<"\t\t\t\t\t\t[3] MODIFY RESERVED FLIGHT\n\n"
			<<"\t\t\t\t\t\t[4] CHECK BOOKED FLIGHT INFO\n\n\n"
			<<"\t\t\t\t\t\t[5] EXIT PROGRAM\n\n\n"
			<<"\t\t\t\t\t\tCHOICE: ";
		cin>>userChoice;
		switch(userChoice)
		{
			case 1: { ABS.bookFlight(); break; }
			case 2: { ABS.deleteFlight(); break; }
			case 3: { ABS.modifyReservation(); break; }
			case 4: { ABS.checkBookedFlightInfo(); break; }
			case 5: { 
						char exitprog[33] = "THANK YOU FOR USING OUR PROGRAM!";
						system("cls");						
						cout<<"\n\n\n\n\n\n\n\t\t\t\t\t";
						for(int i=0; i<33; i++)
						{
							cout<<exitprog[i];
							Sleep(50);
						}
						exit(0);
					}
			case 6: { ABS.displayAll(); break; }	// FOR TESTING ONLY
			default: { cout<<"\n\n\t\t\t\t\t|| SYSTEM: WRONG INPUT. PLEASE TRY AGAIN. ||"; goto userChoiceAgain; }
		}
	}
	return 0;
}

/* ================================= FUNCTIONS =============================== */

void AirportBookingSystem::userData(string pIN, int pAge, string pN, string pDM, int pDd, string pD, string pO, string pRM, int pRD, int pDY, int pRY, string aP1, string aP2, int dFP, int rFP)
{
	AirportBookingSystemLL* pointer = new AirportBookingSystemLL;
	if(root == NULL)
	{
		root = pointer;
		pointer->passengerName = pN;	
		pointer->passengerAge = pAge;	
		pointer->passengerIdentificationNumber = pIN;
		
		pointer->passengerOrigin = pO;
		pointer->passengerDestination = pD;
		
		pointer->passengerDestinationMonth = pDM;
		pointer->passengerDestinationDay = pDd;
		pointer->passengerReturningMonth = pRM;
		pointer->passengerReturningDay = pRD;
		
		pointer->passengerDestinationYear = pDY;
		pointer->passengerReturningYear = pRY;
		
		pointer->airlineProvider1 = aP1;
		pointer->airlineProvider2 = aP2;
		
		pointer->departingFlightPrice = dFP;
		pointer->returningFlightPrice = rFP;
		pointer->next = NULL;
	}
	else
	{
		pointer->next = root;
		pointer->passengerName = pN;	
		pointer->passengerAge = pAge;	
		pointer->passengerIdentificationNumber = pIN;
		
		pointer->passengerOrigin = pO;
		pointer->passengerDestination = pD;
		
		pointer->passengerDestinationMonth = pDM;
		pointer->passengerDestinationDay = pDd;
		pointer->passengerReturningMonth = pRM;
		pointer->passengerReturningDay = pRD;
		
		pointer->passengerDestinationYear = pDY;
		pointer->passengerReturningYear = pRY;
		
		pointer->airlineProvider1 = aP1;
		pointer->airlineProvider2 = aP2;
		
		pointer->departingFlightPrice = dFP;
		pointer->returningFlightPrice = rFP;
		root = pointer;
		
	}
}
/*
AirportBookingSystemLL *AirportBookingSystem::userData(string pIN, int pAge, string pN, string pDM, int pDd, string pD, string pO, string pRM, int pRD, int pDY, int pRY, string aP1, string aP2, int dFP, int rFP)	//	FINISHED
{
	AirportBookingSystemLL *pointer;
	pointer = new AirportBookingSystemLL;

	pointer->passengerName = pN;	
	pointer->passengerAge = pAge;	
	pointer->passengerIdentificationNumber = pIN;
	
	pointer->passengerOrigin = pO;
	pointer->passengerDestination = pD;
	
	pointer->passengerDestinationMonth = pDM;
	pointer->passengerDestinationDay = pDd;
	pointer->passengerReturningMonth = pRM;
	pointer->passengerReturningDay = pRD;
	
	pointer->passengerDestinationYear = pDY;
	pointer->passengerReturningYear = pRY;
	
	pointer->airlineProvider1 = aP1;
	pointer->airlineProvider2 = aP2;
	
	pointer->departingFlightPrice = dFP;
	pointer->returningFlightPrice = rFP;
	
	pointer->next = NULL;
}
*/
void AirportBookingSystem::bookFlight()	//	FINISHED
{
	system("cls");
	int flightOriginChoice, flightDestinationChoice, flightDepartMonthChoice, flightDepartDayChoice, flightDepartYear,
							 flightReturnMonthChoice, flightReturnDayChoice, flightReturnYear;
	cout<<"\n\n\t\t\t\t\t\tINDICATE LOCATIONS:\n\n"
		<<"\t===============================================================================================\n"
		<<"\t[1] MANILA\t[2] ILOCOS NORTE\t[3] BATAAN\t[4] CEBU\t\t[5] ILO-ILO\n"
		<<"\t[6] AKLAN\t[7] BOHOL\t\t[8] DAVAO\t[9] GENERAL SANTOS\t[10] ZAMBOANGA\n"
		<<"\t===============================================================================================\n\n";
		
	inputPlaceAgain:
		
		cout<<"\tCHOOSE YOUR PLACE OF ORIGIN: ";
		cin>>flightOriginChoice;	
		cout<<"\tCHOOSE YOUR DESTINATION: ";
		cin>>flightDestinationChoice;
		
			if(flightOriginChoice == flightDestinationChoice)																	
			{																												
				cout<<"\n\t|| SYSTEM: PLACE OF ORIGIN AND DESTINATION CANNOT BE THE SAME! PLEASE TRY AGAIN! ||\n\n";			
				goto inputPlaceAgain;																							
			}																													
			else if(flightOriginChoice > 10 || flightDestinationChoice > 10)													
			{																													
				cout<<"\n\t|| SYSTEM: LOCATION OUT OF BOUNDS! REFER TO THE LIST. PLEASE TRY AGAIN! ||\n\n";						
				goto inputPlaceAgain;																							
			}																																																							
			
	cout<<"\n\n\n\t\t\t\t\t\tINDICATE MONTH AND DAY: \n\n"
		<<"\t===============================================================================================\n"
		<<"\t[1] JANUARY \t[2] FEBRUARY \t[3] MARCH \t[4] APRIL \t[5] MAY \t[6] JUNE\t\n"
		<<"\t[7] JULY \t[8] AUGUST \t[9] SEPTEMBER \t[10] OCTOBER \t[11] NOVEMBER \t[12] DECEMBER\t\n"
		<<"\t===============================================================================================\n\n";
	
	inputDatesAgain:
	
		cout<<"\tENTER DEPARTING FLIGHT MONTH: ";
		cin>>flightDepartMonthChoice;
		cout<<"\n\tENTER DEPARTING FLIGHT DAY: ";
		cin>>flightDepartDayChoice;
		cout<<"\n\tENTER RETURNING FLIGHT MONTH: ";
		cin>>flightReturnMonthChoice;
		cout<<"\n\tENTER RETURNING FLIGHT DAY: ";
		cin>>flightReturnDayChoice;
		
			if(isMonthAndDateValid(flightDepartMonthChoice, flightDepartDayChoice, flightReturnMonthChoice, flightReturnDayChoice) == 0)
			{
				cout<<"\n\t|| SYSTEM: INVALID INPUTS EITHER BETWEEN DEPARTING MONTH & DAY OR RETURNING MONTH & DAY. PLEASE TRY AGAIN!  ||\n\n";
				goto inputDatesAgain;
			}
			else
			{
				if((flightDepartMonthChoice == flightReturnMonthChoice) && (flightDepartDayChoice > flightReturnDayChoice))
				{
					flightDepartYear = flightYear;
					flightReturnYear = flightYear+1;
				}
				else
				{
					flightDepartYear = flightYear;
					flightReturnYear = flightYear;				
				}

				string locationPoints[10] = {"Manila", "Ilocos Norte", "Bataan", "Cebu", "Ilo-Ilo", "Aklan", "Bohol", "Davao", "General Santos", "Zamboanga"};
				string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};			
				cout<<"\n\n\tINPUT SUMMARY: "<<endl<<endl
					<<"\t||	PLACE OF ORIGIN: "<<locationPoints[flightOriginChoice-1]<<endl
					<<"\t||	DESTINATION: "<<locationPoints[flightDestinationChoice-1]<<endl
					<<"\t||	DEPARTING ON: "<<Months[flightDepartMonthChoice-1]<<", "<<flightDepartDayChoice<<" "<<flightDepartYear<<endl
					<<"\t||	RETURNING IN: "<<Months[flightReturnMonthChoice-1]<<", "<<flightReturnDayChoice<<" "<<flightReturnYear<<endl;
				cout<<"\n\n\t[ENTER] PROCEED TO FINDING FLIGHT SCHEDULES";
				system("pause>0");
				system("cls");
				cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tPROCEEDING TO FLIGHT SCHEDULES.....\n\n";
				Sleep(2000);
				findFlightSchedule(flightOriginChoice-1, flightDestinationChoice-1, flightDepartMonthChoice-1, 
									flightDepartDayChoice, flightReturnMonthChoice-1, flightReturnDayChoice, flightDepartYear, flightReturnYear);						
			}
}

void AirportBookingSystem::findFlightSchedule(int flightO, int flightD, int flightDM, int flightDDt, int flightRM, int flightRDt, int flightDY, int flightRY)	// 	FINISHED
{
	checkPoint:
	system("cls");
	int userChoice, airlineProvider1, airlineProvider2, totalPrice;
	
	string locationPoints[10] = {"Manila", "Ilocos Norte", "Bataan", "Cebu", "Ilo-Ilo", "Aklan", "Bohol", "Davao", "General Santos", "Zamboanga"};
	string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	string airlineProviders[4] = {"Cebu Pacific", "Air Asia", "2GO Travel", "Philippine Airlines"};
	
	cout<<"FLIGHT SCHEDULES: \n\n\n";
	cout<<"=====================================================================";
	cout<<"\nDEPARTING: \n"<<locationPoints[flightO]<<" =====> "<<locationPoints[flightD]<<endl;
	illustrateDate(flightDM, flightDDt);
	cout<<"CHOSEN DATE: "<<Months[flightDM]<<", "<<flightDDt<<" "<<flightDY<<endl
		<<"AVAILABLE AIRLINES: "<<endl;
	checkFlightAvailability(flightO, flightD);
	chooseAirline1Again:
	cout<<"\n\nCHOOSE AIRLINE PROVIDER: ";
	cin>>airlineProvider1;
	if(airlineProvider1 > 4)
	{
		cout<<"\n|| SYSTEM: AIRLINE OUT OF BOUNDS! REFER TO THE LIST. PLEASE TRY AGAIN. ||";
		goto chooseAirline1Again;
	}
	cout<<"TOTAL PRICE FOR DEPARTING FLIGHT: P"<<airlinePricing(flightO, flightD);
	cout<<"\n=====================================================================\n\n";
	
	
	cout<<"=====================================================================";
	cout<<"\nRETURNING: \n"<<locationPoints[flightD]<<" =====> "<<locationPoints[flightO]<<endl;
	illustrateDate(flightRM, flightRDt);	
	cout<<"CHOSEN DATE: "<<Months[flightRM]<<", "<<flightRDt<<" "<<flightRY<<endl
		<<"AVAILABLE AIRLINES: "<<endl;
	checkFlightAvailability(flightD, flightO);
	chooseAirline2Again:	
	cout<<"\n\nCHOOSE AIRLINE PROVIDER: ";
	cin>>airlineProvider2;
	if(airlineProvider2 > 4)
	{
		cout<<"\n|| SYSTEM: AIRLINE OUT OF BOUNDS! REFER TO THE LIST. PLEASE TRY AGAIN. ||\n";
		goto chooseAirline2Again;
	}
	cout<<"TOTAL PRICE FOR RETURNING FLIGHT: P"<<airlinePricing(flightD, flightO);
	cout<<"\n=====================================================================";	

	cout<<"\n\n\tINPUT SUMMARY: "<<endl<<endl
		<<"\t|| DEPARTING FLIGHT: "<<locationPoints[flightO]<<" BOUND TO "<<locationPoints[flightD]<<endl
		<<"\t|| DEPARTING DATE: "<<Months[flightDM]<<", "<<flightDDt<<" "<<flightDY<<endl
		<<"\t|| AIRLINE PROVIDER: "<<airlineProviders[airlineProvider1-1]<<endl
		<<"\t|| DEPARTING FLIGHT PRICE: P"<<airlinePricing(flightO, flightD)<<endl<<endl
		<<"\t|| RETURNING FLIGHT: "<<locationPoints[flightD]<<" GOING BACK TO "<<locationPoints[flightO]<<endl
		<<"\t|| DEPARTING DATE: "<<Months[flightRM]<<", "<<flightRDt<<" "<<flightRY<<endl
		<<"\t|| AIRLINE PROVIDER: "<<airlineProviders[airlineProvider2-1]<<endl
		<<"\t|| RETURNING FLIGHT PRICE: P"<<airlinePricing(flightD, flightO)<<endl<<endl;
		
	cout<<"\n\n\t[ENTER] PROCEED TO GUEST DETAILS";
	system("pause>0");
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tPROCEEDING TO GUEST DETAILS.....\n\n";
	Sleep(2000);
	proceedGuestDetails(locationPoints[flightO],locationPoints[flightD], flightDM, flightDDt, flightRM, flightRDt, flightDY, flightRY, airlineProviders[airlineProvider1-1], airlineProviders[airlineProvider2-1], airlinePricing(flightO, flightD), airlinePricing(flightD, flightO));
	system("pause>0");
}

void AirportBookingSystem::proceedGuestDetails(string flightO, string flightD, int flightDM, int flightDDt, int flightRM, int flightRDt, int flightDY, int flightRY, string aP1, string aP2, int dFP, int rFP)	// FINISHED
{
	system("cls");
	string passengerName;
	int passengerAge;
	struct AirportBookingSystemLL *inputAll, *p;
	string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	cout<<"\n\nENTER YOUR DETAILS:\n\n";
	cout<<"ENTER YOUR NICKNAME: ";
	cin>>passengerName;
	cout<<"ENTER YOUR AGE: ";
	cin>>passengerAge;
	
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tCREATING SUMMARY OF INPUTS.....\n\n";
	Sleep(2000);
	string randomizedID;
	randomizedID = getRandomID();
	system("cls");
	cout<<"\n\n\n\n\t\t\t\t\t\tSUMMARY OF INPUTS\n\n"
		<<"\t\t\t\t|| SYSTEM NOTICE: KINDLY MEMORIZE YOUR ID! ||"	
		<<"\n\n\t\t|| PASSENGER ID: "<<randomizedID<<endl
		<<"\t\t|| PASSENGER NICKNAME: "<<passengerName<<endl
		<<"\t\t|| PASSENGER AGE: "<<passengerAge<<endl<<endl<<endl
		<<"\t\tDEPARTING FLIGHT DETAILS\n"
		<<"\t\t|| DEPARTING FLIGHT ROUTE: "<<flightO<<" BOUND TO "<<flightD<<endl
		<<"\t\t|| DEPARTING FLIGHT DATE: "<<Months[flightDM]<<", "<<flightDDt<<" "<<flightDY<<endl
		<<"\t\t|| AIRLINE PROVIDER: "<<aP1<<endl
		<<"\t\t|| DEPARTING FLIGHT PRICE: P"<<dFP<<endl<<endl
		<<"\t\tRETURNING FLIGHT DETAILS\n"
		<<"\t\t|| RETURNING FLIGHT ROUTE: "<<flightD<<" GOING BACK TO "<<flightO<<endl
		<<"\t\t|| RETURNING FLIGHT DATE: "<<Months[flightRM]<<", "<<flightRDt<<" "<<flightRY<<endl
		<<"\t\t|| AIRLINE PROVIDER: "<<aP2<<endl
		<<"\t\t|| RETURNING FLIGHT PRICE: P"<<rFP<<endl<<endl;
	
	userData(randomizedID, passengerAge, passengerName, Months[flightDM], flightDDt, flightD, flightO, Months[flightRM], flightRDt, flightDY, flightRY, aP1, aP2, dFP, rFP);

	cout<<"\n\n\t\tPROCESS DONE! YOUR FLIGHT IS NOW BOOKED! HAVE A WONDERFUL DAY!";
	cout<<"\t\t\t[ENTER] EXIT";	
	system("pause>0");
}

int AirportBookingSystem::airlinePricing(int flightO, int flightD)	// FINISHED
{
	int flightDif;
	
	flightDif = flightD - flightO;
	
	if(flightDif <= 1 && flightDif >= -1)	//	0,1
	{
		return 3000;
	}
	if((flightDif <= 3 && flightDif >= 2) || (flightDif >= -3 && flightDif <= -2))
	{
		return 6000;
	}
	if((flightDif <= 5 && flightDif >= 4) || (flightDif >= -5 && flightDif <= -4))
	{
		return 9000;
	}
	if((flightDif <= 7 && flightDif >= 6) || (flightDif >= -7 && flightDif <= -6))
	{
		return 12000;
	}
	if((flightDif <= 9 && flightDif >= 8) || (flightDif >= -9 && flightDif <= -8))
	{
		return 15000;
	}
}

void AirportBookingSystem::illustrateDate(int flightMonth, int flightDay)	//	FINISHED
{
	string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout<<Months[flightMonth]<<endl;
	cout<<"===================================="<<endl;
	for(int i = flightDay-3; i <= flightDay+3; i++)
	{
		if((flightMonth == 0 || flightMonth == 2 || flightMonth == 4 || flightMonth == 6 || flightMonth == 7 || flightMonth == 9 || flightMonth == 11) && (i < 1 || i > 31))
		{
			continue;
		}
		else if((flightMonth == 3 || flightMonth == 5 || flightMonth == 8 || flightMonth == 10) && (i < 1 || i > 30))
		{
			continue;
		}
		else if((flightMonth == 1) && (i < 1 || i > 28))
		{
			continue;
		}
		if (i == flightDay && flightDay) 
		{
			cout<<"||> "<<i<<" <|| ";
			continue;
		}				
		cout<<i<<" ";
	}
	cout<<"\n===================================="<<endl;	
}

void AirportBookingSystem::modifyReservation()
{
	system("cls");
	string findPassengerID;
	int userChoice;
	bool dataFound = false;
	if(root == NULL)
	{
		cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHERE IS NO ADDED RECORD YET!\n";
		system("pause>0");
		return;
	}
	else
	{
		cout<<"ENTER ID: ";
		cin>>findPassengerID;
		struct AirportBookingSystemLL *ptr;	
		ptr = root;
		while(ptr != NULL)
		{
			if(ptr->passengerIdentificationNumber == findPassengerID)	
			{
				dataFound = true;
				system("pause>0");
				break;
			}
			ptr = ptr->next;				
		}
		if(dataFound == false)
		{
			cout<<"ID CAN'T FIND!";
			return;
		}	
		

		}
	}


void AirportBookingSystem::deleteFlight()	//	FINISHED
{
	system("cls");
	int userChoice;
	bool dataFound = false;
	string findPassengerID;
	if(root == NULL)
	{
		cout<<"LIST IS EMPTY!";
		system("pause>0");
		return;
	}
	else
	{
		cout<<"CHOICES:\n";
		cout<<"[1] SEARCH THROUGH ID AND DELETE\n[2] EXIT\nCHOICE: ";
		cin>>userChoice;
		switch(userChoice)
		{
			case 1: 
			{
				system("cls");
				cout<<"ENTER YOUR ID: ";
				cin>>findPassengerID;
				struct AirportBookingSystemLL *ptr;
				ptr = root;
				while(ptr != NULL)
				{
					if(root->passengerIdentificationNumber == findPassengerID)
					{
						dataFound = true;
						cout<<"WHAT DO YOU WANT TO MODIFY? ";
						cout<<"[1] NAME	[2]	AGE";
						cin>>userChoice;
						switch(userChoice)
						{
							case 1:
								{
									string newName;
									cout<<"TYPE YOUR NEW NICKNAME: ";
									cin>>newName;
									ptr->passengerName = newName;
									cout<<"OPERATION SUCCESSFULL!";
									break;
								}
							case 2:
								{
									int newAge;
									cout<<"TYPE YOUR NEW AGE: ";
									cin>>newAge;
									ptr->passengerAge = newAge;
									cout<<"OPERATION SUCCESSFULL!";
									break;
								}		
						}
						system("pause>0");
						break;
					}
					ptr = ptr->next;
				}
				if(dataFound == false)
				{
					cout<<"ID CAN'T FIND!";
				}
			}
		}
	}
}

void AirportBookingSystem::checkBookedFlightInfo()
{
	system("cls");
	string findPassengerID;
	bool dataFound = false;
	int pos = 0;
	if(root == NULL)
	{
		cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHERE IS NO ADDED RECORD YET!\n\t\t\t\t\t\t";
		system("pause>0");
		return;
	}
	else
	{
		struct AirportBookingSystemLL *ptr;	
		ptr = root;
		cout<<"ENTER YOUR ID: ";
		cin>>findPassengerID;	
		while(ptr != NULL)
		{
			pos++;
			if(ptr->passengerIdentificationNumber == findPassengerID)	
			{
				dataFound = true;
				cout<<"ID FOUND!"<<endl<<endl;
				cout<<"PASSENGER ID: "<<ptr->passengerIdentificationNumber
					<<"\nPASSENGER NAME: "<<ptr->passengerName
					<<"\nPASSENGER AGE: "<<ptr->passengerAge
					<<"\nDEPARTING FLIGHT DETAILS:"
					<<"\nDEPARTING FLIGHT ROUTE: "<<ptr->passengerOrigin<<" BOUND TO "<<ptr->passengerDestination
					<<"\nDEPARTING FLIGHT DATE: "<<ptr->passengerDestinationMonth<<", "<<ptr->passengerDestinationDay<<" "<<ptr->passengerDestinationYear
					<<"\nAIRLINE PROVIDER: "<<ptr->airlineProvider1
					<<"\nDEPARTING FLIGHT PRICE: P"<<ptr->departingFlightPrice
					<<"\nRETURNING FLIGHT DETAILS:"
					<<"\nRETURNING FLIGHT ROUTE: "<<ptr->passengerDestination<<" GOING BACK TO "<<ptr->passengerOrigin
					<<"\nRETURNING FLIGHT DATE: "<<ptr->passengerReturningMonth<<", "<<ptr->passengerReturningDay<<" "<<ptr->passengerReturningYear
					<<"\nRETURNING FLIGHT PRICE: P"<<ptr->returningFlightPrice;
				system("pause>0");
				break;
			}
			ptr = ptr->next;				
		}
		if(dataFound == false)
		{
			cout<<"ID CAN'T FIND!";
			return;
		}	
	}
}

void AirportBookingSystem::checkFlightAvailability(int flightO, int flightD)	//	FINISHED
{	
	int flightDif, estimatedTravelPrice;
	string estimatedTravelTime;
	
	flightDif = flightD - flightO;
	
	if(flightDif <= 1 && flightDif >= -1)	//	0,1
	{
		estimatedTravelTime = "1 HOUR";
		estimatedTravelPrice = 3000;
	}
	if((flightDif <= 3 && flightDif >= 2) || (flightDif >= -3 && flightDif <= -2))
	{
		estimatedTravelTime = "1 HOUR & 15 MINS.";
		estimatedTravelPrice = 6000;
	}
	if((flightDif <= 5 && flightDif >= 4) || (flightDif >= -5 && flightDif <= -4))
	{
		estimatedTravelTime = "1 HOUR & 30 MINS.";
		estimatedTravelPrice = 9000;
	}
	if((flightDif <= 7 && flightDif >= 6) || (flightDif >= -7 && flightDif <= -6))
	{
		estimatedTravelTime = "1 HOUR & 45 MINS.";
		estimatedTravelPrice = 12000;
	}
	if((flightDif <= 9 && flightDif >= 8) || (flightDif >= -9 && flightDif <= -8))
	{
		estimatedTravelTime = "2 HOURS";
		estimatedTravelPrice = 15000;
	}

	cout<<"AIRLINES\t\t\t"<<"ESTIMATED TRAVEL TIME"<<setw(10)<<"PRICE"<<endl<<endl
		<<"[1] CEBU PACIFIC\t"<<setw(25)<<estimatedTravelTime<<setw(10)<<"P"<<estimatedTravelPrice<<endl
		<<"[2] AIR ASIA\t\t"<<setw(25)<<estimatedTravelTime<<setw(10)<<"P"<<estimatedTravelPrice<<endl
		<<"[3] 2GO TRAVEL\t\t"<<setw(25)<<estimatedTravelTime<<setw(10)<<"P"<<estimatedTravelPrice<<endl
		<<"[4] PHILIPPINE AIRLINES\t"<<setw(25)<<estimatedTravelTime<<setw(10)<<"P"<<estimatedTravelPrice<<endl;
}

void AirportBookingSystem::displayAll()
{
	struct AirportBookingSystemLL *disp;
	disp = root;
	while(disp != NULL)
	{
		cout<<"PASSENGER NAME "<<disp->passengerName;
		disp = disp->next;
	}
}

bool AirportBookingSystem::isMonthAndDateValid(int flightDM, int flightDDt, int flightRM, int flightRDt)	//	FINISHED
{
	if(flightDM == flightRM	&& flightRM > flightDM)
	{
		return 0;
	}
	else if(flightDM < 1 || flightDM > 12 || flightRM < 1 || flightRM > 12)
	{
		return 0;
	}
	else if((flightDM == 1 || flightDM == 3 || flightDM == 5 || flightDM == 7 || flightDM == 8 || flightDM == 10 || flightDM == 12) && (flightDDt < 1 || flightDDt > 31))
	{
		return 0;
	}
	else if((flightRM == 1 || flightRM == 3 || flightRM == 5 || flightRM == 7 || flightRM == 8 || flightRM == 10 || flightRM == 12) && (flightRDt < 1 || flightRDt > 31))
	{
		return 0;
	}
	else if((flightDM == 4 || flightDM == 6 || flightDM == 9 || flightDM == 11) && (flightDDt < 1 || flightDDt > 30))
	{
		return 0;
	}
	else if((flightRM == 4 || flightRM == 6 || flightRM == 9 || flightRM == 11) && (flightRDt < 1 || flightRDt > 30))
	{
		return 0;
	}
	else if((flightDM == 2 && flightDDt < 1 || flightDDt > 28) || (flightRM == 2 && flightRDt < 1 || flightRDt > 28))
	{
		return 0;
	}
	else if((flightDM == flightRM) && (flightDDt == flightRDt))
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

string AirportBookingSystem::getRandomID()	//	FINISHED
{
	srand(time(0));
	static const char alphanum[] = "0123456789""QWERTYUIOPLKJHGFDSAZXCVBNM";
	int stringLength = sizeof(alphanum) - 1;
	string constructedID;	
	for (int i = 0; i < 5; i++)
	{
		constructedID += alphanum[rand() % stringLength];
	}
	return constructedID;
};

