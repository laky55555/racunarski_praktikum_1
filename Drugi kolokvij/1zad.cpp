#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Sport
{
	protected:
	string ime1, ime2;
	int udarac1, udarac2;
	int brzina1, brzina2;
	public:
	Sport( string igrac1, string igrac2);
	virtual string pobjednik()=0;
};

class Boks : public Sport
{
	public:
	Boks( string igrac1, string igrac2);
	void udarac(string ime);
	string pobjednik();
};
class Tenis : public Sport
{
	protected:
	string imeTurnira;
	public:
	Tenis(string igrac1, string igrac2, string turnir="Wimbeldon");
	void servis( string ime, int brzina);
	string pobjednik();
};

Sport :: Sport( string igrac1, string igrac2)
{
	ime1=igrac1; ime2=igrac2;
	udarac1=0; udarac2=0;
	brzina1=0; brzina2=0;
}
Boks :: Boks( string igrac1, string igrac2) : Sport( igrac1, igrac2)
{
	cout<<"Pocela je prva runda. "<<endl;
}
Tenis :: Tenis( string igrac1, string igrac2, string turnir) : Sport( igrac1, igrac2)
{
	imeTurnira = turnir;
	cout<<imeTurnira<<endl;
}
void Boks :: udarac(string ime)
{
	if(ime==ime1) ++udarac1;
	else ++udarac2;
}
void Tenis :: servis( string ime, int brzina)
{
	if( ime==ime1)
	{if(brzina1 < brzina) brzina1=brzina;}
	if(ime2==ime)
	{if(brzina2 < brzina) brzina2=brzina;}
}
string Boks :: pobjednik()
{
	string pobjedio;
	if(udarac1 > udarac2) pobjedio=ime1;
	if(udarac2 > udarac1) pobjedio=ime2;
	cout<<"nokaut"<<" Pobjednik: "<<pobjedio<<" "<<udarac1<<":"<<udarac2<<endl;
	return pobjedio;
}
string Tenis :: pobjednik()
{
	string pobjedio;
	int brz;
	if(brzina1 > brzina2) {pobjedio=ime1; brz=brzina1;}
	else {pobjedio=ime2; brz=brzina2;}
	cout<<"gem, set i mec "<< pobjedio<<" "<<brz<<endl;
	return pobjedio;
}
int main()
{
	vector<Sport* > V;
	for(int i=0; i<50; ++i)
	{
		Boks *b= new Boks( "Marko","Matija");
		(b)->udarac("Marko"); (b)->udarac("Marko"); (b)->udarac("Matija");
		V.push_back(b);
	}
	for(int i=0;i<50;++i)
	{
		Tenis *t=new Tenis("Nadal", "Federer");
		(t)->servis("Nadal", 150); (t)->servis("Federer", 100); (t)->servis("Federer", 200);
		V.push_back(t);
	}

	for(int i=0; i<100; ++i)
	V[i]->pobjednik();

	return 0;
}







