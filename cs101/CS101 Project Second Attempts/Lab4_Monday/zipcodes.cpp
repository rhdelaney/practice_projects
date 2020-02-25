#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Zipcode {
	int zip, lat, lon;
	string city, state;
public:
	Zipcode (int z, string c, string s, int l, int lo){
		zip=z; 
		city=c; 
		state=s; 
		lat=l; 
		lon=lo;
	}
	int getZip( ) { return zip; }
	string getCity( ) { return city; }
	string getState( ){ return state;}
	int getLat() {return lat;}
	int getLon() {return lon;}
	void print( ) { cout << zip << "\t" << city << "\t" << state<<"\t"<<lat<<"\t"<<lon; }
};

struct LessZip {
	bool operator() ( Zipcode p, Zipcode q ) {
		return p.getZip() < q.getZip();
	}
};
struct LessCityState {
	bool operator() ( Zipcode p, Zipcode q ) {
		if (p.getCity() < q.getCity()) return true;
		if (p.getCity() > q.getCity()) return false;
		return p.getState() < q. getState();
	}
};
struct LessStateCity{
	bool operator() ( Zipcode p, Zipcode q ) {
		if (p.getState() < q.getState()) return true;
		if (p.getState() > q.getState()) return false;
		return p.getCity() < q. getCity();
	}
};

struct LessLatLongState {
	bool operator() ( Zipcode p, Zipcode q ) {
		if (p.getLat() < q.getLat()) return true;
		if (p.getLat() > q.getLat()) return false;
		if (p.getLon() < q.getLon()) return true;
		if (p.getLon() > q.getLon()) return false;
		return p.getState() < q.getState();
	}
};
struct LessLongLatState {
	bool operator() ( Zipcode p, Zipcode q ) {
		if (p.getLon() < q.getLon()) return true;
		if (p.getLon() > q.getLon()) return false;
		if (p.getLat() < q.getLat()) return true;
		if (p.getLat() > q.getLat()) return false;
		return p.getState() < q.getState();
	}
};

void print (string s, vector<Zipcode> z) {
	cout << s << endl;
	vector<Zipcode>::iterator i;
	for (i=z.begin(); i!=z.end(); ++i) {
		cout << "\t";
		i->print();
		cout << endl;
	}
	cout << endl;
}

int main ( ) {
	vector<Zipcode> z;

	z.push_back( Zipcode(10001, "New York",  "NY",  41 , -74));
	z.push_back( Zipcode(90001,"Los Angeles", "CA",  34,  -118));
	z.push_back( Zipcode(77001,  "Houston\t" , "TX" , 30,  -95));
	z.push_back( Zipcode(60601, "Chicago\t", "IL",  42,  -88));
	z.push_back( Zipcode(78201, "San Antonio", 	"TX",  29 , -98));
	z.push_back( Zipcode(94101,  "San Francisco", "CA",  38,  -122 ) );
	z.push_back( Zipcode(19101, "Philadelphia", "PA",  40,  -75 ) );
	z.push_back( Zipcode(85001,  "Phoenix\t", "AZ", 33 , -112 ) );
	z.push_back( Zipcode(95101, "San Jose",  "CA",  37,  -122 ) );
	z.push_back( Zipcode(48201,  "Detroit\t", "MI",  42,  -83 ) );
	z.push_back( Zipcode(43201, "Columbus", "OH",  40,  -83 ) );
	z.push_back( Zipcode( 46201, "Indianapolis", "IN",  40 , -86) );
	z.push_back( Zipcode( 2201, "Boston\t", 	"MA",	42,-71) );
	z.push_back( Zipcode( 75201, "Dallas\t",	"TX",	33, -97) );
	z.push_back( Zipcode(64101,"Kansas City", "MO",	39, -95 ) );
	z.push_back( Zipcode( 73301,"Austin\t",	 "TX", 30,  -98) );
	z.push_back( Zipcode( 80201, "Denver\t", 	"CO", 40,  -105) );
	z.push_back( Zipcode(92101 ,"San Diego", 	"CA",  33 , -117 ) );
	z.push_back( Zipcode( 73101,  "Oklahoma City", 	"OK",35,  -97) );
	z.push_back( Zipcode(55401, "Minneapolis", 	"MN",45, -93) );
	z.push_back( Zipcode( 20001, "Washington", 	"DC", 39 , -77) );
	z.push_back( Zipcode(30301, "Atlanta\t", 	"GA", 34, -84 ) );
	z.push_back( Zipcode( 31901, "Columbus", "GA",32, -85 ) );
	z.push_back( Zipcode( 66101,"Kansas City", "KS",39 ,-95) );
	z.push_back( Zipcode(35401,"Tuscaloosa", "AL", 33, -88 ) );

	print( "Zipcode (unsorted)", z );
	sort( z.begin(), z.end(), LessZip() );
	print( "Zipcode (LessZip)", z );
	sort( z.begin(), z.end(), LessCityState() );
	print( "Zipcode (LessCityState)", z );
	sort( z.begin(), z.end(), LessStateCity() );
	print( "Zipcode (LessStateCity)", z );
	sort( z.begin(), z.end(), LessLatLongState() );
	print( "Zipcode (LessLatLongState)", z );
	sort( z.begin(), z.end(), LessLongLatState() );
	print( "Zipcode (LessLongLatState)", z );

	return 0;
}
