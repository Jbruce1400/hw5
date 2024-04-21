#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void helper(
    std::string& combo,
    int index,
    const char* alpha,
    const std::string& in,
    std::set<std::string>& wordBank,
    const std::string floating,
    const std::set<std::string>& dict,
    int count
    ) 
{

  if (index == in.size()){
    //add words to dic
    if (dict.find(combo) != dict.end()){
      //cout << "debug: " << combo << endl;
      wordBank.insert(combo);
       
    }
    return;
   
    //return
  }

 
    // if runtime seems to long then try recursivly iteratring approach
    if (in[index] !='-' ){
        combo[index]= in[index];
        //++count;
        helper(combo, index+1, alpha, in, wordBank, floating, dict,count+1);
        
      }
    if ((in[index] =='-')&&(floating.size()>=1)){
      for (int j = index; j < in.size(); ++j){
        combo[j] = floating[0];
        helper(combo,index+1, alpha, in, wordBank, floating.substr(1),dict,count+1);
        combo[j]= '-';
        //--count;  
    }

    }
      
      else{
        //for (int h = 0; h < in.size(); ++h){

         // if (combo[h] == '-'){
            //if (in.size()==2){
           //   cout << "found dash" << endl;
           // }
          if (combo[index]=='-'){
            for (int i = 0; i < 26; ++i){
              //for (int h = 0; h < in.size(); ++h){
                
                  combo[index] = alpha[i];
                   helper(combo,index + 1, alpha, in, wordBank, floating, dict, count+1);
                    combo[index]='-';
                  if (in.size()==2){
       
                  cout << "check combo after recursion:" << combo << endl;
                  }
                  
                  
                }
          }
                
                 
                
               

             // }

              
             /* if (in.size()==2){
                cout << "check h : " << h <<endl;
                cout << "debug2: " << combo <<endl;

              } */
              
              
               //if (in.size()==2){
                //cout << "backTracking:" << endl;
                //cout << "checking h after backTracking: " << h <<endl;
               // cout << "checking combo after backTracking: " << combo <<endl;
              //}

            }

          
        //} 
       

      }
    
    




//}

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::set<std::string> wordBank; 
    int index = 0;
     std::string combo = "";

    for (int i = 0; i < in.size(); ++i){
      combo.push_back('-');

    }
    helper(combo, index, alphabet, in, wordBank, floating, dict,0);
  /*

    std::set<std::string>::iterator it = wordBank.begin();
    for (it = wordBank.begin(); it != wordBank.end(); ++it){
        cout << *it << endl;
       // if (temp)
    }
    */


    return wordBank;
    


    //check for dashes in the given word?

    //make sure to check for duplicates
    
    //create edge case for if no letters are given.


    //save *it into a string and then check the indexs to for the given letters and then 

    // loop invarient- when we have made all possible combinations

    // reccurive loop should send the different combinations of the letters and return once it's done. 
   // check if word is valid should just be by checking if the indexs of letters match. 
    
   
    
/*
    for (int i = 0; i < stringSize; ++i){
        temp+= in[i];
        for (int j = 0; j < stringSize; ++i){
            helper(temp+in[j], std::set<std::string>&wordBank)
        }
    }
    
   for (int i = 0; i )
    std::set<std::string>::iterator it = dict.begin();
    for (it = dict.begin(); it != dict.end(); ++it){
        std::string temp= *it;
       // if (temp)

    } */

}

// Define any helper functions here
