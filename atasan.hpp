#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include <string>
#define PI 3.14

class MyMusic : public sf::Music
{
protected:

    bool onGetData(Chunk& data) /*override*/
    {
        if (sf::Music::onGetData(data))
        {
            // ... data contains the next chunk of samples to be played by the music ...
            return true;
        }
        else
            return false;
    }
};

using namespace std;
using namespace sf;

class Peluru{
	public:
		CircleShape pelurunya;
		Vector2f currVelocity;
		float maxspeed;
		Peluru(float radius=5.f)
		: currVelocity(0.f, 0.f), maxspeed(15.f){
			this->pelurunya.setRadius(radius);
			this->pelurunya.setFillColor(Color::Yellow);
		}
};

string semuanya(string filename, int urutannya) {
  ifstream fi(filename.c_str());
  string s, g="0";
  int sg=8;
  if(!fi.is_open()){
  	g="error bos waduh";
  }
  else{
  	while(getline(fi,s)){
  		if(sg==urutannya){
  			g=s;
		  }
		  sg-=1;
	}
	fi.close();
  }
  return g;
}
string petakan(string filename, int urutannya) {
  ifstream fi(filename.c_str());
  string s, g="0";
  int sg=1;
  if(!fi.is_open()){
  	g="error bos waduh";
  }
  else{
  	while(getline(fi,s)){
  		if(sg==urutannya){
  			g=s;
		  }
		  sg+=1;
	}
	fi.close();
  }
  return g;
}

bool save(int rut, string bagian, int pos){
	string file="save/"+static_cast<ostringstream*>( &(ostringstream() << pos) )->str()+".txt";
	ofstream baru(file.c_str());
	if(baru.is_open()){
		baru << bagian <<"\n"<< rut;
	}
	baru.close();
	return true;
}

int strkeint(string hasil){
	int harus;
	if(!(istringstream(hasil)>>harus)){
		harus=1;
	}
	if(harus<1){
		harus=1;
	}
	return harus;
}
float sudutnya(float x,float y){
	float goblok=atan(y/x)*180/PI, tolol;
	if(x<0){
		tolol=90;
	}
	else{
		tolol=-90;
	}
	return goblok+tolol;
}
