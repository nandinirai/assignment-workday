#include <bits/stdc++.h>
using namespace std;

class Order {    //Orders Constructor   
  public:          
    int orderID;  //Store OrderID
    string orders;  //Store Order String AAMAAA
    double dist;    //Store the distance in kms  
    Order(int x, string y, double z) { 
      orderID = x;
      orders=y;
      dist = z;
    }
};

int getTimeSlot(string orderItem){ //Function to get timeSlot
  int totalSlots=0;
  for(int i=0;i<orderItem.size();i++){
    if(orderItem[i]!='A' && orderItem[i]!='M'){
      return -1;
      break;
    }
    if(orderItem[i]=='A'){
      totalSlots+=1;
    }
    else if(orderItem[i]=='M'){
      totalSlots+=2;
    }
  }
  return totalSlots;
}

double orderTime(string orderItem, double distance){// Function to calculate orderTime
  int totalSlots=getTimeSlot(orderItem);
  int numA=0, numM=0;//numA for Appetizer numM for MainCourse
  for(int i=0;i<orderItem.size();i++){
    if(orderItem[i]!='A' && orderItem[i]!='M'){
      return -1;
      break;
    }
    if(orderItem[i]=='A'){
      numA++;
    }
    else if(orderItem[i]=='M'){
      numM++;
    }
  }
  if(totalSlots<=7){
    if(numA==0){
      return (29+distance*8);//Time Required For Main Course
    }
    else if(numM==0){
      return (17+distance*8);//Time Required For Appetizer
    }
    else{
    return (17+29+distance*8);
    }
  }
  else{
    return -1;
  }
}

int main() {
  Order obj[]={Order(12,"AA", 5),Order(21,"AM", 1),
  Order(32,"M", 0.1),Order(14,"MMMMAAA", 10),
  Order(22,"A", 3)};
  vector <Order> queue;
  
  int availableSlot = 0;
  int n = sizeof(obj)/sizeof(obj[0]);
  for(int i=0;i<n;i++){
  availableSlot+=getTimeSlot(obj[i].orders);
  double totalTime = orderTime(obj[i].orders,obj[i].dist);
  if(totalTime<=150 && totalTime>-1)
    { 
      queue.push_back(obj[i]);
      if(availableSlot<=7){
      cout<<"Order "<<obj[i].orderID<<" will take "<<totalTime<<"\n";
      }
      else{
      int indx = queue.size();
      double delayedTime = orderTime(queue[indx-2].orders,queue[indx-2].dist);
      cout<<"Order "<<obj[i].orderID<<" will take "<<totalTime+delayedTime<<"\n";
      }
    }
  else{
    cout<<"Order "<<obj[i].orderID<<" cannot be placed "<<"\n";//Condition where Order cannot be placed
    }
  }
} 