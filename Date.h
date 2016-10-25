/***************************************************************
PROGRAM:   DATE.H
AUTHOR:    AKASH RANGOJOO
LOGON ID:  Z1717009
DUE DATE:  10/2/2015

FUNCTION:  THIS IS THE HEADER FILE FOR DATE.CC DATE CLASS. CONTAINS ALL THE MEMBBER METHODS 
REQUIRED FOR DATE CLASS
INPUT:     NONE
OUTPUT:    NONE
 * ****************************************************************/

#include "/home/cs689/common/689.h"

class Date
{
   public:
      Date();
      Date(const string & m,const int & d, const int & y);
      void setMonth(const string & m);
      void setDay(const int & d);
      void setYear(const int &y);
      string getMonth() const;
      int getDay() const;
      int getYear() const;
      bool isValidDate() const;
      void Month();
      string toString() const;


   private:
      int day;
      string month;
      int year;

      friend istream& operator>> (istream& is, Date& d);
      friend ostream& operator<< (ostream& os,const Date& d);
      //RETURNS TRUE IF MONTH ENTERED IS AMONG BELOW VALUES
      bool isValidMonth() const{

         if(month=="January")          return true;
         else if(month=="February")    return true; 
         else if(month=="March")       return true; 
         else if(month=="April")       return true; 
         else if(month=="May")         return true; 
         else if(month=="June")        return true; 
         else if(month=="July")        return true; 
         else if(month=="August")      return true; 
         else if(month=="September")   return true; 
         else if(month=="October")     return true; 
         else if(month=="November")    return true; 
         else if(month=="December")    return true; 
         else return false;
      }

      // rETURNS THE NUMBER OF DAYS ACCORDING TO THE MONTH
      int daysInMonth() const {
         if(month=="January")          return 31;
         else if(month=="February")    {if(isLeapYear()) return 29; else return 28;}
         else if(month=="March")       return 31; 
         else if(month=="April")       return 30; 
         else if(month=="May")         return 31; 
         else if(month=="June")        return 30; 
         else if(month=="July")        return 31; 
         else if(month=="August")      return 31; 
         else if(month=="September")   return 30; 
         else if(month=="October")     return 31; 
         else if(month=="November")    return 30; 
         else if(month=="December")    return 31; 
         else return false;
      }
      // CHECKS IF THE YEAR IS A LEAP YEAR AND RETURNS TRUE IF YES
      bool isLeapYear() const {
         bool flag=false;
         if ((year% 4 == 0) && !(year % 100 == 0))
            flag=true;
         else if (year % 400 == 0) 
            flag=true;
         return flag;
      }
      // CONVERTS DAY AND YEAR COMPONENTS WHICH ARE INTEGER TO STRING
      string intToString(int n) const{
         ostringstream stream;
         stream << n;
         return stream.str();
      }


};


