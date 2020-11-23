

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <ios>
#include <algorithm>
#include <time.h>
#include <chrono>
#include "robin_hood.h"
#include "robin_set.h"
#include "robin_growth_policy.h"
#include <unordered_map>
using namespace std;
using namespace std::chrono;


struct rels
{
     string SID, DestID, RelsGroup;
};

void StoreConcept(string id, robin_hood::unordered_flat_map<string, string> concepts,robin_hood::unordered_flat_map<string, string> desc, unordered_multimap<string, rels> rls  )
{
     
   int noOfGroups = 0;
   int noOfRelationships= 0;
   int noOfParents = 0;
   int noOfChildren = 0;
   int b = 0;
   string arr;
      auto it = desc.find(id);
        string description = it->second;
    
for (auto x : rls) {

    if (x.second.SID == id)
         {
           ++noOfParents;
         }

   if (x.second.DestID == id)
         {
             arr = {x.second.SID};
    StoreConcept(arr, concepts, desc , rls);
         }
   }

cout << id << ", " << description << ", " << noOfParents << "\n";
}


int main(){

cout << "\nReading All Files -- Please Wait";
   robin_hood::unordered_flat_map<string, string> concepts;
   ifstream conceptStream("concept.txt");

   string idConcept, activeConcept;
   string conceptLine;
   getline(conceptStream, conceptLine);
   while (!conceptStream.eof())
   {
       getline(conceptStream, idConcept, '\t');
       conceptStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       getline(conceptStream, activeConcept, '\t');
       conceptStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       conceptStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       if (activeConcept == "1")
        concepts[idConcept] = activeConcept;
   }

   robin_hood::unordered_flat_map<string, string> desc;
   ifstream descriptionStream("description.txt");

   string descriptionLine;
   string idDescription, activeDescription, conceptIdDescription, typeIdDescription, termDescription;
   getline(descriptionStream, descriptionLine);

   while (!descriptionStream.eof())
   {
       descriptionStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       descriptionStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       getline(descriptionStream, activeDescription, '\t');
       descriptionStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       getline(descriptionStream, conceptIdDescription, '\t');
       descriptionStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       getline(descriptionStream, typeIdDescription, '\t');
       getline(descriptionStream, termDescription, '\t');
       descriptionStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       if(activeDescription == "1" && typeIdDescription == "900000000000003001")
       desc[conceptIdDescription] = termDescription;
       //auto pos = desc.insert(desc.begin(), pair<string, string>(conceptIdDescription, termDescription));
   }

    unordered_multimap<string, relationship> rls;

  ifstream relationshipStream("relationship.txt");

   string idRelationship, activeRelationship, SID, DestID,RelsGroup, typeIdRelationship;
   string relationshipLine;
   getline(relationshipStream, relationshipLine);

   while (!relationshipStream.eof())
   {
       getline(relationshipStream, idRelationship, '\t');
       relationshipStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       getline(relationshipStream, activeRelationship, '\t');
       relationshipStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       getline(relationshipStream, SID, '\t');
       getline(relationshipStream, DestID, '\t');
       getline(relationshipStream, RelsGroup, '\t');
       getline(relationshipStream, typeIdRelationship, '\t');
       relationshipStream.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
       relationshipStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       if(activeRelationship == "1")
       {
          if(typeIdRelationship == "116680003")
      {
            auto pos = rls.insert(rls.begin(),pair<string, relationship>(SID,{SID, DestID,RelsGroup}));
      }
       }
   }


    cout << "\n Now commence file reading\n";
    string id;
    cout << "Please enter Concept ID: ";
    cin >> id;
    cout << "\nconceptID \t description \t #ofParents \t #ofRelationships \t #ofGroups\n";
    auto start = high_resolution_clock::now();
   StoreConcept(id,concepts,desc,rls);

    auto stop = high_resolution_clock::now();
      auto duration = duration_cast<seconds>(stop - start);
      cout << "\nTime taken by function: " << duration.count() << " seconds" << endl;
    
   return 0;
}



