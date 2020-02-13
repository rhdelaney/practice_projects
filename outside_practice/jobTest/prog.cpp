#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <istream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct IP {
  public:
    int start1;
    int start2;
    int start3;
    int start4;
    int end1;
    int end2;
    int end3;
    int end4;
    struct node *next;
    struct node *prev;
};

//helper functions bitwise

//helper functions back to IP

int main(int argc, char* argv[]) {
	ifstream fin1;
	fin1.open("data.txt");
  string find = argv[1];
  int size = find.length();
  int f1 = 0;
  int f2 = 0;
  int f3 = 0;
  int f4 = 0;
  string start1, start2, start3, start4, end1, end2, end3, end4;
  string val,let, start, end, lbit;
  int set = 0;
  int j = 0;
  //cout<<find<<endl;
	for (int i = 0;i < size ;i++) {
    if (find[i] == '.') {
      if (set == 0) {
        f1 = stoi(val);
        val.clear();
        set++;
        j = 0;
      }
      else if (set == 1) {
        f2 = stoi(val);
        val.clear();
        set++;
        j = 0;
      }
      else if (set == 2) {
        f3 = stoi(val);
        val.clear();
        set++;
        j = 0;
      }
    }
    else {
      //cout<<find[i];
      val.insert(j,1,find[i]);
      j++;
    }
  }
  f4 = stoi(val);
  val.clear();
  //cout<<f1<<f2<<f3<<f4<<endl;
  string dslash = "/";
  string dhyphen = " - ";
  string dperiod = ".";
	//while(fin1>>let){
  while (getline(fin1,let)) {

      int bit = 0;
    //cout<<let<<endl;
    //temp=let.substr(let.find(dhyphen),let.find(dhyphen)+1);
    //cout<<"temp="<<temp<<endl;
    //if(1){
        start = let.substr(0,let.length()); //the first number half
        lbit = start.substr(start.find(dslash) + 1,start.length());
        start = start.substr(0,start.find(dslash));
        //cout<<"lbit size:"<<lbit.length()<<endl;
        if (lbit.length()>2) {
          lbit = lbit.substr(0,lbit.find(dhyphen));

        //cout<<"lbit in top if: "<<lbit<<endl;
        bit = stoi(lbit);
        if (bit > 7) {
        //cout<<"in if bit>7"<<endl;
          start1 = start.substr(0,start.find(dperiod)) ;
          start = start.substr(start.find(dperiod) + 1,start.length());
          if (bit > 15) {
          //cout<<"in if bit>15"<<endl;
            start2 = start.substr(0,start.find(dperiod)) ;
            start = start.substr(start.find(dperiod) + 1,start.length());
            if (bit > 23) {
            //cout<<"in if bit>23"<<endl;
              start3 = start.substr(0,start.find(dperiod)) ;
              start = start.substr(start.find(dperiod) + 1,start.length());
              if (bit > 31) {
                //cout<<"in if bit>31"<<endl;
                start4 = start;
              }
              else {
                //cout<<"in if, else"<<endl;
                start4 = "000";
              }
            }
            else {
              start3 = "000";
              start4 = "000";
            }
          }
          else {
            start2 = "000";
            start3 = "000";
            start4 = "000";
          }
        }
        else {
          start1 = "000";
          start2 = "000";
          start3 = "000";
          start4 = "000";
        }
        lbit.clear();
        //cout<<"after all those other things"<<endl;
        end = let.substr(let.find(dhyphen) + 3,let.length());
        lbit = end.substr(end.find(dslash) + 1,end.length());
        end = end.substr(0,end.find(dslash));
        //cout<<"end= "<<end<<endl;
      //  cout<<"lbit in if , end section: "<<lbit<<endl;
        bit = stoi(lbit);
        //cout<<"before if/else"<<endl;
        if (bit > 7) {
          //cout<<"in if bit>7"<<endl;
          end1 = end.substr(0,end.find(dperiod)) ;
          end = end.substr(end.find(dperiod) + 1,end.length());
          if(bit>15){
            //cout<<"in if bit>15"<<endl;
            end2 = end.substr(0,end.find(dperiod)) ;
            end = end.substr(end.find(dperiod) + 1, end.length());
            if (bit > 23) {
              //cout<<"in if bit>23"<<endl;
              end3 = end.substr(0,end.find(dperiod)) ;
              end = end.substr(end.find(dperiod) + 1,end.length());
              if (bit > 31) {
                //cout<<"in if bit>31"<<endl;
                end4 = end;
              }
              else {
                end4 = "255";
              }
            }
            else {
              end3 = "255";
              end4 = "255";
            }
          }
          else {
            end2 = "255";
            end3 = "255";
            end4 = "255";
          }
        }
        else{
          end1 = "255";
          end2 = "255";
          end3 = "255";
          end4 = "255";
        }
        //the second range half
    }
      else{
        lbit = let.substr(let.find(dslash) + 1,let.length());
      //  cout<<"lbit in the else: "<<lbit<<endl;
        bit = stoi(lbit);
        start = let.substr(0,let.find(dslash));
        if (bit > 7) {
        //  cout<<"in else bit>7"<<endl;
          start1 = start.substr(0,start.find(dperiod));
          end1 = start1;
          start = start.substr(start.find(dperiod) + 1,start.length());
          if (bit > 15) {
          //  cout<<"in else bit>15"<<endl;
            start2 = let.substr(0,start.find(dperiod)) ;
            end2 = start2;
            start = start.substr(start.find(dperiod) + 1,start.length());
            if (bit > 23) {
          //    cout<<"in else bit>23"<<endl;
              start3 = start.substr(0,start.find(dperiod)) ;
              end3 = start3;
              start = start.substr(start.find(dperiod) + 1,start.length());
              if (bit > 31) {
          //      cout<<"in else bit>31"<<endl;
                start4 = start;
                end4 = start;
              }
              else {
                start4 = "000";
                end4 = "255";
              }
            }
            else {
              start3 = "000";
              start4 = "000";
              end3 = "255";
              end4 = "255";
            }
          }
          else {
            start2 = "000";
            start3 = "000";
            start4 = "000";
            end2 = "255";
            end3 = "255";
            end4 = "255";
          }
        }
        else {
          start1 = "000";
          start2 = "000";
          start3 = "000";
          start4 = "000";
          end1 = "255";
          end2 = "255";
          end3 = "255";
          end4 = "255";
        }
      }
      if (stoi(start1) <= f1 && stoi(start2) <= f2 && stoi(start3) <= f3 && stoi(start4) <= f4
          && stoi(end1) >= f1 && stoi(end2) >= f2 && stoi(end3) >= f3 && stoi(end4) >= f4) {
           //cout<<start1<<"."<<start2<<"."<<start3<<"."<<start4<<"-"<<end1<<"."<<end2<<"."<<end3<<"."<<end4<<endl;
           cout << let << endl;
           return 0;
      }
      let.clear();
  }
  cout << "None Found" << endl;
  fin1.close();
	return 0;
}
