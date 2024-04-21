#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here


// Add your implementation of schedule() and other helper functions here

int helper(DailySchedule& schedule, std::vector<size_t>& listOfShift, size_t day,const AvailabilityMatrix& availibity, size_t need, size_t totalShift){
    if (true == (availibity.size()==day)){
        return 1;
    }

    size_t totalWorkers = availibity[day].size();
   int worker;

    for(int i = 0; i < totalWorkers; ++i){
        worker = availibity[day][i];
      
        if ( (worker == 1) && (totalShift > listOfShift[i])){
           
            listOfShift[i]=listOfShift[i] +1;
             schedule[day].push_back(i);

           }
            
        

        if ((worker == 1) &&(need == schedule[day].size())){
          int rand = day +1;
            if (helper(schedule, listOfShift, rand, availibity, need, totalShift)==1){
            return helper(schedule, listOfShift, rand, availibity, need, totalShift);
            }
            else{
        
                
                listOfShift[i] = listOfShift[i] -1 ;
                schedule[day].pop_back();
            }
        
            
        }
      

    }
    return 0;

}

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    std:vector<size_t> listOfShift(avail[0].size(),0);
     sched = DailySchedule(avail.size());
  int getReturn = helper(sched, listOfShift, 0, avail ,dailyNeed,maxShifts);
    if (getReturn==1){
        return true;
    }
    else{
        return false;
    }

   
    // Add your code below




}












