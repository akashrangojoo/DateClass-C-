/***************************************************************
PROGRAM:   DATE.CC
AUTHOR:    AKASH RANGOJOO
LOGON ID:  Z1717009
DUE DATE:  10/2/2015

FUNCTION:  THIS IS THE FILE THAT CONTAINS ALL THE PUBLIC MEMBER METHODS REQUIRED 
           FOR IMPLEMETNING DATE CLASS
INPUT:     NONE
OUTPUT:    NONE
* ****************************************************************/

#include "Date.h"

//DEFAULT CONSTRUCTOR
Date::Date(){  
   day = 1;
   month = "January";
   year = 1900;
}

// OVERLOADED CONSTRUCTOR
Date::Date(const string & m,const int & d, const int & y){
   month = m;
   Month();
   day = d;
   year = y; 
}

// SETTER METHOD FOR MONTH
void Date::setMonth(const string & m) {
   month=m;
   Month();
}
//SETTER METHOD FOR DAY
void Date::setDay(const int & d) {
   day = d;
}
//SETTER METHOD FOR YEAR
void Date::setYear(const int &y) {
   year = y;
}
//GETTER METHOD FOR MONTH
string Date::getMonth() const {
   return month;
}
//GETTER METHOD FOR DAY
int Date::getDay() const {
   return day;
}
//GETTER METHOD FOR YEAR
int Date::getYear() const {
   return year;
}

//RETURNS TRUE IFALL THE COMPONENTS OF THE DATE ENTERED IS CORRECT
bool Date::isValidDate() const {
   bool flag=false;
   if(isValidMonth()){
      if(day<=daysInMonth() && day>0){
         if(year>=1){
            flag=true;}
      }
   }
   return flag;
}
// RETURNS MONTH PART WITH FIRST LETTER CAPITAL AND REST IN LOWERCASE
void Date::Month(){
   month[0]=  toupper(month[0]);
   for(unsigned i=1;i<month.length();i++)
   {
      month[i]=tolower(month[i]);
   }
}
// CONVERTS DATE VALUE INTO STRING AND RETRURN THE STRING IN THE REQUIRED MANNER 
string Date::toString() const {
   string dateString = intToString(day) + "-" + month.substr(0,3)+"-"+ intToString(year);
   return dateString;
}
// OVERLOADS >> OPERATOR. USED TO TAKE IN DATE VALUES FROM THE TERMINAL
istream& operator>> (istream& is, Date& d){
   char next;
   is>>d.month>>d.day>>next;
   if(isdigit(next)) is.unget();
   is>>d.year;
   return is;
}

// OVERLOADS << OPERATOR. USED TO PRINT DATE DIRECTLY.
ostream& operator<< (ostream& os,const Date& d){
   string mon = d.getMonth();
   int dy = d.getDay();
   int yr = d.getYear();
   os<<mon<<" "<<dy<<", "<<yr;
   return os;
}

